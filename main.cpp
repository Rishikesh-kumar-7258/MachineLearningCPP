#include "basicml/math/matrix.hpp"
using namespace basicml::math;

int main()
{
  Matrix<double> m(2, 2, true);
  cout << m << endl;

  Matrix<double> m1(2, 2, true);
  cout << m1 << endl;

  return 0;
}