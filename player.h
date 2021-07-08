#pragma once
#include "entity.h"

// Here, we want to extend an entity
class Player : public Entity
{
    public:
        Player();
        int getX_vir() const;  // say, we have this function to override the same one in Entity
                               // Go to player.cpp implement where we will be overriding the function
};

// TODO :: Might have to recompile all files together because I didn't see .obj files in the folder
//         That is most likely why I keep getting underfined reference to `Player::Player()'
//         g++ -o out -I ./folder *.cpp folder/*.cpp
