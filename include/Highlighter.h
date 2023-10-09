#ifndef HIGHLIGHTER_H_
#define HIGHLIGHTER_H_

#include <QSyntaxHighlighter>
#include <QRegularExpression>

//! Highlightingklasse für von-Neumann-Befehle
/*!
 * Highlightingklasse, die von-Neumann-Befehle farblich hervorhebt.
 */
class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text);

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};

#endif /*HIGHLIGHTER_H_*/
