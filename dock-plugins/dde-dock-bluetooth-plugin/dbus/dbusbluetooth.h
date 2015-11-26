/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c Bluetooth -p dbusbluetooth com.deepin.daemon.Bluetooth.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef DBUSBLUETOOTH_H_1437099652
#define DBUSBLUETOOTH_H_1437099652

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface com.deepin.daemon.Bluetooth
 */
class DBusBluetooth: public QDBusAbstractInterface
{
    Q_OBJECT

    Q_SLOT void __propertyChanged__(const QDBusMessage& msg)
    {
        QList<QVariant> arguments = msg.arguments();
        if (3 != arguments.count())
            return;
        QString interfaceName = msg.arguments().at(0).toString();
        if (interfaceName !="com.deepin.daemon.Bluetooth")
            return;
        QVariantMap changedProps = qdbus_cast<QVariantMap>(arguments.at(1).value<QDBusArgument>());
        foreach(const QString &prop, changedProps.keys()) {
        const QMetaObject* self = metaObject();
            for (int i=self->propertyOffset(); i < self->propertyCount(); ++i) {
                QMetaProperty p = self->property(i);
                if (p.name() == prop) {
 	            Q_EMIT p.notifySignal().invoke(this);
                }
            }
        }
   }
public:
    static inline const char *staticServerPath()
    { return "com.deepin.daemon.Bluetooth"; }
    static inline const char *staticInterfacePath()
    { return "/com/deepin/daemon/Bluetooth"; }
    static inline const char *staticInterfaceName()
    { return "com.deepin.daemon.Bluetooth"; }

public:
    DBusBluetooth(QObject *parent = 0);

    ~DBusBluetooth();

    Q_PROPERTY(QString Adapters READ adapters NOTIFY AdaptersChanged)
    inline QString adapters() const
    { return qvariant_cast< QString >(property("Adapters")); }

    Q_PROPERTY(QString Devices READ devices NOTIFY DevicesChanged)
    inline QString devices() const
    { return qvariant_cast< QString >(property("Devices")); }

    Q_PROPERTY(uint State READ state NOTIFY StateChanged)
    inline uint state() const
    { return qvariant_cast< uint >(property("State")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> ConnectDevice(const QDBusObjectPath &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("ConnectDevice"), argumentList);
    }

    inline QDBusPendingReply<QString> DebugInfo()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("DebugInfo"), argumentList);
    }

    inline QDBusPendingReply<> DisconnectDevice(const QDBusObjectPath &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("DisconnectDevice"), argumentList);
    }

    inline QDBusPendingReply<> FeedAuthorizeService(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("FeedAuthorizeService"), argumentList);
    }

    inline QDBusPendingReply<> FeedPinCode(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("FeedPinCode"), argumentList);
    }

    inline QDBusPendingReply<QString> GetAdapters()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("GetAdapters"), argumentList);
    }

    inline QDBusPendingReply<QString> GetDevices(const QDBusObjectPath &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("GetDevices"), argumentList);
    }

    inline QDBusPendingReply<> RemoveDevice(const QDBusObjectPath &in0, const QDBusObjectPath &in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("RemoveDevice"), argumentList);
    }

    inline QDBusPendingReply<> RequestDiscovery(const QDBusObjectPath &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("RequestDiscovery"), argumentList);
    }

    inline QDBusPendingReply<> SetAdapterAlias(const QDBusObjectPath &in0, const QString &in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("SetAdapterAlias"), argumentList);
    }

    inline QDBusPendingReply<> SetAdapterDiscoverable(const QDBusObjectPath &in0, bool in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("SetAdapterDiscoverable"), argumentList);
    }

    inline QDBusPendingReply<> SetAdapterDiscoverableTimeout(const QDBusObjectPath &in0, uint in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("SetAdapterDiscoverableTimeout"), argumentList);
    }

    inline QDBusPendingReply<> SetAdapterPowered(const QDBusObjectPath &in0, bool in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("SetAdapterPowered"), argumentList);
    }

    inline QDBusPendingReply<> SetDeviceAlias(const QDBusObjectPath &in0, const QString &in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("SetDeviceAlias"), argumentList);
    }

    inline QDBusPendingReply<> SetDeviceTrusted(const QDBusObjectPath &in0, bool in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("SetDeviceTrusted"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void AdapterAdded(const QString &in0);
    void AdapterPropertiesChanged(const QString &in0);
    void AdapterRemoved(const QString &in0);
    void AuthorizeService(const QString &in0, const QString &in1);
    void DeviceAdded(const QString &in0);
    void DevicePropertiesChanged(const QString &in0);
    void DeviceRemoved(const QString &in0);
    void RequestPinCode(const QString &in0);
// begin property changed signals
void AdaptersChanged();
void DevicesChanged();
void StateChanged();
};

namespace com {
  namespace deepin {
    namespace daemon {
      typedef ::DBusBluetooth DBusBluetooth;
    }
  }
}
#endif
