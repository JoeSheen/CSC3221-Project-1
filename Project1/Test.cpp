
#include <iostream>
#include "Cubic.h"
#include "Polynomial.h"

// Function for testing Cubic
void cubicTest() {
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "	CUBIC TESTING" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Testing output of cubic:" << std::endl;
	int arr[4] = { 9,7,13,12 };
	Cubic c(arr);
	std::cout << "	C: " << c << std::endl; //displays the whole cubic
	for (int i = 3; i >= 0; i--) { //displays the indvidual coeffcients of cubic c1
		std::cout << "	C(" << i << "): " << c.getCoefficient(i) << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Computing the value of cubic (x=7):" << std::endl;
	std::cout << "	12(7^3)+13(7^2)+7(7^1)+9" << std::endl;
	std::cout << "	Cubic value: " << c.computeCubicValue(7) << std::endl; //should equal: 12(7^3)+13(7^2)+7(7^1)+9=4811
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Arithmetic Operators Testing:" << std::endl;
	int arr2[4] = { 1,3,-3,-2 };
	Cubic c2(arr2);
	std::cout << "	C2: " << c2 << std::endl; //displays the whole of cubic c2
	Cubic c3 = c + c2;
	std::cout << "	C+C2=C3: " << c3 << std::endl;//adds c to c2, c3 should be 10x^3+10x^2+10x^1+10
	Cubic c4 = c2 - c;
	std::cout << "	C2-C=C4: " << c4 << std::endl; //subs c from c2, c4 should be -14x^3+-16x^2+-4x^1+-8
	Cubic c5 = c * 2;
	std::cout << "	C*2=C5: " << c5 << std::endl; //multiplies c by 2, should equal 24x^3+26x^2+14x^1+18
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Update Operators Testing:" << std::endl;
	int arr3[4] = { 6,5,3,2 };
	Cubic c6(arr3);
	std::cout << "	C6: " << c6 << std::endl;//intalizes Cubic c6 to have values 2X^3+3X^2+5x+6
	c6 += c5;
	std::cout << "	C6+=C5: " << c6 << std::endl; //outputs c6+=c5 and equals 26x^3+29x^2+19x^1+24
	c6 -= c5;
	std::cout << "	C6-=C5: " << c6 << std::endl; //Updates values in c6 to equal 2X^3+3X^2+5x+6 (c6 -= c5)
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Relational Operators Testing:" << std::endl;
	Cubic c7(arr); //intialise values of cubic c7 to be equal to c
	std::cout << "	C: " << c << std::endl;
	std::cout << "	C7: " << c7 << std::endl;
	std::cout << "	C3: " << c3 << std::endl;
	std::cout << "Testing(==):";
	if (c7 == c) {
		std::cout << " Correct C and C7 are equal!" << std::endl; //should show to console
	}
	else {
		std::cout << "	Error! Implmentation is incorrect" << std::endl; //should not be seen on console
	}
	std::cout << "Testing(!=):";
	if (c7 != c3) {
		std::cout << " Correct C3 and C7 are not equal!" << std::endl; //should show to console
	}
	else {
		std::cout << "	Error! Implmentation is incorrect" << std::endl; //should not be seen on console
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Input Testing (>>):" << std::endl;
	int arr4[4]; //array for storing user input
	for (int i = 0; i < 4; i++) {
		std::cout << " Enter coefficient (x^" << i << "): ";
		std::cin >> arr4[i]; //allowes user to create cubic, thus provie >> works
	}
	
	Cubic c9(arr4); //takes in values from user
	//std::cin >> c9; //allowes user to create cubic, thus provie >> works
	
	std::cout << "	C9: " << c9 << std::endl; //displays the whole cubic
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "	END OF CUBIC TESTING" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
}

// Function for testing Polynomial
void polynomialTest() {
	std::cout << "	TESTING POLYNOMIAL" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Testing output of polynomail:" << std::endl;
	int arr5[] = { 4,2,7,5,9,2,11 };
	Polynomial* p = new Polynomial(7, arr5);
	std::cout << "	P: " << (*p) << std::endl; //displays polynomial p in polynomial form to console
	for (int i = 6; i >= 0; i--) {
		std::cout << "	P(" << i << "): " << p->getCoefficient(i) << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Computing the value of Polynomial (x=2):" << std::endl;
	std::cout << "	11(2^6)+2(2^5)+9(2^4)+5(2^3)+7(2^2)+2(2^1)+4" << std::endl;
	std::cout << "	Polynomial value: " << p->computePolynomialValue(2) << std::endl; //should equal: 2(2^5)+9(2^4)+5(2^3)+7(2^2)+2(2^1)+4=988
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Arithmetic Operators Testing:" << std::endl;
	int arr6[] = { 3,5,7,8 };
	Polynomial* p2 = new Polynomial(4, arr6);
	std::cout << "	P2: " << (*p2) << std::endl; //outputs testing polys (P2)
	int arr7[] = { 6,4,2,1 };
	Polynomial* p3 = new Polynomial(4, arr7);
	std::cout << "	P3: " << (*p3) << std::endl; //outputs testing polys (P3)
	int arr8[] = { 7,9,2,4,6,7,1,7 };
	Polynomial* p4 = new Polynomial(7, arr8);
	std::cout << "	P4: " << (*p4) << std::endl; //outputs testing polys (P4)
	Polynomial p5 = (*p2) + (*p3);
	std::cout << "Addition:" << std::endl;
	std::cout << "	P2+P3=P5: " << p5 << std::endl; //adds P2+P3=P5 (9x^3+9x^2+9x^1+9)
	Polynomial p6 = (*p4) + (*p3);
	std::cout << "	P3+P4=P6: " << p6 << std::endl; //1x^6+7x^5+6x^4+5x^3+4x^2+13x^1+13
	Polynomial p7 = (*p3) + (*p4);
	std::cout << "	P3+P4=P7: " << p7 << std::endl; //1x^6+7x^5+6x^4+5x^3+4x^2+13x^1+13
	std::cout << "Subtraction:" << std::endl;
	Polynomial p8 = (*p2) - (*p3);
	std::cout << "	P2-P3=P8: " << p8 << std::endl; //7x^3+5x^2+1x^1+-3
	Polynomial p9 = (*p4) - (*p3);
	std::cout << "	P4-P3=P9: " << p9 << std::endl; //1x^6+7x^5+6x^4+3x^3+5x^1+1
	Polynomial p10 = (*p3) - (*p4);
	std::cout << "	P3-P4=P10: " << p10 << std::endl; //1x^6+7x^5+6x^4+3x^3+5x^1+1
	std::cout << "Multiplication:" << std::endl;
	Polynomial p11 = (*p2) * (*p3);
	std::cout << "	P2*P3=P11: " << p11 << std::endl; //8x^6+23x^5+51x^4+89x^3+68x^2+42x^1+18
	Polynomial p12 = (*p3) * 2;
	std::cout << "	P3*2=P12: " << p12 << std::endl; //2x^3+4x^2+8x^1+12
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Update Operators Testing:" << std::endl;
	*p2 += *p3;
	std::cout << "	P2+=P3: " << (*p2) << std::endl; //9x^3+9x^2+9x^1+9
	p5 -= *p3;
	std::cout << "	P5-=P3: " << p5 << std::endl; //8x^3+7x^2+5x^1+3
	(*p3) *= 3;
	std::cout << "	P3*=3: " << (*p3) << std::endl; //3x^3+6x^2+12x^1+18*/
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Relational Operators Testing:" << std::endl;
	std::cout << "Testing(==):"<<std::endl;
	if (p6 == p7) {
		std::cout << " Correct P6 and P7 are equal!" << std::endl; //should show to console
	}
	else {
		std::cout << "	Error! Implmentation is incorrect" << std::endl; //should not be seen on console
	}
	std::cout << "Testing(!=):";
	if (p7 != (*p)) {
		std::cout << " Correct P and P7 are not equal!" << std::endl; //should show to console
	}
	else {
		std::cout << "	Error! Implmentation is incorrect" << std::endl; //should not be seen on console
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Input Testing (>>):" << std::endl;
	int userSize; // stores a user speficeied degree for the polynomial
	std::cout << " Enter polynomial size (max degree+1): ";
	std::cin >> userSize;
	int* userArray = new int[userSize];
	for (int i = 0; i < userSize; i++) {
		std::cout << " Enter coefficient (x^" << i << "): ";
		std::cin >> userArray[i];
	}
	Polynomial p13(userSize, userArray);
	std::cout << "	P13: " << p13 << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "	END OF POLYNOMIAL TESTING" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	//deletes user input thar required dynamic memory
	delete[] userArray;
	userArray = NULL;
	delete p;
}

int main() {
	//Function Call for testing Cubic
	cubicTest();
	//Function Call for tetsing Polynomial
	polynomialTest();
}