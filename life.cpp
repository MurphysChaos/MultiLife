/**
  * life.cpp
  * Object to handle the MultiLife logic.
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

#include <life.h>

Life::Life(int x, int y)
{
    int i, j;
    width = x;
    height = y;
    
    /** One-dimensional array is necessary because of limitations in C++.
      A cell at coordinates (x,y) can be referenced with field[ x + y*width ]; where
      width is a private field in the Life object. */
    field = new int[width*height]; 
    
    for (j=0;j<height;j++)
	for (i=0;i<width;i++)
	    field[ i + j*width ] = -1;
    
    critterType = new CritterType[8];
}

Life::~Life()
{
    if (field != NULL) {
	delete [] field;
	field = NULL;
    }
}

int Life::getCell( int x, int y ) 
{
    return field[ x + y * width ];
}

// returns CritterType in critterType[] at index n
CritterType& Life::getCritterType( int n )
{
    return critterType[n];
}

// returns CritterType at cell (x,y)
CritterType& Life::getCritterType( int x, int y )
{
    return critterType[field[x * y + width]];
}

void Life::populateCell( int x, int y, int critter )
{
    // Note -- critter should be >=0 and <=7, and only called by mainWindow. Value of critter is
    // dependent upon selected button in colorGroupBox.
    field[ x + y * width ] = critter;
}

void Life::unpopulateCell( int x, int y )
{
    field[ x + y * width ] = -1;
}
