#include "basicml/math/matrix.hpp"
using namespace basicml::math;

int main()
{
  vector<vector<int>> v(3, vector<int>(3, 0));
  int count = 1;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      v[i][j] = count++;
    }
  }
  Matrix<int> matrix(v);

  cout << matrix << endl;
  cout << matrix.minor(1, 1) << endl;
  return 0;
}