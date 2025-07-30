#ifndef COMMANDSYSTEM_H
#define COMMANDSYSTEM_H

#include "RuleEngine.h"
#include <QObject>

#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

// #include "terminalwidget.h"



/**
 * @brief 命令系统类，集成规则引擎并提供具体命令实现
 *
 * 该类封装了各种系统命令的实现，并注册到规则引擎中。  public QObject
 */
class CommandSystem : public QObject
{
    Q_OBJECT

public:
    explicit CommandSystem(QObject *parent = nullptr);

    qint64 pid = 0;

    QTextEdit *outputArea;
    QTextEdit *outputArea2;
    QLineEdit *inputField;
    QPushButton *executeButton;
    QLabel *statusLabel;


    QMetaObject::Connection conncommandResult;
    QMetaObject::Connection connerrorOccurred;
    QMetaObject::Connection connclicked;

    // TerminalWidget * terminaltest;

    // // 新增交互式命令执行方法
    // void executeInteractiveCommand(const QString& command);
    // // 新增命令输入方法
    // void writeToProcess(const QString& input);

    // void executeInteractiveCommand(const QString& program, const QStringList& arguments);

    /**
     * @brief 初始化命令系统
     */
    void initialize();

    /**
     * @brief 处理用户输入
     * @param input 用户输入文本
     */
    void processInput(const QString& input);

    /**
     * @brief 获取规则引擎实例
     * @return 规则引擎指针
     */
    RuleEngine* ruleEngine() const;

signals:
    /**
     * @brief 命令执行结果信号
     * @param result 命令执行结果文本
     */
    void commandResult(const QString& result);

    /**
     * @brief 错误发生信号
     * @param error 错误信息
     */
    void errorOccurred(const QString& error);

    // 在类声明中添加信号

    void commandOutput(const QString& output);
    void commandFinished(int exitCode);

private:



    static const QMap<QString, QStringList> appMap;
    // PID记录表

    QWidget *childwindowtest;
    QProcess* process;

    QMap<QString, int> PIDMap;
    // 命令实现方法
    void openApplication(const QString& appName);
    void CloseApplication(const QString& appName);

    void Openfile(const QString& fileName);
    void Closefile(const QString& fileName);
    void createFile(const QString& fileName);
    void CloseFile(const QString& fileName);
    void searchFiles(const QString& pattern);
    void runSystemCommand(const QString& command);
    void getCurrentTime();

    RuleEngine* m_ruleEngine; ///< 规则引擎实例

    QProcess* m_interactiveProcess = nullptr;  // 保持进程指针


};

#endif // COMMANDSYSTEM_H
