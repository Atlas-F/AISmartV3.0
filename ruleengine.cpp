#include "RuleEngine.h"

RuleEngine::RuleEngine(QObject *parent) : QObject(parent)
{
    // 构造函数可以留空，规则通过addRule添加
}

//添加规则，最终通过action执行
void RuleEngine::addRule(const QString& name,
                         const QString& pattern,
                         std::function<void(const QRegularExpressionMatch&)> action)
{
    Rule newRule;
    newRule.name = name;
    newRule.pattern = QRegularExpression(pattern);
    newRule.action = action;
    m_rules.append(newRule);
    qDebug() << "Added rule:" << name << "with pattern:" << pattern;
}

// 最终执行，匹配规则
void RuleEngine::execute(const QString& input)
{
    bool matched = false;
    qDebug() << "Processing input:" << input;

    for (const Rule& rule : m_rules) {
        QRegularExpressionMatch match = rule.pattern.match(input);
        if (match.hasMatch()) {
            try {
                qDebug() << "Matched rule:" << rule.name;
                rule.action(match);
                matched = true;
                break; // 匹配后停止搜索
            } catch (const std::exception& e) {
                qWarning() << "Rule execution failed:" << e.what();
            } catch (...) {
                qWarning() << "Unknown error during rule execution";
            }
        }
    }

    if (!matched) {
        qDebug() << "No rule matched for input:" << input;
        emit noMatchFound(input);
    }
}

void RuleEngine::setContext(const QString& key, const QString& value)
{
    m_context[key] = value;
    qDebug() << "Context set:" << key << "=" << value;
}

QString RuleEngine::getContext(const QString& key) const
{
    return m_context.value(key, "");
}

const QVector<RuleEngine::Rule>& RuleEngine::getRules() const
{
    return m_rules;
}
