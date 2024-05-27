#include "basicml/models/LinearRegression/NormalForm.hpp"
using namespace basicml::models::LinearRegression;

int main()
{
  Matrix<double> X(2, 2);
  X(0, 0) = 5;
  X(0, 1) = 6;
  X(1, 0) = 11;
  X(1, 1) = 13;

  Matrix<double> Y(2, 1);
  Y(0, 0) = 5;
  Y(1, 0) = 6;

  // Matrix<double> theta = X.transpose();
  // cout << "transpose : " << endl;
  // cout << theta << endl;

  // theta = theta * X;
  // cout << "transpose * X : " << endl;
  // cout << theta << endl;

  // double det = theta.determinant();
  // cout << "determinant : " << endl;
  // cout << det << endl;

  // Matrix<double> adj = theta.adjoint();
  // cout << "adjoint : " << endl;
  // cout << adj << endl;

  // theta = theta.inverse();
  // cout << "inverse : " << endl;
  // cout << theta << endl;

  NormalForm model;
  model.fit(X, Y);
  Matrix<double> parameters = model.getParameters();
  std::cout << "Parameters: " << std::endl
            << parameters << std::endl;

  Matrix<double> X_test(2, 2);
  X_test(0, 0) = 7;
  X_test(0, 1) = 8;
  X_test(1, 0) = 9;
  X_test(1, 1) = 10;

  Matrix<double> predictions = model.predict(X_test);
  std::cout << "Predictions: " << std::endl
            << predictions << std::endl;

  return 0;
}