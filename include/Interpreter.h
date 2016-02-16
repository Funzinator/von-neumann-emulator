#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include "Operation.h"

class Interpreter
{
private:
    Configuration *config;
    QMap<unsigned int, Operation *> ops;
    
public:
    Interpreter(QMap<unsigned int, Operation *>, Configuration*);
    bool next();
    Configuration *getConfiguration();
    QString getNextOperation(bool);
};

#endif /*INTERPRETER_H_*/
