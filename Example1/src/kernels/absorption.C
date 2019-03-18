#include "absorption.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App you entered in when running the stork.sh script with an "App"
 * suffix. If you ran "stork.sh Example", then the argument here becomes "ExampleApp". The second
 * argument is the name of the C++ class you created.
 */
 // still not sure what this is!
registerMooseObject("ExampleApp", absorption);

/**
 * This function defines the valid parameters for
 * this Kernel and their default values
 */
template <>
InputParameters
validParams<absorption>()
{
  InputParameters params = validParams<Kernel>();
  // I commented the next line because the cross section now is not 
  // given by the user directly but calculated by linear interpolation
  
  //params.addRequiredParam<Real>("sigmaA", "SigmaA Value");
  return params;
}

absorption::absorption(const InputParameters & parameters)
  : // You must call the constructor of the base class first
    Kernel(parameters),
    _sigmaA(getMaterialProperty<Real>("absXs"))
{
}

Real
absorption::computeQpResidual()
{
  return _test[_i][_qp] *_sigmaA[_qp]* _u[_qp];
}

Real
absorption::computeQpJacobian()
{
  // the partial derivative of _grad_u is just _grad_phi[_j]
  return _sigmaA[_qp] * _test[_i][_qp] * _phi[_j][_qp];
}
