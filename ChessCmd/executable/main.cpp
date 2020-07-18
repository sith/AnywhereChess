/*#include <ChessCmd.h>

int main(int argc, char **argv) {
    ChessCmd chessCmd(std::cin, std::cout, argc, argv);
    chessCmd.run();
    return 0;
}*/


#include <iostream>
using namespace std;

void testAllocated( int *p )
{
    cout << "Pointer is " << ( p ? "allocated" : "not allocated" ) << '\n';
}


void constructor( int * &p )           // simulated constructor
{
    p = new int;
}


void destructor( int * &p )            // simulated destructor
{
    delete p;
    p = nullptr;
}


int main()
{
    int *p = nullptr;
    testAllocated( p );

    constructor( p );
    testAllocated( p );

    destructor( p );
    testAllocated( p );
}
