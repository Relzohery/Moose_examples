//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "neutronicsTestApp.h"
#include "neutronicsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<neutronicsTestApp>()
{
  InputParameters params = validParams<neutronicsApp>();
  return params;
}

neutronicsTestApp::neutronicsTestApp(InputParameters parameters) : MooseApp(parameters)
{
  neutronicsTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

neutronicsTestApp::~neutronicsTestApp() {}

void
neutronicsTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  neutronicsApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"neutronicsTestApp"});
    Registry::registerActionsTo(af, {"neutronicsTestApp"});
  }
}

void
neutronicsTestApp::registerApps()
{
  registerApp(neutronicsApp);
  registerApp(neutronicsTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
neutronicsTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  neutronicsTestApp::registerAll(f, af, s);
}
extern "C" void
neutronicsTestApp__registerApps()
{
  neutronicsTestApp::registerApps();
}
