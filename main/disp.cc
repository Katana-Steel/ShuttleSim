#include "disp.h"
#include "system.h"
#include <QtGui>

Disp::Disp(QWidget *parent)
	: QWidget(parent),CtlStyle("background: purple;")
{
    vlay = new QVBoxLayout(this);
    winGrid = new QGridLayout; // the grid that holds the frontal view port
    winGrid->setMargin(5);

    row << 0 << 0 << 0 << 0 << 1 << 1 << 2 << 2 << 3 << 3 << 4 << 4;
    col << 0 << 1 << 2 << 3 << 0 << 3 << 0 << 3 << 0 << 3 << 0 << 3;

    QWidget *viewPort = new QWidget; // the left window
    viewPort->setStyleSheet("background: black; font-weight: bold; color: yellow;");
    new QLabel("front Left", viewPort);
    winGrid->addWidget(viewPort, 0,0);
    viewPort = new QWidget; // the cental window
    viewPort->setStyleSheet("background: black; color: yellow;");
    new QLabel("front Center", viewPort);
    winGrid->addWidget(viewPort, 0,1,1,2);
    viewPort = new QWidget; // the right window
    viewPort->setStyleSheet("background: black; font-weight: bold; color: yellow;");
    new QLabel("front Right", viewPort);
    winGrid->addWidget(viewPort, 0,3);

    vlay->addLayout(winGrid); // this is where the main view port ourght to be
    QLabel *l = new QLabel("System overview");
    l->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    l->setAlignment(Qt::AlignCenter);
    vlay->addWidget(l); // the main systems overview
    LoadSystems(); // load the controls and systems
}

Disp::~Disp()
{
}

void
Disp::LoadSystems()
{
    QTextStream cout(stdout);
    sysGrid = new QGridLayout;
    sysGrid->setMargin(0);
    sysGrid->setSpacing(0);
    QDir plugs = QDir(qApp->applicationDirPath());

    int sysCount = 0;
    if(plugs.cd("plugins")) {
        SystemInterface *sysInf=0;
        foreach(QString filename, plugs.entryList(QDir::Files))
        {
            cout << "Trying to load: " << filename << endl;
            QPluginLoader loader(plugs.absoluteFilePath(filename));
            QObject *plugin = loader.instance();
            if(plugin) {
		sysInf = qobject_cast<SystemInterface*>(plugin);
                if(sysInf) {
                    systems << sysInf;
		    sysInf->setStyleSheet(CtlStyle);
                    if(sysCount < 10) {
                        sysGrid->addWidget(sysInf->SysSummary(),row.at(sysCount),col.at(sysCount));
                        connect(sysInf, SIGNAL(clicked(SystemInterface*)), this, SLOT(AccessSystem(SystemInterface*)));
                    }
                    sysCount++;
                }
            }
        }
    }
    QLabel *l;
    for(;sysCount<10;sysCount++) {
          l = new QLabel(" "); l->setStyleSheet(CtlStyle);
          sysGrid->addWidget(l,row[sysCount] , col[sysCount]);
    }
    QWidget *mainDisp = new QLabel("Center Console");
    mainDisp->setStyleSheet(CtlStyle + "color: red; border: solid yellow 2px;");
    sysGrid->addWidget(mainDisp, 1, 1, 3, 2);
    vlay->addLayout(sysGrid);
}

void
Disp::AccessSystem(SystemInterface * inf)
{
    QWidget *getCode = new QWidget;
    sysGrid->addWidget(inf->AccessSystem(),1,1,-1,2);
}
