#include <iostream>
#include <string>
//a sequence of instructions that can be executed concurrently with other such sequences in multithreading environments, while sharing a same address space
#include <thread>
//"chronological"
#include <chrono>


using namespace std;
//flush prints out the characters 1 by 1
using std::flush;
using std::string;
//the thread makes the characters "sleep" until printed
using std::this_thread::sleep_for;
//the time for the lag is milliseconds
using std::chrono::milliseconds;


// declaring our functions!
void hackers(int& a, int& b);
void transaction(int a, int b);
void accounts(int you, int terrorists);
//forward slow print
void slow_print(const string&, unsigned int);

int main()
{
	system("title Bank Account!");

	// bank account amounts
	int myBankAccount = 2;
	int terroristsCollegeFund = 420000;

	// print account values
	accounts(myBankAccount, terroristsCollegeFund);

	// call normal transaction
	transaction(myBankAccount, terroristsCollegeFund);

	// print account values
	accounts(myBankAccount, terroristsCollegeFund);

	// call hacked transaction
	hackers(myBankAccount, terroristsCollegeFund);

	// print account values
	accounts(myBankAccount, terroristsCollegeFund);

	system("pause");
	return 0;
}

/// swap using references
void hackers(int& a, int& b) {
	string hacka = "Hacking in Progress....\n";
	slow_print(hacka, 60);
	int buffer = a;
	a = b;
	b = buffer;
	cout << "Hacking Complete.\n\n";
	return;
}

/// swap using copies
void transaction(int a, int b) {
	string normal= "Processing Transaction....\n";
	slow_print(normal, 60);
	int buffer = a;
	a = b;
	b = buffer;
	cout << "Transaction Complete.\n\n";
	return;
}

/// prints the balances of both you and the hacker
void accounts(int you, int hackerMan) {
	string yourBalance = "Current Balances:\n";
	slow_print(yourBalance, 60);
	cout << "________________________________________\n________________________________________\n";
	cout << "Your Balance: $" << you << endl;
	cout << "Hacker's Balance: $" << hackerMan << endl;
	cout << "________________________________________\n________________________________________\n\n";
	return;
}

//implementing slow print
void slow_print(const string& message, unsigned int millis_per_char)
{
	for (const char c : message)
	{
		//flush helps us put the text character by character
		cout << c << flush;
		//sleep_for maakes the characters lag for a specific amount of milliseconds.
		//you can choose how many milliseconds for the characters
		//millis_per_chr means that each character must wait the certain amount of time before printing 
		sleep_for(milliseconds(millis_per_char));
	}
}
