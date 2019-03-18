#include "ExampleMaterial.h"

registerMooseObject("ExampleApp", ExampleMaterial);

template <>
InputParameters
validParams<ExampleMaterial>()
{
  InputParameters params = validParams<Material>();

  // Allow users to specify vectors defining the points of a piecewise function formed via linear
  // interpolation.
  params.addRequiredParam<std::vector<Real>>(
      "independent_vals",
      "The vector of z-coordinate values for a piecewise function's independent variable");
  params.addRequiredParam<std::vector<Real>>(
      "dependent_vals_1", "The vector of absorbtion cross sections for a piecewise function's dependent");

  params.addRequiredParam<std::vector<Real>>(
      "dependent_vals_2", "The vector of diffusion coefficient values for a piecewise function's dependent");
   params.addRequiredParam<std::vector<Real>>(
      "dependent_vals_3", "The vector of source values for a piecewise function's dependent");
  return params;
}

ExampleMaterial::ExampleMaterial(const InputParameters & parameters)
  : Material(parameters),
    // Declare that this material is going to provide a Real value typed
    // material property named "diffusivity" that Kernels and other objects can use.
    // This property is "bound" to the class's "_diffusivity" member.
    _absXs(declareProperty<Real>("absXs")),
    _diffCoeff(declareProperty<Real>("diffCoeff")),
    _S(declareProperty<Real>("S")),

    // Initialize our piecewise function helper with the user-specified interpolation points.
    _piecewise_func1(getParam<std::vector<Real>>("independent_vals"),
                    getParam<std::vector<Real>>("dependent_vals_1")),

    _piecewise_func2(getParam<std::vector<Real>>("independent_vals"),
                    getParam<std::vector<Real>>("dependent_vals_2")),
                    
    _piecewise_func3(getParam<std::vector<Real>>("independent_vals"),
                    getParam<std::vector<Real>>("dependent_vals_3"))
{
}

void
ExampleMaterial::computeQpProperties()
{
  _absXs[_qp] = _piecewise_func1.sample(_q_point[_qp](0));

  _diffCoeff[_qp] = _piecewise_func2.sample(_q_point[_qp](0));
  _S[_qp] = _piecewise_func3.sample(_q_point[_qp](0));
}
