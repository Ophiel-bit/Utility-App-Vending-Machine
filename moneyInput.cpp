#include <iostream>
#include <string>
#include <ios>
#include <limits>
using namespace std;

double moneyInput() {
	bool moneyValid = false;
	string sMoney; //needs to be a string so can get the length
	int attempt = 5;
	double money = 0;
	do {
		cout << "Enter money, limit of under " << char(156) << "10" << endl; //asks user to input, as ascii doesn't like £ sign
		//so have to use the char 
		cin >> sMoney; //user input
		double money = stod(sMoney); //uses the stod function which converts string into double
		if (money > 0 && money < 10) { //if the input is between 0 and under 10
			if (sMoney.length() < 4) { //since there should only be three numbers so checks if length is under 4
				cout << "Credit " << char(156) << money << endl; //outputs how much credit you have input
				moneyValid = true; //means money input is valid
			}
			else {
				cout << "Invalid length of number, please re-enter" << endl; //else it's invalid
				attempt = attempt - 1;
				cout << "Invalid input \nYou now have " << attempt << " attempts left" << endl; //minuses an attempt
			}
		}
		else {
			attempt = attempt - 1; 
			cout << "Invalid input \nYou now have " << attempt << " attempts left" << endl; //gets rid of an attempt
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //gets rid of the cin input, means no infinite loop if letter entered
		}
	} while (moneyValid != true && attempt > 0); //while loop as long as have enough attempts left and money isn't valid
	return money;//returns how much money has been input 
}