// This file is the implementation of inheritance
// Since header file (.h) doesn't get compiled, we need .cpp for this to work
// The good thing with splitting this out from main file is that you can modularly compile codes.
// Say, we make a few changes in the main. We won't need to recompile this entity.cpp
// This reduces the compile time dramatically.

#include "entity.h"

int Entity::a = 2;  // declare static variable
                    // NOTE :: Make sure this static `a` is not defined multiple times.

Entity::Entity(int x, int y)
{
    this -> x = x;  // remember, this is an operation to memory address.
                    // TODO:: How's this different from *variable?
    this -> y = y;
}

// we need to specify that this getX is in the Entity's Namespace instead of Global
int Entity::getX() const
{
    return x;  // this is the x within Entity
               // Usually, we will use values from header file instead of a reference like this.
}

int Entity::getY() const
{
    return y;  // this is the y within Entity
}