#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

class SecondClass
{
public:
	SecondClass();
	SecondClass(double num);
	void printNum(double num);

private:
	double secondDouble;
};