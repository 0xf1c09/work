#include <QCoreApplication>
#include "main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ffmpeg_test_01_avio_list_dir();

    return a.exec();
}
