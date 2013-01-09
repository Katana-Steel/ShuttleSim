#include "tactical.h"
#include <QtGui>

Tactical::Tactical()
	: SystemInterface(), access(false)
{
    summary = new QWidget;
    QString online = "background: lime;";
    QString offline = "background: red;";
    QGridLayout *grid = new QGridLayout(summary);
    QLabel *lab = new QLabel(this->sys_name());
    lab->setAlignment(Qt::AlignCenter);
    grid->addWidget(lab,0,0,1,2);
    lab = new QLabel("Shields");
    grid->addWidget(lab,1,0);
    lab = new QLabel("2500KMw");
    lab->setStyleSheet(online);
    grid->addWidget(lab,1,1);
    lab = new QLabel("Phasers Cannons");
    grid->addWidget(lab,2,0);
    lab = new QLabel("75% charging");
    lab->setStyleSheet(offline);
    grid->addWidget(lab,2,1);
    lab = new QLabel("Photon Torpedos");
    grid->addWidget(lab,3,0);
    lab = new QLabel("Tube 1-4 loading");
    lab->setStyleSheet(offline);
    grid->addWidget(lab,3,1);
    summary->setStyleSheet("background: purple; border: solid red 2px;");
}

QWidget *
Tactical::SysSummary()
{
    return this->summary;
}

QWidget *
Tactical::AccessSystem()
{
    if(!access) return this->summary;
    return new QWidget;
}

void
Tactical::mouseReleaseEvent(QMouseEvent *evt)
{
    if(evt->button() == Qt::LeftButton) {
        access = false;
        emit clicked(this);
    }
}

Q_EXPORT_PLUGIN2(tactical,Tactical)
