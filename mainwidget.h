#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "gamearea.h"
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSoundEffect>

class MainWidget : public QWidget {
	Q_OBJECT
  private:
	GameArea *gameArea;
	//--------------------------------------------------
	QPushButton *btn_Action;
	//--------------------------------------------------
	QSlider *slider_Angel;
	QSlider *slider_Speed;
	//--------------------------------------------------
	QLineEdit *ledit_NumberOfShootsInput;
	QLineEdit *ledit_SpeedInput;
	QLineEdit *ledit_AngelInput;
	//--------------------------------------------------
	QVBoxLayout *frmLayout;
	QHBoxLayout *hbox_Titel;
	QVBoxLayout *frmGameArea;
	QHBoxLayout *hbox_ButtomWidgets;
	//--------------------------------------------------
	QLabel *lbl_titel;
	QLabel *lbl_shoots;
	QLabel *lbl_angel;
	QLabel *lbl_speed;
	//--------------------------------------------------
	//--------------------------------------------------
	int shoots = 0;
	//--------------------------------------------------
	QSoundEffect *bgSound;
	QSoundEffect *shoot;
	QSoundEffect *treffer;

  public:
	explicit MainWidget(QWidget *parent = nullptr);
	void createLayout();
	void createObjects();
	void connectObjects();

  signals:

  public slots:
	void actionButtonClicked();
	void angleSliderMoved(int);
	void speedSliderMoved(int);
};

#endif // MAINWIDGET_H
