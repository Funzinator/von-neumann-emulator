#include "Highlighter.h"

#if QT_VERSION >= 0x060500
Highlighter::Highlighter(QTextDocument *parent, Qt::ColorScheme colorScheme) : QSyntaxHighlighter(parent)
#else
Highlighter::Highlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
#endif
{
#if QT_VERSION >= 0x060500
    bool isDark = colorScheme == Qt::ColorScheme::Dark;
#else
    bool isDark = false;
#endif
    QTextCharFormat formatCmd, formatCmdValid, formatInt, formatFloat, formatLineNo, formatComment;
    HighlightingRule ruleCmd, ruleCmdValid, ruleInt, ruleFloat, ruleLineNo, ruleComment;

    formatCmd.setFontWeight(QFont::Bold);
    formatCmdValid.setFontWeight(QFont::Bold);
    formatComment.setFontItalic(true);

    if (!isDark)
    {
        formatCmd.setForeground(Qt::darkGray);
        formatCmdValid.setForeground(Qt::black);
        formatInt.setForeground(Qt::darkGreen);
        formatFloat.setForeground(Qt::darkGreen);
        formatLineNo.setForeground(Qt::darkBlue);
        formatComment.setForeground(Qt::gray);
    }
    else
    {
        formatCmd.setForeground(Qt::lightGray);
        formatCmdValid.setForeground(Qt::white);
        formatInt.setForeground(Qt::green);
        formatFloat.setForeground(Qt::green);
        formatLineNo.setForeground(Qt::yellow);
        formatComment.setForeground(Qt::gray);
    }

    /* Befehle (allgemein, unvalidiert) */
    ruleCmd.pattern = QRegularExpression("(NGA|FNG|NOT|PRIM|INR|INI|INB|OUR|OUI|OUB|IRE|RIN|ENTIRE|ENTIER|NOP|STP|HLT|SRR|ENAR|ENAI|ENA|ENIA|ADI|SBI|ENI|LDA|STA|ADA|SBA|MUA|DVA|MDA|FAD|FSB|FMU|FDV|AND|OR|XOR|UJP|SRJ|AZJ,(GR|GE|LS|LE|EQ|NE))", QRegularExpression::CaseInsensitiveOption);
    ruleCmd.format = formatCmd;
    highlightingRules.append(ruleCmd);

    /* Befehle (korrekt) */
    ruleCmdValid.pattern = QRegularExpression("((NGA|FNG|NOT|PRIM|INR|INI|INB|OUR|OUI|OUB|IRE|RIN|ENTIRE|ENTIER|NOP|STP|HLT|SRR)|((ENA\\s+-?[0-9]+)|(ENAR\\s+-?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)))|((ENAI|ENIA|ADI|SBI)(,I)?\\s+[0-9]+)|(ENI\\s+[0-9]+\\s*,\\s*[0-9]+)|((LDA|STA|ADA|SBA|MUA|DVA|MDA|FAD|FSB|FMU|FDV|AND|OR|XOR|UJP|AZJ,GR|AZJ,GE|AZJ,LS|AZJ,LE|AZJ,EQ|AZJ,NE|SRJ)((,I)?\\s+[0-9]+|\\s+[0-9]+\\s*,\\s*[0-9]+)))\\s*(\\{([^\\}])*\\}\\s*)*$", QRegularExpression::CaseInsensitiveOption);
    ruleCmdValid.format = formatCmdValid;
    highlightingRules.append(ruleCmdValid);

    /* Integer-Zahlen */
    ruleInt.pattern = QRegularExpression("[-+]?[0-9]+");
    ruleInt.format = formatInt;
    highlightingRules.append(ruleInt);

    /* Float-Zahlen */
    ruleFloat.pattern = QRegularExpression("[-+]?([0-9]*\\.[0-9]*)");
    ruleFloat.format = formatFloat;
    highlightingRules.append(ruleFloat);

    /* Zeilennummern */
    ruleLineNo.pattern = QRegularExpression("^\\s*[0-9]+:");
    ruleLineNo.format = formatLineNo;
    highlightingRules.append(ruleLineNo);

    /* Kommentare */
    ruleComment.pattern = QRegularExpression("(\\{([^\\}])*\\}?\\s*)$");
    ruleComment.format = formatComment;
    highlightingRules.append(ruleComment);
}

void Highlighter::highlightBlock(const QString &text)
{
    foreach (HighlightingRule rule, highlightingRules)
    {
        QRegularExpression expression(rule.pattern);
        QRegularExpressionMatch match;
        int index = text.indexOf(expression, 0, &match);

        while (index >= 0)
        {
            int length = match.capturedLength();
            setFormat(index, length, rule.format);
            index = text.indexOf(expression, index + length);
        }
    }
}
