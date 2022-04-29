
#include <iostream>
#include<string>
#include <vector>
#include "process.h"


using namespace std;

void selections(void) {
	cout << "1-balance check" << endl;
	cout << "2-drawing cash" << endl;
	cout << "3-investment" << endl;
	cout << "4-send money" << endl;
	cout << "5-EXIT" << endl << endl;
}



int main()
{
	process pr;
	string cus_id, password,r_id,r_name,r_surname;
	int select;
	double money;
	valid person;
	cout << "customer id:";
	cin >> cus_id;
	cout << "password:";
	cin >> password;
	person = pr.customer_validation(cus_id, password);
	if (person.control) {
	start:
		selections();
		cout << endl << "select process : ";
		cin >> select;
		cout << endl << endl;
		if (select > 0 && select < 6) {
			switch (select) {
			case 1:
				pr.balance_check(person);
				break;
			case 2:
				cout << "amount of money:";
				cin >> money;
				pr.drawing_cash(person.id, money);
				break;
			case 3:
				cout << "amount of money:";
				cin >> money;
				pr.investment(person.id, money);
				break;
			case 4:
				cout << "receiver customer id:";
				cin >> r_id;
				cout << "receiver name:";
				cin >> r_name;
				cout << "receiver surname:";
				cin >> r_surname;
				cout << "amount:";
				cin >> money;
				pr.send_money(r_id, r_name, r_surname, cus_id, money);
				break;
			case 5:
				exit(0);
			}
			cout << "process happen successfully" << endl << endl;
			goto start;
		}
		else {
		cout << "unvalid process!!!" << endl << endl;
		goto start;
		}

	}
	else
		cout << "not valid customer!!!";
}


