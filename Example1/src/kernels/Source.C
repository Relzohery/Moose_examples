#include "Source.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App you entered in when running the stork.sh script with an "App"
 * suffix. If you ran "stork.sh Example", then the argument here becomes "ExampleApp". The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("ExampleApp", Source);

/**
 * This function defines the valid parameters for
 * this Kernel and their default values
 */
template <>
InputParameters
validParams<Source>()
{
  InputParameters params = validParams<Kernel>();
  //params.addRequiredParam<Real>("S", "External Source");
  return params;
}

Source::Source(const InputParameters & parameters)
  : // You must call the constructor of the base class first
    Kernel(parameters),
    _S(getMaterialProperty<Real>("S"))
{
}

Real
Source::computeQpResidual()
{
  return -1*_test[_i][_qp] *_S[_qp];
}

Real
Source::computeQpJacobian()
{
  // the source is not function of the flux so the jacobian is zero
  return 0;
}
