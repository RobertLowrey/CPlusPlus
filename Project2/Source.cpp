#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


void printDetails(int t_year, double t_yearEndBalance, double t_interestEarned) {
	cout << right <<  setw(4) << t_year
		<< setw(15) <<"$" << fixed << setprecision(2) << t_yearEndBalance 
		<< setw(15) << "$" << t_interestEarned << endl; // will print year, year end balance, and year end earned interest with left alignment using 15 characters
}


double calculateBalanceWithoutMonthlyDeposit(double t_initialDeposit, double t_interestRate, int t_numYears) {
	int months;
	int numYears = t_numYears;
	double initialDeposit = t_initialDeposit;
	double interestRate = t_interestRate;
	double monthlyInterest;
	double yearEndBalance = initialDeposit;
	double earnedInterest = 0;
	double monthlyDeposit = 0;
	double openningAmount = initialDeposit;
	double closingBalance = 0;

	cout << "\tBalance and Interest Without Additional Monthly Deposits" << endl;//display headers for balance and interest without montly deposits
	cout << "===============================================================================" << endl;
	cout << left << setw(10)<< "Year" // will align the text to the left a 10 character space
		 << left << setw(20) << "Year End Balance"  // will align to the left with 20 characters
		<< left << setw(10) << "Year End Earned Interest" << endl; // will align to the left with 20 characters
	cout << "-------------------------------------------------------------------------------" << endl;
	for (int i = 1; i <= numYears; i++) { // will loop for how many years are input
		months = 12;
		for (int j = 1; j <= months; j++) {
			monthlyInterest = (openningAmount + monthlyDeposit) * ((interestRate / 100) / 12); // interest rate formula for monthly interest
			openningAmount += monthlyDeposit + monthlyInterest;
			earnedInterest += monthlyInterest;
			yearEndBalance += monthlyInterest;
		}

		printDetails(i, yearEndBalance, earnedInterest); // calls the print details function
		cout << endl;
	}
	return yearEndBalance;
}

double balanceWithMonthlyDeposit(double t_initialDeposit, double t_monthlyDeposit, double t_interestRate, int t_numYears) {
	int months;
	int numYears = t_numYears;
	double initialDeposit = t_initialDeposit;
	double interestRate = t_interestRate;
	double monthlyDeposit = t_monthlyDeposit;
	double monthlyInterest;
	double earnedInterest = 0;
	double openningAmount = initialDeposit;
	double closingBalance = 0;

	cout << "\tBalance and Interest With Additional Monthly Deposits" << endl;//display headers for balance and interest without montly deposits
	cout << "===============================================================================" << endl;
	cout << left << setw(10) << "Year"// will align to the left and set to 10 characters for spacing
		<< left << setw(20) << "Year End Balance" //will align the text to the left with 20 characters of white space
		<< left << setw(10) << "Year End Earned Interest" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	for (int i = 1; i <= numYears; i++) {
		months = 12;
		for (int j = 1; j <= months; j++) {
			monthlyInterest = (openningAmount + monthlyDeposit) * ((interestRate / 100) / 12);
			openningAmount += monthlyDeposit + monthlyInterest;
			earnedInterest += monthlyInterest;
		}

		printDetails(i, openningAmount, earnedInterest); // calls the print details function
		earnedInterest = 0;
		cout << endl;
	}
	return closingBalance;
}


int main() {
	double initialDeposit;
	double monthlyDeposit;
	double interestRate;
	int numYears;
	char input;
	do {
		cout << "*********************************" << endl; // formatting of input table
		cout << "**********Data Input*************" << endl;
		cout << "Inital Investment Amount: $"; // prompt for initial investment
		cin >> initialDeposit;
		if (initialDeposit <= 0) {
			cout << "Please enter a positive number." << endl; // if user enter 0 then it will result in an error
		}
		cout << "Monthly Deposit: $"; // prompt for monthly deposit
		cin >> monthlyDeposit;
		if (monthlyDeposit < 0) {
			cout << "Please enter a positive number." << endl; // will display if the monthly deposit is less than 0
		}
		cout << "Anual Interest: %"; // prompt for interest rate
		cin >> interestRate;
		if (interestRate < 0) {
			cout << "Please enter a positive number." << endl; // will output if the user enters less than 0
		}
		cout << "Number of years: "; // prompt for number of years
		cin >> numYears;
		if (numYears <= 0) {
			cout << "Please enter a valid year."; // will output if the year entered is either 0 or less than 0
		}
		cout << endl; // line in between input and table for formatting

		calculateBalanceWithoutMonthlyDeposit(initialDeposit, interestRate, numYears); // calling the calculateBalanceWithoutMonthlyDeposit function
		cout << endl;
		balanceWithMonthlyDeposit(initialDeposit, monthlyDeposit, interestRate, numYears);//calling the balanceWithMonthlyDeposit function

		cout << endl;
		cout << "Would you line to try another? (Y/N)";
		cin >> input;
	} while (input == 'Y' || input == 'y');
	return 0;
}