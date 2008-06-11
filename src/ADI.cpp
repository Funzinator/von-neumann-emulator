#include "ADI.h"

ADI::ADI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void ADI::run(Configuration *c)
{
    StorageCell *p1 = BinaryToUnary(c); //in p1 ist jetzt der "echte" Wert
    // switch AC-Storage-Typ
    // falls Binary, speichere AC+IR-Inhalt als Binary im IR
    //  .... Int .............................. Integer ....
    //  .... Float .....
    switch(c->getAC()->getType())
    {
	case StorageCell::Binary:
	    c->getIndexRegister(p1->getInt())->setBinary(\
		    c->getAC()->getBinary() + \
		    c->getIndexRegister(p1->getInt())->getBinary()\
		    ); 
	    break;
	case StorageCell::Integer:
	    c->getIndexRegister(p1->getInt())->setInt(\
		    c->getAC()->getInt() + \
		    c->getIndexRegister(p1->getInt())->getInt()\
		    ); 
	    break;
	case StorageCell::Float:
	    c->getIndexRegister(p1->getInt())->setFloat(\
		    c->getAC()->getFloat() + \
		    c->getIndexRegister(p1->getInt())->getFloat()\
		    ); 
	    break;
    }
    c->setPC(c->getPC() + 1);
    delete p1;	
}
