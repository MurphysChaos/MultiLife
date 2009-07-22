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
    int i = 0, j = 0;
    width = x;
    height = y;
    
    /** One-dimensional array is necessary because of limitations in C++.
      A cell at coordinates (x,y) can be referenced with field[ x + y*width ]; where
      width is a private field in the Life object. */
    field = new int[width*height];     
    for (i=0;i<(width*height);i++)
	field[ i + j*width ] = -1;
    
    critterType = new CritterType *[8];
    influence = new int *[8];
    for (i=0;i<8;i++)
    {
	critterType[i] = new CritterType();
	influence[i] = new int[width*height];
	for (j=0;j<(width*height);j++)
	{
	    (influence[i])[j] = 0;
	}
    }
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
    return *critterType[n];
}

// returns CritterType at cell (x,y)
CritterType& Life::getCritterType( int x, int y )
{
    return *critterType[field[x * y + width]];
}

void Life::populateCell( int x, int y, int index )
{
    int offX, offY, lookX, lookY;
    // Note -- critter should be >=0 and <=7, and only called by mainWindow. Value of critter is
    // dependent upon selected button in colorGroupBox.
    field[ x + y * width ] = index;
    
    // Manipulate influence data
    for (offY=-3;offY<=3;offY++)
    {
	for (offX=-3;offX<=3;offX++)
	{
	    // Avoid accessing invalid array elements
	    lookX = x + offX;
	    lookY = y + offY;
	    if (lookX >= 0 && lookX < width && lookY >= 0 && lookY < height) 
	    {
		influence[index][ lookX + lookY * width ] += 
			critterType[index]->getObserve( offX, offY ) ?
			1 : 0;
	    }
	}
    }
}

void Life::unpopulateCell( int x, int y )
{
    field[ x + y * width ] = -1;
}

void Life::nextGeneration()
{
    int x, y, ox, oy, index, count; // ox := X offset, oy := Y offset
    CritterType* centerCell = NULL;
    CritterType* compareType = NULL;
    int newField[ height * width ];
    
    for (y=0;y<height;y++)
    {
	for (x=0;x<width;x++)
	{
	    for (index=0;index<8;index++)
	    {
	    }
	}
    }
}
