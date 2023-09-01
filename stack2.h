#ifndef __STACK2__
#define __STACK2__

#include <iostream>
#include <exception>
#include <stdexcept>

class stack_size_error : public std::length_error{
public:
    explicit stack_size_error( const std::string &msg );
};

class stack_bad_alloc : public std::bad_alloc{
public:
    explicit stack_bad_alloc( const std::string &msg );
};

class stack_overflow : public std::logic_error{
public:
    explicit stack_overflow( const std::string &msg );
};

class stack_empty : public std::logic_error{
public:
    explicit stack_empty( const std::string &msg );
};

class Stack{
private:
    int *stackstore;
    int stacksize;
    int SP;
public:
    Stack( int size = 100 );
    ~Stack();
    void push( int value );
    int pop(); 
};

#endif