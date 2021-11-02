#pragma once
#include <iostream>

class Cubic
{
public:
	// Constructor 
	Cubic();
	Cubic(int inputCoefficients[4]);

	// Member Functions
	int getCoefficient(int x) const;
	double computeCubicValue(double x) const;

	// Arithmetic Operators 
	const Cubic operator+(Cubic cubic) const;
	const Cubic operator-(Cubic cubic) const;
	const Cubic operator*(int x) const;

	// Update Operators
	Cubic& operator+=(const Cubic& cubic);
	Cubic& operator-=(const Cubic& cubic);

	// Relational Operators
	bool operator==(Cubic cubic);
	bool operator!=(Cubic cubic);

private:
	// Concrete Representation of Cubic
	int coefficientsArray[4];
};

std::istream& operator>>(std::istream& inStream, Cubic& cubic);
std::ostream& operator<<(std::ostream& outStream, const Cubic& cubic);
