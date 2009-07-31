TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_on release

HEADERS	+= paintableframe.h \
	life.h \
	critter_type.h \
	timeClass.h \
	bitmap.h

SOURCES	+= main.cpp \
	paintableframe.cpp \
	life.cpp \
	critter_type.cpp \
	timeFunct.cpp

FORMS	= mainwindow.ui

IMAGES	= images/PaintableFrame.png \
	images/penDude.png

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}



