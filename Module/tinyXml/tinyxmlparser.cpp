

#include <ctype.h>
#include <stddef.h>
// #include "stdafx.h"

#include "tinyxml.h"

//#define DEBUG_PARSER
#if defined( DEBUG_PARSER )
#	if defined( DEBUG ) && defined( _MSC_VER )
#		include <windows.h>
#		define TIXML_LOG OutputDebugString
#	else
#		define TIXML_LOG printf
#	endif
#endif
	
TiXmlBase::Entity TiXmlBase::entity[ NUM_ENTITY ] = 
{
	{ "&amp;",  5, '&' },
	{ "&lt;",   4, '<' },
	{ "&gt;",   4, '>' },
	{ "&quot;", 6, '\"' },
	{ "&apos;", 6, '\'' }
};


const unsigned char TIXML_UTF_LEAD_0 = 0xefU;
const unsigned char TIXML_UTF_LEAD_1 = 0xbbU;
const unsigned char TIXML_UTF_LEAD_2 = 0xbfU;

const int TiXmlBase::utf8ByteTable[256] = 
{
	//	0	1	2	3	4	5	6	7	8	9	a	b	c	d	e	f
		1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	// 0x00
		1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	// 0x10
		1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	// 0x20
		1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	// 0x30
		1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	// 0x40
		1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	// 0x50
		1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	// 0x60
		1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	// 0x70	End of ASCII range
		1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	// 0x80 0x80 to 0xc1 invalid
		1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	// 0x90 
		1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	// 0xa0 
		1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	// 0xb0 
		1,	1,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	// 0xc0 0xc2 to 0xdf 2 byte
		2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	// 0xd0
		3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	// 0xe0 0xe0 to 0xef 3 byte
		4,	4,	4,	4,	4,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1	// 0xf0 0xf0 to 0xf4 4 byte, 0xf5 and higher invalid
};


void TiXmlBase::ConvertUTF32ToUTF8( unsigned long input, char* output, int* length )
{
	const unsigned long BYTE_MASK = 0xBF;
	const unsigned long BYTE_MARK = 0x80;
	const unsigned long FIRST_BYTE_MARK[7] = { 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC };

	if (input < 0x80) 
		*length = 1;
	else if ( input < 0x800 )
		*length = 2;
	else if ( input < 0x10000 )
		*length = 3;
	else if ( input < 0x200000 )
		*length = 4;
	else
		{ *length = 0; return; }	// This code won't covert this correctly anyway.

	output += *length;

	// Scary scary fall throughs.
	switch (*length) 
	{
		case 4:
			--output; 
			*output = (char)((input | BYTE_MARK) & BYTE_MASK); 
			input >>= 6;
		case 3:
			--output; 
			*output = (char)((input | BYTE_MARK) & BYTE_MASK); 
			input >>= 6;
		case 2:
			--output; 
			*output = (char)((input | BYTE_MARK) & BYTE_MASK); 
			input >>= 6;
		case 1:
			--output; 
			*output = (char)(input | FIRST_BYTE_MARK[*length]);
	}
}


/*static*/ int TiXmlBase::IsAlpha( unsigned char anyByte, TiXmlEncoding /*encoding*/ )
{
		if ( anyByte < 127 )
			return isalpha( anyByte );
		else
			return 1;	// What else to do? The unicode set is huge...get the english ones right.
}


/*static*/ int TiXmlBase::IsAlphaNum( unsigned char anyByte, TiXmlEncoding /*encoding*/ )
{
		if ( anyByte < 127 )
			return isalnum( anyByte );
		else
			return 1;	// What else to do? The unicode set is huge...get the english ones right.
}


class TiXmlParsingData
{
	friend class TiXmlDocument;
  public:
	void Stamp( const char* now, TiXmlEncoding encoding );

	const TiXmlCursor& Cursor()	{ return cursor; }

  private:
	// Only used by the document!
	TiXmlParsingData( const char* start, int _tabsize, int row, int col )
	{
		assert( start );
		stamp = start;
		tabsize = _tabsize;
		cursor.row = row;
		cursor.col = col;
	}

	TiXmlCursor		cursor;
	const char*		stamp;
	int				tabsize;
};


void TiXmlParsingData::Stamp( const char* now, TiXmlEncoding encoding )
{
	assert( now );

	// Do nothing if the tabsize is 0.
	if ( tabsize < 1 )
	{
		return;
	}

	// Get the current row, column.
	int row = cursor.row;
	int col = cursor.col;
	const char* p = stamp;
	assert( p );

	while ( p < now )
	{
		// Treat p as unsigned, so we have a happy compiler.
		const unsigned char* pU = (const unsigned char*)p;

		// Code contributed by Fletcher Dunn: (modified by lee)
		switch (*pU) {
			case 0:
				// We *should* never get here, but in case we do, don't
				// advance past the terminating null character, ever
				return;

			case '\r':
				// bump down to the next line
				++row;
				col = 0;				
				// Eat the character
				++p;

				// Check for \r\n sequence, and treat this as a single character
				if (*p == '\n') {
					++p;
				}
				break;

			case '\n':
				// bump down to the next line
				++row;
				col = 0;

				// Eat the character
				++p;

				// Check for \n\r sequence, and treat this as a single
				// character.  (Yes, this bizarre thing does occur still
				// on some arcane platforms...)
				if (*p == '\r') {
					++p;
				}
				break;

			case '\t':
				// Eat the character
				++p;

				// Skip to next tab stop
				col = (col / tabsize + 1) * tabsize;
				break;

			case TIXML_UTF_LEAD_0:
				if ( encoding == TIXML_ENCODING_UTF8 )
				{
					if ( *(p+1) && *(p+2) )
					{
						// In these cases, don't advance the column. These are
						// 0-width spaces.
						if ( *(pU+1)==TIXML_UTF_LEAD_1 && *(pU+2)==TIXML_UTF_LEAD_2 )
							p += 3;	
						else if ( *(pU+1)==0xbfU && *(pU+2)==0xbeU )
							p += 3;	
						else if ( *(pU+1)==0xbfU && *(pU+2)==0xbfU )
							p += 3;	
						else
							{ p +=3; ++col; }	// A normal character.
					}
				}
				else
				{
					++p;
					++col;
				}
				break;

			default:
				if ( encoding == TIXML_ENCODING_UTF8 )
				{
					// Eat the 1 to 4 byte utf8 character.
					int step = TiXmlBase::utf8ByteTable[*((const unsigned char*)p)];
					if ( step == 0 )
						step = 1;		// Error case from bad encoding, but handle gracefully.
					p += step;

					// Just advance one column, of course.
					++col;
				}
				else
				{
					++p;
					++col;
				}
				break;
		}
	}
	cursor.row = row;
	cursor.col = col;
	assert( cursor.row >= -1 );
	assert( cursor.col >= -1 );
	stamp = p;
	assert( stamp );
}


const char* TiXmlBase::SkipWhiteSpace( const char* p, TiXmlEncoding encoding )
{
	if ( !p || !*p )
	{
		return 0;
	}
	if ( encoding == TIXML_ENCODING_UTF8 )
	{
		while ( *p )
		{
			const unsigned char* pU = (const unsigned char*)p;
			
			// Skip the stupid Microsoft UTF-8 Byte order marks
			if (	*(pU+0)==TIXML_UTF_LEAD_0
				 && *(pU+1)==TIXML_UTF_LEAD_1 
				 && *(pU+2)==TIXML_UTF_LEAD_2 )
			{
				p += 3;
				continue;
			}
			else if(*(pU+0)==TIXML_UTF_LEAD_0
				 && *(pU+1)==0xbfU
				 && *(pU+2)==0xbeU )
			{
				p += 3;
				continue;
			}
			else if(*(pU+0)==TIXML_UTF_LEAD_0
				 && *(pU+1)==0xbfU
				 && *(pU+2)==0xbfU )
			{
				p += 3;
				continue;
			}

			if ( IsWhiteSpace( *p ) )		// Still using old rules for white space.
				++p;
			else
				break;
		}
	}
	else
	{
		while ( *p && IsWhiteSpace( *p ) )
			++p;
	}

	return p;
}

#ifdef TIXML_USE_STL
/*static*/ bool TiXmlBase::StreamWhiteSpace( std::istream * in, TIXML_STRING * tag )
{
	for( ;; )
	{
		if ( !in->good() ) return false;

		int c = in->peek();
		// At this scope, we can't get to a document. So fail silently.
		if ( !IsWhiteSpace( c ) || c <= 0 )
			return true;

		*tag += (char) in->get();
	}
}

/*static*/ bool TiXmlBase::StreamTo( std::istream * in, int character, TIXML_STRING * tag )
{
	//assert( character > 0 && character < 128 );	// else it won't work in utf-8
	while ( in->good() )
	{
		int c = in->peek();
		if ( c == character )
			return true;
		if ( c <= 0 )		// Silent failure: can't get document at this scope
			return false;

		in->get();
		*tag += (char) c;
	}
	return false;
}
#endif

// One of TinyXML's more performance demanding functions. Try to keep the memory overhead down. The
// "assign" optimization removes over 10% of the execution time.
//
const char* TiXmlBase::ReadName( const char* p, TIXML_STRING * name, TiXmlEncoding encoding )
{
	*name = "";
	assert( p );
	if (    p && *p 
		 && ( IsAlpha( (unsigned char) *p, encoding ) || *p == '_' ) )
	{
		const char* start = p;
		while(		p && *p
				&&	(		IsAlphaNum( (unsigned char ) *p, encoding ) 
						 || *p == '_'
						 || *p == '-'
						 || *p == '.'
						 || *p == ':' ) )
		{
			//(*name) += *p; // expensive
			++p;
		}
		if ( p-start > 0 ) {
			name->assign( start, p-start );
		}
		return p;
	}
	return 0;
}

const char* TiXmlBase::GetEntity( const char* p, char* value, int* length, TiXmlEncoding encoding )
{
	// Presume an entity, and pull it out.
    TIXML_STRING ent;
	int i;
	*length = 0;

	if ( *(p+1) && *(p+1) == '#' && *(p+2) )
	{
		unsigned long ucs = 0;
		ptrdiff_t delta = 0;
		unsigned mult = 1;

		if ( *(p+2) == 'x' )
		{
			// Hexadecimal.
			if ( !*(p+3) ) return 0;

			const char* q = p+3;
			q = strchr( q, ';' );

			if ( !q || !*q ) return 0;

			delta = q-p;
			--q;

			while ( *q != 'x' )
			{
				if ( *q >= '0' && *q <= '9' )
					ucs += mult * (*q - '0');
				else if ( *q >= 'a' && *q <= 'f' )
					ucs += mult * (*q - 'a' + 10);
				else if ( *q >= 'A' && *q <= 'F' )
					ucs += mult * (*q - 'A' + 10 );
				else 
					return 0;
				mult *= 16;
				--q;
			}
		}
		else
		{
			// Decimal.
			if ( !*(p+2) ) return 0;

			const char* q = p+2;
			q = strchr( q, ';' );

			if ( !q || !*q ) return 0;

			delta = q-p;
			--q;

			while ( *q != '#' )
			{
				if ( *q >= '0' && *q <= '9' )
					ucs += mult * (*q - '0');
				else 
					return 0;
				mult *= 10;
				--q;
			}
		}
		if ( encoding == TIXML_ENCODING_UTF8 )
		{
			// convert the UCS to UTF-8
			ConvertUTF32ToUTF8( ucs, value, length );
		}
		else
		{
			*value = (char)ucs;
			*length = 1;
		}
		return p + delta + 1;
	}

	// Now try to match it.
	for( i=0; i<NUM_ENTITY; ++i )
	{
		if ( strncmp( entity[i].str, p, entity[i].strLength ) == 0 )
		{
			assert( strlen( entity[i].str ) == entity[i].strLength );
			*value = entity[i].chr;
			*length = 1;
			return ( p + entity[i].strLength );
		}
	}

	// So it wasn't an entity, its unrecognized, or something like that.
	*value = *p;	// Don't put back the last one, since we return it!
	//*length = 1;	// Leave unrecognized entities - this doesn't really work.
					// Just writes strange XML.
	return p+1;
}


bool TiXmlBase::StringEqual( const char* p,
							 const char* tag,
							 bool ignoreCase,
							 TiXmlEncoding encoding )
{
	assert( p );
	assert( tag );
	if ( !p || !*p )
	{
		assert( 0 );
		return false;
	}

	const char* q = p;

	if ( ignoreCase )
	{
		while ( *q && *tag && ToLower( *q, encoding ) == ToLower( *tag, encoding ) )
		{
			++q;
			++tag;
		}

		if ( *tag == 0 )
			return true;
	}
	else
	{
		while ( *q && *tag && *q == *tag )
		{
			++q;
			++tag;
		}

		if ( *tag == 0 )		// Have we found the end of the tag, and everything equal?
			return true;
	}
	return false;
}

const char* TiXmlBase::ReadText(	const char* p, 
									TIXML_STRING * text, 
									bool trimWhiteSpace, 
									const char* endTag, 
									bool caseInsensitive,
									TiXmlEncoding encoding )
{
    *text = "";
	if (    !trimWhiteSpace			// certain tags always keep whitespace
		 || !condenseWhiteSpace )	// if true, whitespace is always kept
	{
		// Keep all the white space.
		while (	   p && *p
				&& !StringEqual( p, endTag, caseInsensitive, encoding )
			  )
		{
			int len;
			char cArr[4] = { 0, 0, 0, 0 };
			p = GetChar( p, cArr, &len, encoding );
			text->append( cArr, len );
		}
	}
	else
	{
		bool whitespace = false;

		// Remove leading white space:
		p = SkipWhiteSpace( p, encoding );
		while (	   p && *p
				&& !StringEqual( p, endTag, caseInsensitive, encoding ) )
		{
			if ( *p == '\r' || *p == '\n' )
			{
				whitespace = true;
				++p;
			}
			else if ( IsWhiteSpace( *p ) )
			{
				whitespace = true;
				++p;
			}
			else
			{
				// If we've found whitespace, add it before the
				// new character. Any whitespace just becomes a space.
				if ( whitespace )
				{
					(*text) += ' ';
					whitespace = false;
				}
				int len;
				char cArr[4] = { 0, 0, 0, 0 };
				p = GetChar( p, cArr, &len, encoding );
				if ( len == 1 )
					(*text) += cArr[0];	// more efficient
				else
					text->append( cArr, len );
			}
		}
	}
	if ( p && *p ) 
		p += strlen( endTag );
	return p;
}

#ifdef TIXML_USE_STL

void TiXmlDocument::StreamIn( std::istream * in, TIXML_STRING * tag )
{

	if ( !StreamTo( in, '<', tag ) ) 
	{
		SetError( TIXML_ERROR_PARSING_EMPTY, 0, 0, TIXML_ENCODING_UNKNOWN );
		return;
	}

	while ( in->good() )
	{
		int tagIndex = (int) tag->length();
		while ( in->good() && in->peek() != '>' )
		{
			int c = in->get();
			if ( c <= 0 )
			{
				SetError( TIXML_ERROR_EMBEDDED_NULL, 0, 0, TIXML_ENCODING_UNKNOWN );
				break;
			}
			(*tag) += (char) c;
		}

		if ( in->good() )
		{
			TiXmlNode* node = Identify( tag->c_str() + tagIndex, TIXML_DEFAULT_ENCODING );

			if ( node )
			{
				node->StreamIn( in, tag );
				bool isElement = node->ToElement() != 0;
				delete node;
				node = 0;
				if ( isElement )
				{
					return;
				}
			}
			else
			{
				SetError( TIXML_ERROR, 0, 0, TIXML_ENCODING_UNKNOWN );
				return;
			}
		}
	}
	// We should have returned sooner.
	SetError( TIXML_ERROR, 0, 0, TIXML_ENCODING_UNKNOWN );
}

#endif

const char* TiXmlDocument::Parse( const char* p, TiXmlParsingData* prevData, TiXmlEncoding encoding )
{
	ClearError();

	if ( !p || !*p )
	{
		SetError( TIXML_ERROR_DOCUMENT_EMPTY, 0, 0, TIXML_ENCODING_UNKNOWN );
		return 0;
	}
	location.Clear();
	if ( prevData )
	{
		location.row = prevData->cursor.row;
		location.col = prevData->cursor.col;
	}
	else
	{
		location.row = 0;
		location.col = 0;
	}
	TiXmlParsingData data( p, TabSize(), location.row, location.col );
	location = data.Cursor();

	if ( encoding == TIXML_ENCODING_UNKNOWN )
	{
		// Check for the Microsoft UTF-8 lead bytes.
		const unsigned char* pU = (const unsigned char*)p;
		if (	*(pU+0) && *(pU+0) == TIXML_UTF_LEAD_0
			 && *(pU+1) && *(pU+1) == TIXML_UTF_LEAD_1
			 && *(pU+2) && *(pU+2) == TIXML_UTF_LEAD_2 )
		{
			encoding = TIXML_ENCODING_UTF8;
			useMicrosoftBOM = true;
		}
	}

    p = SkipWhiteSpace( p, encoding );
	if ( !p )
	{
		SetError( TIXML_ERROR_DOCUMENT_EMPTY, 0, 0, TIXML_ENCODING_UNKNOWN );
		return 0;
	}

	while ( p && *p )
	{
		TiXmlNode* node = Identify( p, encoding );

		if ( node )
		{
			p = node->Parse( p, &data, encoding );
			LinkEndChild( node );
		}
		else
		{
			break;
		}

		// Did we get encoding info?
		if (    encoding == TIXML_ENCODING_UNKNOWN
			 && node->ToDeclaration() )
		{
			TiXmlDeclaration* dec = node->ToDeclaration();
			const char* enc = dec->Encoding();
			assert( enc );

			if ( *enc == 0 )
				encoding = TIXML_ENCODING_UTF8;
			else if ( StringEqual( enc, "UTF-8", true, TIXML_ENCODING_UNKNOWN ) )
				encoding = TIXML_ENCODING_UTF8;
			else if ( StringEqual( enc, "UTF8", true, TIXML_ENCODING_UNKNOWN ) )
				encoding = TIXML_ENCODING_UTF8;	// incorrect, but be nice
			else 
				encoding = TIXML_ENCODING_LEGACY;
		}

		p = SkipWhiteSpace( p, encoding );
	}

	// Was this empty?
	if ( !firstChild ) {
		SetError( TIXML_ERROR_DOCUMENT_EMPTY, 0, 0, encoding );
		return 0;
	}

	// All is well.
	return p;
}

void TiXmlDocument::SetError( int err, const char* pError, TiXmlParsingData* data, TiXmlEncoding encoding )
{	
	// The first error in a chain is more accurate - don't set again!
	if ( error )
		return;

	assert( err > 0 && err < TIXML_ERROR_STRING_COUNT );
	error   = true;
	errorId = err;
	errorDesc = errorString[ errorId ];

	errorLocation.Clear();
	if ( pError && data )
	{
		data->Stamp( pError, encoding );
		errorLocation = data->Cursor();
	}
}


TiXmlNode* TiXmlNode::Identify( const char* p, TiXmlEncoding encoding )
{
	TiXmlNode* returnNode = 0;

	p = SkipWhiteSpace( p, encoding );
	if( !p || !*p || *p != '<' )
	{
		return 0;
	}

	p = SkipWhiteSpace( p, encoding );

	if ( !p || !*p )
	{
		return 0;
	}

	const char* xmlHeader = { "<?xml" };
	const char* commentHeader = { "<!--" };
	const char* dtdHeader = { "<!" };
	const char* cdataHeader = { "<![CDATA[" };

	if ( StringEqual( p, xmlHeader, true, encoding ) )
	{
		#ifdef DEBUG_PARSER
			TIXML_LOG( "XML parsing Declaration\n" );
		#endif
		returnNode = new TiXmlDeclaration();
	}
	else if ( StringEqual( p, commentHeader, false, encoding ) )
	{
		#ifdef DEBUG_PARSER
			TIXML_LOG( "XML parsing Comment\n" );
		#endif
		returnNode = new TiXmlComment();
	}
	else if ( StringEqual( p, cdataHeader, false, encoding ) )
	{
		#ifdef DEBUG_PARSER
			TIXML_LOG( "XML parsing CDATA\n" );
		#endif
		TiXmlText* text = new TiXmlText( "" );
		text->SetCDATA( true );
		returnNode = text;
	}
	else if ( StringEqual( p, dtdHeader, false, encoding ) )
	{
		#ifdef DEBUG_PARSER
			TIXML_LOG( "XML parsing Unknown(1)\n" );
		#endif
		returnNode = new TiXmlUnknown();
	}
	else if (    IsAlpha( *(p+1), encoding )
			  || *(p+1) == '_' )
	{
		#ifdef DEBUG_PARSER
			TIXML_LOG( "XML parsing Element\n" );
		#endif
		returnNode = new TiXmlElement( "" );
	}
	else
	{
		#ifdef DEBUG_PARSER
			TIXML_LOG( "XML parsing Unknown(2)\n" );
		#endif
		returnNode = new TiXmlUnknown();
	}

	if ( returnNode )
	{
		// Set the parent, so it can report errors
		returnNode->parent = this;
	}
	return returnNode;
}

#ifdef TIXML_USE_STL

void TiXmlElement::StreamIn (std::istream * in, TIXML_STRING * tag)
{
	while( in->good() )
	{
		int c = in->get();
		if ( c <= 0 )
		{
			TiXmlDocument* document = GetDocument();
			if ( document )
				document->SetError( TIXML_ERROR_EMBEDDED_NULL, 0, 0, TIXML_ENCODING_UNKNOWN );
			return;
		}
		(*tag) += (char) c ;
		
		if ( c == '>' )
			break;
	}

	if ( tag->length() < 3 ) return;

	// Okay...if we are a "/>" tag, then we're done. We've read a complete tag.
	// If not, identify and stream.

	if (    tag->at( tag->length() - 1 ) == '>' 
		 && tag->at( tag->length() - 2 ) == '/' )
	{
		// All good!
		return;
	}
	else if ( tag->at( tag->length() - 1 ) == '>' )
	{
		// There is more. Could be:
		//		text
		//		cdata text (which looks like another node)
		//		closing tag
		//		another node.
		for ( ;; )
		{
			StreamWhiteSpace( in, tag );

			// Do we have text?
			if ( in->good() && in->peek() != '<' ) 
			{
				// Yep, text.
				TiXmlText text( "" );
				text.StreamIn( in, tag );

				// What follows text is a closing tag or another node.
				// Go around again and figure it out.
				continue;
			}

			// We now have either a closing tag...or another node.
			// We should be at a "<", regardless.
			if ( !in->good() ) return;
			assert( in->peek() == '<' );
			int tagIndex = (int) tag->length();

			bool closingTag = false;
			bool firstCharFound = false;

			for( ;; )
			{
				if ( !in->good() )
					return;

				int c = in->peek();
				if ( c <= 0 )
				{
					TiXmlDocument* document = GetDocument();
					if ( document )
						document->SetError( TIXML_ERROR_EMBEDDED_NULL, 0, 0, TIXML_ENCODING_UNKNOWN );
					return;
				}
				
				if ( c == '>' )
					break;

				*tag += (char) c;
				in->get();

				// Early out if we find the CDATA id.
				if ( c == '[' && tag->size() >= 9 )
				{
					size_t len = tag->size();
					const char* start = tag->c_str() + len - 9;
					if ( strcmp( start, "<![CDATA[" ) == 0 ) {
						assert( !closingTag );
						break;
					}
				}

				if ( !firstCharFound && c != '<' && !IsWhiteSpace( c ) )
				{
					firstCharFound = true;
					if ( c == '/' )
						closingTag = true;
				}
			}
			// If it was a closing tag, then read in the closing '>' to clean up the input stream.
			// If it was not, the streaming will be done by the tag.
			if ( closingTag )
			{
				if ( !in->good() )
					return;

				int c = in->get();
				if ( c <= 0 )
				{
					TiXmlDocument* document = GetDocument();
					if ( document )
						document->SetError( TIXML_ERROR_EMBEDDED_NULL, 0, 0, TIXML_ENCODING_UNKNOWN );
					return;
				}
				assert( c == '>' );
				*tag += (char) c;

				// We are done, once we've found our closing tag.
				return;
			}
			else
			{
				// If not a closing tag, id it, and stream.
				const char* tagloc = tag->c_str() + tagIndex;
				TiXmlNode* node = Identify( tagloc, TIXML_DEFAULT_ENCODING );
				if ( !node )
					return;
				node->StreamIn( in, tag );
				delete node;
				node = 0;

				// No return: go around from the beginning: text, closing tag, or node.
			}
		}
	}
}
#endif

const char* TiXmlElement::Parse( const char* p, TiXmlParsingData* data, TiXmlEncoding encoding )
{
	p = SkipWhiteSpace( p, encoding );
	TiXmlDocument* document = GetDocument();

	if ( !p || !*p )
	{
		if ( document ) document->SetError( TIXML_ERROR_PARSING_ELEMENT, 0, 0, encoding );
		return 0;
	}

	if ( data )
	{
		data->Stamp( p, encoding );
		location = data->Cursor();
	}

	if ( *p != '<' )
	{
		if ( document ) document->SetError( TIXML_ERROR_PARSING_ELEMENT, p, data, encoding );
		return 0;
	}

	p = SkipWhiteSpace( p+1, encoding );

	// Read the name.
	const char* pErr = p;

    p = ReadName( p, &value, encoding );
	if ( !p || !*p )
	{
		if ( document )	document->SetError( TIXML_ERROR_FAILED_TO_READ_ELEMENT_NAME, pErr, data, encoding );
		return 0;
	}

    TIXML_STRING endTag ("</");
	endTag += value;

	// Check for and read attributes. Also look for an empty
	// tag or an end tag.
	while ( p && *p )
	{
		pErr = p;
		p = SkipWhiteSpace( p, encoding );
		if ( !p || !*p )
		{
			if ( document ) document->SetError( TIXML_ERROR_READING_ATTRIBUTES, pErr, data, encoding );
			return 0;
		}
		if ( *p == '/' )
		{
			++p;
			// Empty tag.
			if ( *p  != '>' )
			{
				if ( document ) document->SetError( TIXML_ERROR_PARSING_EMPTY, p, data, encoding );		
				return 0;
			}
			return (p+1);
		}
		else if ( *p == '>' )
		{
			++p;
			p = ReadValue( p, data, encoding );		// Note this is an Element method, and will set the error if one happens.
			if ( !p || !*p ) {
				// We were looking for the end tag, but found nothing.
				// Fix for [ 1663758 ] Failure to report error on bad XML
				if ( document ) document->SetError( TIXML_ERROR_READING_END_TAG, p, data, encoding );
				return 0;
			}
			if ( StringEqual( p, endTag.c_str(), false, encoding ) )
			{
				p += endTag.length();
				p = SkipWhiteSpace( p, encoding );
				if ( p && *p && *p == '>' ) {
					++p;
					return p;
				}
				if ( document ) document->SetError( TIXML_ERROR_READING_END_TAG, p, data, encoding );
				return 0;
			}
			else
			{
				if ( document ) document->SetError( TIXML_ERROR_READING_END_TAG, p, data, encoding );
				return 0;
			}
		}
		else
		{
			// Try to read an attribute:
			TiXmlAttribute* attrib = new TiXmlAttribute();
			if ( !attrib )
			{
				return 0;
			}

			attrib->SetDocument( document );
			pErr = p;
			p = attrib->Parse( p, data, encoding );

			if ( !p || !*p )
			{
				if ( document ) document->SetError( TIXML_ERROR_PARSING_ELEMENT, pErr, data, encoding );
				delete attrib;
				return 0;
			}

			// Handle the strange case of double attributes:
			#ifdef TIXML_USE_STL
			TiXmlAttribute* node = attributeSet.Find( attrib->NameTStr() );
			#else
			TiXmlAttribute* node = attributeSet.Find( attrib->Name() );
			#endif
			if ( node )
			{
				if ( document ) document->SetError( TIXML_ERROR_PARSING_ELEMENT, pErr, data, encoding );
				delete attrib;
				return 0;
			}

			attributeSet.Add( attrib );
		}
	}
	return p;
}


const char* TiXmlElement::ReadValue( const char* p, TiXmlParsingData* data, TiXmlEncoding encoding )
{
	TiXmlDocument* document = GetDocument();

	// Read in text and elements in any order.
	const char* pWithWhiteSpace = p;
	p = SkipWhiteSpace( p, encoding );

	while ( p && *p )
	{
		if ( *p != '<' )
		{
			// Take what we have, make a text element.
			TiXmlText* textNode = new TiXmlText( "" );

			if ( !textNode )
			{
			    return 0;
			}

			if ( TiXmlBase::IsWhiteSpaceCondensed() )
			{
				p = textNode->Parse( p, data, encoding );
			}
			else
			{
				p = textNode->Parse( pWithWhiteSpace, data, encoding );
			}

			if ( !textNode->Blank() )
				LinkEndChild( textNode );
			else
				delete textNode;
		} 
		else 
		{
			if ( StringEqual( p, "</", false, encoding ) )
			{
				return p;
			}
			else
			{
				TiXmlNode* node = Identify( p, encoding );
				if ( node )
				{
					p = node->Parse( p, data, encoding );
					LinkEndChild( node );
				}				
				else
				{
					return 0;
				}
			}
		}
		pWithWhiteSpace = p;
		p = SkipWhiteSpace( p, encoding );
	}

	if ( !p )
	{
		if ( document ) document->SetError( TIXML_ERROR_READING_ELEMENT_VALUE, 0, 0, encoding );
	}	
	return p;
}


#ifdef TIXML_USE_STL
void TiXmlUnknown::StreamIn( std::istream * in, TIXML_STRING * tag )
{
	while ( in->good() )
	{
		int c = in->get();	
		if ( c <= 0 )
		{
			TiXmlDocument* document = GetDocument();
			if ( document )
				document->SetError( TIXML_ERROR_EMBEDDED_NULL, 0, 0, TIXML_ENCODING_UNKNOWN );
			return;
		}
		(*tag) += (char) c;

		if ( c == '>' )
		{
			// All is well.
			return;		
		}
	}
}
#endif


const char* TiXmlUnknown::Parse( const char* p, TiXmlParsingData* data, TiXmlEncoding encoding )
{
	TiXmlDocument* document = GetDocument();
	p = SkipWhiteSpace( p, encoding );

	if ( data )
	{
		data->Stamp( p, encoding );
		location = data->Cursor();
	}
	if ( !p || !*p || *p != '<' )
	{
		if ( document ) document->SetError( TIXML_ERROR_PARSING_UNKNOWN, p, data, encoding );
		return 0;
	}
	++p;
    value = "";

	while ( p && *p && *p != '>' )
	{
		value += *p;
		++p;
	}

	if ( !p )
	{
		if ( document )	document->SetError( TIXML_ERROR_PARSING_UNKNOWN, 0, 0, encoding );
	}
	if ( *p == '>' )
		return p+1;
	return p;
}

#ifdef TIXML_USE_STL
void TiXmlComment::StreamIn( std::istream * in, TIXML_STRING * tag )
{
	while ( in->good() )
	{
		int c = in->get();	
		if ( c <= 0 )
		{
			TiXmlDocument* document = GetDocument();
			if ( document )
				document->SetError( TIXML_ERROR_EMBEDDED_NULL, 0, 0, TIXML_ENCODING_UNKNOWN );
			return;
		}

		(*tag) += (char) c;

		if ( c == '>' 
			 && tag->at( tag->length() - 2 ) == '-'
			 && tag->at( tag->length() - 3 ) == '-' )
		{
			// All is well.
			return;		
		}
	}
}
#endif


const char* TiXmlComment::Parse( const char* p, TiXmlParsingData* data, TiXmlEncoding encoding )
{
	TiXmlDocument* document = GetDocument();
	value = "";

	p = SkipWhiteSpace( p, encoding );

	if ( data )
	{
		data->Stamp( p, encoding );
		location = data->Cursor();
	}
	const char* startTag = "<!--";
	const char* endTag   = "-->";

	if ( !StringEqual( p, startTag, false, encoding ) )
	{
		document->SetError( TIXML_ERROR_PARSING_COMMENT, p, data, encoding );
		return 0;
	}
	p += strlen( startTag );


    value = "";
	// Keep all the white space.
	while (	p && *p && !StringEqual( p, endTag, false, encoding ) )
	{
		value.append( p, 1 );
		++p;
	}
	if ( p && *p ) 
		p += strlen( endTag );

	return p;
}


const char* TiXmlAttribute::Parse( const char* p, TiXmlParsingData* data, TiXmlEncoding encoding )
{
	p = SkipWhiteSpace( p, encoding );
	if ( !p || !*p ) return 0;

	if ( data )
	{
		data->Stamp( p, encoding );
		location = data->Cursor();
	}
	// Read the name, the '=' and the value.
	const char* pErr = p;
	p = ReadName( p, &m_name, encoding );
	if ( !p || !*p )
	{
		if ( m_document ) m_document->SetError( TIXML_ERROR_READING_ATTRIBUTES, pErr, data, encoding );
		return 0;
	}
	p = SkipWhiteSpace( p, encoding );
	if ( !p || !*p || *p != '=' )
	{
		if ( m_document ) m_document->SetError( TIXML_ERROR_READING_ATTRIBUTES, p, data, encoding );
		return 0;
	}

	++p;	// skip '='
	p = SkipWhiteSpace( p, encoding );
	if ( !p || !*p )
	{
		if ( m_document ) m_document->SetError( TIXML_ERROR_READING_ATTRIBUTES, p, data, encoding );
		return 0;
	}
	
	const char* end;
	const char SINGLE_QUOTE = '\'';
	const char DOUBLE_QUOTE = '\"';

	if ( *p == SINGLE_QUOTE )
	{
		++p;
		end = "\'";		// single quote in string
		p = ReadText( p, &m_value, false, end, false, encoding );
	}
	else if ( *p == DOUBLE_QUOTE )
	{
		++p;
		end = "\"";		// double quote in string
		p = ReadText( p, &m_value, false, end, false, encoding );
	}
	else
	{
		m_value = "";
		while (    p && *p											// existence
				&& !IsWhiteSpace( *p )								// whitespace
				&& *p != '/' && *p != '>' )							// tag end
		{
			if ( *p == SINGLE_QUOTE || *p == DOUBLE_QUOTE ) {
				if ( m_document ) m_document->SetError( TIXML_ERROR_READING_ATTRIBUTES, p, data, encoding );
				return 0;
			}
			m_value += *p;
			++p;
		}
	}
	return p;
}

#ifdef TIXML_USE_STL
void TiXmlText::StreamIn( std::istream * in, TIXML_STRING * tag )
{
	while ( in->good() )
	{
		int c = in->peek();	
		if ( !cdata && (c == '<' ) ) 
		{
			return;
		}
		if ( c <= 0 )
		{
			TiXmlDocument* document = GetDocument();
			if ( document )
				document->SetError( TIXML_ERROR_EMBEDDED_NULL, 0, 0, TIXML_ENCODING_UNKNOWN );
			return;
		}

		(*tag) += (char) c;
		in->get();	// "commits" the peek made above

		if ( cdata && c == '>' && tag->size() >= 3 ) {
			size_t len = tag->size();
			if ( (*tag)[len-2] == ']' && (*tag)[len-3] == ']' ) {
				// terminator of cdata.
				return;
			}
		}    
	}
}
#endif

const char* TiXmlText::Parse( const char* p, TiXmlParsingData* data, TiXmlEncoding encoding )
{
	value = "";
	TiXmlDocument* document = GetDocument();

	if ( data )
	{
		data->Stamp( p, encoding );
		location = data->Cursor();
	}

	const char* const startTag = "<![CDATA[";
	const char* const endTag   = "]]>";

	if ( cdata || StringEqual( p, startTag, false, encoding ) )
	{
		cdata = true;

		if ( !StringEqual( p, startTag, false, encoding ) )
		{
			document->SetError( TIXML_ERROR_PARSING_CDATA, p, data, encoding );
			return 0;
		}
		p += strlen( startTag );

		// Keep all the white space, ignore the encoding, etc.
		while (	   p && *p
				&& !StringEqual( p, endTag, false, encoding )
			  )
		{
			value += *p;
			++p;
		}

		TIXML_STRING dummy; 
		p = ReadText( p, &dummy, false, endTag, false, encoding );
		return p;
	}
	else
	{
		bool ignoreWhite = true;

		const char* end = "<";
		p = ReadText( p, &value, ignoreWhite, end, false, encoding );
		if ( p )
			return p-1;	// don't truncate the '<'
		return 0;
	}
}

#ifdef TIXML_USE_STL
void TiXmlDeclaration::StreamIn( std::istream * in, TIXML_STRING * tag )
{
	while ( in->good() )
	{
		int c = in->get();
		if ( c <= 0 )
		{
			TiXmlDocument* document = GetDocument();
			if ( document )
				document->SetError( TIXML_ERROR_EMBEDDED_NULL, 0, 0, TIXML_ENCODING_UNKNOWN );
			return;
		}
		(*tag) += (char) c;

		if ( c == '>' )
		{
			// All is well.
			return;
		}
	}
}
#endif

const char* TiXmlDeclaration::Parse( const char* p, TiXmlParsingData* data, TiXmlEncoding _encoding )
{
	p = SkipWhiteSpace( p, _encoding );
	// Find the beginning, find the end, and look for
	// the stuff in-between.
	TiXmlDocument* document = GetDocument();
	if ( !p || !*p || !StringEqual( p, "<?xml", true, _encoding ) )
	{
		if ( document ) document->SetError( TIXML_ERROR_PARSING_DECLARATION, 0, 0, _encoding );
		return 0;
	}
	if ( data )
	{
		data->Stamp( p, _encoding );
		location = data->Cursor();
	}
	p += 5;

	version = "";
	encoding = "";
	standalone = "";

	while ( p && *p )
	{
		if ( *p == '>' )
		{
			++p;
			return p;
		}

		p = SkipWhiteSpace( p, _encoding );
		if ( StringEqual( p, "version", true, _encoding ) )
		{
			TiXmlAttribute attrib;
			p = attrib.Parse( p, data, _encoding );		
			version = attrib.Value();
		}
		else if ( StringEqual( p, "encoding", true, _encoding ) )
		{
			TiXmlAttribute attrib;
			p = attrib.Parse( p, data, _encoding );		
			encoding = attrib.Value();
		}
		else if ( StringEqual( p, "standalone", true, _encoding ) )
		{
			TiXmlAttribute attrib;
			p = attrib.Parse( p, data, _encoding );		
			standalone = attrib.Value();
		}
		else
		{
			// Read over whatever it is.
			while( p && *p && *p != '>' && !IsWhiteSpace( *p ) )
				++p;
		}
	}
	return 0;
}

bool TiXmlText::Blank() const
{
	for ( unsigned i=0; i<value.length(); i++ )
		if ( !IsWhiteSpace( value[i] ) )
			return false;
	return true;
}

