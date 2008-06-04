#include "SBI.h"

SBI::SBI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void SBI::run(Configuration *c)
{	
	// switch AC-Storage-Typ
	// falls Binary, speichere IR_Inhalt-AC als Binary im IR
	//  .... Int .............................. Integer ....
	//  .... Float .....
    switch(c->getAC()->getType())
    {
	case StorageCell::Binary:
	    c->getIndexRegister(this->Param1->getInt())->setBinary(\
		    c->getIndexRegister(this->Param1->getInt())->getBinary() - c->getAC()->getBinary()); 
	    break;
	case StorageCell::Integer:
	    c->getIndexRegister(this->Param1->getInt())->setInt(\
		    c->getIndexRegister(this->Param1->getInt())->getInt() - c->getAC()->getInt()); 
	    break;
	case StorageCell::Float:
	    c->getIndexRegister(this->Param1->getInt())->setFloat(\
		    c->getIndexRegister(this->Param1->getInt())->getFloat() - c->getAC()->getFloat()); 
	    break;
    }	
}
