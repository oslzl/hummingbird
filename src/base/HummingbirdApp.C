#include "HummingbirdApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<HummingbirdApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

HummingbirdApp::HummingbirdApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  HummingbirdApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  HummingbirdApp::associateSyntax(_syntax, _action_factory);
}

HummingbirdApp::~HummingbirdApp()
{
}

// External entry point for dynamic application loading
extern "C" void HummingbirdApp__registerApps() { HummingbirdApp::registerApps(); }
void
HummingbirdApp::registerApps()
{
  registerApp(HummingbirdApp);
}

// External entry point for dynamic object registration
extern "C" void HummingbirdApp__registerObjects(Factory & factory) { HummingbirdApp::registerObjects(factory); }
void
HummingbirdApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void HummingbirdApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { HummingbirdApp::associateSyntax(syntax, action_factory); }
void
HummingbirdApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
