
#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef struct validCustomer {
	bool control;
	string id;
}valid;

class process
{
public:

	valid customer_validation(string, string);
	void balance_check(valid);
	void send_money(string receiver_ýd, string receiver_name, string receiver_surname, string id, double money);
	void drawing_cash(string, double money);
	void investment(string,double money);

private:

	vector<string> str_seperator(string);

};

