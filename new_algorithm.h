#ifndef NEW_ALGORITHM_H
#define NEW_ALGORITHM_H

#include "calculationstrategy.h"  // Подключаем заголовочный файл для CalculationStrategy

// Объявление класса NewAlgorithm, наследующегося от CalculationStrategy
class NewAlgorithm : public CalculationStrategy{
public:
    // Переопределение чисто виртуальной функции для выполнения вычислений в соответствии с новым алгоритмом
    void SomeCalculationMethod(const QString &directoryPath) override;

    // Дополнительный метод для вычисления общего объема файлов в директории
    qint64 calculateTotalVolume(const QString &directoryPath);
};

#endif // NEW_ALGORITHM_H

