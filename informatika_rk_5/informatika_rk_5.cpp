#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
	int account_number;
	string owners_name;
	double balance;

public:
	BankAccount(int a, string b, double c) : account_number(a), owners_name(b), balance(c) {}

	double getBalance() {
		return balance;
	}

	void deposit(double deposit) {
		balance += deposit;
	}

	void withdraw(double withdraw) {
		if (balance > withdraw) {
			balance -= withdraw;
		}
		else {
			cout << "Недостаточно средств на счету" << endl;
		}
		
	}

	virtual void display() {
		cout << "Номер счёта:" << account_number << endl;
		cout << "Имя владельца: " << owners_name << endl;
		cout << "Баланс: " << balance << endl;
	}
};

class SavingsAccount : public BankAccount {
private:
	int interest_rate;
public:

	SavingsAccount (int a, string b, double c, int d) : BankAccount(a,b,c), interest_rate(d) {}

	void add_percent() {
		double interest = getBalance() * (interest_rate / 100.0);
		deposit(interest);
	}

	void display() override {
		BankAccount::display();
		cout << "Процентная ставка: " << interest_rate << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	BankAccount* account1 = new SavingsAccount(123, "David", 10000, 10);
	account1->display();
	cout << '\n';
	account1->deposit(1000);
	account1->withdraw(500);

	SavingsAccount* account2 = dynamic_cast<SavingsAccount*>(account1);
	account2->add_percent();
	account2->display();

}
