#include "IndexregisterOperation.h"

IndexregisterOperation::IndexregisterOperation(RawOperation *rawOp) : UnaryOperation(rawOp)
{
	this->Param1->setInt(rawOp->Param1.toInt());
	/* Param1 ist die Nummer eines IR, deshalb Integer */
}
