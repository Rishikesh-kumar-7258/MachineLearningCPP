/**
 * @file basicModel.hpp
 * @brief This file contains the declaration of the basicModel class.
 * @ingroup models
 * @date 2021-08-29
 * @author Rishikesh Kumar
 */

#ifndef BASICML_MODELS_BASICMODEL_HPP
#define BASICML_MODELS_BASICMODEL_HPP

#include "../math/matrix.hpp"
using namespace basicml::math;

namespace basicml
{
  namespace models
  {
    class BasicModel
    {
    private:
      Matrix<double> theta;
      Matrix<double> X, Y;

    protected:
      // Setters
      void setX(Matrix<double> X)
      {
        this->X = X;
      }

      void setY(Matrix<double> Y)
      {
        this->Y = Y;
      }

      void setTheta(Matrix<double> theta)
      {
        this->theta = theta;
      }

    public:
      // Constructor
      BasicModel() {}

      // Getters
      Matrix<double> getX()
      {
        return X;
      }

      Matrix<double> getY()
      {
        return Y;
      }

      Matrix<double> getTheta()
      {
        return theta;
      }
      // training function
      virtual void fit(Matrix<double> x, Matrix<double> y) = 0;

      // prediction function
      virtual Matrix<double> predict(Matrix<double> X) = 0;

      // get parameters
      virtual Matrix<double> getParameters() = 0;
    };
  } // namespace models
} // namespace basicml

#endif