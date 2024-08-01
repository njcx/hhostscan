#include "networktoolsapp.h"
#include <QApplication>
#include "pinger.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Pinger pinger;
    pinger.ping("www.example.com");

    NetworkToolsApp window;
    window.show();
    return app.exec();
}
