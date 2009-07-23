/**
  * life.h
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

#ifndef LIFE_H
#define LIFE_H

#include <qobject.h>
#include <critter_type.h>

class Life : public QObject
{
    Q_OBJECT
public:
    Life(int x, int y);
    ~Life();
    void nextGeneration();			 // Replaces contents of field with next generation
    int getCell(int x, int y);			 // Examines a given cell, returns the index to critterType[]
    CritterType& getCritterType( int n ); 	 // Used so mainWindow can read / manipulate contents of a CritterType
    CritterType& getCritterType( int x, int y ); // Shortcut similar to getCritterType( getCell( x, y ) )
    void populateCell( int x, int y, int critter );
    void unpopulateCell( int x, int y );
private:
    int* cell;			// Array of indexes to critterType[]
    int** influence;		// Arrays for tracking influence of each CritterType
    CritterType** critterType;	// Array of rule sets
    int width;			// Width of array
    int height;			// Height of array
};

#endif
