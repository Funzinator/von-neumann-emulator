#include "ADI.h"

ADI::ADI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void ADI::run(Configuration *c)
{
    //Um einheitlich zu bleiben, hier auch p1 statt Param1 verwenden
    StorageCell *p1 = new StorageCell;
    p1->setInt(this->Param1->getInt());	
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
