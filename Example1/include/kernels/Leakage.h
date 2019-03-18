#ifndef LEAKAGE
#define LEAKAGE

#include "Diffusion.h"

// Forward Declarations
class Leakage;

template <>
InputParameters validParams<Leakage>();

class Leakage : public Diffusion
{
public:
  Leakage(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

 // D is a material property 
 const MaterialProperty<Real> &_D;
};

#endif // Leakage
