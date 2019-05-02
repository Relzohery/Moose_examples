//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "diffusionTestApp.h"
#include "diffusionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<diffusionTestApp>()
{
  InputParameters params = validParams<diffusionApp>();
  return params;
}

diffusionTestApp::diffusionTestApp(InputParameters parameters) : MooseApp(parameters)
{
  diffusionTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

diffusionTestApp::~diffusionTestApp() {}

void
diffusionTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  diffusionApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"diffusionTestApp"});
    Registry::registerActionsTo(af, {"diffusionTestApp"});
  }
}

void
diffusionTestApp::registerApps()
{
  registerApp(diffusionApp);
  registerApp(diffusionTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
diffusionTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  diffusionTestApp::registerAll(f, af, s);
}
extern "C" void
diffusionTestApp__registerApps()
{
  diffusionTestApp::registerApps();
}
