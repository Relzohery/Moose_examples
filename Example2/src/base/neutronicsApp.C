#include "neutronicsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<neutronicsApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

neutronicsApp::neutronicsApp(InputParameters parameters) : MooseApp(parameters)
{
  neutronicsApp::registerAll(_factory, _action_factory, _syntax);
}

neutronicsApp::~neutronicsApp() {}

void
neutronicsApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"neutronicsApp"});
  Registry::registerActionsTo(af, {"neutronicsApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
neutronicsApp::registerApps()
{
  registerApp(neutronicsApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
neutronicsApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  neutronicsApp::registerAll(f, af, s);
}
extern "C" void
neutronicsApp__registerApps()
{
  neutronicsApp::registerApps();
}
