#include "defs.h"
#include <fstream>
#include <sstream>

PandasCPP::PandasCPP() {
  // cout << "PandasCPP constructor called" << endl;
}

DataFrame PandasCPP::read_csv(string filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    exit(1);
  }

  vector<vector<string>> data;
  string line, word;
  while (getline(file, line)) {
    vector<string> row;
    stringstream ss(line);
    while (getline(ss, word, ',')) {
      row.push_back(word);
    }
    data.push_back(row);
  }

  file.close();
  return DataFrame(data);
}