/**
 * @file functions.hpp
 * @brief This file contains the declaration of the functions
 * @ingroup Utilities
 * @date 2021-08-29
 * @author Rishikesh Kumar
 */

#ifndef BASICML_UTILITIES_FUNCTIONS_HPP
#define BASICML_UTILITIES_FUNCTIONS_HPP

#include "dataframe.hpp"
#include <fstream>
#include <sstream>
#include <map>
using namespace basicml::Utilities;

namespace basicml
{
  namespace Utilities
  {

    // function to read csv file and return DataFrame
    template <typename T>
    DataFrame<T> read_csv(string filename, char delimiter = ',')
    {
      ifstream file(filename);
      string line;
      vector<string> columns;
      vector<vector<T>> data;

      if (!file.is_open())
      {
        throw runtime_error("Could not open file");
      }

      // read columns
      getline(file, line);
      stringstream ss(line);
      string column;
      while (getline(ss, column, delimiter))
      {
        columns.push_back(column);
      }

      // read data
      while (getline(file, line))
      {
        vector<T> row;
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, delimiter))
        {
          row.push_back(cell);
        }
        data.push_back(row);
      }

      Matrix<T> m(data);

      return DataFrame<T>(m, columns);
    }

    // function to split the data into train and test
    template <typename T>
    vector<Matrix<T>> train_test_split(Matrix<T> X, Matrix<T> Y, float test_size)
    {
      int n = X.shape().first;
      int test_rows = n * test_size;

      Matrix<T> X_train(n - test_rows, X.shape().second);
      Matrix<T> X_test(test_rows, X.shape().second);
      Matrix<T> Y_train(n - test_rows, Y.shape().second);
      Matrix<T> Y_test(test_rows, Y.shape().second);

      for (int i = 0; i < n; i++)
      {
        if (i < n - test_rows)
        {
          for (int j = 0; j < X.shape().second; j++)
          {
            X_train(i, j) = X(i, j);
          }
          for (int j = 0; j < Y.shape().second; j++)
          {
            Y_train(i, j) = Y(i, j);
          }
        }
        else
        {
          for (int j = 0; j < X.shape().second; j++)
          {
            X_test(i - (n - test_rows), j) = X(i, j);
          }
          for (int j = 0; j < Y.shape().second; j++)
          {
            Y_test(i - (n - test_rows), j) = Y(i, j);
          }
        }
      }

      return {X_train, X_test, Y_train, Y_test};
    }

    // Standard Scalar function
    Matrix<double> standardScalar(Matrix<double> X)
    {
      Matrix<double> X_std(X.shape().first, X.shape().second);
      Matrix<double> mean = X.mean(0);
      Matrix<double> std = X.std(0);

      for (int i = 0; i < X.shape().first; i++)
      {
        for (int j = 0; j < X.shape().second; j++)
        {
          X_std(i, j) = (X(i, j) - mean(0, j)) / std(0, j);
        }
      }

      return X_std;
    }

    // Mean Squared Error function
    double mean_squared_error(Matrix<double> y_true, Matrix<double> y_pred)
    {
      return ((y_true - y_pred).transpose() * (y_true - y_pred)).sum() / (2 * y_true.getRows());
    }

    // label encoding
    template <typename T>
    vector<T> label_encoding(Matrix<string> data)
    {
      map<string, int> encoding;
      T count = 0;
      vector<T> encoded_data;
      for (int i = 0; i < data.shape().first; i++)
      {
        if (encoding.find(data(i, 0)) == encoding.end())
        {
          encoding[data(i, 0)] = count++;
        }
        encoded_data.push_back(encoding[data(i, 0)]);
      }
      return encoded_data;
    }

  } // namespace Utilities
} // namespace basicml

#endif