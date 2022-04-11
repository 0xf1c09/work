#include <QCoreApplication>
#include "main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    libxml2_test_01_xml_analysis();

    return a.exec();
}
