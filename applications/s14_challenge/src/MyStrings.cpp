#include <iostream>
#include <cstring>
#include "MyStrings.h"

// No-args constructor
MyString::MyString() 
    : str{nullptr} {
}

// Overloaded constructor
MyString::MyString(const char *sin) : str{nullptr} {
    str = new char[std::strlen(sin) + 1];
    std::strcpy(str, sin);
}

// Copy constructor

// Move constructor

// Destructor
MyString::~MyString() {
    delete [] str;
}

// Copy assigment

// Move assigment

// Display method

// Getters
const char *MyString::get_str() const{
    return this->str;
}