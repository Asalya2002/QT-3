#include "byfolder_calculationstrategy.h"

// метод для вычисления размера файлов в разных папках
void ByFolder_CalculationStrategy::SomeCalculationMethod(const QString &directoryPath)
{
    qint64 totalSize = 0;  // Переменная для хранения общего размера файлов
    QDir dir(directoryPath);
    if (!dir.exists()) {
        qDebug() << "Directory does not exist.";
        return;
    }

    qint64 totalVolume = calculateFolderSize(directoryPath); // Вычисляем общий объем директории

    totalSize = calculateFolderSize(directoryPath);  // Повторно вычисляем общий размер (дублирование)

    // Вычисляем процент и выводим результат
    double percentage = 0.0;
    if (totalVolume != 0) {
        percentage = (static_cast<double>(totalSize) / totalVolume) * 100.0;
    }

    if (qFuzzyCompare(percentage, 0.0)) {
        qDebug() << "Percentage: < 0.01%";
    } else {
        qDebug() << "Percentage: " << QString::number(percentage, 'f', 2) << "%";
    }
}

// Метод для вычисления размера папки на основе переданного пути
qint64 ByFolder_CalculationStrategy::calculateFolderSize(const QString &folderPath)
{
    QDir dir(folderPath);  // Создаем объект QDir для указанной директории
    qint64 folderSize = 0;  // Переменная для хранения размера папки

    if (dir.exists()) {  // Проверяем, существует ли указанная директория
        QFileInfoList fileList = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);  // Получаем список файлов и папок в директории
        foreach (QFileInfo fileInfo, fileList) {  // Перебираем список файлов и папок
            if (fileInfo.isFile()) {  // Если это файл, добавляем его размер к размеру папки
                folderSize += fileInfo.size();
            } else if (fileInfo.isDir()) {  // Если это папка, вызываем рекурсивно метод calculateFolderSize для подсчета размера вложенной папки
                folderSize += calculateFolderSize(fileInfo.filePath());
            }
        }
    }

    return folderSize;  // Возвращаем общий размер папки
}
