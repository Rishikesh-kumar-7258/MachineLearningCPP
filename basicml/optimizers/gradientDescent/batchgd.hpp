/**
 * @file batchgd.hpp
 * @brief This file contains the declaration of the Batch Gradient Descent class.
 * @ingroup gradientDescent
 * @date 2021-08-29
 * @author Rishikesh Kumar
 */

#ifndef BASICML_OPTIMIZERS_BATCHGD_HPP
#define BASICML_OPTIMIZERS_BATCHGD_HPP

namespace basicml
{
  namespace optimizers
  {
    namespace gradientDescent
    {
      template <typename Model, typename LossFunction>
      class BatchGD
      {
      private:
        Model _model;
        LossFunction _lossfn;

        // hyper parameters
        double _learningRate;
        int _epochs;
        double _tolerance;

      public:
        BatchGD(double learningRate = 1e-5, int epochs = 1000, double tolerance = 0.1) : _learningRate(learningRate), _epochs(epochs), _tolerance(tolerance) {}

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
}

#endif