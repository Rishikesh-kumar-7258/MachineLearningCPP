/**
 * @file base.hpp
 * @brief This file contains the declaration of the LossFunction class.
 * @ingroup lossfn
 * @date 2021-08-29
 * @author Rishikesh Kumar
 */

#ifndef BASICML_LOSSFN_BASE_HPP
#define BASICML_LOSSFN_BASE_HPP

#include "../models/basicModel.hpp"

namespace basicml
{
  namespace lossfn
  {
    class LossFunction
    {
    private:
    public:
      LossFunction() {}
      virtual double loss(double y_true, double y_pred) = 0;
      // virtual double gradient(double y_true, double y_pred) = 0;
    };
  } // namespace lossfn
} // namespace basicml

#endif