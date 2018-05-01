#include "thread.h"
#include <QThread>
#include <QDebug>

Thread::Thread() {
}

void Thread::run() {
	while (true) {
		emit refresh();
		//qDebug() << "emit refresh()";
		msleep(35);
	}
}
