#include "mainwindow_filebrowser.h"
#include "ui_mainwindow_filebrowser.h"

MainWindow_FileBrowser::MainWindow_FileBrowser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow_FileBrowser)
{
    ui->setupUi(this);
}

MainWindow_FileBrowser::~MainWindow_FileBrowser()
{
    delete ui;
}

