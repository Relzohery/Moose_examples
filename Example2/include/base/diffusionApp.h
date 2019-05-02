//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef DIFFUSIONAPP_H
#define DIFFUSIONAPP_H

#include "MooseApp.h"

class diffusionApp;

template <>
InputParameters validParams<diffusionApp>();

class diffusionApp : public MooseApp
{
public:
  diffusionApp(InputParameters parameters);
  virtual ~diffusionApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* DIFFUSIONAPP_H */
