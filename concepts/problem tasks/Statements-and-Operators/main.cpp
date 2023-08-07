// Section 8 Challenge
/*
	For this program I will be using US dollars and cents.
	
    Write a program that asks the user to enter the following:
	An integer representing the number of cents 
    	
	You may assume that the number of cents entered is greater than or equal to zero
    
	The program should then display how to provide that change to the user.
	
	In the US:
		1 dollar is 100 cents
		1 quarter is 25 cents
		1 dime is 10 cents
		1 nickel is 5 cents, and
		1 penny is 1 cent.
		
	Here is a sample run:
	
	Enter an amount in cents :  92
	
	You can provide this change as follows:
	dollars    : 0
	quarters : 3
	dimes     : 1
	nickels   : 1
	pennies  : 2
	
	Feel free to use your own currency system.
	Also, think of how you might solve the problem using the modulo operator.

	Have fun and test your program!!

*/
#include <iostream>

using namespace std;

int main() {
	int change_amount;
	const int dollar_value{100};
	const int quarters_value{25};
	const int dimes_value{10};
	const int nickels_value{5};
	
	
	cout<< "The conversion is as follows :" <<endl;
	cout << " In the US:"<<endl;
	cout <<" 1 dollar is 100 cents"<<endl;
	cout <<	" 1 quarter is 25 cents"<<endl;
	cout <<	" 1 dime is 10 cents"<<endl;
	cout <<	" 1 nickel is 5 cents, and"<<endl;
	cout <<	" 1 penny is 1 cent."<<endl;
		

	cout <<"Enter an amount in cents : ";
	cin >> change_amount;

	
    int balance{}, dollars{}, quarters {}, dimes{}, nickels{}, pennies{};
    
	dollars = change_amount/dollar_value;
	balance = change_amount-(dollars*dollar_value);
	
	quarters = balance/quarters_value;
	balance = balance - quarters*quarters_value;
	//balance -= quarters * quarters_value;

	dimes = balance/dimes_value;
	balance = balance - dimes*dimes_value;
	//balance -= dimes * dimes_value;
	
	nickels = balance/nickels_value;
	balance = balance - nickels*nickels_value;
	//balance -= nickels * nickels_value;
	
	pennies = balance;

	cout<< "Change can be provided as follow : "<< endl;
	cout<< "dollars :" << dollars <<endl;
	cout<< "quarters :" << quarters <<endl;
	cout<< "dimes :" << dimes <<endl;
	cout<< "nickels :" << nickels <<endl;
	cout<< "pennies :" << pennies <<endl;
	
    cout << endl;
    return 0;
}




