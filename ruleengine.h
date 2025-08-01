/*********************
 * @file RuleEngine.h
 * @brief 规则引擎核心源文件
 * @author LFG (lfg@.com)
 * @version 1.0
 * @date 2025-08-01
 * 
 * @copyright Copyright (c) 2025  LFG
 * 
 *************************************************/
#ifndef RULEENGINE_H
#define RULEENGINE_H

#include <QObject>
#include <QVector>
#include <QRegularExpression>
#include <QMap>
#include <functional>
#include <QProcess>
#include <QFile>
#include <QDebug>

/**
 * @brief 规则引擎类，负责解析和执行用户指令
 *
 * 该类使用正则表达式匹配用户输入，并执行相应的动作。
 * 支持动态添加规则和上下文管理。
 */
class RuleEngine : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief 规则定义结构体
     * @param action 执行命令的开关，先定义，后执行
     */
    struct Rule {
        QString name;               ///< 规则名称
        QRegularExpression pattern; ///< 匹配模式
        std::function<void(const QRegularExpressionMatch&)> action; ///< 执行动作
    };

    explicit RuleEngine(QObject *parent = nullptr);

    /**
     * @brief 添加新规则
     * @param name 规则名称
     * @param pattern 正则表达式模式
     * @param action 规则匹配时执行的动作
     */
    void addRule(const QString& name,
                 const QString& pattern,
                 std::function<void(const QRegularExpressionMatch&)> action);

    /**
     * @brief 执行用户输入
     * @param input 用户输入文本
     */
    void execute(const QString& input);

    /**
     * @brief 设置上下文值
     * @param key 键
     * @param value 值
     */
    void setContext(const QString& key, const QString& value);

    /**
     * @brief 获取上下文值
     * @param key 键
     * @return 对应的值，如果不存在则返回空字符串
     */
    QString getContext(const QString& key) const;

    /**
     * @brief 获取所有规则
     * @return 规则列表
     */
    const QVector<Rule>& getRules() const;

signals:
    void noMatchFound(const QString& input);

private:
    QVector<Rule> m_rules;              ///< 规则集合
    QMap<QString, QString> m_context;    ///< 执行上下文
};

#endif // RULEENGINE_H
