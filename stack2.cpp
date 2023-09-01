#include "stack2.h"

stack_size_error::stack_size_error( const std::string &msg ) : std::length_error( msg ){};

stack_bad_alloc::stack_bad_alloc( const std::string &msg ) : std::bad_alloc(){};

stack_overflow::stack_overflow( const std::string &msg ) : std::logic_error( msg ){};

stack_empty::stack_empty( const std::string &msg ) : std::logic_error( msg ){};

Stack::Stack( int size ){
    if( size <= 0 ) throw stack_size_error( "stack size must be >= 0" );
    try{
        stackstore = new int[size];
    }
    catch( std::bad_alloc &ba ){
        throw stack_bad_alloc( "stack allocation error" );
    }
    stacksize = size;
    SP = 0;
}

Stack::~Stack(){
    delete [] stackstore;
}

void Stack::push( int value ){
    if( SP == stacksize ) throw stack_overflow( "stack size exceeded" );
    stackstore[SP++] = value;
}

int Stack::pop(){
    if( SP == 0 ) throw stack_empty( "stack is empty" );
    return stackstore[--SP];
}