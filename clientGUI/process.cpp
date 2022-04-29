#include "process.h"
#include <fstream>
using namespace std;

void process::balance_check(valid customer) {

    fstream reach;
    reach.open("data.txt", ios::in);

    string line;
    vector<string> info;
    
    while (getline(reach, line)) {
        info = str_seperator(line);
        if (info[0] == customer.id)
            cout << info.at(5);
    }

    reach.close();


}

valid process::customer_validation(string  customer_id,string password) {

    valid is_valid;
    string id,pass="xxxxx";
    is_valid.id = "xxxxx";
    is_valid.control = false;

    fstream reach;
    reach.open("data.txt", ios::in);
    string line;
    vector<string> info;

    if (reach.is_open()) {
        while (getline(reach, line)) {
            info = str_seperator(line);
            id = info.at(0);
            if (info[0] == customer_id && info[6] == password) {
                is_valid.control = true;
                is_valid.id = customer_id;
            }
            info.clear();
        }
        reach.close();
    }
    else
        cout << "system ERROR!!!" << endl;

    return is_valid;

}

void process::send_money(string receiver_ýd, string receiver_name, string receiver_surname,string id, double money) {

    string x, cNumber, cName, cSurname,hold,cId,bank;
    double remunaration = 4.32;
    vector<string> holder,start;

    ifstream f2("data.txt");
    ofstream o2("hold.txt");

    while (getline(f2, x))
    {
        start.push_back(x);
        hold = x;
        holder = str_seperator(x);
        cNumber = holder.at(0);
        cName = holder.at(1);
        cSurname = holder.at(2);



        if (receiver_ýd == cNumber && receiver_name == cName && receiver_surname == cSurname)
        {
            bank = holder[7];
            for (int i = 0;i < 7;i++) {
                if (i == 5)
                    o2 << stod(holder.at(5)) + money << " ";
                else
                    o2 << holder.at(i) << " ";
            }

            o2 << endl;
        }
        else
            o2 << hold << endl;
        holder.clear();
    }

    f2.close();
    o2.close();


    ifstream file("data.txt");
    ofstream ofile("hold.txt");

    while (getline(file, x))
    {

        hold = x;
        holder = str_seperator(x);
        cId = holder.at(0);


        if (id == cId)
        {
            for (int i = 0;i < 7;i++) {
                if (i == 5)
                    if(bank==holder[7])
                    ofile << stod(holder.at(5)) - money << " ";
                    else
                    ofile << stod(holder.at(5)) - (money+remunaration) << " ";
                else
                    ofile << holder.at(i) << " ";
            }

            ofile << endl;
        }
        else
            ofile << hold << endl;
        holder.clear();
    }
    file.close();
    ofile.close();


    ifstream i("hold.txt");
    ofstream o("data.txt");

    while (!i.eof()) {
        getline(i, x);
        o << x << endl;
    }
    i.close();
    o.close();
    remove("hold.txt");
}


void process::drawing_cash(string id,double money) {
    
    string x,cId,hold;
    vector<string> holder;


    ifstream file("data.txt");
    ofstream ofile("hold.txt");



    while (getline(file, x))
    {

        hold = x;
        holder = str_seperator(x);
        cId = holder.at(0);

        if (id == cId)
        {
            if (stod(holder.at(5)) > money) {
                for (int i = 0;i < 7;i++) {
                    if (i == 5)
                        ofile << stod(holder.at(5)) - money << " ";
                    else
                        ofile << holder.at(i) << " ";
                }

                ofile << endl;
            }
            ofile << hold << endl;
        }
        else
            ofile << hold << endl;
        holder.clear();
    }
    file.close();
    ofile.close();

    ifstream i("hold.txt");
    ofstream o("data.txt");

    while (!i.eof()) {
        getline(i, x);
        o << x << endl;
    }
    i.close();
    o.close();
    remove("hold.txt");


}

void process::investment(string id,double money) {

    string x,hold, cId;
    vector<string> holder;


    ifstream file("data.txt");
    ofstream ofile("hold.txt");



    while (getline(file, x))
    {

        hold = x;
        holder = str_seperator(x);
        cId = holder.at(0);

        if (id == cId)
        {
            for (int i = 0;i < 7;i++) {
                if (i == 5)
                    ofile << stod(holder.at(5)) - money << " ";
                else
                    ofile << holder.at(i) << " ";
            }

            ofile << endl;
        }
        else
            ofile << hold << endl;
        holder.clear();
    }
    file.close();
    ofile.close();

    ifstream i("hold.txt");
    ofstream o("data.txt");

    while (!i.eof()) {
        getline(i, x);
        o << x << endl;
    }
    i.close();
    o.close();
    remove("hold.txt");

}

vector<string> process::str_seperator(string line) {

    vector<string> holder;
    std::string delimiter = " ";

    size_t pos = 0;
    string token;

    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        holder.push_back(token);
        line.erase(0, pos + delimiter.length());
    }

    holder.push_back(line);
    
    return holder;

}

