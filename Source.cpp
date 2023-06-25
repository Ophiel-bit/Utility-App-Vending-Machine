#include <iostream>
#include <string>
#include <ios>
#include <limits>
using namespace std;

string drinks[] = { "Coca cola" , "Diet Coke" , "Coke Zero" , "Pepsi  Orig" , "Pepsi  Diet" , "Pepsi  Zero" , "Still Water" , "Lime  Water" , "Still Water" , "Monster  Energy" , "Monster  Juiced" , "Rockstar Juiced" };
double price[] = { 1.59 , 1.45 , 1.45 , 1.45 , 1.12 , 1.18 , 0.45 , 0.55 , 0.45 , 1.53 , 1.15 , 0.99 };
//these are they arrays for the contents of the vending machine which are global as they are used in multiple functions


void table() {
	char abcd[] = { 'A' , 'B' , 'C' , 'D' };
	string groups[] = { "Coca Colas" , "Pepsis" , "Waters" , "Energy drinks" };
	int y = 0;
	int dNumber = 0; //this is used to select the number of the drink
	int cNum = 1; // this is th ecode number
	int DrinksSize = (sizeof(drinks) / sizeof(drinks[0])) / 3; //this calculates how many rows of drinks there are in the machine
	for (int i = 0; i < DrinksSize; i++) { //for loop that iterates as to print out each of the rows
		int a = drinks[dNumber].length(); //this calculates the length of each drink
		int b = 19 - a; //19 is the longest length of drink, and then minus the length of the drink
		int c = b / 2; //this is the number of ~ required between each drink
		string d = "~";
		int x = 0;
		for (x; x < (c - 1); x++) {
			d = d + "~"; //this iterates creating the right number of ~ for each side
		}
		cout << " ------------------- ------------------- ------------------- \n"; //top of the table
		cout << "| " << groups[y] << endl; //changes the group name for each row 
		cout << " ------------------- ------------------- ------------------- \n"; //top of the table
		cout << "|" << d << drinks[dNumber] << d << "|" << d << drinks[dNumber + 1] << d << "|" << d << drinks[dNumber + 2] << d << "|\n";
		//the drinks, using dNumber to get the required drink
		cout << "|~~~~~~~~" << price[dNumber] << "~~~~~~~|~~~~~~~~" << price[dNumber + 1] << "~~~~~~~|~~~~~~~~" << price[dNumber + 2] << "~~~~~~~|\n";
		//same as above but with the price array
		cout << " ------------------- ------------------- ------------------- \n";
		cout << "|~~~~~~~~" << abcd[y] << " " << cNum << "~~~~~~~~|~~~~~~~~" << abcd[y]<< " " << cNum + 1 << "~~~~~~~~|~~~~~~~~"<< abcd[y]<< " " << cNum + 2 << "~~~~~~~~|\n";
		//this is the machine code that user needs to get the right drink
		dNumber = dNumber + (DrinksSize - 1); //this adds 3 to the dnumber by the end of each iteration as there's three drinks in a row
		y++;
	}
	cout << " ------------------- ------------------- ------------------- \n"; //bottom of the table
}

int letCheck(char a) { //takes the input from the main
	bool letterValid = false;
	do{
		switch (a) { //if input is any of the following then valid
		case 'A':
		case 'a':
		case 'B':
		case 'b':
		case 'C':
		case 'c':
		case 'D':
		case 'd':
			letterValid = true;
			break;
		default: //if not invalid
			cout << "Invalid input" << endl;
			cin.clear(); //clears the cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores the cin and means it won't infinitely output if a letter is typed in
			cout << "Input the letter of the drink's code" << endl;
			cin >> a;
		}
	} while (letterValid != true);
	return 0;
}

int moneyInput(double b){ //takes the money input from the main
	bool moneyValid = false;
	do {
		if (b > 0 && b < 10) { //if the input is between 0 and under 10
			cout << "Credit " << b << endl; //outputs how much credit you have input
			moneyValid = true; //means money input is valid
		}
		else if (b == 10) {
			table(); //outputs the table again
		}
		else {
			cout << "Enter money, limit of under " << char(156) << "10" << endl; //asks user to input, as ascii doesn't like £ sign
			//so have to use the char 
			cout << "Press '10' to see the display again" << endl;
			cin.clear(); //clears the cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //gets rid of the cin input, means no infinite loop if letter entered
		}
	} while (moneyValid != true);
	return 0;
}

int sMoneyInput(double x, double y) { //takes the original money input and the second one from main
	bool moneyValid = false;
	do{
		if (x > 0 && x < 10) { //if the input is between 0 and under 10
			cout << "Credit " << x << " added" << endl; //outputs how much credit you have input
			moneyValid = true; //means money input is valid
			y = y + x; //money = money plus the second input
			cout << "You now have " << y << " in credit" << endl; //outputs the total credit user has
		}
		else if (x == 10) {
			table();
		}
		else {
			cout << "Enter money, limit of under " << char(156) << "10" << endl; //asks user to input, as ascii doesn't like £ sign
				//so have to use the char 
			cout << "Press '10' to see the display again" << endl;
			cin.clear(); //clears the cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //gets rid of the cin input, means no infinite loop if letter entered
		}
	} while (moneyValid != true); //while loop as long as have enough attempts left and money isn't valid

	return 0;
}

int main() {
	table();
	bool numValid = false;
	int num = 0;
	char let;
	int code = 0;
	int sCode = 0;
	double totalPrice = 0;
	bool enough = false;
	double change = 0;
	double money = 0;
	double sMoney = 0;
	int totalPriceHun = 0;
	bool moneyValid = false;
	char ans;
	char sAns;
	char tAns;
	bool start = false;
	bool moreD = false;
	bool again = false;
	bool more = false;
	bool ansValid = false;
	bool sAnsValid = false;
	cout << "Input the letter of the drink's code" << endl;
	cin >> let; //inputs the code letter
	letCheck(let);
	if (let == 'A' || let == 'a') {
		code = 0;
	}
	if (let == 'B' || let == 'b') {
		code = 3;
	}
	if (let == 'C' || let == 'c') {
		code = 6;
	}
	if (let == 'D' || let == 'd') {
		code = 9;
	} //adds number in the 3 times tables to the code depending in the letter so will correspond to the array
	do { //while the number isn't valid
		cout << "Input the number of the drink's code" << endl;
		cin >> num; //number from code
		if (num > 0 && num < 4) { //if input is between 1 and 3 then number input is valid
			numValid = true;
		}
		else {
			cout << "Invalid input" << endl;
			cin.clear(); //if not then clears the cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores it up to the max range and has a new line
		}
	} while (numValid != true);
	code = code + (num - 1); //adds the number from the input but minuses one due to arrays starting from 0
	cout << "Drink: " << drinks[code] << endl; //outputs the drink
	cout << "Price: " << price[sCode] << endl; //outputs the price
	totalPrice = totalPrice + price[code]; //the total price is the total price plus the number from the price array using the code number
	cout << "total price: " << char(156) << totalPrice << endl; //outputs the total price
	do {
		cout << "Would you like anything else? Y/N" << endl;
		do {
			cin >> ans; //user inputs if they want to input more
			switch (ans) {
			case 'Y':
			case 'y': //if the answer is y (only takes one letter)
				again = true;
				ansValid = true; //then the more is yes and the ans is valid
				break;
			case 'N':
			case 'n': //if answer is no
				again = false;
				ansValid = true; //then more no but answer yes
				moreD = true; //ends the loop of more 
				break;
			default:
				cout << "Invalid input" << endl;
				break;
			}
		} while (ansValid != true);
		if (again) {
			cout << "Input the letter of the drink's code" << endl;
			cin >> let; //inputs the code letter
			letCheck(let);
			if (let == 'A' || let == 'a') {
				sCode = 0;
			}
			if (let == 'B' || let == 'b') {
				sCode = 3;
			}
			if (let == 'C' || let == 'c') {
				sCode = 6;
			}
			if (let == 'D' || let == 'd') {
				sCode = 9;
			}//adds number in the 3 times tables to the second code depending in the letter so will correspond to the array
			do { //while the number isn't valid
				cout << "Input the number of the drink's code" << endl;
				cin >> num; //number from code
				if (num > 0 && num < 4) { //if input is between 1 and 3 then number input is valid
					numValid = true;
					sCode = sCode + (num - 1);
					cout << "Drink: " << drinks[sCode] << endl;
					cout << "Price: " << price[sCode] << endl;
					totalPrice = totalPrice + price[sCode]; //the total price is the total price plus the number from the price array using the code number
				}
				else {
					cout << "Invalid input" << endl;
					cin.clear(); //if not then clears the cin
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores it up to the max range and has a new line
				}
			} while (numValid != true);
			cout << "total price: " << char(156) << totalPrice << endl;
		}
	}while (moreD != true); //loops the more drinks until user says no
	cout << "Enter money, limit of under " << char(156) << "10" << endl; //asks user to input, as ascii doesn't like £ sign
	//so have to use the char 
	cout << "Press '10' to see the display again" << endl;
	cin >> money; //user input
	totalPriceHun = money * 100; //assigns total price hun to the money * 100 and stores as an int so if too many decimals are input it gets cut off
	money = totalPriceHun; //money is assigned the same
	money = money / 100; //divides it by 100 so it's the same but without the extra decimals if input
	moneyInput(money); //runs the money input function
	do {
		if (totalPrice <= money) { //if the total price is less than the money input then valid
			enough = true;//no need to add extra money so breaks the loop
		}
		else {
			do {
				cout << "Not enough credit" << endl;
				cout << "Input more credit? Y/N" << endl;
				cin >> sAns; //user inputs if they want to input more
				switch (sAns) {
				case 'Y':
				case 'y': //if the answer is y (only takes one letter)
					more = true;
					sAnsValid = true; //then the more is yes and the ans is valid
					break;
				case 'N':
				case 'n': //if answer is no
					sAnsValid = true; //then more no but answer yes
					cout << "Would you like to try again from the start? Y/N" << endl;		
					cin >> tAns; //third answer 
					do {
						if (tAns == 'Y' || tAns == 'y') {
							main(); //if they do then runs the main function from the start
							start = true;//breaks the loop
						}
						else if (tAns == 'N' || tAns == 'n') {
							cout << "Insufficient funds, transaction cancelled" << endl; //then not enough funds so end
							return 0; //if doesn't want to restart then ends the program
							start = true;
						}
						else {
							cout << "Invalid input" << endl;
						}
					} while (start != true);
					break;
					default:
					cout << "Invalid input" << endl;
					break;
				}
			} while (sAnsValid != true);
			if (more) {
				cout << "Enter money, limit of under " << char(156) << "10" << endl; //asks user to input, as ascii doesn't like £ sign
				//so have to use the char 
				cout << "Press '10' to see the display again" << endl;
				cin >> sMoney; //user input
				totalPriceHun = sMoney * 100;
				sMoney = totalPriceHun;
				sMoney = sMoney / 100; //converts the money into max 2 decimals again
				sMoneyInput(sMoney, money); //runs the second money input function
				money = money + sMoney; //adds all the money together
			}
		}
	} while (enough != true); //while there isn't enough
	change = money - totalPrice; //change is the price - money
	cout << "The total price is " << char(156) << totalPrice << " with " << char(156) << change << " change" << endl; //outputs the price and change
	return 0;
}