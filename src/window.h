#ifndef WINDOW_H
#define WINDOW_H

#include <QtCore>
#if QTCORE_VERSION>=0x050000
#include <QtWidgets>
#endif
#include <QtGui>

class Window:public QWidget
{
	Q_OBJECT

public:
	Window(QWidget *parent=0);
	~Window(void);

public slots:
	void search(const QString &text);
private:
	QMap<int,QMultiMap<QString,QString>> map;
	QLayout *layout;
	QLineEdit *edit;
	QListWidget *list;
};

#endif /** WINDOW_H **/
