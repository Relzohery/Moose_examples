#ifndef EXAMPLEMATERIAL_H
#define EXAMPLEMATERIAL_H

#include "Material.h"
#include "LinearInterpolation.h"

class ExampleMaterial;

template <>
InputParameters validParams<ExampleMaterial>();

class ExampleMaterial : public Material
{
public:
  ExampleMaterial(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

private:
  /// member variable to hold the computed XS, D and S
  MaterialProperty<Real> & _absXs;
  MaterialProperty<Real> & _diffCoeff;
  MaterialProperty<Real> & _S;

  /// A helper object for performaing linear interpolations on tabulated data for calculating the
  /// diffusivity property.
  LinearInterpolation _piecewise_func1;
  LinearInterpolation _piecewise_func2;
  LinearInterpolation _piecewise_func3;
};

#endif // EXAMPLEMATERIAL_H
