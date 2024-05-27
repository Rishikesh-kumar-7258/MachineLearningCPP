/**
 * @file batchGDRegressor.hpp
 * @brief This file contains the declaration of the batchGDRegressor class.
 * @ingroup Regression
 * @date 2021-08-29
 * @author Rishikesh Kumar
 */

#ifndef BASICML_MODELS_LINEARREGRESSION_BATCHGDREGRESSOR_HPP
#define BASICML_MODELS_LINEARREGRESSION_BATCHGDREGRESSOR_HPP

#include "../basicModel.hpp"
using namespace basicml::models;

namespace basicml
{
  namespace models
  {
    namespace Regression
    {
      class BatchGDRegressor : protected BasicModel
      {
      private:
        double _lr, _tolerance;
        int _epochs;

      public:
        // Constructor
        BatchGDRegressor(double lr = 0.1, int epochs = 1000, double tolerance = 0.1) : BasicModel()
        {
          _lr = lr;
          _epochs = epochs;
          _tolerance = tolerance;
        }

        // training function
        void fit(Matrix<double> x, Matrix<double> y)
        {
          setX(Matrix<double>(x.getRows(), 1, (double)1).hstack(x));
          setY(y);

          // randomly initialize theta
          setTheta(Matrix<double>(getX().getCols(), 1, true));

          cout << "Training: " << endl;
          // gradient descent
          double prevMSE = -1;
          for (int i = 0; i < _epochs; i++)
          {
            cout << "Epoch: " << i + 1 << "/" << _epochs << " => ";

            Matrix<double> theta = getTheta();
            Matrix<double> h = getX() * theta;
            long double mse = ((h - getY()).transpose() * (h - getY())).sum() / (2 * getY().getRows());
            Matrix<double> gradient = (getX().transpose() * (h - getY())) / getY().getRows();
            setTheta(theta - _lr * gradient);

            cout << "MSE: " << mse << endl;

            // if (prevMSE != -1 && prevMSE - mse < _tolerance)
            //   break;

            // prevMSE = mse;
          }
        }

        // prediction function
        Matrix<double> predict(Matrix<double> X)
        {
          return X.hstack(Matrix<double>(X.getRows(), 1, (double)1)) * getTheta();
        }

        // get parameters
        Matrix<double> getParameters()
        {
          return getTheta();
        }
      };
    } // namespace Regression
  } // namespace models
} // namespace basicml

#endif