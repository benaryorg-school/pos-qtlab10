#include <window.h>

Window::Window(QWidget *parent):QWidget(parent)
{
	this->setWindowTitle(tr("Dictionary"));

	this->layout=new QVBoxLayout(this);
	this->setLayout(this->layout);

	this->edit=new QLineEdit(this);
	connect(this->edit,SIGNAL(textChanged(const QString &)),this,SLOT(search(const QString &)));
	this->layout->addWidget(this->edit);

	this->list=new QListWidget(this);
	this->list->setSortingEnabled(true);
	this->layout->addWidget(this->list);

	QFile f(":/data/dict.dic");
	f.open(QIODevice::ReadOnly);

	QTextStream stream(&f);
	QString str;
	while(!(str=stream.readLine()).isNull())
	{
		if(str.startsWith(QChar(' ')))
		{
			continue;
		}
		QString text=str.split(QRegExp("\\/")).first();
		QString ls(text.toLower());
		qSort(ls.begin(),ls.end());
		int l=ls.length();
		if(!this->map.contains(l))
		{
			this->map[l]=QMultiMap<QString,QString>();
		}
		this->map[l].insert(ls,text);
	}

	f.close();
}

Window::~Window(void)
{
}

void Window::search(const QString &text)
{
	QString ls(text.toLower());
	qSort(ls.begin(),ls.end());
	int l=ls.length();
	this->list->clear();
	if(l)
	{
		if(this->map.contains(l))
		{
			if(this->map[l].contains(ls))
			{
				this->list->addItems(this->map[l].values(ls));
			}
		}
	}
}

