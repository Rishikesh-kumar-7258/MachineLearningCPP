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

  cout << "Original Matrix" << endl;
  cout << matrix << endl;

  cout << "Matrix Minor" << endl;
  cout << matrix.minor(1, 1) << endl;

  cout << "Matrix transpose" << endl;
  cout << matrix.transpose() << endl;

  cout << "Matrix determinant" << endl;
  cout << matrix.determinant() << endl;

  cout << "Matrix inverse" << endl;
  cout << matrix.inverse() << endl;
  return 0;
}