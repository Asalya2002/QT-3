#ifndef BYFOLDER_CALCULATIONSTRATEGY_H
#define BYFOLDER_CALCULATIONSTRATEGY_H

#include "calculationstrategy.h"  // Подключаем заголовочный файл для CalculationStrategy
#include <QDir>
#include <QFileInfo>

class ByFolder_CalculationStrategy : public CalculationStrategy
{
public:
    // Объявляем метод для вычисления размера файлов в разных папках
    void SomeCalculationMethod(const QString &directoryPath) override;

private:
    // Приватный метод для вычисления размера папки
    qint64 calculateFolderSize(const QString &folderPath);
};

#endif // BYFOLDER_CALCULATIONSTRATEGY_H


