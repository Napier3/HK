##########################################################################
# SISCO SOFTWARE MODULE HEADER ###########################################
##########################################################################
#			       						 #
# MODULE NAME : smem.mak          	             			 #
# PRODUCT(S)  : MMS-EASE-Lite						 #
#			       						 #
# MODULE DESCRIPTION :        						 #
# This makefile is used by the Linux 'make' utility to build the Memory	 #
# allocation library for MMS-EASE-Lite.  All paths including header 	 #
# files and object modules are relative to the current project directory #
# which makes this file as environment independent as possible.  Both    #
# the DEBUG and Non DEBUG versions of the Utilities are made with this   #
# script								 #
#									 #
# To make the SMEM_L.A:							 #
# 	make -f smem.mak     	    DFLAG=_l   DEFS=-DDEBUG_SISCO	 #
# To make the SMEM_N.A:							 #
# 	make -f smem.mak     	    DFLAG=_n				 #
# To make the SMEM_LD.A:						 #
# 	make -f smem.mak     OPT=-g DFLAG=_ld  DEFS=-DDEBUG_SISCO	 #
# To make the SMEM_ND.A:						 #
# 	make -f smem.mak     OPT=-g DFLAG=_nd				 #
#			       						 #
# MODIFICATION LOG :	       						 #
#  Date     Who   Rev			Comments			 #
# --------  ---  ------   -------------------------------------------	 #
# 08/04/05  EJV    05     Moved platform defs to platform.mak.
#			  Revised link & clean. Added -c in compile rule.
# 08/04/04  EJV    04     Add AIX OS support.
# 12/10/03  JRB    03     Add LYNX OS support. Del "no-stack-check" option.
# 10/21/03  JRB    02     Chg CFLAGS & LDFLAGS to be "user-settable",
#			   use $(AR), as recommended by GNU Make.
#			  Add "$(OBJDIR)/" prefix before all objects & "%.o",
#			   del "$(OBJDIR)/" prefix before "$@",
#			   then use $(OBJECTS) in $(AR) cmd.
#			  Use ARFLAGS (for QNX = -n -q, default = -r).
# 12/09/02  CRM    01     Created from QNX makefile.			 #
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
SRCDIR = ../../src
PROJ  = smem$(DFLAG)
LIST  = >> cc.lst 2>&1
VPATH = $(SRCDIR) $(OBJDIR) $(LIBDIR) $(INCDIR)

ALL_CFLAGS = $(PLATFORM_CFLAGS) \
	$(OPT) -I$(INCDIR) $(DEFS) -DMMS_LITE -DSMEM_ENABLE \
	$(CFLAGS)

# setup the dependencies for the source files
INCLUDES = $(INCDIR)/glbtypes.h \
	$(INCDIR)/sysincs.h \
	$(INCDIR)/mem_chk.h \
	$(INCDIR)/smem.h \
	$(INCDIR)/memlog.h \
	$(INCDIR)/slog.h \
	$(INCDIR)/gen_list.h

# These are the objects that belong in the library
OBJECTS = \
	$(OBJDIR)/mem_smem.o \
	$(OBJDIR)/smem.o \
	$(OBJDIR)/smemcfgx.o

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
$(OBJDIR)/mem_smem.o : mem_smem.c $(INCLUDES)
$(OBJDIR)/smem.o : smem.c $(INCLUDES)
$(OBJDIR)/smemcfgx.o : smemcfgx.c $(INCLUDES)
