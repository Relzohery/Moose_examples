//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

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

  Real _D;
};

#endif // Leakage
