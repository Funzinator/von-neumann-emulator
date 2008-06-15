#include "Highlighter.h"

Highlighter::Highlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    classFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("^\\s*([0-9]+)\\s*:\\s*((NGA|FNG|NOT|INR|INI|INB|OUR|OUI|OUB|IRE|RIN|ENTIER|NOP|STP|HLT|SRR)|((ENA\\s+-?[0-9]+)|(ENAR\\s+-?[0-9]*(\\.[0-9]+)?))|((ENAI|ENIA|ADI|SBI)(,I)?\\s+[0-9]+)|(ENI\\s+[0-9]+\\s*,\\s*[0-9]+)|((LDA|STA|ADA|SBA|MUA|DVA|MDA|FAD|FSB|FMU|FDV|AND|OR|XOR|UJP|AZJ,GR|AZJ,GE|AZJ,LS|AZJ,LE|AZJ,EQ|AZJ,NE|SRJ)((,I)?\\s+[0-9]+|\\s+[0-9]+\\s*,\\s*[0-9]+)))\\s*(\\{([^\\}])*\\}\\s*)*$");
    rule.format = classFormat;
    highlightingRules.append(rule);
}

void Highlighter::highlightBlock(const QString &text)
{
    foreach (HighlightingRule rule, highlightingRules)
    {
        QRegExp expression(rule.pattern);
        int index = text.indexOf(expression);
        while (index >= 0)
        {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = text.indexOf(expression, index + length);
        }
    }
}
