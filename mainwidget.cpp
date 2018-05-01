#include "mainwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QFormLayout>
#include <QDebug>
#include <QSoundEffect>

MainWidget::MainWidget(QWidget *parent) {
	gameArea = new GameArea(parent);
	createObjects();
	createLayout();
	connectObjects();
	bgSound = new QSoundEffect;
	shoot = new QSoundEffect;
	treffer = new QSoundEffect;
	//--------------------------------------------------
	bgSound->setSource(QUrl::fromLocalFile("../sounds/The Trashmen - Surfin Bird.wav"));
	shoot->setSource(QUrl::fromLocalFile("../sounds/lauter-boeller-schuss.wav"));
	treffer->setSource(QUrl::fromLocalFile("../sounds/sfx-explosion-treffer.wav"));
	//--------------------------------------------------
	bgSound->setVolume(0.02);
	bgSound->play(); // loop einfügen
}

void MainWidget::createObjects() {
	frmLayout = new QVBoxLayout();
	hbox_Titel = new QHBoxLayout();
	frmGameArea = new QVBoxLayout();
	hbox_ButtomWidgets = new QHBoxLayout();
	//--------------------------------------------------
	lbl_titel = new QLabel();
	lbl_shoots = new QLabel();
	lbl_angel = new QLabel();
	lbl_speed = new QLabel();
	lbl_titel->setText(tr("<h1>TEWCTB</h1>TheEarlyWormCatchedTheBird"));
	lbl_shoots->setText(tr("Shoots"));
	lbl_angel->setText(tr("Angle"));
	lbl_speed->setText(tr("Speed"));
	//--------------------------------------------------
	btn_Action = new QPushButton("Start");
	//--------------------------------------------------
	ledit_NumberOfShootsInput = new QLineEdit();
	ledit_NumberOfShootsInput->setFixedWidth(60);
	ledit_NumberOfShootsInput->setReadOnly(true);
	ledit_NumberOfShootsInput->setText(QString::number(shoots));
	//--------------------------------------------------
	slider_Angel = new QSlider(Qt::Horizontal);
	slider_Angel->setRange(0, 90);
	slider_Angel->setValue(1);
	slider_Speed = new QSlider(Qt::Horizontal);
	slider_Speed->setRange(1, 100);
	slider_Speed->setValue(1);
	//--------------------------------------------------
	ledit_SpeedInput = new QLineEdit(QString::number(slider_Speed->value()));
	ledit_SpeedInput->setFixedWidth(60);
	ledit_SpeedInput->setReadOnly(true);
	ledit_AngelInput = new QLineEdit(QString::number(slider_Angel->value()));
	ledit_AngelInput->setFixedWidth(60);
	ledit_AngelInput->setReadOnly(true);
}

void MainWidget::createLayout() {
	frmGameArea->addWidget(gameArea, 1);
	hbox_Titel->addWidget(lbl_titel);
	//--------------------------------------------------
	hbox_ButtomWidgets->addWidget(btn_Action);
	hbox_ButtomWidgets->addWidget(lbl_shoots);
	hbox_ButtomWidgets->addWidget(ledit_NumberOfShootsInput);
	hbox_ButtomWidgets->addWidget(lbl_speed);
	hbox_ButtomWidgets->addWidget(slider_Speed);
	hbox_ButtomWidgets->addWidget(ledit_SpeedInput);
	hbox_ButtomWidgets->addWidget(lbl_angel);
	hbox_ButtomWidgets->addWidget(slider_Angel);
	hbox_ButtomWidgets->addWidget(ledit_AngelInput);
	//--------------------------------------------------
	frmLayout->addLayout(hbox_Titel);
	frmLayout->addLayout(frmGameArea);
	frmLayout->addLayout(hbox_ButtomWidgets);
	setLayout(frmLayout);
}


void MainWidget::connectObjects() {
	QObject::connect(btn_Action, &QPushButton::clicked, this,
					 &MainWidget::actionButtonClicked);
	QObject::connect(slider_Angel, &QSlider::valueChanged, this,
					 &MainWidget::angleSliderMoved);
	QObject::connect(slider_Speed, &QSlider::valueChanged, this,
					 &MainWidget::speedSliderMoved);
}

//--------------------------------------------------

void MainWidget::actionButtonClicked() {
	qDebug() << shoots;
	ledit_NumberOfShootsInput->setText(QString::number(shoots));
	//--------------------------------------------------
	if (shoots == 0) {
		qDebug() << "MainWidget - start Game";
		gameArea->startGame();
		btn_Action->setText("Shoot");
	} else {
		gameArea->shoot(ledit_SpeedInput->text().toInt(), ledit_AngelInput->text().toInt());
		shoot->setVolume(0.99);
		shoot->play();
	}
	shoots ++;
}

void MainWidget::angleSliderMoved(int v) {
	qDebug() << "Slider Angle -> " << v;
	ledit_AngelInput->setText(QString::number(v));
}

void MainWidget::speedSliderMoved(int v) {
	qDebug() << "Slider Speed -> " << v;
	ledit_SpeedInput->setText(QString::number(v));
}



