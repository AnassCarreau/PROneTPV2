#pragma once

#include "RandomNumberGenerator.h"
#include "checkML.h"

/*
 *
 */
class SRandBasedGenerator: public RandomNumberGenerator {
public:
	SRandBasedGenerator();
	SRandBasedGenerator(unsigned seed);
	virtual ~SRandBasedGenerator();
	void init() override;
	int nextInt() override;
	int nextInt(int low, int high) override;
private:
	unsigned seed_;
};

