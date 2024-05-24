#include "defs.h"

int main() {
  // PandasCPP pd;
  vector<vector<string>> data = {
    {"Name", "Age", "City"},
    {"Alice", "25", "New York"},
    {"Bob", "30", "Los Angeles"},
    {"Charlie", "35", "Chicago"},
    {"David", "40", "Houston"},
    {"Ed", "45", "Phoenix"}
  };

  DataFrame df(data);
  df.showData();

  return 0;
}