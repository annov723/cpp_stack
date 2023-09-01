#include "stack2.cpp"

using namespace std;

int main( void ){

    try{
        Stack stack;
        stack.push( 1 );
        cout << stack.pop() << endl;
    }
    catch( stack_bad_alloc &sba ){
        cout << "Allocation problem occured." << endl;
    }
    catch( stack_size_error &sse ){
        cout << "Stack of that size cannot exist." << endl;
    }
    catch( stack_overflow &sov ){
        cout << "Stack is too samll for another push." << endl;
    }
    catch( stack_empty &se ){
        cout << "Stack is empty." << endl;
    }
    catch( ... ){
        cout << "Something is wrong..." << endl;
    }

    return 0;
}
