#include "defs.h"
#include <iomanip>

DataFrame::DataFrame(vector<vector<string>> data) {
  this->columns = data[0];
  data.erase(data.begin());

  this->rows = data.size();
  this->cols = data[0].size();

  this->data = data;
}

void DataFrame::showData() {

  // measuring max width of each column
  vector<int> max_widths(this->cols, 0);
  for (int i = 0; i < this->cols; i++) {
    max_widths[i] = this->columns[i].size();
    for (int j = 0; j < this->rows; j++) {
      max_widths[i] = max(max_widths[i], (int)this->data[j][i].size());
    }
  }

  // printing column names
  cout << setw(7) << "Index";
  for (int i = 0; i < this->cols; i++) {
    cout << setw(max_widths[i] + 2) << this->columns[i] << " ";
  }
  cout << endl;

  // printing data
  for (int i = 0; i < this->rows; i++) {
    cout << setw(6) << i;
    for (int j = 0; j < this->cols; j++) {
      cout << setw(max_widths[j] + 2) << this->data[i][j] << " ";
    }
    cout << endl;
  }
}

size_t DataFrame::getRows() {
  return this->rows;
}

size_t DataFrame::getCols() {
  return this->cols;
}