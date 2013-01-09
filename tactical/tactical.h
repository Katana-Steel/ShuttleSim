#ifndef __shuttle_sim_tact_dll_tactical_h
#define __shuttle_sim_tact_dll_tactical_h

#include "system.h"

class Tactical : public SystemInterface
{
	Q_OBJECT
	Q_INTERFACES(SystemInterface)
public:
	Tactical();
	QString sys_name() { return QString("Tactical"); };
        bool UserAccess(const QString &pass) { return (access = (QString("") == pass)); };
	QWidget * AccessSystem();
	QWidget * SysSummary();
private:
        bool access;
	QWidget *summary;
        void mouseReleaseEvent(QMouseEvent *evt);
signals:
	void clicked(SystemInterface*);
};

#endif
