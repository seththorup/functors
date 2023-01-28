#include <iostream>

#include "linkbudget_math.h"

using std::cout;
using std::endl;

int main() {
  double power_backoff_db{3};
  double tx_feed_loss_db{1};
  double tx_power_dbm{20};
  double tx_gain_dbi{2.5};
  double path_loss_db{87};
  double rx_gain_dbi{1.75};


  calculate_rx_power rx_power(power_backoff_db, tx_feed_loss_db);
  
  cout << "Rx_power_db: "
       << rx_power(tx_power_dbm, rx_gain_dbi, path_loss_db, rx_gain_dbi)
       << endl;
}
