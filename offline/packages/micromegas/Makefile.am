##############################################
# please add new classes in alphabetical order

AUTOMAKE_OPTIONS = foreign

if USE_ONLINE

### trimmed version of libmicromegas_io library, for online monitoring
### it only contains MicromegasDefs.h and MicromegasMapping

lib_LTLIBRARIES = \
  libmicromegas_io.la

## TODO: check with Chris where headers are installed (TrkrDefs.h) in "online" build
AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include \
  -isystem$(ROOTSYS)/include

## TODO: check with Chris where libraries are installed (TrkrDefs.h) in "online" build
AM_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib

pkginclude_HEADERS = \
  MicromegasCalibrationData.h \
  MicromegasDefs.h \
  MicromegasHotChannelMapData.h \
  MicromegasMapping.h

# sources for io library
libmicromegas_io_la_SOURCES = \
  MicromegasCalibrationData.cc \
  MicromegasDefs.cc \
  MicromegasHotChannelMapData.cc \
  MicromegasMapping.cc

libmicromegas_io_la_LIBADD = \
  -lcdbobjects \
  -ltrack_io

BUILT_SOURCES = testexternals.cc

noinst_PROGRAMS = \
  testexternals_micromegas_io

testexternals_micromegas_io_SOURCES = testexternals.cc
testexternals_micromegas_io_LDADD = libmicromegas_io.la

else

### full offline version
lib_LTLIBRARIES = \
  libmicromegas_io.la \
  libmicromegas.la

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include  \
  -isystem$(ROOTSYS)/include

AM_LDFLAGS = \
  -L$(libdir) \
  -L$(ROOTSYS)/lib \
  -L$(OFFLINE_MAIN)/lib

pkginclude_HEADERS = \
  CylinderGeomMicromegas.h \
  MicromegasCalibrationData.h \
  MicromegasClusterizer.h \
  MicromegasCombinedDataCalibration.h \
  MicromegasCombinedDataDecoder.h \
  MicromegasCombinedDataEvaluation.h \
  MicromegasDefs.h \
  MicromegasHotChannelMapData.h \
  MicromegasMapping.h \
  MicromegasTile.h

ROOTDICTS = \
  CylinderGeomMicromegas_Dict.cc \
  MicromegasTile_Dict.cc

pcmdir = $(libdir)
nobase_dist_pcm_DATA = \
  CylinderGeomMicromegas_Dict_rdict.pcm \
  MicromegasCombinedDataEvaluation_Dict_rdict.pcm \
  MicromegasTile_Dict_rdict.pcm

libmicromegas_io_la_SOURCES = \
  $(ROOTDICTS) \
  CylinderGeomMicromegas.cc \
  MicromegasCalibrationData.cc \
  MicromegasDefs.cc \
  MicromegasHotChannelMapData.cc \
  MicromegasMapping.cc

libmicromegas_io_la_LIBADD = \
  -lCLHEP \
  -ltrack \
  -ltrack_io \
  -lcdbobjects \
  -lg4detectors_io

libmicromegas_la_SOURCES = \
  MicromegasClusterizer.cc \
	 MicromegasCombinedDataCalibration.cc \
  MicromegasCombinedDataDecoder.cc \
  MicromegasCombinedDataEvaluation.cc \
  MicromegasCombinedDataEvaluation_Dict.cc

libmicromegas_la_LIBADD = \
  libmicromegas_io.la \
  -lfun4allraw \
  -lffarawobjects \
  -lphg4hit \
  -lSubsysReco

%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@  $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

%_Dict_rdict.pcm: %_Dict.cc ;

BUILT_SOURCES = testexternals.cc

noinst_PROGRAMS = \
  testexternals_micromegas_io \
  testexternals_micromegas

testexternals_micromegas_io_SOURCES = testexternals.cc
testexternals_micromegas_io_LDADD = libmicromegas_io.la

testexternals_micromegas_SOURCES = testexternals.cc
testexternals_micromegas_LDADD = libmicromegas.la

endif

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

clean-local:
	rm -f *Dict* $(BUILT_SOURCES) *.pcm
