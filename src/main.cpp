#include <window.h>
#include <QApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc,char **argv)
{
	//create the application
	QApplication app(argc,argv);

	//load our favourite locale
	QLocale locale=QLocale::system();
	QTranslator translator;
	translator.load(QString(":/lang/")+locale.name());
	app.installTranslator(&translator);

	//create the window
	Window win;
	win.show();

	//execute
	return app.exec();
}
