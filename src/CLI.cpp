#include "CLI.h"

CLI::CLI(QString filename)
{
    this->timerRun = new QTimer(this);
    connect(this->timerRun, SIGNAL(timeout()), this, SLOT(timerNextStep()));

    this->parser = new Parser;
    this->file = new QFile(filename);

    this->i = new Interpreter(this->parser->Parse(this->file), new Configuration(new CliInterface()));
    
    this->showConfiguration(this->i->getConfiguration());

    this->timerRun->start(100);
}

void CLI::resetConfiguration()
{
}

void CLI::showConfiguration(Configuration *config)
{
    QString AC_PC_SR;
    switch(config->getAC()->getType())
    {
        case StorageCell::Integer:
            AC_PC_SR.setNum(config->getAC()->getInt()); 
            break;

        case StorageCell::Float:
            AC_PC_SR.setNum(config->getAC()->getFloat());
            break;

        case StorageCell::Binary:
            AC_PC_SR.setNum(config->getAC()->getInt());/* vielleicht umwandeln, dann aber bereits in StorageCell */
            break;
    }
    AC_PC_SR.insert(0,"AC: ");
    AC_PC_SR.append("\tPC: ");
    AC_PC_SR.append(config->getPC());
    AC_PC_SR.append("\tSR: ");
    AC_PC_SR.append(config->getSR());
    std::cout << AC_PC_SR.toStdString() << std::endl;

    std::cout << "next Operation: " << (this->i->getNextOperation(true)).toStdString() << std::endl;

    std::cout << "Data:\n";
    QVector<unsigned int> usedSlots = config->getUsedData();
    for (int i = 0; i < usedSlots.size(); i++)
        std::cout << (usedSlots[i]) <<": " << config->getData(usedSlots[i])->getInt() << std::endl;

    std::cout << "Indexregister:\n";
    for (int i = 0; i < 16; i++) /* FIXME auslagern in Konstante */
    {
        if (config->getIndexRegister(i)->getInt() != 0)
        {
            switch(config->getIndexRegister(i)->getType())
            {
                /* FIXME: Typen setzen */
                case StorageCell::Integer:
                    std::cout << i << ": " << config->getIndexRegister(i)->getInt() << std::endl;
                    break;

                case StorageCell::Float:
                    std::cout << i << ": " << config->getIndexRegister(i)->getFloat() << std::endl;
                    break;

                case StorageCell::Binary:
                    std::cout << i << ": " << config->getIndexRegister(i)->getInt() << std::endl;
                    /* vielleicht umwandeln, dann aber bereits in StorageCell */
                    break;     
            }
        }
    }
}

void CLI::timerNextStep()
{
    this->i->next();
    this->showConfiguration(this->i->getConfiguration());
}

void CLI::stop(QString message)
{

}

void CLI::halt(QString message)
{

}


