#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

#include <QString>

// Объявление абстрактного класса CalculationStrategy
class CalculationStrategy{
public:
    // Чисто виртуальная функция для выполнения вычислений в зависимости от конкретной стратегии
    virtual void SomeCalculationMethod(const QString &directoryPath) = 0;

    // Виртуальный деструктор
    virtual ~CalculationStrategy() {} //Деструктор
};

#endif // CALCULATIONSTRATEGY_H
