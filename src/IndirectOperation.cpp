#include "IndirectOperation.h"

IndirectOperation::IndirectOperation(RawOperation *rawOp) : IndexregisterOperation(rawOp)
{
}

StorageCell* IndirectOperation::IndirectToDirect(Configuration *c)
{
    StorageCell *p1 = new StorageCell;
    if (this->indirect)
    {
    //Überführe "OP,I x" in "OP Inh(x)"
        p1->setInt(c->getData(this->Param1->getInt())->getInt());
    } else 
    {
        p1->setInt(this->Param1->getInt());
    }
    return p1;
}

StorageCell* IndirectOperation::setP1(Configuration *c)
{
    StorageCell *p1;
    // Ein Befehl ist NIE Indirect UND 2-parametrig (vorerst)
      // Dann funktioniert das hier:
    if (this->Param2)
    {
        p1=BinaryToUnary(c);
    } 
    else p1=IndirectToDirect(c); //behandelt auch !indirect (s.o.)

    //Irgendwas funzt hier nicht so ganz:
/*    //Falls wir Indirct und 2-param gleichzeitig zulassen:
    int oldParam1=this->Param1->getInt();
    if (this->Param2) this->Param1=BinaryToUnary(c);
        //zuerst BinaryToUnary, siehe Inf-I-Skript Kap.3, S.38
    if (this->indirect) p1=IndirectToDirect(c);
    else p1->setInt(this->Param1->getInt());
    this->Param1->setInt(oldParam1);
    delete &oldParam1;*/
    return p1;
}
