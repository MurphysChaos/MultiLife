TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_on release

HEADERS	+= paintableframe.h \
	life.h \
	critter.h

SOURCES	+= main.cpp \
	paintableframe.cpp \
	life.cpp \
	critter.cpp

FORMS	= mainwindow.ui

IMAGES	= images/PaintableFrame.png

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}



