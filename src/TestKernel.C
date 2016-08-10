
#include "TestKernel.h"

template<>
InputParameters validParams<TestKernel>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<int>("value", 0, "value值");
  return params;
}


TestKernel::TestKernel(const InputParameters & parameters) :
    Kernel(parameters),
	_a(getParam<int>("value"))
{
}

TestKernel::~TestKernel()
{
}

Real TestKernel::computeQpResidual()
{
	Real fu=_u[_qp]*_u[_qp]/2;
	RealVectorValue f(fu, 0 ,0);
	return -f*_grad_test[_i][_qp];
}



