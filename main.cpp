#include <QCoreApplication>
#include "mainwindow_filebrowser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Создаем экземпляр MainWindow_FileBrowser
    MainWindow_FileBrowser fileBrowser;

    // Устанавливаем стратегию вычислений (0 - ByFolder, 1 - ByFileType, 2 - NewAlgorithm)
    fileBrowser.setCalculationStrategy(1); // Выбор стратегии

    // Выполняем вычисления для указанной директории
    fileBrowser.performCalculation("C:/Users/User/OneDrive/Документы");

    return a.exec();
}

