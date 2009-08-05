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
    age = 0;
    
    /** One-dimensional array is necessary because of limitations in C++.
      * A cell at coordinates (x,y) can be referenced with cell[x+y*width];
      * where width is a private cell in the Life object. */
    cell = new int[width*height];
    for (i=0;i<(width*height);i++)
	cell[i] = EMPTY_CELL;
    
    critterType = new CritterType *[8];
    influence = new int *[8];
    
    // Set some default critterTypes.
    QColor rootColor;
    rootColor = QColor(0,0,192);
    critterType[0] = new CritterType( rootColor, true, true, 2, 3, 3, 3 );
    critterType[0]->setObserveCells( 0x00, 0x00, 0x1C, 0x14, 0x1C, 0x00, 0x00 );
    rootColor = QColor(0,192,0);
    critterType[1] = new CritterType( rootColor, true, true, 2, 3, 3, 3 );
    critterType[1]->setObserveCells( 0x00, 0x08, 0x08, 0x36, 0x08, 0x08, 0x00 );
    rootColor = QColor(192,0,0);
    critterType[2] = new CritterType( rootColor, true, true, 2, 3, 3, 3 );
    critterType[2]->setObserveCells( 0x00, 0x22, 0x14, 0x00, 0x14, 0x22, 0x00 );
    rootColor = QColor(64,128,192);
    critterType[3] = new CritterType( rootColor, false, false, 3, 4, 3, 4 );
    critterType[3]->setObserveCells( 0x00, 0x08, 0x1C, 0x36, 0x1C, 0x08, 0x00 );
    
    // Blank remaining critter types and create influence fields
    for (i=0;i<4;i++)
    {
        critterType[i+4] = new CritterType();
	influence[i] = new int[width*height];
	influence[i+4] = new int[width*height];
	for (j=0;j<(width*height);j++)
	{
	    influence[i][j] = 0;
	    influence[i+4][j] = 0;
	}
    }
}

Life::~Life()
{
    if (cell != NULL) {
	delete [] cell;
	cell = NULL;
    }
}

int Life::getCell( int x, int y ) 
{
    return cell[ x+y*width ];
}

// returns CritterType in critterType[] at index n
CritterType& Life::getCritterType( int n )
{
    return *critterType[n];
}

// returns CritterType at cell (x,y)
CritterType& Life::getCritterType( int x, int y )
{
    return *critterType[ cell[ x+y*width ] ];
}

void Life::populateCell( int x, int y, int index )
{
    int offX, offY, lookX, lookY;
    bool observeValue;
    // Note -- critter should be >=0 and <=7, and only called by mainWindow. Value of 
    // critter is dependent upon selected button in colorGroupBox.
    cell[ x+y*width ] = index;
    
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
                observeValue = critterType[index]->getObserveCell( offX, offY );
                if (observeValue)
                {
                    influence[index][ lookX + lookY * width ] += 1;
                }
	    }
	}
    }
}

void Life::unpopulateCell( int x, int y )
{
    int offX, offY, lookX, lookY;
    
    int index = cell[ x+y*width ];
 
    if (index >= 0)
    {
	for (offY=-3;offY<=3;offY++)
	{
	    for (offX=-3;offX<=3;offX++)
	    {
		// Avoid accessing invalid array elements
		lookX = x + offX;
		lookY = y + offY;
		if (lookX >= 0 && lookX < width && lookY >= 0 && lookY < height) 
		{
		    influence[index][ lookX + lookY * width ] -= 
                            critterType[index]->getObserveCell( offX, offY ) ?
			    1 : 0;
		}
	    }
	}
        cell[ x+y*width ] = EMPTY_CELL;
    }
}

void Life::nextGeneration()
{
    // ctIndex := index of critterType; tInfl := influence for survival
    int i, j, x, y, index, ctIndex, tInfl;	
    
    int* oldCell = cell;
    int** oldInfluence = influence;    
    
    // Create blank cell array
    cell = new int[height*width];
    for (i=0;i<(width*height);i++)
    {
        cell[i] = EMPTY_CELL;
    }
    
    // Create blank influence array
    influence = new int *[8];
    for (i=0;i<8;i++)
    {
	influence[i] = new int[width*height];
	for (j=0;j<(width*height);j++)
	{
            influence[i][j] = 0;
	}
    }
    
    // Primary loop
    for (y=0;y<height;y++)
    {
	for (x=0;x<width;x++)
	{
	    index = x + y * width;
            // Survive Phase
            if (oldCell[index] != EMPTY_CELL)
            {
                // Get survival-based influence
                if (critterType[oldCell[index]]->getObserveOthers())
                {
                    tInfl = 0;
                    for (ctIndex=0;ctIndex<8;ctIndex++)
                    {
                        tInfl += oldInfluence[ctIndex][index];
                    }
                } else {
                    tInfl = oldInfluence[oldCell[index]][index];
                }
                // Write next generation
                ctIndex = oldCell[index];
                if (tInfl >= critterType[ctIndex]->getMinSurvive() &&
                    tInfl <= critterType[ctIndex]->getMaxSurvive())
                {
                    populateCell(x, y, ctIndex);
                }
            }
	    // Create Phase
            if (oldCell[index] == EMPTY_CELL || critterType[oldCell[index]]->getPushOut())
            {
                for (ctIndex=0;ctIndex<8;ctIndex++)                    
                {
                    tInfl = oldInfluence[ctIndex][index];
                    if (tInfl >= critterType[ctIndex]->getMinCreate() && 
                        tInfl <= critterType[ctIndex]->getMaxCreate() &&
                        ctIndex != oldCell[index])
                    {
                        populateCell(x, y, ctIndex);
                        break;
                    }
                }
            }
        }
    }
    
    delete [] oldCell;
    delete [] oldInfluence;
}

int Life::getWidth()
{
    return this->width;
}

int Life::getHeight()
{
    return this->height;
}

void Life::setAge(int x){
  age = x;
}

void Life::clear(){
    int i,j,x,y=0;
    setAge(0);
    for (i=0;i<8;i++)	//delete nextInfluence
    {
	for (j=0;j<(width*height);j++)
	{   
                influence[i][j] = 0;
	}
    }
    //delete the cell
    for (i=0;i<( x+y*width );i++)
    {
     cell[i] = EMPTY_CELL;
    }
}

void Life::rebuildInfluence( int critter )
{
    int i, x, y, offX, offY, lookX, lookY;
    bool observeValue;
    
    // Clear influence
    for (i=0;i<(width*height);i++) 
    {
        influence[critter][i] = 0;
    }
    
    // Primary loop
    for (y=0;y<height;y++)
    {
        for (x=0;x<width;x++)
        {
            if (cell[x+y*width]==critter) {
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
                            observeValue = critterType[critter]->getObserveCell( offX, offY );
                            if (observeValue)
                            {
                                influence[critter][ lookX + lookY * width ] += 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
