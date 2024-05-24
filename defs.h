#ifndef DEFS_H
#define DEFS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DataFrame {
private:
  int rows, cols;
  vector<vector<string>> data;
  vector<string> columns;
public:
  DataFrame(vector<vector<string>> data);

  void showData();
};

class PandasCPP {
private:

public:
  PandasCPP();


};

#endif