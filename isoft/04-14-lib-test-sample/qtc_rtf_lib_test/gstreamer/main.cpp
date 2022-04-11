#include <QCoreApplication>
#include "main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    gstreamer_test_01_get_version();

    return a.exec();
}
