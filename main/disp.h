#ifndef __suttle_sim_maindisp_h
#define __suttle_sim_maindisp_h

#include <QWidget>
#include <QVector>

class QVBoxLayout;
class QGridLayout;
class SystemInterface;

class Disp : public QWidget
{
	Q_OBJECT
public:
	Disp(QWidget *parent=0);
        ~Disp();
private:
	QVBoxLayout *vlay;
        QGridLayout *sysGrid, *winGrid;
	QVector<SystemInterface*> systems;
        QString CtlStyle;
        QVector<int> row;
        QVector<int> col;
        void LoadSystems();
private slots:
        void AccessSystem(SystemInterface *inf);

};

#endif
