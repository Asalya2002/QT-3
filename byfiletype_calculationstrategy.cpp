#include "byfiletype_calculationstrategy.h"

void ByFileType_CalculationStrategy::SomeCalculationMethod(const QString &directoryPath)
{
    // Получаем размеры файлов по их типу с помощью метода calculateFileSizesByType
    QMap<QString, qint64> fileSizesByType = calculateFileSizesByType(directoryPath);

    qint64 totalVolume = 0;
    // Вычисляем общий объем всех файлов по типам
    for (auto it = fileSizesByType.constBegin(); it != fileSizesByType.constEnd(); ++it) {
        totalVolume += it.value();
    }

    // Выводим результаты для каждого типа файла
    for (auto it = fileSizesByType.constBegin(); it != fileSizesByType.constEnd(); ++it) {
        // Вычисляем процентное соотношение для каждого типа файла
        double percentage = (static_cast<double>(it.value()) / totalVolume) * 100.0;
        if (qFuzzyCompare(percentage, 0.0)) {
            // Выводим результат с точностью до двух знаков после запятой
            qDebug() << "Total size of" << it.key() << "files in directory" << directoryPath << "is" << it.value() << "bytes";
            qDebug() << "Percentage: < 0.01%";
        } else {
            // Выводим результат с точностью до двух знаков после запятой
            qDebug() << "Total size of" << it.key() << "files in directory" << directoryPath << "is" << it.value() << "bytes";
            qDebug() << "Percentage: " << QString::number(percentage, 'f', 2) << "%";
        }
    }
}

QMap<QString, qint64> ByFileType_CalculationStrategy::calculateFileSizesByType(const QString &directoryPath)
{
    QDir dir(directoryPath);  // Создаем объект QDir для указанной директории
    QMap<QString, qint64> fileSizesByType;  // Создаем QMap для хранения размеров файлов по их типу

    if (dir.exists()) {  // Проверяем, существует ли указанная директория
        QFileInfoList fileList = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);  // Получаем список файлов в директории
        foreach (QFileInfo fileInfo, fileList) {  // Перебираем список файлов
            QString fileType = fileInfo.suffix();  // Получаем тип файла
            qint64 fileSize = fileInfo.size();  // Получаем размер файла
            fileSizesByType[fileType] += fileSize;  // Увеличиваем размер для данного типа файла
        }
    }

    return fileSizesByType;  // Возвращаем QMap с размерами файлов по их типу
}


