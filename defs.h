#ifndef DEFS_H
#define DEFS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class definitions
class DataFrame
{
private:
  int rows, cols;
  vector<vector<string>> data;
  vector<string> columns;

public:
  DataFrame(vector<vector<string>> data);
  DataFrame(vector<vector<double>> data);

  void showData();
  size_t getRows();
  size_t getCols();
};

class PandasCPP
{
private:
public:
  PandasCPP();

  DataFrame read_csv(string filename);
};

class LinearRegression
{
private:
public:
  LinearRegression();
  void fit(vector<vector<double>> x, vector<double> y);
  double predict(double x);
};

#endif