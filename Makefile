#############################################################################
# Makefile for building: MultiLife
# Generated by qmake (1.07a) (Qt 3.3.8b) on: Mon Jul  6 16:42:26 2009
# Project:  MultiLife.pro
# Template: app
# Command: $(QMAKE) -o Makefile MultiLife.pro
#############################################################################

####### Compiler, tools and options

CC       = gcc
CXX      = g++
LEX      = flex
YACC     = yacc
CFLAGS   = -pipe -g -Wall -W -O2 -D_REENTRANT  -DQT_NO_DEBUG -DQT_THREAD_SUPPORT -DQT_SHARED -DQT_TABLET_SUPPORT
CXXFLAGS = -pipe -g -Wall -W -O2 -D_REENTRANT  -DQT_NO_DEBUG -DQT_THREAD_SUPPORT -DQT_SHARED -DQT_TABLET_SUPPORT
LEXFLAGS = 
YACCFLAGS= -d
INCPATH  = -I/usr/share/qt3/mkspecs/default -I. -I/usr/include/qt3 -I.ui/ -I. -I.moc/
LINK     = g++
LFLAGS   = 
LIBS     = $(SUBLIBS) -L/usr/share/qt3/lib -L/usr/X11R6/lib -lqt-mt -lXext -lX11 -lm -lpthread
AR       = ar cqs
RANLIB   = 
MOC      = /usr/share/qt3/bin/moc
UIC      = /usr/share/qt3/bin/uic
QMAKE    = qmake
TAR      = tar -cf
GZIP     = gzip -9f
COPY     = cp -f
COPY_FILE= $(COPY)
COPY_DIR = $(COPY) -r
INSTALL_FILE= $(COPY_FILE)
INSTALL_DIR = $(COPY_DIR)
DEL_FILE = rm -f
SYMLINK  = ln -sf
DEL_DIR  = rmdir
MOVE     = mv -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p

####### Output directory

OBJECTS_DIR = .obj/

####### Files

HEADERS = paintableframe.h
SOURCES = main.cpp \
		paintableframe.cpp
OBJECTS = .obj/main.o \
		.obj/paintableframe.o \
		.obj/formmain.o \
		.obj/qmake_image_collection.o
FORMS = formmain.ui
UICDECLS = .ui/formmain.h
UICIMPLS = .ui/formmain.cpp
SRCMOC   = .moc/moc_paintableframe.cpp \
		.moc/moc_formmain.cpp
OBJMOC = .obj/moc_paintableframe.o \
		.obj/moc_formmain.o
DIST	   = MultiLife.pro
QMAKE_TARGET = MultiLife
DESTDIR  = 
TARGET   = MultiLife

first: all
####### Implicit rules

.SUFFIXES: .c .o .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(UICDECLS) $(OBJECTS) $(OBJMOC)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJMOC) $(OBJCOMP) $(LIBS)

mocables: $(SRCMOC)
uicables: $(UICDECLS) $(UICIMPLS)

$(MOC): 
	( cd $(QTDIR)/src/moc && $(MAKE) )

Makefile: MultiLife.pro  /usr/share/qt3/mkspecs/default/qmake.conf /usr/share/qt3/lib/libqt-mt.prl
	$(QMAKE) -o Makefile MultiLife.pro
qmake: 
	@$(QMAKE) -o Makefile MultiLife.pro

dist: 
	@mkdir -p .obj/MultiLife && $(COPY_FILE) --parents $(SOURCES) $(HEADERS) $(FORMS) $(DIST) .obj/MultiLife/ && $(COPY_FILE) --parents images/filenew images/fileopen images/filesave images/print images/undo images/redo images/editcut images/editcopy images/editpaste images/searchfind .obj/MultiLife/ && $(COPY_FILE) --parents formmain.ui.h .obj/MultiLife/ && ( cd `dirname .obj/MultiLife` && $(TAR) MultiLife.tar MultiLife && $(GZIP) MultiLife.tar ) && $(MOVE) `dirname .obj/MultiLife`/MultiLife.tar.gz . && $(DEL_FILE) -r .obj/MultiLife

mocclean:
	-$(DEL_FILE) $(OBJMOC)
	-$(DEL_FILE) $(SRCMOC)

uiclean:
	-$(DEL_FILE) $(UICIMPLS) $(UICDECLS)

yaccclean:
lexclean:
clean: mocclean uiclean
	-$(DEL_FILE) $(OBJECTS)
		-$(DEL_FILE) .ui/qmake_image_collection.cpp
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) $(TARGET)


FORCE:

####### Compile

.obj/main.o: main.cpp .ui/formmain.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/main.o main.cpp

.obj/paintableframe.o: paintableframe.cpp paintableframe.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/paintableframe.o paintableframe.cpp

.ui/formmain.h: formmain.ui paintableframe.h
	$(UIC) formmain.ui -o .ui/formmain.h

.ui/formmain.cpp: .ui/formmain.h formmain.ui formmain.ui.h paintableframe.h
	$(UIC) formmain.ui -i formmain.h -o .ui/formmain.cpp

.obj/formmain.o: .ui/formmain.cpp formmain.ui.h \
		.ui/formmain.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/formmain.o .ui/formmain.cpp

.obj/moc_paintableframe.o: .moc/moc_paintableframe.cpp  paintableframe.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_paintableframe.o .moc/moc_paintableframe.cpp

.obj/moc_formmain.o: .moc/moc_formmain.cpp  .ui/formmain.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_formmain.o .moc/moc_formmain.cpp

.moc/moc_paintableframe.cpp: $(MOC) paintableframe.h
	$(MOC) paintableframe.h -o .moc/moc_paintableframe.cpp

.moc/moc_formmain.cpp: $(MOC) .ui/formmain.h
	$(MOC) .ui/formmain.h -o .moc/moc_formmain.cpp

.obj/qmake_image_collection.o: .ui/qmake_image_collection.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/qmake_image_collection.o .ui/qmake_image_collection.cpp

.ui/qmake_image_collection.cpp: images/filenew \
		images/fileopen \
		images/filesave \
		images/print \
		images/undo \
		images/redo \
		images/editcut \
		images/editcopy \
		images/editpaste \
		images/searchfind
	$(UIC)  -embed MultiLife images/filenew images/fileopen images/filesave images/print images/undo images/redo images/editcut images/editcopy images/editpaste images/searchfind -o .ui/qmake_image_collection.cpp

####### Install

install:  

uninstall:  

