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
    this->observe = new char[7];
    for (int i=0;i<7;i++)
    {
	this->observe[i] = 0x00;
    }
    this->color = QColor::QColor(0,0,0);
    this->observeOthers = false;
    this->pushOut = false;
    this->minSurvive = 2;
    this->maxSurvive = 3;
    this->minCreate = 3;
    this->maxCreate = 3;
    this->valid = true;
}

CritterType::CritterType( QColor& initColor, bool initObserveOthers, bool initPushOut,
		 int initMinSurvive, int initMaxSurvive, 
		 int initMinCreate, int initMaxCreate )
{
    this->observe = new char[7];
    for (int i=0;i<7;i++)
    {
	this->observe[i] = 0x00;
    }
    this->color = QColor::QColor(initColor);
    this->observeOthers = initObserveOthers;
    this->pushOut = initPushOut;
    this->minSurvive = initMinSurvive;
    this->maxSurvive = initMaxSurvive;
    this->minCreate = initMinCreate;
    this->maxCreate = initMaxCreate;
    this->valid = true;
}

CritterType::~CritterType()
{
    delete [] this->observe;
    this->observe = NULL;
}

void CritterType::setColor( QColor& newColor )
{
    this->color = QColor::QColor(newColor);
}

// Usage: setObserveCell( [-3,3], [-3,3], [true,false] );
// x := horizontal offset from center (-3 to 3)
// y := vertical offset from center (-3 to 3)
// value := true to observe, false to ignore
// Note: offset 0,0 is not used by the simulation
void CritterType::setObserveCell( int x, int y, bool value )
{
    int i;
    char change = (char) pow(2,x+3);
    char remain = 0xff - change;
    
    this->observe[y+3] = (observe[y+3] & remain) + (change & ( value ? 0xff : 0x00 ) );
}

void CritterType::setObserveCells( char r0, char r1, char r2, char r3, 
                                   char r4, char r5, char r6 )
{
    this->observe[0] = r0;
    this->observe[1] = r1;
    this->observe[2] = r2;
    this->observe[3] = r3;
    this->observe[4] = r4;
    this->observe[5] = r5;
    this->observe[6] = r6;
}

void CritterType::setObserveOthers( bool value )
{
    this->observeOthers = value;
}

void CritterType::setPushOut( bool value )
{
    this->pushOut = value;
}

void CritterType::setMinSurvive( int value )
{
    this->minSurvive = value;
}

void CritterType::setMaxSurvive( int value )
{
    this->maxSurvive = value;
}

void CritterType::setMinCreate( int value )
{
    this->minCreate = value;
}

void CritterType::setMaxCreate( int value )
{
    this->maxCreate = value;
}

void CritterType::deleteCritterType()
{
    this->valid = false;
    delete [] this->observe;
}

QColor& CritterType::getColor()
{
    return this->color;
}

bool CritterType::getObserveCell( int x, int y )
{
    char c = (this->observe[y + 3]);
    c = c & (char) pow(2,x+3);
    return c ? true : false;
}

bool CritterType::getObserveOthers()
{
    return this->observeOthers;
}

bool CritterType::getPushOut() 
{
    return this->pushOut; 
}

int CritterType::getMinSurvive()
{
    return this->minSurvive; 
}

int CritterType::getMaxSurvive() 
{ 
    return this->maxSurvive;
}

int CritterType::getMinCreate() 
{
    return this->minCreate; 
}

int CritterType::getMaxCreate() 
{
    return this->maxCreate; 
}

bool CritterType::isValid()
{
    return this->valid;
}
