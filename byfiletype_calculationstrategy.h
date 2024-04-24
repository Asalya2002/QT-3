#ifndef BYFILETYPE_CALCULATIONSTRATEGY_H
#define BYFILETYPE_CALCULATIONSTRATEGY_H

#include "calculationstrategy.h"  // Подключаем заголовочный файл для CalculationStrategy
#include <QDir>
#include <QFileInfo>
#include <QMap>

class ByFileType_CalculationStrategy : public CalculationStrategy
{
public:
    // Объявляем метод для вычисления размера файлов по их типу
    void SomeCalculationMethod(const QString &directoryPath) override;

private:
    // Приватный метод для вычисления размеров файлов по их типу
    QMap<QString, qint64> calculateFileSizesByType(const QString &directoryPath);
};

#endif // BYFILETYPE_CALCULATIONSTRATEGY_H
