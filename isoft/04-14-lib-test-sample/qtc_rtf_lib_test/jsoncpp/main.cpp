#include <QCoreApplication>
#include "main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    jsoncpp_test_01_json_read();

    return a.exec();
}
