###############################################################################
##         (c) Copyright, Real-Time Innovations, All rights reserved.        ##
##                                                                           ##
##         Permission to modify and use for internal purposes granted.       ##
## This software is provided "as is", without warranty, express or implied.  ##
##                                                                           ##
###############################################################################
ARCH=x64Linux3.xgcc4.6.3
CXX = g++
CXXFLAGS = -DRTI_UNIX -DRTI_LINUX -DRTI_64BIT -m64
CXXLD = g++
CXXLDFLAGS = -m64 -static-libgcc
SYSLIBS = -ldl -lnsl -lm -lpthread -lrt
INCLUDES = -Isrc -Isrc/idl -I$(NDDSHOME)/include -I$(NDDSHOME)/include/ndds

###############################################################################
# Ensure this Makefile is invoked with the right variable set
###############################################################################
ifeq ($(ARCH), )
all:
	@echo "***************************************************************"
	@echo "You cannot use this Makefile directly, instead use the"
	@echo "architecture-specific Makefile. For example:"
	@echo "         gmake -f make/Makefile.i86Linux2.6gcc4.1.1"
	@echo "***************************************************************"
	@false
else
###############################################################################
# Ensure $NDDSHOME is defined
###############################################################################
ifeq ($(NDDSHOME), )
all:
	@echo "***************************************************************"
	@echo "The environment variable 'NDDSHOME' is not set!"
	@echo "To use this makefile you need to set NDDSHOME to the directory"
	@echo "where you have RTI Connext installed."
	@echo "***************************************************************"
	@false
endif
###############################################################################
# Ensure $OCLINTHOME is defined
###############################################################################
ifeq ($(OCLINTHOME), )
all:
	@echo "***************************************************************"
	@echo "The environment variable 'OCLINTHOME' is not set!"
	@echo "To use this makefile you need to set OCLINTHOME to the directory"
	@echo "where you have OCLINT installed."
	@echo "***************************************************************"
	@false
endif
endif
###############################################################################
# Modify build flags for debug/release
###############################################################################
ifeq ($(DEBUG),1)
CXXFLAGS += -g -O0
ifeq ($(SHAREDLIB),1)
NDDSLIBS = -lnddscppd -lnddscd -lnddscored
else
NDDSLIBS = -lnddscppzd -lnddsczd -lnddscorezd
endif
else
CXXFLAGS += -O2
ifeq ($(SHAREDLIB),1)
NDDSLIBS = -lnddscpp -lnddsc -lnddscore
else
NDDSLIBS = -lnddscppz -lnddscz -lnddscorez
endif
endif

LIBS = -L$(NDDSHOME)/lib/$(ARCH) $(NDDSLIBS) $(SYSLIBS)

SOURCES = src/cmu-sdsp-datamediator.cpp
DIRECTORIES   = objs.dir objs/$(ARCH).dir
EXECUTABLE    = cmu-sdsp-datamediator
SOURCES_NODIR = $(notdir $(SOURCES))
OBJECTS       = $(SOURCES_NODIR:%.cpp=objs/$(ARCH)/%.o)

###############################################################################
# Build Rules
###############################################################################
all: OCLINT $(ARCH)
	@echo all
	
$(ARCH): $(DIRECTORIES) $(OBJECTS) $(EXECUTABLE:%=objs/$(ARCH)/%.o) \
	       $(EXECUTABLE:%=objs/$(ARCH)/%.out)

objs/$(ARCH)/%.out: objs/$(ARCH)/%.o
	$(CXXLD) $(CXXLDFLAGS) $< -o $(@:%.out=%) $(LIBS)

objs/$(ARCH)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $(DEFINES) $(INCLUDES) -c $<

# Here is how we create those subdirectories automatically.
%.dir :
	@echo "Checking directory $*"
	@if [ ! -d $* ]; then \
		echo "Making directory $*"; \
		mkdir -p $* ; \
	fi;

.PHONY: OCLINT

OCLINT:
	$(OCLINTHOME)/bin/oclint -max-priority-3=1 -max-priority-2=1 -max-priority-1=1 $(SOURCES) -- ${CXXFLAGS} -c

clean:
	@rm -Rf objs/$(ARCH)
	@echo "Successfully deleted object and executable files for architecture $(ARCH)"
	@echo "To delete ALL the architectures and any generated file use target 'veryclean'"

veryclean:
	@rm -Rf objs
	@echo "Deleted all executables, objects and generated files"
