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
	cell[i] = -1;
    
    critterType = new CritterType *[8];
    influence = new int *[8];
    for (i=0;i<8;i++)
    {
	this->critterType[i] = new CritterType();
	influence[i] = new int[width*height];
	for (j=0;j<(width*height);j++)
	{
	    influence[i][j] = 0;
	}
    }
    
    // Set first critterType to Conway-basic type.
    delete critterType[0];
    QColor rootColor = QColor(0,0,0);
    critterType[0] = new CritterType( rootColor, false, false, 2, 3, 3, 3 );
    critterType[0]->setObserveCells( 0x00, 0x00, 0x1C, 0x14, 0x1C, 0x00, 0x00 );
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
        cell[ x+y*width ] = -1;
    }
}

void Life::nextGeneration()
{
    // ctIndex := index of critterType; svInfl := influence for survival
    int i, j, x, y, index, ctIndex, svInfl;	
    int offX, offY, lookX, lookY;
    
    int* nextCell = new int[height*width];
    int** nextInfluence = new int *[8];
    
    // Duplicate Influence
    for (i=0;i<8;i++)
    {
	nextInfluence[i] = new int[width*height];
	for (j=0;j<(width*height);j++)
	{   
            nextInfluence[i][j] = influence[i][j];
	}
    }
    
    // Primary loop
    for (y=0;y<height;y++)
    {
	for (x=0;x<width;x++)
	{
	    index = x + y * width;
            // Survive Phase
            if (cell[index] != -1)
            {
                // Get survival-based influence
                if (critterType[cell[index]]->getObserveOthers())
                {
                    svInfl = 0;
                    for (ctIndex=0;ctIndex<8;ctIndex++)
                    {
                        svInfl += influence[ctIndex][index];
                    }
                } else {
                    svInfl = influence[cell[index]][index];
                }
                // Write next generation
                ctIndex = cell[index];
                if (influence[ctIndex][index] >= 
                    critterType[ctIndex]->getMinSurvive() &&
                    influence[ctIndex][index] <= 
                    critterType[ctIndex]->getMaxSurvive())
                {
                    nextCell[index] = ctIndex;
                } else {
                    nextCell[index] = -1;
                    
                    // Update influence
                    for (offY=-3;offY<=3;offY++)
                    {
                        for (offX=-3;offX<=3;offX++)
                        {
                            // Avoid accessing invalid array elements
                            lookX = x + offX;
                            lookY = y + offY;
                            if (lookX >= 0 && lookX < width && lookY >= 0 && lookY < height) 
                            {
                                nextInfluence[ctIndex][ lookX + lookY * width ] -= 
                                        critterType[ctIndex]->getObserveCell( offX, offY ) ?
                                        1 : 0;
                            }
                        }
                    }
                }
            }
	    // Create Phase -- only if empty or pushOut allowed
	    if (cell[index] == -1 || critterType[cell[index]]->getPushOut())
	    {
                nextCell[index] = cell[index];
for (ctIndex=0;ctIndex<8;ctIndex++)
                {
                    if (influence[ctIndex][index] >= 
                        critterType[ctIndex]->getMinCreate() && 
                        influence[ctIndex][index] <= 
                        critterType[ctIndex]->getMaxCreate())
                    {
                        nextCell[index] = ctIndex;
                        
                        // Update influence
                        for (offY=-3;offY<=3;offY++)
                        {
                            for (offX=-3;offX<=3;offX++)
                            {
                                // Avoid accessing invalid array elements
                                lookX = x + offX;
                                lookY = y + offY;
                                if (lookX >= 0 && lookX < width && lookY >= 0 && lookY < height) 
                                {
                                    if (critterType[ctIndex]->getObserveCell( offX, offY ))
                                    {
                                        nextInfluence[ctIndex][ lookX + lookY * width ] += 1;
                                    }
                                }
                            }
                        }
                        
                        break;
                    }
                }
	    }
	}
    }
    
    delete [] cell;
    delete [] influence;
    cell = nextCell;
    influence = nextInfluence;
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
     cell[i]=-1;
    }
}
