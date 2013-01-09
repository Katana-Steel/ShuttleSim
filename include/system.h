/**************************************************************************
    This file: include/system.h is part of Shuttle Simulator.

    Helhed Client is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    Shuttle Simulator is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Shuttle Simulator.  If not, see <http://www.gnu.org/licenses/>.

    Copyright 2011 René Kjellerup aka Katana Steel
**************************************************************************/
#ifndef __shuttle_sim_system_h
#define __shuttle_sim_system_h

#include <QWidget>

/** the Systems inteface
 *
 * this defines the plugin interface used to
 * poll systems and to display a summary of
 * their function and to actuall load and
 * control said system
 */
class SystemInterface : public QWidget
{
public:
    /** the destructor */
    virtual ~SystemInterface() {};

    /** the name.
     *
     * returns a static string with the name of the plugin.
     */
    virtual QString sys_name()=0;

    /** AccessLevel function.
     *
     * Tells the minimum hard-coded user level needed to use
     * the plugin.
     *
     * Usually implemented like this:
     *
     * {
     *     return (QString("XXX") == arg);
     * }
     *
     * where n is an integer from 1-10.
     */
    virtual bool UserAccess(const QString&)=0;

    /** Get the system interface's summary display */
    virtual QWidget * SysSummary()=0;

    /** Get the system GUI
     *
     * This is the function that get all the graphics from
     */
    virtual QWidget * AccessSystem()=0;

signals:
    /** Status Update
     *
     * The signal which is emitted every time an update occurred in a
     * under lying system.
     */
    void sys_update(QString mod,QString message,int lvl=0);

    /** clicked signal
     *
     * activated the system to the main screen.
     */
    void clicked(SystemInterface*);
};

Q_DECLARE_INTERFACE(SystemInterface,"shuttle.sim/system/1.0")

#endif
