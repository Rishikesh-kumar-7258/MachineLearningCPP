#include "basicml/models/Regression/batchGDRegressor.hpp"
#include "basicml/models/Regression/NormalForm.hpp"
#include "basicml/Utilities/functions.hpp"
#include "basicml/Utilities/dataframe.hpp"
using namespace basicml::models::Regression;

pair<Matrix<double>, Matrix<double>> processData(Matrix<string> &X, Matrix<string> &Y);

int main()
{
  // Read the data
  auto df = basicml::Utilities::read_csv<string>("house_data.csv");
  cout << df.head() << endl;
  cout << df.tail() << endl;

  auto X = df.removeColumn("median_house_value").removeColumn("ocean_proximity");
  auto Y = df.getColumn("median_house_value");

  cout << X.head() << endl;
  cout << Y.head() << endl;

  // train, test, validation split
  auto train_test = basicml::Utilities::train_test_split(X.getData(), Y.getData(), 0.2);
  auto X_train = train_test[0];
  auto X_test = train_test[1];
  auto Y_train = train_test[2];
  auto Y_test = train_test[3];

  // cout << X_train << endl;
  // cout << Y_train << endl;
  BatchGDRegressor model(0.5, 100, 1e-3);
  auto data_train_double = processData(X_train, Y_train);
  model.fit(data_train_double.first, data_train_double.second);

  // printing theta
  cout << "Parameters :" << endl
       << model.getParameters() << endl;

  auto data_test_double = processData(X_test, Y_test);
  auto Y_pred = model.predict(data_test_double.first);
  // cout << "Predictions: " << endl
  //      << Y_pred << endl;

  // cout << "MSE: " << basicml::Utilities::mean_squared_error(data_test_double.second, Y_pred) << endl;

  // print y_pred and y_test
  // for (int i = 0; i < Y_pred.getRows(); i++)
  // {
  //   cout << "Y_pred: " << Y_pred(i, 0) << " Y_test: " << data_test_double.second(i, 0) << endl;
  // }

  return 0;
}

pair<Matrix<double>, Matrix<double>> processData(Matrix<string> &X, Matrix<string> &Y)
{
  // convert string data to double
  Matrix<double> X_double(X.shape().first, X.shape().second);
  Matrix<double> Y_double(Y.shape().first, Y.shape().second);

  for (int i = 0; i < X.shape().first; i++)
  {
    for (int j = 0; j < X.shape().second; j++)
    {
      X_double(i, j) = stod(X(i, j) == "" ? "0" : X(i, j));
    }
  }

  for (int i = 0; i < Y.shape().first; i++)
  {
    Y_double(i, 0) = stod(Y(i, 0));
  }

  // standard scalar
  auto X_double_scaled = basicml::Utilities::standardScalar(X_double);

  // print prev X_double and X_double_scaled
  // for (size_t i = 0; i < 5; i++)
  // {
  //   for (size_t j = 0; j < X_double.getCols(); j++)
  //   {
  //     cout << X_double(i, j) << " ";
  //   }
  //   cout << " | ";
  //   for (size_t j = 0; j < X_double_scaled.getCols(); j++)
  //   {
  //     cout << X_double_scaled(i, j) << " ";
  //   }
  //   cout << endl;
  // }

  return {X_double_scaled, Y_double};
}
