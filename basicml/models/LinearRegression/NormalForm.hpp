/**
 * @file NormalForm.hpp
 * @brief This file contains the declaration of the NormalForm class.
 * @ingroup LinearRegression
 * @date 2021-08-29
 * @author Rishikesh Kumar
 */

#ifndef BASICML_MODELS_LINEARREGRESSION_NORMALFORM_HPP
#define BASICML_MODELS_LINEARREGRESSION_NORMALFORM_HPP

#include "../basicModel.hpp"
using namespace basicml::models;

namespace basicml
{
  namespace models
  {
    namespace LinearRegression
    {
      class NormalForm : protected BasicModel
      {
      public:
        NormalForm() : BasicModel() {}

        void fit(Matrix<double> x, Matrix<double> y)
        {
          setX(Matrix<double>(x.getRows(), 1, 1).hstack(x));
          // setX(x);
          setY(y);
          setTheta((getX().transpose() * getX()).inverse() * (getX().transpose() * getY()));
          // setTheta((getX().transpose() * getX()).inverse() * getX().transpose() * getY());
        }

        Matrix<double> predict(Matrix<double> X)
        {
          return (X * getTheta());
        }

        Matrix<double> getParameters()
        {
          return getTheta();
        }
      };
    } // namespace LinearRegression
  } // namespace models
} // namespace basicml

#endif