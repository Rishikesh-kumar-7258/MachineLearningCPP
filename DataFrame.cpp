#include "defs.h"

DataFrame::DataFrame(vector<vector<string>> data) {
  this->columns = data[0];
  data.erase(data.begin());

  this->rows = data.size();
  this->cols = data[0].size();

  this->data = data;


}

void DataFrame::showData() {
  // cout << "Rows: " << this->rows << endl;
  // cout << "Columns: " << this->cols << endl;

  // cout << "Columns: ";
  for (int i = 0; i < this->cols; i++) {
    cout << this->columns[i] << " ";
  }
  cout << endl;

  // cout << "Data: " << endl;
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < this->cols; j++) {
      cout << this->data[i][j] << " ";
    }
    cout << endl;
  }
}