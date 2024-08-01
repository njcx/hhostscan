#include "networktoolsapp.h"
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QCheckBox>

NetworkToolsApp::NetworkToolsApp(QWidget *parent)
    : QMainWindow(parent), tabWidget(nullptr), resultArea(nullptr)
{
    setWindowTitle("网路安全工具 By nj888");
    setGeometry(100, 100, 600, 400);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    tabWidget = new QTabWidget(this);
    tabWidget->addTab(new QWidget(), "简介");
    tabWidget->addTab(new QWidget(), "NC监听");
    tabWidget->addTab(new QWidget(), "HW常用Poc");
    tabWidget->addTab(createPingScanTab(), "Ping");
//    tabWidget->addTab(new QWidget(), "Lookup");
//    tabWidget->addTab(new QWidget(), "Traceroute");
//    tabWidget->addTab(new QWidget(), "Whois");
//    tabWidget->addTab(new QWidget(), "Finger");
    tabWidget->addTab(createPortScanTab(), "端口扫描");

    mainLayout->addWidget(tabWidget);
}

NetworkToolsApp::~NetworkToolsApp()
{
    // 析构函数，如果需要清理资源可以在这里实现
}

QWidget* NetworkToolsApp::createPortScanTab()
{
    QWidget *tab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(tab);

    // 输入行
    QHBoxLayout *inputLayout = new QHBoxLayout();
    QLabel *inputLabel = new QLabel("请输入一个互联网地址以扫描打开的端口:");
    QLineEdit *inputField = new QLineEdit();
    inputField->setPlaceholderText("(例如, 10.0.2.1 或 www.example.com)");
    inputLayout->addWidget(inputLabel);
    inputLayout->addWidget(inputField);

    // 选项
    QHBoxLayout *optionLayout = new QHBoxLayout();
    QCheckBox *onlyOpenPorts = new QCheckBox("只测试端口,范围从");
    QLineEdit *startPort = new QLineEdit();
    QLineEdit *endPort = new QLineEdit();
    QLabel *toLabel = new QLabel("到");
    QPushButton *scanButton = new QPushButton("扫描");
    optionLayout->addWidget(onlyOpenPorts);
    optionLayout->addWidget(startPort);
    optionLayout->addWidget(toLabel);
    optionLayout->addWidget(endPort);
    optionLayout->addWidget(scanButton);

    // 结果显示
    resultArea = new QTextEdit();
    resultArea->setReadOnly(true);

    layout->addLayout(inputLayout);
    layout->addLayout(optionLayout);
    layout->addWidget(resultArea);

    return tab;
}



QWidget* NetworkToolsApp::createPingScanTab()
{
    QWidget *tab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(tab);

    // 输入行
    QHBoxLayout *inputLayout = new QHBoxLayout();
    QLabel *inputLabel = new QLabel("请输入一个互联网地址以扫描打开的端口:");
    QLineEdit *inputField = new QLineEdit();
    inputField->setPlaceholderText("(例如, 10.0.2.1 或 www.example.com)");
    inputLayout->addWidget(inputLabel);
    inputLayout->addWidget(inputField);

    // 选项
    QHBoxLayout *optionLayout = new QHBoxLayout();
    QCheckBox *onlyOpenPorts = new QCheckBox("只测试端口,范围从");
    QLineEdit *startPort = new QLineEdit();
    QLineEdit *endPort = new QLineEdit();
    QLabel *toLabel = new QLabel("到");
    QPushButton *scanButton = new QPushButton("扫描");
    optionLayout->addWidget(onlyOpenPorts);
    optionLayout->addWidget(startPort);
    optionLayout->addWidget(toLabel);
    optionLayout->addWidget(endPort);
    optionLayout->addWidget(scanButton);

    // 结果显示
    resultArea = new QTextEdit();
    resultArea->setReadOnly(true);

    layout->addLayout(inputLayout);
    layout->addLayout(optionLayout);
    layout->addWidget(resultArea);

    return tab;
}
