##########################################################################
# SISCO SOFTWARE MODULE HEADER ###########################################
##########################################################################
#
# MODULE NAME : gse_mgmt.mak
# PRODUCT(S)  : MMS-EASE-Lite
#
# MODULE DESCRIPTION :
# This makefile is used by the Linux 'make' utility to build the
# "gse_mgmt" library for MMS-EASE-Lite.  All paths including header
# files and object modules are relative to the current project directory
# which makes this file as environment independent as possible.  Both
# the DEBUG and Non DEBUG versions of the library are made with this
# script.
#
# To make the gse_mgmt_l.a:
# 	make -f gse_mgmt.mak DFLAG=_l         DEFS=-DDEBUG_SISCO
# To make the gse_mgmt_n.a:
# 	make -f gse_mgmt.mak DFLAG=_n
# To make the gse_mgmt_ld.a:
# 	make -f gse_mgmt.mak DFLAG=_ld OPT=-g DEFS=-DDEBUG_SISCO
# To make the gse_mgmt_nd.a:
# 	make -f gse_mgmt.mak DFLAG=_nd OPT=-g
#
# MODIFICATION LOG :
#  Date     Who   Rev			Comments
# --------  ---  ------   -------------------------------------------
# 11/10/06  JRB    01     Created.
##########################################################################

# Include common and platform-dependent definitions
include ./platform.mak

# set the library, object, and include file path names
DFLAG  =
DEFS   =
OPT    =
LIBDIR = ../../lib
OBJDIR = obj$(DFLAG)
INCDIR = ../../inc
SRCDIR = ../../uca/goose
PROJ  = gse_mgmt$(DFLAG)
LIST  = >> cc.lst 2>&1
VPATH = $(SRCDIR) $(OBJDIR) $(LIBDIR) $(INCDIR)

ALL_CFLAGS = $(PLATFORM_CFLAGS) \
	$(OPT) -I$(INCDIR) $(DEFS) -DMMS_LITE \
	$(CFLAGS)

# setup the dependencies for the source files
INCLUDES = $(INCDIR)/glbtypes.h \
	$(INCDIR)/sysincs.h \
	$(INCDIR)/mem_chk.h \
	$(INCDIR)/slog.h \
	$(INCDIR)/gse_mgmt.h

# These are the objects that belong in the library
OBJECTS = \
	$(OBJDIR)/gse_mgmt_dec.o \
	$(OBJDIR)/gse_mgmt_enc.o

LIBRARY = $(LIBDIR)/$(PROJ).a

# Main target is the library
# Make sure all objects are up to date
# If any objects have changed, delete and recreate it.
$(LIBRARY): $(OBJECTS)
	rm -f $(LIBRARY)
	$(AR) $(ARFLAGS) $(LIBRARY) $(OBJECTS) $(LIST)
	echo "FINISHED CREATING $(LIBRARY) LIBRARY" $(LIST)
	echo "-----------------------------------------------------" $(LIST)

clean:
	rm -f $(OBJECTS)
	rm -f $(LIBRARY)
	echo "Finished clean" $(LIST)

# Pattern rule for all object files
# NOTE: the $@ is the complete target name including the "$(OBJDIR)/" prefix
$(OBJDIR)/%.o : %.c
#	Enable next line to log name of file being compiled (may help clarify error messages).
#	echo Compiling: $< $(LIST)
	$(CC) -c $(ALL_CFLAGS) $< -o $@ $(LIST)

# Object file target dependencies. All use the pattern rule above.
$(OBJDIR)/gse_mgmt_dec.o : gse_mgmt_dec.c $(INCLUDES)
$(OBJDIR)/gse_mgmt_enc.o : gse_mgmt_enc.c $(INCLUDES)
