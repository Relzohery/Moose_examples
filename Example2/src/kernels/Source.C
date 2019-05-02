//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "Source.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App you entered in when running the stork.sh script with an "App"
 * suffix. If you ran "stork.sh Example", then the argument here becomes "ExampleApp". The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("neutronicsApp", Source);

/**
 * This function defines the valid parameters for
 * this Kernel and their default values
 */
template <>
InputParameters
validParams<Source>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredParam<Real>("S", "External Source");
  return params;
}

Source::Source(const InputParameters & parameters)
  : // You must call the constructor of the base class first
    Kernel(parameters),
    _S(getParam<Real>("S"))
{
}

Real
Source::computeQpResidual()
{
  // velocity * _grad_u[_qp] is actually doing a dot product
 //_test[_i][_qp] * (_sigmaA * _u[_qp]);
  return -1*_test[_i][_qp] *_S;
}

Real
Source::computeQpJacobian()
{
  // the partial derivative of _grad_u is just _grad_phi[_j]
  return 0;
}
