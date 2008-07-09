#include "SBI.h"

SBI::SBI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void SBI::run(Configuration *c)
{	
    StorageCell *p1 = IndirectToDirect(c); //in p1 ist jetzt der "echte" Wert
    // switch AC-Storage-Typ
    // falls Binary, speichere IR_Inhalt-AC als Binary im IR
    //  .... Int .............................. Integer ....
    //  .... Float .....
    switch(c->getAC()->getType())
    {
	case StorageCell::Binary:

	case StorageCell::Integer:
	    c->getIndexRegister(p1->getInt())->setInt(\
		    c->getIndexRegister(p1->getInt())->getInt() - c->getAC()->getInt()); 
	    break;
	case StorageCell::Float:
	    c->getIndexRegister(p1->getInt())->setFloat(\
		    c->getIndexRegister(p1->getInt())->getFloat() - c->getAC()->getFloat()); 
	    break;
    }
    c->setPC(c->getPC() + 1);
    delete p1;
}
