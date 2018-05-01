#include "mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent) {
	MainWidget *mw = new MainWidget();
	setCentralWidget(mw);
	this->setFixedSize(1000, 650);
}

MainWindow::~MainWindow() {
}
