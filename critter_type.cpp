/**
  * critter_type.cpp
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

#include <critter_type.h>

CritterType::CritterType()
{
    observe = new char[7];
    for (int i=0;i++;i<7)
	observe[i] = 0;
}

CritterType::~CritterType()
{
    delete [] observe;
}

void setColor( QColor& newColor )
{
    this.color = newColor;
}

// Usage: setObserveCell( [-3,3], [-3,3], [true,false] );
// x := horizontal offset from center (-3 to 3)
// y := vertical offset from center (-3 to 3)
// value := true to observe, false to ignore
// Note: offset 0,0 is not used by the simulation
void setObserveCell( int x, int y, bool value )
{
    char change = 2 ^ (x + 3);
    char remain = 0xff - change;
    this.observe[y] = (observe[y] & remain) + (change & ( value ? 0xff : 0x00 ) );
}

void setObserveOthers( bool value )
{
    this.observeOthers = value;
}

void setPushOut( bool value )
{
    this.pushOut = value;
}

void setMinSurvive( int value )
{
    this.minSurvive = value;
}

void setMaxSurvive( int value )
{
    this.maxSurvive = value;
}

void setMinCreate( int value )
{
    this.minCreate = value;
}

void setMaxCreate( int value )
{
    this.maxCreate = value;
}
