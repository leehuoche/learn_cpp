#include"account.h"
#include <iostream>
#include <cmath>
using namespace std;

double SavingsAccount::total = 0;
SavingsAccount::SavingsAccount(Date date, const std::string id, double rate)
	:id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
	date.show();
}

void SavingsAccount:: record(const Date date, double amount, const std::string desc){
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	total += amount;
	date.show();
	cout<< "\t#" << id << "\t" << amount << "\t" << balance << endl;
}
void SavingsAccount::error(const std::string msg)const {
	cout << "error(#" << id << "):" << msg << endl;
}


void SavingsAccount::deposit(const Date date, double amount, const std::string desc) {
	record(date, amount,desc);
}


void SavingsAccount::withdraw(Date date, double amount, const std::string desc) {
	if (amount > getBalance())
		error("not enougn money");
	else
		record(date, -amount,desc);
}

void SavingsAccount::settle(Date date) {
	double interest = accumulate(date)*rate / date.distance(Date(date.getYear() - 1, 1, 1));
	if (interest != 0)
		record(date, interest,"interest");
	accumulation = 0;
}



void SavingsAccount::show() const{
	cout << "#" << id << "\tbalance:" << balance;
}
