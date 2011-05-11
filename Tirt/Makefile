#
# OMNeT++/OMNEST Makefile for Tirt_new
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out
#

# Name of target to be created (-o option)
TARGET = Tirt_new$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -IadmissionControl \
    -Idata \
    -Igenerators \
    -Ireceivers \
    -Iresults \
    -Ischeduler \
    -Itraffic

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/admissionControl/AdmissionControl.o \
    $O/generators/ExponentialGenerator.o \
    $O/generators/MmppGenerator.o \
    $O/generators/OnOffGenerator.o \
    $O/generators/PoissonGenerator.o \
    $O/receivers/Receiver.o \
    $O/scheduler/Scheduler.o \
    $O/traffic/TrafficShaper.o \
    $O/data/Package_m.o

# Message files
MSGFILES = \
    data/Package.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $(TARGET)

$(TARGET) : $O/$(TARGET)
	$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY:

.SUFFIXES: .cc

$O/%.o: %.cc
	@$(MKPATH) $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f Tirt_new Tirt_new.exe libTirt_new.so libTirt_new.a libTirt_new.dll libTirt_new.dylib
	-rm -f ./*_m.cc ./*_m.h
	-rm -f admissionControl/*_m.cc admissionControl/*_m.h
	-rm -f data/*_m.cc data/*_m.h
	-rm -f generators/*_m.cc generators/*_m.h
	-rm -f receivers/*_m.cc receivers/*_m.h
	-rm -f results/*_m.cc results/*_m.h
	-rm -f scheduler/*_m.cc scheduler/*_m.h
	-rm -f traffic/*_m.cc traffic/*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc admissionControl/*.cc data/*.cc generators/*.cc receivers/*.cc results/*.cc scheduler/*.cc traffic/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/admissionControl/AdmissionControl.o: admissionControl/AdmissionControl.cc \
	data/Package_m.h
$O/data/Package_m.o: data/Package_m.cc \
	data/Package_m.h
$O/generators/MmppGenerator.o: generators/MmppGenerator.cc \
	data/Package_m.h
$O/generators/OnOffGenerator.o: generators/OnOffGenerator.cc \
	data/Package_m.h
$O/generators/PoissonGenerator.o: generators/PoissonGenerator.cc \
	data/Package_m.h
$O/generators/ExponentialGenerator.o: generators/ExponentialGenerator.cc \
	data/Package_m.h
$O/receivers/Receiver.o: receivers/Receiver.cc \
	data/Package_m.h
$O/scheduler/Scheduler.o: scheduler/Scheduler.cc \
	data/Package_m.h
$O/traffic/TrafficShaper.o: traffic/TrafficShaper.cc \
	data/Package_m.h

