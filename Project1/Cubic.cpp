#include "Cubic.h"
#include <cmath> //pow

const int CUBIC_SIZE = 4; //Global constant for iterating

// Constructor for creating a cubic poulated by 0s
Cubic::Cubic() {
	*this->coefficientsArray = { 0 };
	for (int i = 0; i < CUBIC_SIZE; i++) {
		coefficientsArray[i] = 0;
	}
}

// Constructor for creating a cubic with user specified coefficients 
Cubic::Cubic(int inputArray[CUBIC_SIZE]) {
	*this->coefficientsArray = { 0 };
	for (int i = 0; i < CUBIC_SIZE; i++) {
		coefficientsArray[i] = inputArray[i];
	}
}

// Returns the coefficient at a given power within the cubic
int Cubic::getCoefficient(int power) const {
	if ((power < 0) || (power > 3)) {
		return(-1); // error handeling 
	}
	return(coefficientsArray[power]);
}

// Computes the value of the Cubic when provided with a value for x
double Cubic::computeCubicValue(double xValue) const {
	double value = 0;
	for (int i = 0; i < CUBIC_SIZE; i++) {
		value += (getCoefficient(i) * pow(xValue, i));
	}
	return(value);
}

// Overloading operator+ so cubics can be added togther
const Cubic Cubic::operator+(Cubic cubic) const {
	int plusArray[CUBIC_SIZE];
	for (int i = 0; i < CUBIC_SIZE; i++) {
		plusArray[i] = (coefficientsArray[i] + cubic.getCoefficient(i));
	}
	return Cubic(plusArray);
}

// Overlaoding opeator- so cubics can be subtrated for one another
const Cubic Cubic::operator-(Cubic cubic) const {
	int minusArray[CUBIC_SIZE];
	for (int i = 0; i < CUBIC_SIZE; i++) {
		minusArray[i] = (coefficientsArray[i] - cubic.getCoefficient(i));
	}
	return Cubic(minusArray);
}

// Allows the cubic to be multiplied by a constant 
const Cubic Cubic::operator*(int multValue) const {
	int multArray[CUBIC_SIZE];
	for (int i = 0; i < CUBIC_SIZE; i++) {
		multArray[i] = (coefficientsArray[i] * multValue);
	}
	return Cubic(multArray);
}

// Allows cubics to be updated adding cubics togther 
Cubic& Cubic::operator+=(const Cubic& cubic) {
	for (int i = 0; i < CUBIC_SIZE; i++) {
		this->coefficientsArray[i] += cubic.getCoefficient(i);
	}
	return *this;
}

// Allows cubics to be updated via subtracting cubics
Cubic& Cubic::operator-=(const Cubic& cubic) {
	for (int i = 0; i < CUBIC_SIZE; i++) {
		this->coefficientsArray[i] -= cubic.getCoefficient(i);
	}
	return *this;
}

// Relational Operators for testing equality of cubics (==)
bool Cubic::operator==(Cubic cubic) {
	return ((coefficientsArray[0] == cubic.getCoefficient(0)) && (coefficientsArray[1] == cubic.getCoefficient(1))
		&& (coefficientsArray[2] == cubic.getCoefficient(2)) && (coefficientsArray[3] == cubic.getCoefficient(3)));
}

// Relational Operators for testing equality of cubics (!=)
bool Cubic::operator!=(Cubic cubic) {
	return((coefficientsArray[0] != cubic.getCoefficient(0)) || (coefficientsArray[1] != cubic.getCoefficient(1))
		|| (coefficientsArray[2] != cubic.getCoefficient(2)) || (coefficientsArray[3] != cubic.getCoefficient(3)));
}

// Implemntation of input opertor (>>) allows for cubics to be created
std::istream& operator>>(std::istream& inStream, Cubic& cubic) {
	int createCubicArray[CUBIC_SIZE];
	for (int i = 0; i < CUBIC_SIZE; i++) {
		inStream >> createCubicArray[i];
	}
	cubic = Cubic(createCubicArray);
	return inStream;
}

// Implemntation of output opertor (<<) allows cubics to be represented on screen
std::ostream& operator<<(std::ostream& outStream, const Cubic& cubic) {
	for (int i = 3; i >= 0; i--) {
		if (i > 0) {
			outStream << cubic.getCoefficient(i) << "x^" << (i) << '+';
		}
		else {
			outStream << cubic.getCoefficient(i);
		}
	}
	return outStream;
}