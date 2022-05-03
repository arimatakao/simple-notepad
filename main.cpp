#include "simplenotepad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    simplenotepad w;
    w.show();
    return a.exec();
}
