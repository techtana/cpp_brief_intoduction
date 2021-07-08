// Learning from The Cherno: https://www.youtube.com/watch?v=FBs7UoPy-sc

#include <iostream>     

#define WIDTH 800
#define DEBUG 1

#if DEBUG  // This way, we can turn on/off very easily.
    #define LOG(x) std::cout << "Debug :: " << x << std::endl // This is called macro.
#else
    #define LOG(x) 
#endif

#include "entity.h"
// #include "entity.h"  // This will fail because we already included entity.h earlier
                     // However, if "HEADER GUARD" is implemented in the header file
                     // that will prevent the class to be defined twice and cause issues.
                     // This can happen when the headers include several duplicate files.
#include "player.h"
#include "header.h"  // Header is just copy and paste code chunks, this statement itself doesn't get compiled.


int add(int a, int b)
{
    LOG("Addition function");  
    return a + b;
}

void increment_without_reference(int value)
{
    // Without the reference, the original variable/memory will not be updated
    // instead, you will just be making a copy i.e. temporary variable
    value++;
}

void increment_with_reference(int *value)
{
    // on the other hand, this will take the memory of original variable and do increment
    // but then, we have to use an ampersand, then dereference it in this function. this is messy
    (*value)++;
}

void increment_with_reference_ampersand(int &value)
{
    // Here, you're passing in the address directly
    value++;
}

int add_with_reference(int &a, int &b)
{
    // Going back to add function, we can then optimize the input by not copying the values
    return a + b;
    // However, this leaves your memory vulnerable because even if we did not intend to make 
    // any changes to the original a and b variables, this code does not promise us so.
    // Instead, one might make a copy of a variable instead i.e. thus, no `&` reference.
    //          or using `const` as will be shown below. 
}  

int add_with_constant(const int &a, const int &b)
{
    // int& letsdothis = const_cast<int&>(a); // here, we attempted to forcefully case `a` into `letsdothis` variable 
    // letsdothis++;  // and try to make the changes. This WILL change the value! DON'T DO THIS!!
    return a + b;
}  

int _types_of_constant(const int* a, int* const b)
{
    // Adding one more const in front of the variable will also mean the address 
    // will also not be permitted to change even in this scope as well.
    // i.e. In function above, the global `a` variable will not change, but can still reassign the pointer.
    //      In this function, the global `a` variable will not change, and will remain as a const within this scope too.
    int d = 0; // Say, we give a new memory address.
    
    // *a = 2;  // **ERROR: the memory of pointer for `a` is NOT allowed to be changed.
    a = &d;  // But, the value of the pointer (in this func context) is allowed to be changed.

    *b = 3;  // The memory of pointer for `a` is allowed to be changed.
    // b = &d;  // But, the value of the pointer (in this func context) is NOT allowed to be changed.
    
    return d;
}  

struct Vector3f
{
    // This is basically the same as class, but everything is public.
    // You should only use it for data
    // Like the name suggests, this is used to defined a complex data structure
    float x, y, z;
};

void println(const char* input)
{
    using namespace std;
    cout << input << endl;
}

// int Entity::a = 3;  // declare static variable
//                     // NOTE :: Make sure this static `a` is not defined multiple times.
//                     // There is another definition entity.cpp

int main(int argc, char *args[])
{
    LOG("DEBUGING is on");
    LOG(add(5, 8)); // here you will see double "DEBUG :: DEBUG ::"  because there is a LOG() inside of add
    print_WIDTH(WIDTH);
    std::cout << "sizeof long long =  " << sizeof(long long) << std::endl;


    //* Pointer and Reference *//
    int a = 5;
    int* p = &a; // here, we reference (with *) a pointer 'a' (with &a) which is basically a memory address of a
    LOG("p is just the reference, and will return address of a");
    LOG(p);  // this will show the memory address and not the actual value of a
    LOG("dereference instead and we will get");
    LOG(*p); // here, we instead dereference 'p' pointer to get the data from 'a'
    int b = *p;  // b will have the value from a, but will no longer have the same address. If we change a, b won't change.
    increment_with_reference(&a);
    LOG("increment to a");
    LOG(a);
    increment_with_reference_ampersand(a);
    LOG("increment to a");
    LOG(a);
    LOG("so, what happens to b?");
    LOG(b);


    //* Constant *//
    const int c = 2;
    // c = 3; // This will show error because you cannot change the constant value.
    // This means there is one more trick to using reference in a function: look at `add_with_constant` above
    LOG("using constant?");
    LOG(add_with_constant(a,a));
    LOG(a);
    // Also, once you put reference into a variable, you cannot change that reference.
    // TODO:: ... Note of this later ...
    //


    //* Making an array *//
    int array[50];  // This is an array of size 50
    int array_a[5] = {2,3,4,5,6};
    int array_arbitrary[] = {1,2,3,4,5,6,7,8,9};
    int *array_heap = new int[5];
    delete[] array_heap;
    // IMPORTANT NOTE:: if we're using a pointer, there is no natural way to know 
    //                  the size of the actual array. The trick to find the size is 
    //                  to count the array. The problem with not knowing the size of 
    //                  the entire array is that the system doesn't know where the data ends.
    // For example, this shouldn't work, but it does.
    int *some_long_array = new int[5];
    LOG("This is 6th index of the some_long_array");
    LOG(some_long_array[6]);  // it will return some strange number that you didn't intend


    //* Working with Class *//
    Entity e(5, 8);  // making a stack for an object i.e. declare an object
    LOG("We have now created an Entity with x and y");
    LOG(e.getX());
    LOG(e.getY());
    // Here, we make it as a heap instead
    Entity* player = new Entity(5, 8);  
    LOG("We have now created an Entity as a heap");
    // With a stack, the memory will be deleted once it's done
    // But for heap, the memory will not be deleted until you deliberately deleted it
    // So, you can see that the heap can cause what is called memory-leak issue
    // Making an object as a stack, the system will take care of memory for you
    player -> getX();  // this -> operator is used when working with pointer objects / variables
    delete player;  // when making `new` object, ALWAYS comes with delete
    
    // Here is a function which takes a class as an argument
    printEntity(Entity(1,2));

    // To declare static variable in Entity, we declare this in the global scope i.e. outside of main(){}
    // int Entity::a = 2;  
    // To use the static variable in Entity class
    LOG("Entity::a = ");
    LOG(Entity::a);


    //* Namespace *//
    // ```using namespace std;``` this is the same as ```from package import *``` in python
    // Especially, don't do this in global scope. Instead, it has uses inside a function.
    // For example;
    // void println(char* input)
    // {
    //     using namespace std;
    //     cout << input << endl;
    // }
    // ^ This is copied to outside of main() scope
    println("Println Test");


    // //* Inheritance *//
    
    Player plyr;
    printEntity(plyr);


    system("PAUSE");
    return 0;
}

