#pragma once
#include <QObject>

#include <QtBluetooth/qbluetoothaddress.h>
#include <QtBluetooth/qbluetoothserviceinfo.h>

QT_FORWARD_DECLARE_CLASS(QBluetoothServer)
QT_FORWARD_DECLARE_CLASS(QBluetoothSocket)

class BtServer : public QObject
{
    Q_OBJECT
public:
    explicit BtServer(QObject *parent = nullptr);
    ~BtServer();

    bool startServer(const QBluetoothAddress &localAdapter = QBluetoothAddress());
    void stopServer();

public slots:
    void sendMessage(const QString &message);

signals:
    void messageReceived(const QString &sender, const QString &message);
    void clientConnected(const QString &name);
    void clientDisconnected(const QString &name);

private slots:
    void clientConnected();
    void clientDisconnected();
    void readSocket();

private:
    QBluetoothServer* rfcommServer = nullptr;
    QBluetoothServiceInfo serviceInfo;
    QBluetoothSocket* pClientSocket = nullptr;
    QString sClientName;
};

