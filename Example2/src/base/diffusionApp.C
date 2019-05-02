#include "diffusionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<diffusionApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

diffusionApp::diffusionApp(InputParameters parameters) : MooseApp(parameters)
{
  diffusionApp::registerAll(_factory, _action_factory, _syntax);
}

diffusionApp::~diffusionApp() {}

void
diffusionApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"diffusionApp"});
  Registry::registerActionsTo(af, {"diffusionApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
diffusionApp::registerApps()
{
  registerApp(diffusionApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
diffusionApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  diffusionApp::registerAll(f, af, s);
}
extern "C" void
diffusionApp__registerApps()
{
  diffusionApp::registerApps();
}
