#ifndef __shuttle_sim_utils_h
#define __shuttle_sim_utils_h

#include <QThread>
#include <QString>

/** a version compare routine */
bool compareVersion(QString serv, QString cli);

#ifdef WIN32
/** sleep
 * --
 * this object is used as the unix sleep function. Because the Windows API for
 * doing the same are way to complicated so I leave it in Nokia's and Qt's most
 * capable hands.
 */
class sleep : public QThread
{
    void run() {};
public:
    sleep(unsigned long sec,QObject *parent=0) :
      QThread(parent)
    {
        QThread::sleep(sec);
    };
};
#endif

#endif
