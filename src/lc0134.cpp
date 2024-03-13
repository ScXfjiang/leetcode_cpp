#include <vector>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
  int total_gas = 0;
  int cur_tank = 0;
  int start_station = 0;
  for (int i = 0; i < gas.size(); ++i) {
    total_gas += gas[i] - cost[i];
    cur_tank += gas[i] - cost[i];
    if (cur_tank < 0) {
      start_station = i + 1;
      cur_tank = 0;
    }
  }
  return (total_gas >= 0) ? start_station : -1;
}
