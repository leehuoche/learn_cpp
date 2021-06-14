#include <iostream>
#include <cmath>
using namespace std;
//lei shengming
class SavingAcount{
public:
	SavingAcount(int date,int id,double rate);
	int getID(){return id;}
	double getBalance(){return balance;}
	double getRate(){return rate;}
	void deposit(int date,double amount);
	void withdraw(int date,double amount);
	void settle(int date);
	void show();
private:
	int id;
	double balance;
	double rate;
	int lastDate;
	double accumulation;
	void record(int date,double amount);
	double accumulate(int date)const{
		return accumulation+balance*(date-lastDate);
	}

};
//shixian
SavingAcount::SavingAcount(int date,int id,double rate)
	:id(id),balance(0),rate(rate),lastDate(date),accumulation(0){
	cout<<date<<"\t#"<<id<<"is created"<<endl;
}

void SavingAcount:: record(int date,double amount){
	accumulation=accumulate(date);
	lastDate=date;
	amount=floor(amount*100+0.5)/100;
	balance+=amount;
	cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}


void SavingAcount::deposit(int date,double amount){
	record(date,amount);
}


void SavingAcount:: withdraw(int date,double amount){
	if(amount>getBalance())
		cout<<"erro:not enough money"<<endl;
	else
		record(date,-amount);
}

void SavingAcount::settle(int date){
	double interest=accumulate(date)*rate/365;
	if(interest!=0)
		record(date,interest);
	accumulation=0;
}



void SavingAcount::show(){
	cout<<"#"<<id<<"\tbalance:"<<balance;
}


int main(){
	SavingAcount sa0(1,111111,0.015);
	SavingAcount sa1(1,222222,0.015);

	sa0.deposit(5,5000);
	sa1.deposit(25,10000);
	sa0.deposit(45,5500);
	sa1.withdraw(60,4000);
	sa0.settle(90);
	sa1.settle(90);
	sa0.show();   cout<<endl;
	sa1.show();   cout<<endl;
	return 0;
}

