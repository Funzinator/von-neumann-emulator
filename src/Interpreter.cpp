#include "Interpreter.h"

Interpreter::Interpreter(QMap<unsigned int, Operation *> ops, Configuration *config)
{
    this->config = config;
    this->ops = ops;
}

bool Interpreter::next()
{
    unsigned int PC = this->config->getPC();

    if (this->ops[PC])
    {
        this->ops[PC]->run(this->config);

        return true;
    }

    return false;
}

Configuration *Interpreter::getConfiguration()
{
    return this->config;
}

QString Interpreter::getNextOperation(bool full)
{
    unsigned int PC = this->config->getPC();
    
    if (this->ops[PC])
    {
        return this->ops[PC]->getOperationName(full);
    }
    else
    {
        return "";
    }
}
