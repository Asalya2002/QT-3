#ifndef MAINWINDOW_FILEBROWSER_H
#define MAINWINDOW_FILEBROWSER_H

#include "calculationstrategy.h"
#include "byfolder_calculationstrategy.h"
#include "byfiletype_calculationstrategy.h"
#include "new_algorithm.h"

#include <QMainWindow>

class MainWindow_FileBrowser
{
private:
    CalculationStrategy *calculation;  // Указатель на базовый класс стратегии вычисления
    CalculationStrategy *folderStrategy = new ByFolder_CalculationStrategy();  // Создание объекта стратегии для вычисления по папкам
    CalculationStrategy *fileTypeStrategy = new ByFileType_CalculationStrategy();  // Создание объекта стратегии для вычисления по типу файлов
    CalculationStrategy *newStrategy = new NewAlgorithm();  // Создание объекта нового алгоритма

public:
    void setCalculationStrategy(int strategyType)
    {
        switch (strategyType)
        {
        case 0:
            calculation = folderStrategy;  // Установка стратегии вычисления по папкам
            break;
        case 1:
            calculation = fileTypeStrategy;  // Установка стратегии вычисления по типу файлов
            break;
        case 2:
            calculation = newStrategy;  // Установка нового алгоритма
            break;
        }
    }

    void performCalculation(const QString &directoryPath)
    {
        calculation->SomeCalculationMethod(directoryPath);  // Вызов метода вычисления, соответствующего выбранной стратегии
    }
};

#endif // MAINWINDOW_FILEBROWSER_H
