#include "Highlighter.h"

Highlighter::Highlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    /* Befehle (allgemein, unvalidiert) */
    classFormat.setForeground(Qt::darkGray);
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setFontItalic(false);
    rule.pattern = QRegExp("(NGA|FNG|NOT|PRIM|INR|INI|INB|OUR|OUI|OUB|IRE|RIN|ENTIER|NOP|STP|HLT|SRR|ENA|ENAR|ENAI|ENIA|ADI|SBI|ENI|LDA|STA|ADA|SBA|MUA|DVA|MDA|FAD|FSB|FMU|FDV|AND|OR|XOR|UJP|SRJ|AZJ,(GR|GE|LS|LE|EQ|NE))", Qt::CaseInsensitive);
    rule.format = classFormat;
    highlightingRules.append(rule);

    /* Befehle (korrekt) */
    classFormat.setForeground(Qt::black);
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setFontItalic(false);
    rule.pattern = QRegExp("((NGA|FNG|NOT|PRIM|INR|INI|INB|OUR|OUI|OUB|IRE|RIN|ENTIER|NOP|STP|HLT|SRR)|((ENA\\s+-?[0-9]+)|(ENAR\\s+-?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)))|((ENAI|ENIA|ADI|SBI)(,I)?\\s+[0-9]+)|(ENI\\s+[0-9]+\\s*,\\s*[0-9]+)|((LDA|STA|ADA|SBA|MUA|DVA|MDA|FAD|FSB|FMU|FDV|AND|OR|XOR|UJP|AZJ,GR|AZJ,GE|AZJ,LS|AZJ,LE|AZJ,EQ|AZJ,NE|SRJ)((,I)?\\s+[0-9]+|\\s+[0-9]+\\s*,\\s*[0-9]+)))\\s*(\\{([^\\}])*\\}\\s*)*$", Qt::CaseInsensitive);
    rule.format = classFormat;
    highlightingRules.append(rule);

    /* Integer-Zahlen */
    classFormat.setForeground(Qt::darkGreen);
    classFormat.setFontItalic(false);
    classFormat.setFontWeight(QFont::Normal);
    rule.pattern = QRegExp("[-+]?[0-9]+");
    rule.format = classFormat;
    highlightingRules.append(rule);

    /* Float-Zahlen */
    classFormat.setForeground(Qt::darkGreen);
    classFormat.setFontItalic(false);
    classFormat.setFontWeight(QFont::Normal);
    rule.pattern = QRegExp("[-+]?([0-9]*\\.[0-9]*)");
    rule.format = classFormat;
    highlightingRules.append(rule);

    /* Zeilennummern */
    classFormat.setForeground(Qt::darkBlue);
    classFormat.setFontWeight(QFont::Normal);
    classFormat.setFontItalic(false);
    rule.pattern = QRegExp("^\\s*[0-9]+:");
    rule.format = classFormat;
    highlightingRules.append(rule);

    /* Kommentare */
    classFormat.setForeground(Qt::gray);
    classFormat.setFontItalic(true);
    classFormat.setFontWeight(QFont::Normal);
    rule.pattern = QRegExp("(\\{([^\\}])*\\}?\\s*)$");
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
