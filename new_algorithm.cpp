#include "new_algorithm.h"
#include <QDebug>
#include <QDir>
#include <QFileInfoList>

qint64 NewAlgorithm::calculateTotalVolume(const QString &directoryPath) {
    QDir dir(directoryPath);
    qint64 totalSize = 0;
    // Проверяем, существует ли указанная директория
    if (dir.exists()) {
        // Получаем список файлов в указанной директории
        QFileInfoList fileList = dir.entryInfoList(QDir::Files);

        // Считаем общий размер файлов в директории
        foreach (const QFileInfo &fileInfo, fileList) {
            totalSize += fileInfo.size();
        }
    }
    return totalSize;  // Возвращаем общий размер файлов в директории
}

void NewAlgorithm::SomeCalculationMethod(const QString &directoryPath)
{
    QDir dir(directoryPath);
    qint64 totalSize = 0;

    // Проверяем, существует ли указанная директория
    if (dir.exists()) {
        // Получаем список файлов в указанной директории
        QFileInfoList fileList = dir.entryInfoList(QDir::Files);

        // Считаем общий размер файлов в директории
        foreach (const QFileInfo &fileInfo, fileList) {
            totalSize += fileInfo.size();
        }

        // Выводим общий размер файлов в директории
        qDebug() << "Total size of files in directory" << directoryPath << "is" << totalSize << "bytes";

        // Вычисляем общий объем директории с помощью метода calculateTotalVolume
        qint64 totalVolume = calculateTotalVolume(directoryPath);

        // Вычисляем процентное соотношение и выводим результат
        double percentage = 0.0;
        if (totalVolume != 0) {
            percentage = (static_cast<double>(totalSize) / totalVolume) * 100.0;
        }

        if (qFuzzyCompare(percentage, 0.0)) {
            qDebug() << "Percentage: < 0.01%";
        } else {
            qDebug() << "Percentage: " << QString::number(percentage, 'f', 2) << "%";
        }
    } else {
        qDebug() << "Directory" << directoryPath << "does not exist";
    }
}
