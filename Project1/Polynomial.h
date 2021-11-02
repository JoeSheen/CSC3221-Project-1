#pragma once
#include <iostream>

class Polynomial
{
public:
	// Constructors
	Polynomial();
	Polynomial(int size, int inputCoefficients[]);
	Polynomial(const Polynomial& copyPolynomial); // Copy Constructor 

	// Destructor
	~Polynomial();

	// Assignment Operator
	Polynomial& operator=(const Polynomial& polynomial);

	// Member Functions 
	int getCoefficient(int x) const;
	double computePolynomialValue(double x) const;

	// Arithmetic Operators 
	const Polynomial operator+(Polynomial& polynomial);
	const Polynomial operator-(Polynomial& polynomial);
	const Polynomial operator*(Polynomial& polynomial);
	const Polynomial operator*(int multValue);

	// Update Operators
	Polynomial& operator+=(const Polynomial& polynomial);
	Polynomial& operator-=(const Polynomial& polynomial);
	Polynomial& operator*=(const Polynomial& polynomial);
	Polynomial& operator*=(const int& multValue);

	// Relational Operators
	bool operator==(Polynomial polynomial);
	bool operator!=(Polynomial polynomial);

	// Input/Output (freind so they gave access to private vraibles)
	friend std::istream& operator>>(std::istream& inStream, Polynomial& polynomial);
	friend std::ostream& operator<<(std::ostream& outStream, const Polynomial& polynomial);

private:
	//Private Copy Function 
	void copy(const Polynomial& copyPolynomial);

	// Concrete Representation of Polynomial
	int size;
	int* polynomialPtr;
};
