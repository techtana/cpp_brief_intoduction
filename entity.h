// To prevent people from including this class twice, use what is called a "HEADER GUARD".
// #ifndef CLASS_ENTITY // if this class is not defined before
// #define CLASS_ENTITY 

#pragma once // This is basically the same as doing the check above. Much cleaner!

class Entity
{
    public:
        static int a;  // to declare this, you have to is ` int Entity::a = 2; `

    protected:
        int x, y;
    
    public:
        Entity(int x, int y)
        {
            this -> x = x;  // this -> operator is used when working with pointer objects / variables
            this -> y = y;
        }

        int getX() const { return x; }
        int getY() const { return y; }
        // int getY() { y++; return y; } // This is what we want to avoid: messing with original memory.

        // This declare an object which will allow us to modify later in player.cpp file
        // virtual int getX_vir() const;  // vitual will allow the function to be overriden.
        // virtual int getY_vir() const;

    // private:

};
// #endif