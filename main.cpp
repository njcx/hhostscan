#include "networktoolsapp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    NetworkToolsApp window;
    window.show();
    return app.exec();
}
