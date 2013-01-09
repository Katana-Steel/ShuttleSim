/**************************************************************************
    This file: main/main.cc is part of Shuttle Simulator.

    Helhed Client is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    Shuttle Simulator is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helhed Client.  If not, see <http://www.gnu.org/licenses/>.

    Copyright 2011 René Kjellerup aka Katana Steel
**************************************************************************/
/*! \file main.cc
    \brief suttle_sim -- the simulator start up file.
 */
#include <QtGui>
#include <cstring>
#include "disp.h"
#include "utils.h"

/*! \mainpage

  Class relations expressed via an inline dot graph:

  \dotfile mainpage.dot

  Note that the classes in the above graph are clickable
  (in the HTML output).
 */

int
main (int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QIcon i("sim_icon.png");
//    a.setWindowIcon(i);
    QStyle *st = 0;
    QString path("");
    // looping over the program arguments
    for(int i=1; argc > i;++i)
    {
        if(std::strncmp("-cde",argv[i],4) == 0) st = new QCDEStyle;
#ifdef WIN32
        // use Qt's WinXP look?
        if(std::strncmp("-win",argv[i],4) == 0) st = new QWindowsXPStyle;
#endif

    }
    bool ok;

    QFont fn("Andale Mono");
    fn.setPixelSize(12);
    a.setFont(fn);
    if(st==0) {
        st = new QCleanlooksStyle;
    }

    a.setPalette(st->standardPalette());
    a.setStyle(st);
    Disp *w = new Disp;
    w->showMaximized();
    int ret = a.exec();
/*
#ifdef WIN32
    sleep sl(4);
#else
    sleep(4);
#endif
*/
    delete w;
    return ret;
}

bool compareVersion(QString serv, QString cli)
{
        int sMaj, sMin, sRel;
        int cMaj, cMin, cRel;
        QStringList strl = serv.split('.');
        sMaj = strl.at(0).toInt();
        sMin = strl.at(1).toInt();
        sRel = strl.at(2).toInt();

        strl = cli.split('.');
        cMaj = strl.at(0).toInt();
        cMin = strl.at(1).toInt();
        cRel = strl.at(2).toInt();
        return (((sMaj == cMaj) && (sMin == cMin) && (sRel > cRel)) || ((sMaj == cMaj) && (sMin > cMin)) || (sMaj > cMaj));
}
