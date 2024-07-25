#ifndef NETWORKTOOLSAPP_H
#define NETWORKTOOLSAPP_H

#include <QMainWindow>

class QTabWidget;
class QTextEdit;

class NetworkToolsApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit NetworkToolsApp(QWidget *parent = nullptr);
    virtual ~NetworkToolsApp();

private:
    QWidget* createPortScanTab();

    QTabWidget *tabWidget;
    QTextEdit *resultArea;
};

#endif // NETWORKTOOLSAPP_H
