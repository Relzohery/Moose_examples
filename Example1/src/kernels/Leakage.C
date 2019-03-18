#include "Leakage.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App you entered in when running the stork.sh script with an "App"
 * suffix. If you ran "stork.sh Example", then the argument here becomes "ExampleApp". The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("ExampleApp", Leakage);

/**
 * This function defines the valid parameters for
 * this Kernel and their default values
 */
template <>
InputParameters
validParams<Leakage>()
{
  InputParameters params = validParams<Diffusion>();
  // the next line is commented since I am treating D as a material property
  // not a user input
  //params.addRequiredParam<Real>("D", "Diffusion Coefficient");
  return params;
}

Leakage::Leakage(const InputParameters & parameters)
  : // You must call the constructor of the base class first
    Diffusion(parameters),
    _D(getMaterialProperty<Real>("diffCoeff"))
{
}

Real
Leakage::computeQpResidual()
{
 
  return _D[_qp]* Diffusion::computeQpResidual();

}

Real
Leakage::computeQpJacobian()
{
  // the partial derivative of _grad_u is just _grad_phi[_j]
  return _D[_qp]* Diffusion::computeQpJacobian();
}
