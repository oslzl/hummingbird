#ifndef HUMMINGBIRDAPP_H
#define HUMMINGBIRDAPP_H

#include "MooseApp.h"

class HummingbirdApp;

template<>
InputParameters validParams<HummingbirdApp>();

class HummingbirdApp : public MooseApp
{
public:
  HummingbirdApp(InputParameters parameters);
  virtual ~HummingbirdApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* HUMMINGBIRDAPP_H */
