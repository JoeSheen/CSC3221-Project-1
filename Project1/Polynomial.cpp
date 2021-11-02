#include "Polynomial.h"
#include <cmath>

//Defualt constructor crates a polynomial of 0
Polynomial::Polynomial() {
	size = 0;
	polynomialPtr = new int[0];
}

//Contructor that constructes polynomial based on inputsize and array provided
Polynomial::Polynomial(int inputSize, int inputCoefficients[]) {
	size = inputSize;
	polynomialPtr = new int[inputSize];
	for (int i = 0; i < inputSize; i++) {
		polynomialPtr[i] = inputCoefficients[i];
	}
}

//copy constructor (calls private copy function)
Polynomial::Polynomial(const Polynomial& copyPolynomial) {
	this->copy(copyPolynomial);
}

//Destructor 
Polynomial::~Polynomial() {
	delete[] polynomialPtr;
	polynomialPtr = nullptr;
}

// Assignemnt operator
Polynomial& Polynomial::operator=(const Polynomial& copyPolynomial) {
	if (this == &copyPolynomial) {
		return *this;
	}
	if (size) {
		delete[] polynomialPtr;
	}
	this->copy(copyPolynomial);
	return *this;
}

//Function for getting the coefficient at a given degree within the polynomial
int Polynomial::getCoefficient(int degree) const {
	if ((degree > size) || (degree < 0)) {
		return -1; //error
	}
	else {
		return polynomialPtr[degree];
	}
}

// Function that computes the value of the polynomial when provided with an x value
double Polynomial::computePolynomialValue(double xValue) const {
	double value = 0;
	for (int i = 0; i < this->size; i++) {
		value += (this->getCoefficient(i) * pow(xValue, i));
	}
	return value;
}

//Implementation of the + operator so polynomails can be added
const Polynomial Polynomial::operator+(Polynomial& polynomial) {
	if (this->size == polynomial.size) {
		//handles same size polynomials
		int* addArray = new int[size];
		for (int i = 0; i < size; i++) {
			addArray[i] = this->getCoefficient(i) + polynomial.getCoefficient(i);
		}
		return Polynomial(size, addArray);
	}
	else if (this->size > polynomial.size) {
		//handles addition when this has a greater size
		int* addArray = new int[size];
		for (int i = 0; i < size; i++) {
			addArray[i] = this->getCoefficient(i);
		}
		for (int i = 0; i < polynomial.size; i++) {
			addArray[i] += polynomial.getCoefficient(i);
		}
		return Polynomial(this->size, addArray);
	}
	else {
		//handles addition when rhs (polynomial) has greater size
		int* addArray = new int[polynomial.size];
		for (int i = 0; i < polynomial.size; i++) {
			addArray[i] = polynomial.getCoefficient(i);
		}
		for (int i = 0; i < this->size; i++) {
			addArray[i] += this->getCoefficient(i);
		}
		return Polynomial(polynomial.size, addArray);
	}
}


// Function for subtracting polynomials
const Polynomial Polynomial::operator-(Polynomial& polynomial) {
	if (this->size == polynomial.size) {
		//Handles subtraction of polynomials of the same size
		int* subArray = new int[size];
		for (int i = 0; i < size; i++) {
			subArray[i] = this->getCoefficient(i) - polynomial.getCoefficient(i);
		}
		return Polynomial(size, subArray);
	}
	else if (this->size > polynomial.size) {
		//Handles subtraction when this has a greater size
		int* subArray = new int[size];
		for (int i = 0; i < this->size; i++) {
			subArray[i] = this->getCoefficient(i);
		}
		for (int i = 0; i < polynomial.size; i++) {
			subArray[i] -= polynomial.getCoefficient(i);
		}
		return Polynomial(size, subArray);
	}
	else {
		//handles subtraction when rhs (polynomial) is longer 
		int* subArray = new int[polynomial.size];
		for (int i = 0; i < polynomial.size; i++) {
			subArray[i] = polynomial.getCoefficient(i);
		}
		for (int i = 0; i < this->size; i++) {
			subArray[i] -= this->getCoefficient(i);
		}
		return Polynomial(polynomial.size, subArray);
	}
}

// Function for multiplying polynomials
const Polynomial Polynomial::operator*(Polynomial& polynomial) {
	int multSize = this->size + polynomial.size;
	int* multArray = new int[multSize];
	for (int i = 0; i < multSize; i++) {
		multArray[i] = 0;
	}
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < polynomial.size; j++) {
			multArray[i + j] += (this->getCoefficient(i) * polynomial.getCoefficient(j)); //generates false warning
		}
	}
	return Polynomial(multSize, multArray);
}

// Function for multiplying polynomial coefficients by a constant value (multValue)
const Polynomial Polynomial::operator*(int multValue) {
	int* multArray = new int[size];
	for (int i = 0; i < size; i++) {
		multArray[i] = (this->getCoefficient(i) * multValue);
	}
	return Polynomial(size, multArray);
}

// Overloding a polynomial via adddition  
Polynomial& Polynomial::operator+=(const Polynomial& polynomial) {
	// Handels equal sizes 
	if (this->size == polynomial.size) {
		for (int i = 0; i < size; i++) {
			this->polynomialPtr[i] += polynomial.getCoefficient(i);
		}
		return *this;
	}
	// Handels += when this is of greater size
	else if (this->size > polynomial.size) {
		for (int i = 0; i < polynomial.size; i++) {
			this->polynomialPtr[i] += polynomial.getCoefficient(i);
		}
		return *this;
	}
	else {
		// Handles += when this is of smaller size
		Polynomial copyPolynomial(size, polynomialPtr);
		this->size = polynomial.size;
		for (int i = 0; i < size; i++) {
			this->polynomialPtr[i] = polynomial.getCoefficient(i);
		}
		for (int i = 0; i < copyPolynomial.size; i++) {
			this->polynomialPtr[i] += copyPolynomial.getCoefficient(i);
		}
		return *this;
	}
}

// Overloding a polynomial via subtraction 
Polynomial& Polynomial::operator-=(const Polynomial& polynomial) {
	//Handles -= when both polynomails are of equal size
	if (this->size == polynomial.size) {
		for (int i = 0; i < size; i++) {
			this->polynomialPtr[i] -= polynomial.getCoefficient(i);
		}
		return *this;
	}
	// Handles -= when this is of greater size
	else if (this->size > polynomial.size) {
		for (int i = 0; i < polynomial.size; i++) {
			this->polynomialPtr[i] -= polynomial.getCoefficient(i);
		}
		return *this;
	}
	// Handles -= when this is of smaller size
	else {
		Polynomial copyPolynomial(size, polynomialPtr);
		this->size = polynomial.size;
		for (int i = 0; i < size; i++) {
			this->polynomialPtr[i] = polynomial.getCoefficient(i);
		}
		for (int i = 0; i < copyPolynomial.size; i++) {
			this->polynomialPtr[i] -= copyPolynomial.getCoefficient(i);
		}
		return *this;
	}
}

// Overloding a polynomial via multiplication
Polynomial& Polynomial::operator*=(const Polynomial& polynomial) {
	Polynomial copyPolynomial(size, polynomialPtr);
	this->size = (this->size + polynomial.size);
	for (int i = 0; i < this->size; i++) {
		this->polynomialPtr[i] = 0;
	}
	for (int i = 0; i < copyPolynomial.size; i++) {
		for (int j = 0; j < polynomial.size; j++) {
			this->polynomialPtr[i + j] += (copyPolynomial.getCoefficient(i) * polynomial.getCoefficient(j));
		}
	}
	return *this;
}


// allows all coefficients of a polynomial to be multiplied by a constant value (store in the same variable)
Polynomial& Polynomial::operator*=(const int& multValue) {
	for (int i = 0; i < this->size; i++) {
		this->polynomialPtr[i] *= multValue;
	}
	return *this;
}


// Function implementation for eqaul (comapres two polynomails to see if they are equal) 
bool Polynomial::operator==(Polynomial polynomial) {
	if (this->size != polynomial.size) {
		return false;
	}
	else {
		for (int i = 0; i < this->size; i++) {
			if (this->getCoefficient(i) != polynomial.getCoefficient(i)) {
				return false;
				break;
			}
		}
		return true;
	}
}

// Function implementation for not eqaul (comapres two polynomails to see if they are not equal)
bool Polynomial::operator!=(Polynomial polynomial) {
	if (this->size != polynomial.size) {
		return true;
	}
	else {
		for (int i = 0; i < this->size; i++) {
			if (this->getCoefficient(i) != polynomial.getCoefficient(i)) {
				return true;
				break;
			}
		}
		return false;
	}
}

//private copy function
void Polynomial::copy(const Polynomial& copyPolynomial) {
	size = copyPolynomial.size;
	polynomialPtr = new int[size];
	for (int i = 0; i < size; i++) {
		polynomialPtr[i] = copyPolynomial.getCoefficient(i);
	}
}

// Allows the user to create a polynomial via input from keyboard
std::istream& operator>>(std::istream& inStream, Polynomial& polynomial) {
	int createPolynomialSize = polynomial.size;
	int* createArray = new int[createPolynomialSize];
	for (int i = 0; i < createPolynomialSize; i++) {
		inStream >> createArray[i];
	}
	polynomial = Polynomial(createPolynomialSize, createArray);
	delete[] createArray;
	createArray = NULL;
	return inStream;
}

// Outputs Polynomails to console in standrard format (e.g. ...x^..)
std::ostream& operator<<(std::ostream& outStream, const Polynomial& polynomial) {
	//int displaySize = (polynomial.size() - 1);
	int displaySize = (polynomial.size - 1);
	for (int i = displaySize; i >= 0; i--) {
		if (polynomial.getCoefficient(i) != 0) {
			if (i > 0) {
				outStream << polynomial.getCoefficient(i) << "x^" << i << "+";
			}
			else {
				outStream << polynomial.getCoefficient(i); //outputs last coefficient
			}
		}
	}
	return outStream;
}