// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2015-2016 XDN developers
// Copyright (c) 2016-2017 The Karbowanec developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <QFrame>

class QAbstractButton;

namespace Ui {
class MiningFrame;
}

namespace WalletGui {

class Miner;
class PoolModel;

class MiningFrame : public QFrame {
  Q_OBJECT

public:
  MiningFrame(QWidget* _parent);
  ~MiningFrame();

protected:
  void timerEvent(QTimerEvent* _event) Q_DECL_OVERRIDE;

private:
  QScopedPointer<Ui::MiningFrame> m_ui;
  Miner* m_miner;
  PoolModel* m_poolModel;
  int m_hashRateTimerId;
  int m_soloHashRateTimerId;

  void initCpuCoreList();
  void startMining();
  void stopMining();
  void startSolo();
  void stopSolo();

  void walletClosed();
  bool isSoloRunning() const;
  quint32 getHashRate() const;

  Q_SLOT void addPoolClicked();
  Q_SLOT void startStopClicked(QAbstractButton* _button);
  Q_SLOT void startStopSoloClicked(QAbstractButton* _button);
};

}
