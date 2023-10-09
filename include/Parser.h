#ifndef PARSER_H_
#define PARSER_H_

#define PARSE_REGEXP "^\\s*([0-9]+)\\s*:\\s*((NGA|FNG|NOT|INR|INI|INB|OUR|OUI|OUB|IRE|RIN|ENTIER|NOP|STP|HLT|SRR|PRIM)|((ENA\\s+-?[0-9]+)|(ENAR\\s+-?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)))|((ENAI|ENIA|ADI|SBI)(,I)?\\s+[0-9]+)|(ENI\\s+[0-9]+\\s*,\\s*[0-9]+)|((LDA|STA|ADA|SBA|MUA|DVA|MDA|FAD|FSB|FMU|FDV|AND|OR|XOR|UJP|AZJ,GR|AZJ,GE|AZJ,LS|AZJ,LE|AZJ,EQ|AZJ,NE|SRJ)((,I)?\\s+[0-9]+|\\s+[0-9]+\\s*,\\s*[0-9]+)))\\s*(\\{([^\\}])*\\}\\s*)*$"                         
#define SPLIT_REGEXP "\\s*([0-9]+)\\s*:\\s*(AZJ,[a-zA-Z][a-zA-Z]|[a-zA-Z]{2,6})(,I)?(\\s*(-?[0-9]+\\.?[0-9]*)\\s*(,\\s*([0-9]+))?)?\\s*((\\{([^\\}])*\\}\\s*)*)"

#include <QRegularExpression>
#include <QVector>
#include <QString>
#include <QStringList>
#include <QFile>

#include "Operations.h"

class Parser
{
private:
    QRegularExpression *ParseRegExp;
    QRegularExpression *SplitRegExp;

    //! prüft, ob die Quelltextzeile eine gültige Anweisung enthält
    /*!
     * \param line Quelltextzeile
     * \return Gültigkeit
     */
    bool validateLine(QString);

    //! wandelt eine Quelltextzeile in eine RawOperation um.
    /*!
     * \param line Quelltextzeile
     * \return RawOperation-Objekt zu dieser Zeile
     */
    RawOperation* convertLine(QString);

public:
    Parser();
    ~Parser();

    //! parst ein QVector mit Quelltextzeilen
    /*
     * \param input Quelltextzeilen
     * \return Map mit Operationen zur Verwendung durch den Interpreter
     */
    QMap<unsigned int,Operation *> Parse(QVector<QString>);

    //! parst eine Quelltextdatei
    /**
     * \param file Quelltextdatei
     * \return Map mit Operationen zur Verwendung durch den Interpreter
     */ 
    QMap<unsigned int,Operation *> Parse(QFile *);

    //! parst einen Quelltext
    /**
     * \param plainText Quelltext
     * \return Map mit Operationen zur Verwendung durch den Interpreter
     */
    QMap<unsigned int,Operation *> Parse(QString);
};

#endif /*PARSER_H_*/
