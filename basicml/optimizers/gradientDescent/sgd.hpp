/**
 * @file sgd.hpp
 * @brief This file contains the declaration of the SGD class.
 * @ingroup gradientDescent
 * @date 2021-08-29
 * @author Rishikesh Kumar
 */

#ifndef BASICML_OPTIMIZERS_SGD_HPP
#define BASICML_OPTIMIZERS_SGD_HPP

#include "../../math/matrix.hpp"
using namespace basicml::math;

namespace basicml
{
  namespace optimizers
  {
    namespace gradientDescent
    {
      template <typename Model, typename LossFunction>
      class SGD
      {
      private:
        Model _model;
        LossFunction _lossfn;

        // hyper parameters
        double learningRate;
        int epochs;

      public:
        SGD(double learningRate, int epochs) : learningRate(learningRate), epochs(epochs) {}

        Matrix<double> optimize(Matrix<double> X, Matrix<double> Y, Matrix<double> theta)
        {
          for (int i = 0; i < epochs; i++)
          {
            Matrix<double> predictions = X * theta;
            Matrix<double> error = predictions - Y;
            Matrix<double> gradient = (X.transpose() * error) / X.getRows();
            theta = theta - learningRate * gradient;
          }
          return theta;
        }
      };
    } // namespace gradientDescent
  } // namespace optimizers
} // namespace basicml

#endif