#include "ADI.h"

ADI::ADI(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
    /*nichts zu tun*/
}

void ADI::run(Configuration *c)
{	
	// switch AC-Storage-Typ
	// falls Binary, speichere AC+IR-Inhalt als Binary im IR
	//  .... Int .............................. Integer ....
	//  .... Float .....
    switch(c->getAC()->getType())
    {
	case StorageCell::Binary:
	    c->getIndexRegister(this->Param1->getInt())->setBinary(\
		    c->getAC()->getBinary() + \
		    c->getIndexRegister(this->Param1->getInt())->getBinary()\
		    ); 
	    break;
	case StorageCell::Integer:
	    c->getIndexRegister(this->Param1->getInt())->setInt(\
		    c->getAC()->getInt() + \
		    c->getIndexRegister(this->Param1->getInt())->getInt()\
		    ); 
	    break;
	case StorageCell::Float:
	    c->getIndexRegister(this->Param1->getInt())->setFloat(\
		    c->getAC()->getFloat() + \
		    c->getIndexRegister(this->Param1->getInt())->getFloat()\
		    ); 
	    break;
    }	
}
