#ifndef PARSER_H_
#define PARSER_H_

#define PARSE_REGEXP "^\\s*([0-9]+)\\s*:\\s*((NGA|FNG|NOT|INR|INI|INB|OUR|OUI|OUB|IRE|RIN|ENTIER|NOP|STP|HLT|SRR)|((ENA\\s+[0-9]+)|(ENAR\\s+[0-9]*(\\.[0-9]+)?))|((ENAI|ENIA|ADI|SBI)(,I)?\\s+[0-9]+)|(ENI\\s+[0-9]+\\s*,\\s*[0-9]+)|((LDA|STA|ADA|SBA|MUA|DVA|MDA|FAD|FSB|FMU|FDV|AND|OR|XOR|UJP|AZJ,GR|AZJ,GE|AZJ,LS|AZJ,LE|AZJ,EQ|AZJ,NE|SRJ)((,I)?\\s+[0-9]+|\\s+[0-9]+\\s*,\\s*[0-9]+)))\\s*(\\{([^\\}])*\\}\\s*)*$"
#define SPLIT_REGEXP "\\s*([0-9]+)\\s*:\\s*(AZJ,[a-zA-Z][a-zA-Z]|[a-zA-Z]{3,6})(,I)?(\\s*([0-9]+\\.?[0-9]*)\\s*(,\\s*([0-9]+))?)?\\s*((\\{([^\\}])*\\}\\s*)*)"

#include <QRegExp>
#include <QString>

#include "RawOperation.h"

class Parser
{
private:
    QRegExp *ParseRegExp;
    QRegExp *SplitRegExp;

    bool validateLine(QString);

public:
    Parser();
    ~Parser();
        
    RawOperation* convertLine(QString);
};

#endif /*PARSER_H_*/
