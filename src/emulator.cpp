#include <iostream>

#include "Parser.h"
#include "RawOperation.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << argc;
    Parser p;
    RawOperation *x = 0;
    
    if ((x = p.convertLine(argv[1])))
    {
        x->show();
    }

    return 0;
}
