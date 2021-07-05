#pragma once 

#include "entity.h"

void print_WIDTH(int16_t input)
{
    std::cout << "WIDTH input = " << input << std::endl;
}

void printEntity(const Entity& entity)
{
    // This is how you pass a class object into a function or another class. 
    LOG("Entity: ");
    LOG(entity.getX());
    LOG(entity.getY());
}