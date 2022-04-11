#include <QCoreApplication>
#include "main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cjson_test_01_json_package();
    cjson_test_02_json_analysis();

    return a.exec();
}
