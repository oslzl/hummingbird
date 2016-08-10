#pragma once

#include "Kernel.h"

class TestKernel : public Kernel
{
public:
	TestKernel(const InputParameters & parameters);
	virtual ~TestKernel(){};

	virtual Real computeQpResidual();


protected:
	int _a;
};


template<>
InputParameters validParams<TestKernel>();
