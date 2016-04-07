#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


using namespace std;

class PowerTeam
{
public:
	PowerTeam();
	PowerTeam(double num);
	void setNum(double num);
	double getNum();
	void loop(vector<PowerTeam> &batObjects, double amountToSub);

private:
	double doubleNumber;
};