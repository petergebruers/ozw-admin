#ifndef QTOZWNOTIFICATION_H
#define QTOZWNOTIFICATION_H

#include <QObject>
#include "Notification.h"

#define QTValueID uint64_t

class OZWNotification : public QObject {
    Q_OBJECT
public:
    static OZWNotification *Get();
    //-----------------------------------------------------------------------------
    // All our Signals that we emit - one for each type of Notification
    //-----------------------------------------------------------------------------
signals:
    void valueAdded(QTValueID);
    void valueRemoved(QTValueID);
    void valueChanged(QTValueID);
    void valueRefreshed(QTValueID);
    void valuePollingEnabled(QTValueID);
    void valuePollingDisabled(QTValueID);
    void nodeGroupChanged(uint8_t node, uint8_t group);
    void nodeNew(uint8_t node);
    void nodeAdded(uint8_t node);
    void nodeRemoved(uint8_t node);
    void nodeReset(uint8_t node);
    void nodeNaming(uint8_t node);
    void nodeEvent(uint8_t node, uint8_t event);
    void nodeProtocolInfo(uint8_t node);
    void nodeEssentialNodeQueriesComplete(uint8_t node);
    void nodeQueriesComplete(uint8_t node);
    void driverReady();
    void driverFailed();
    void driverReset();
    void driverRemoved();
    void driverAllNodesQueriedSomeDead();
    void driverAwakeNodesQueried();
    void driverAllNodesQueried();
    void controllerCommand(uint8_t command);
    void ozwNotification(OpenZWave::Notification::NotificationCode event);
    void ozwUserAlert(OpenZWave::Notification::UserAlertNotification event);
    void manufacturerSpecificDBReady();
    //-----------------------------------------------------------------------------
    // <OZWNotification::processNotification>
    // Callback that is triggered when a value, group or node changes
    //-----------------------------------------------------------------------------
public:
    static void processNotification(OpenZWave::Notification const* _notification, void* _context);
private:
    static OZWNotification *s_Instance;

};


#endif // QTOZWNOTIFICATION_H
