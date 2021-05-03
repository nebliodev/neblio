#ifndef OVERVIEWPAGE_H
#define OVERVIEWPAGE_H

#include "ui_overviewpage.h"
#include <QTimer>
#include <QWidget>

#include <boost/thread.hpp>
#include <boost/thread/future.hpp>

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

namespace Ui {
class OverviewPage;
}
class WalletModel;
class TxViewDelegate;
class TransactionFilterProxy;

/** Overview ("home") page widget */
class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget* parent = 0);
    ~OverviewPage();

    void setModel(WalletModel* modelIn);
    void showOutOfSyncWarning(bool fShow);

public slots:
    void setBalance(qint64 balance, qint64 stake, qint64 unconfirmedBalance, qint64 immatureBalance);
    void setUnknownBalance();

signals:
    void transactionClicked(const QModelIndex& index);

public:
    Ui::OverviewPage* ui;

private:
    WalletModel* model;
    qint64       currentBalance;
    qint64       currentStake;
    qint64       currentUnconfirmedBalance;
    qint64       currentImmatureBalance;

    TxViewDelegate*         txdelegate;
    TransactionFilterProxy* filter;

private slots:
    void updateDisplayUnit();
    void handleTransactionClicked(const QModelIndex& index);
};

#endif // OVERVIEWPAGE_H
