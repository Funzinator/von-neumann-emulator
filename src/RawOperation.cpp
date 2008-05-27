#include "RawOperation.h"

void RawOperation::show()
{
    std::cout << "Line Number: " << this->LineNumber << std::endl;
    std::cout << "Operator   : " << this->Operator.toStdString() << std::endl;
    std::cout << "indirect   : " << (this->indirect ? "true" : "false") << std::endl;
    std::cout << "Parameter 1: " << this->Param1.toStdString() << std::endl;
    std::cout << "Parameter 2: " << this->Param2.toStdString() << std::endl;
    std::cout << "Comment    : " << this->Comment.toStdString() << std::endl;
}
