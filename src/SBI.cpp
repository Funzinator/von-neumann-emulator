#include "SBI.h"

SBI::SBI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void SBI::run(Configuration *c)
{	
    //Um einheitlich zu bleiben, hier auch p1 statt Param1 verwenden
    StorageCell *p1 = new StorageCell;
    p1->setInt(this->Param1->getInt());	

    // switch AC-Storage-Typ
    // falls Binary, speichere IR_Inhalt-AC als Binary im IR
    //  .... Int .............................. Integer ....
    //  .... Float .....
    switch(c->getAC()->getType())
    {
	case StorageCell::Binary:
	    c->getIndexRegister(p1->getInt())->setBinary(\
		    c->getIndexRegister(p1->getInt())->getBinary() - c->getAC()->getBinary()); 
	    break;
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
