#include <iostream>
#include "PowerTeam.h"
#include "SecondClass.h"
#include <vector>

using namespace std;

PowerTeam::PowerTeam(){}
PowerTeam::PowerTeam(double num){doubleNumber = num;}
void PowerTeam::setNum(double num){doubleNumber = num;}
double PowerTeam::getNum(){return doubleNumber;}

void loop(vector<PowerTeam> &batObjects, double amountToSub){
	double FIVE = 5;
	double getTotal = 0;

	for (int i = 0; i < batObjects.size(); i++){
		getTotal += batObjects.at(i).getNum();
	}

	if (amountToSub > getTotal){
		cout << "Trying to pull too many volts from battery" << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	// do math
	for (int i = 0; i < batObjects.size(); i++)
	{
		if (amountToSub > FIVE){
			batObjects.at(i).setNum(0);
			amountToSub = amountToSub - FIVE;
		}
		else if (amountToSub <= FIVE && batObjects.at(i).getNum() - amountToSub >= 0){
			batObjects.at(i).setNum(FIVE - amountToSub);
			amountToSub = amountToSub - (FIVE - amountToSub);
			break;
		}
	}
}


int main(int argc, char** argv){
	// variables
	double num = 5.00;
	PowerTeam power(num);
	SecondClass second(power.getNum());
	vector <PowerTeam> vectorBattery;

	// change the to amount you want to pull from battery
	double amountToSub = 20.00;
	cout << "We are pulling " << amountToSub << " volts from the battery" << endl;

	// populate vector with 5V
	for (int i = 0; i < 4; i++){
		vectorBattery.push_back(power);
	}

	// print original vector
	cout << "Numbers before: " << endl;
	vector<PowerTeam>stringVector;
	for (vector<PowerTeam>::iterator i = vectorBattery.begin(); i != vectorBattery.end(); ++i){
		cout << i->getNum() << endl;
	}

	// do math
	loop(vectorBattery, amountToSub);

	// reprint
	cout << "Numbers after: " << endl;
	for (vector<PowerTeam>::iterator i = vectorBattery.begin(); i != vectorBattery.end(); ++i){
		cout << i->getNum() << endl;
	}

	system("pause");
	return 0;
}