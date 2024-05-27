/**
 * @file mse.hpp
 * @brief This file contains the declaration of the Mean Squared Error class.
 * @ingroup lossfn
 * @date 2021-08-29
 * @author Rishikesh Kumar
 */

#ifndef BASICML_LOSSFN_MSE_HPP
#define BASICML_LOSSFN_MSE_HPP

#include "base.hpp"

namespace basicml
{
  namespace lossfn
  {
    class MSE : protected LossFunction
    {
    public:
      double loss(double y_true, double y_pred) override
      {
        return (y_true - y_pred) * (y_true - y_pred);
      }
    };
  } // namespace lossfn
} // namespace basicml

#endif