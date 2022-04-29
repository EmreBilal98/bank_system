// database_txt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct dataType {
	string customerNum, customerName,customerSurname, account, card,password,bank;
	double money;
};

int main()
{
 
	fstream database;
	database.open("C:\\Users\\Emre\\Desktop\\piton_test\\clientGUI\\data.txt",ios::app);
	dataType customer;
	vector<dataType> customerList;
	bool control=0;
	cout << "add customer?:";
	cin >> control;

	while (control) {
		
		cout << "customer number:";
		cin >> customer.customerNum;
		while(customer.customerNum.length()!=6){
			cout<<"customer id must be 6 character enter again:";
			cin >> customer.customerNum;
		}
		
		cout << "customer name:";
		cin >> customer.customerName;
			while(customer.customerName.length()>20 && customer.customerName.length()<2){
			cout<<"customer id must be 6 character enter again:";
			cin >> customer.customerName;
		}

		cout << "customer surname:";
		cin >> customer.customerSurname;
		while(customer.customerSurname.length()>20 && customer.customerSurname.length()<2){
			cout<<"customer id must be 6 character enter again:";
			cin >> customer.customerSurname;
		}
		
		cout << "account:";
		cin >> customer.account;
		while(customer.account.length()!=6){
			cout<<"account must be 6 character enter again:";
			cin >> customer.account;
		}
		
		cout << "card id:";
		cin >> customer.card;
		while(customer.card.length()!=6){
			cout<<"card must be 6 character enter again:";
			cin >> customer.card;
		}

		cout << "balance of account:";
		cin >> customer.money;
		
		cout<<"password:";
		cin>>customer.password;
		while(customer.password.length()!=6){
			cout<<"password must be 6 character enter again:";
			cin >> customer.password;
		}
		
		cout<<"enter bank name:";
		cin>>customer.bank;

		customerList.push_back(customer);
		
		cout<<"enter bank name:";
		cin>>customer.bank;

		cout << "add customer?:";
		cin >> control;
	}
	vector<dataType>::iterator i = customerList.begin();
	
	if (database.is_open()) {
		while (i != customerList.end()) {
			database << i->customerNum << " " << i->customerName <<" "<<
				i->customerSurname << " " << i->account << " " << i->card << " " << i->money <<" "<<i->password<<" "<<i->bank<< endl;
			i++;
		}


		database.close();
	}




}


