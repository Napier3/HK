//=========================================================
// File: simparr.cpp

#include "stdafx.h"
#include "Simparr.h"


//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::InsertAt( int nIndex, T argT, int nCount )
{
	// Valid index?
	if( nIndex < 0 || nIndex > m_nUpperBound )
		return FALSE;

	int i;
	// Is there enough space after m_nUpperBound for inserting?
	if( ( m_nSize - 1 ) - m_nUpperBound >= nCount )
	{
		// Yes, no need to allocate more memory.
		// Push up the elements at the current position.
		for( i = m_nUpperBound + nCount; i >= nIndex + nCount; i-- )
			m_pT[ i ] = m_pT[ i - nCount ];
		// Copy in the new data.
		for( i = 0; i < nCount; i++ )
			m_pT[ nIndex + i ] = argT;
		// Adjust m_nUpperBound to new size.
		m_nUpperBound += nCount;
	}
	else
	{
		// No, need to allocate more memory.
		for (i = m_nSize - 1; i >= nIndex + nCount; i--)
			m_pT[i] = m_pT[i - nCount];
		if (m_nSize - nIndex < nCount)
			nCount = m_nSize - nIndex;
		for (i = 0; i < nCount; i++)
			m_pT[nIndex + i] = argT;
		m_nUpperBound = m_nSize - 1;
	}
	return TRUE;
}

//-------------------------------------------------------------------
template<class T> void SimpleArray<T>::InsertAtRef(int nIndex, T& argT, int nCount)
{
	if(nIndex < 0 || nIndex > m_nUpperBound)
		return;
	int i;
	if ((m_nSize - 1) - m_nUpperBound >= nCount)
	{
		for(i = m_nUpperBound + nCount; i >= nIndex + nCount; i--)
			m_pT[i] = m_pT[i - nCount];
		for(i = 0; i < nCount; i++)
			m_pT[nIndex + i] = argT;
		m_nUpperBound += nCount;
	}
	else
	{
		for (i = m_nSize - 1; i >= nIndex + nCount; i--)
			m_pT[i] = m_pT[i - nCount];
		if (m_nSize - nIndex < nCount)
			nCount = m_nSize - nIndex;
		for (i = 0; i < nCount; i++)
			m_pT[nIndex + i] = argT;
		m_nUpperBound = m_nSize - 1;
	}
}

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::RemoveAt(int nIndex, int nCount)
{
	if(nIndex < 0 || nIndex > m_nUpperBound || nCount < 1) return FALSE;
	if(nCount > m_nUpperBound - nIndex)
	{
		m_nUpperBound = nIndex - 1;
		return TRUE;
	}
	int i;
	for(i = nIndex; i <= m_nUpperBound - nCount; i++)
	{
		m_pT[i] = m_pT[i + nCount];
	}
	m_nUpperBound -= nCount;
	return TRUE;
}

//-------------------------------------------------------------------
template<class T> void SimpleArray<T>::SetAtGrow(int nIndex, T argT)
{
	if(nIndex < 0) return;
	if(nIndex > m_nSize - 1)
		AddSpace(nIndex - m_nSize + 1);
	m_pT[nIndex] = argT;
	if(nIndex > m_nUpperBound) m_nUpperBound = nIndex;
}

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::SetAtGrowRef(int nIndex, T& argT)
{
	if(nIndex < 0)
		return FALSE;
	if(nIndex > m_nSize - 1)
	{
		if (AddSpace(nIndex - m_nSize + 1) == FALSE)
			return FALSE;
	}
	m_pT[nIndex] = argT;
	if(nIndex > m_nUpperBound)
		m_nUpperBound = nIndex;
	return TRUE;
}

//-------------------------------------------------------------------
template<class T> void SimpleArray<T>::SetAt(int nIndex, T argT)
{
	if(nIndex >= 0 && nIndex < m_nSize)
	{
		m_pT[nIndex] = argT;
		if(nIndex > m_nUpperBound)
			m_nUpperBound = nIndex;
	}
	else
		return;
}

//-------------------------------------------------------------------
template<class T> void SimpleArray<T>::SetAtRef(int nIndex, T& argT)
{
	if(nIndex >= 0 && nIndex < m_nSize)
	{
		m_pT[nIndex] = argT;
		if(nIndex > m_nUpperBound)
			m_nUpperBound = nIndex;
	}
	else
		return;
}

//-------------------------------------------------------------------

//-------------------------------------------------------------------

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::GetGrowBy()
{
	return m_nGrowBy;
}

//-------------------------------------------------------------------


//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::GetUpperBound()
{
	return m_nUpperBound;
}

//-------------------------------------------------------------------


//-------------------------------------------------------------------




template<class T> int SimpleArray<T>::blContainsRef(T& argT)
{
	int i;
	for(i = 0; i <= m_nUpperBound; i++)
		if(argT == m_pT[i])
			return TRUE;
	return FALSE;
}

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::blContains(T argT)
{
	int i;
	for(i = 0; i <= m_nUpperBound; i++)
		if(argT == m_pT[i])
			return TRUE;
	return FALSE;
}

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::nContainsAt(T argT)
{
	int i;
	for(i = 0; i <= m_nUpperBound; i++)
		if(argT == m_pT[i])
			return i;
	return ARR_EMPTY;
}

//-------------------------------------------------------------------
// Make a copy of the other SimpleArray.

//-------------------------------------------------------------------
template<class T> void SimpleArray<T>::AppendRef(T& argT)
{
	SetAt(m_nUpperBound+1, argT);
}

//-------------------------------------------------------------------
template<class T> void SimpleArray<T>::Append(T argT)
{
	SetAtGrow(m_nUpperBound+1, argT);
}

//-------------------------------------------------------------------
template<class T> T& SimpleArray<T>::GetRefAt(int nIndex)
{
	return m_pT[nIndex];
}

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::blCompare(SimpleArray<T>& spa)
{
	if(m_nUpperBound != spa.GetUpperBound() ) return FALSE;
	int k;
	for(k = 0; k <= m_nUpperBound; k++)
	{
		if(m_pT[k] != spa[k]) return FALSE;
	}
	return TRUE;
}

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::operator==(SimpleArray<T>& spa)
{
	return blCompare(spa);
}

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::operator!=(SimpleArray<T>& spa)
{
	return !blCompare(spa);
}

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::blIsEmpty()
{
	return (GetUpperBound() < 0) ? TRUE : FALSE;
}

//-------------------------------------------------------------------
template<class T> void SimpleArray<T>::Exchange(int nIndex1, int nIndex2)
{
	T temp(GetRefAt(nIndex2));
	GetRefAt(nIndex2) = GetRefAt(nIndex1);
	GetRefAt(nIndex1) = temp;
}

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::Adopt(T* ptArray, int upbound, int size)
{
#ifdef _DEBUG
	if(ptArray == NULL || upbound<0 || size<=0 || upbound >= size)
		return FALSE;
#endif
	if(m_pT!=NULL)
		delete [] m_pT;
	m_pT = ptArray;
	m_nSize = size;
	m_nUpperBound = upbound;
	return TRUE;
}

//-------------------------------------------------------------------

//-------------------------------------------------------------------

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::ExpandToSize()
{
	m_nUpperBound = m_nSize - 1;
	return TRUE;
}

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::CopyFrom( int index, T* pSrc, int srclen )
{
	if( m_nSize - index >= srclen )
	{
		// Enough space to copy into.
		int i;
		for( i = 0; i < srclen; i++ )
			m_pT[ index + i ] = pSrc[ i ];
		if( index + srclen - 1 > m_nUpperBound )
			m_nUpperBound = index + srclen - 1;
		return TRUE;
	}
	else
		return FALSE;
}

//-------------------------------------------------------------------
int SimpleString::AppendString( char* ps )
{
	if( m_nUpperBound == -1 )
		return SetToString( ps );
	else
	{
		InsertAtGrow( m_nUpperBound, ps, 0, strlen( ps ) );
	}
	return TRUE;
}

//-------------------------------------------------------------------
int SimpleString::SetToString( char* ps )
{
	Clear();
	return AppendString( ps );
}

//-------------------------------------------------------------------
char* SimpleString::operator=( char* ps )
{
	SetToString( ps );
	return ps;
}

//-------------------------------------------------------------------
SimpleString& SimpleString::operator=( SimpleString str )
{
	SetToString( &str[0] );
	return *this;
}

//-------------------------------------------------------------------
char* SimpleString::operator+=( char* ps )
{
	if( m_nUpperBound == -1 )
		SetToString( ps );
	else
	{
		InsertAtGrow( m_nUpperBound, ps, 0, strlen( ps ) );
	}
	return ps;
}

//-------------------------------------------------------------------
int SimpleString::StrLen()
{
	if( m_pT != NULL )
		return strlen( m_pT );
	else
		return 0;
}

//-------------------------------------------------------------------
SimpleString::SimpleString()
{
	// Create a string containing only a zero-byte.
	m_nGrowBy = 64;
	Clear();
}

//-------------------------------------------------------------------
SimpleString::SimpleString( char* ps )
{
	// Create a SimpleString from a normal char array-string.
	m_nGrowBy = 64;
	Clear();
	SetToString( ps );
}

//-------------------------------------------------------------------
void SimpleString::Clear()
{
	ClearAll(0);
	Append( '\0' );
}

//-------------------------------------------------------------------
SimpleString SimpleString::operator+( SimpleString& str1 )
{
	SimpleString t1;
	t1.SetToString( m_pT );
	t1 += str1;
	return SimpleString( &t1[0] );
}

//-------------------------------------------------------------------
int SimpleString::IsEmpty()
{
	return !StrLen();
}

//-------------------------------------------------------------------
SimpleString operator+( SimpleString ps1, char* ps2 )
{
	SimpleString s1;
	s1 += ps1;
	s1 += ps2;
	return SimpleString(s1);
}

//-------------------------------------------------------------------
SimpleString operator+( char* ps1, SimpleString ps2 )
{
	SimpleString s1;
	s1 += ps1;
	s1 += ps2;
	return SimpleString(s1);
}

//-------------------------------------------------------------------
template<class T> int SimpleArray<T>::Replace( int ToReplaceIndex, int ToReplaceLength, T* pReplaceWith, int ReplaceWithLength )
{
	if( m_pT != NULL && ToReplaceLength > 0 )
	{
		// Number of elements from start to end of array large enough for request?
		if( m_nUpperBound - ToReplaceIndex + 1 >= ToReplaceLength )
		{
			if( ToReplaceLength < ReplaceWithLength )
			{
				int i;
				T dummy;

				// Next line might cause problems if used with non-pure-binary
				// objects.
				dummy = 0;

				InsertAtGrow( ToReplaceIndex, dummy, ReplaceWithLength - ToReplaceLength );
				for( i = 0; i < ReplaceWithLength; i++ )
				{
					m_pT[ ToReplaceIndex + i ] = pReplaceWith[ i ];
				}

				return TRUE;
			}
			else if( ToReplaceLength == ReplaceWithLength )
			{
				int i;
				for( i = 0; i < ReplaceWithLength; i++ )
				{
					m_pT[ ToReplaceIndex + i ] = pReplaceWith[ i ];
				}
				return TRUE;
			}
			else // if( ToReplaceLength > ReplaceWithLength )
			{
				int i;
				for( i = 0; i < ReplaceWithLength; i++ )
				{
					m_pT[ ToReplaceIndex + i ] = pReplaceWith[ i ];
				}

				RemoveAt( ToReplaceIndex + ReplaceWithLength, ToReplaceLength - ReplaceWithLength );
				return TRUE;
			}
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}
