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

#include <cstdlib>
#include <iostream>
#include <critter_type.h>

class Life 
{
public:
    Life(int x, int y);
    ~Life();
    // Replace contents of field with next generation
    void nextGeneration();
    // Examines a given cell, returns the index to critterType[]
    int getCell(int x, int y);
    // Used so mainWindow can read / manipulate contents of a CritterType
    CritterType& getCritterType( int n );
    // Shortcut similar to getCritterType( getCell( x, y ) )
    CritterType& getCritterType( int x, int y );
    void populateCell( int x, int y, int critter );
    void unpopulateCell( int x, int y );
    int getWidth();
    int getHeight();
    int getAge() const { return age;}
    void setAge(int x);
    void clear();
private:
    int* cell;			// Array of indexes to critterType[]
    int** influence;		// Arrays for tracking influence of each CritterType
    CritterType** critterType;	// Array of rule sets
    int width;			// Width of array
    int height;			// Height of array
    int age;
    enum { EMPTY_CELL = -1 };
};

#endif
