#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <QMap>

#include "Operation.h"
#include "Configuration.h"

class Interpreter
{
private:
    Configuration *config;
    QMap<unsigned int, Operation *> ops; 
    
public:
    Interpreter(QMap<unsigned int, Operation *>, Configuration*);
    void next();
    Configuration *getConfiguration();
};

#endif /*INTERPRETER_H_*/
