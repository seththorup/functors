#pragma once

class calculate_rx_power {
private:
  double tx_feed_loss_db{0};
  double power_backoff_db{0};

public:
  calculate_rx_power(double power_backoff_db, double tx_feed_loss_db)
      : power_backoff_db(power_backoff_db), tx_feed_loss_db(tx_feed_loss_db) {}

  double operator()(double tx_power_dbm, double tx_gain_dbi,
                    double path_loss_db, double rx_gain_dbi) {
    return tx_power_dbm - power_backoff_db - tx_feed_loss_db + tx_gain_dbi -
           path_loss_db + rx_gain_dbi;
  }
};