/**
  * critter_type.h
  * Class to represent the behavior of a particular type of critter.
  */

/**
  * Multilife
  * A Multi-species variant of Conway's Game of Life
  * 
  * Copyright (C) 2009 Joel Murphy, Ba Nguyen
  * All rights reserved
  * Licensed under the GNU Public License, v2. Full text of license can be found
  * in gpl-2.0.txt.
  */

#ifndef CRITTER_TYPE_H
#define CRITTER_TYPE_H

#include <qcolor.h>
#include <iostream>
#include <cmath>

class CritterType
{
public:
    CritterType();
    CritterType( QColor& initColor, bool initObserveOthers, bool initPushOut,
		 int initMinSurvive, int initMaxSurvive, 
		 int initMinCreate, int initMaxCreate );
    ~CritterType();
    void setColor( QColor& newcolor );
    void setObserveCell( int x, int y, bool value );
    void setObserveCells( char r0, char r1, char r2, char r3, 
                          char r4, char r5, char r6 );
    void setObserveOthers( bool value );
    void setPushOut( bool value );
    void setMinSurvive( int value );
    void setMaxSurvive( int value );
    void setMinCreate( int value );
    void setMaxCreate( int value );
    void deleteCritterType();
    QColor& getColor();
    bool getObserveCell( int x, int y );
    bool getObserveOthers();
    bool getPushOut();
    int getMinSurvive();
    int getMaxSurvive();
    int getMinCreate();
    int getMaxCreate();
    bool isValid();
private:
    bool valid;
    QColor color;	// Color to paint on paintableframe.
    char *observe;	// 7x7 bit array for examining adjacent cells.
    bool observeOthers;	// TRUE := Use non-similar life for survival 
			// check, FALSE := use only this type
    bool pushOut;	// TRUE := Create into populated cells, 
			// FALSE := do not create into populated cells
    int minSurvive;
    int maxSurvive;
    int minCreate;
    int maxCreate;
};

#endif
