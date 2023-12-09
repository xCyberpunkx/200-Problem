#include <iostream>
#include <fstream>
#include<vector>
#include <string>
#include <iomanip>
using namespace std;

const string fileName = "Filee.txt";

struct stData {
	string accountNumber, pinCode, name, phone, accountBalance;
};

vector<string> myVec(string line, string separetor) {

	vector<string> result;

	short pos = 0;
	string temp;

	while ((pos = line.find(separetor)) != string::npos) {

		temp = line.substr(0, pos);
		if (temp != "") {
			result.push_back(temp);
		}

		line = line.erase(0, pos + separetor.length());

	}

	if (line != "") {
		result.push_back(line);
	}

	return result;
}

stData informationClient(string line, string separetor) {
	stData info;

	vector<string> result = myVec(line, separetor);

	info.accountNumber = result.at(0);
	info.pinCode = result.at(1);
	info.name = result.at(2);
	info.phone = result.at(3);
	info.accountBalance = result.at(4);

	return info;
}

vector<stData> getDataFromFile(string fileName) {

	vector<stData> result;

	
	fstream theFile;

	theFile.open(fileName, ios::in);

	if (theFile.is_open()) {

		string line;
		stData client;

		while (getline(theFile, line)) {

			if (line != "") {
				
				client = informationClient(line, "#//#");
				result.push_back(client);

			}
		}
		theFile.close();
	}

	return result;

}

bool ifFoundClient(string& accountNumber, stData& result) {
	
	if (result.accountNumber == accountNumber) return true;
	else return false;
}

void printDataClient(vector<stData>& result) {
	string accountNumber;
	cout << "please enter account number: "; cin >> accountNumber;

	cout << "the following are the client details:" << endl;

	for (int i = 0; i < result.size(); i++) {

		if (ifFoundClient(accountNumber, result.at(i))) {

			stData res = result.at(i);

			cout << "\nAccount Number: " << res.accountNumber << endl;
			cout << "Pin Code: " << res.pinCode << endl;
			cout << "Name: " << res.name << endl;
			cout << "Phone: " << res.phone << endl;
			cout << "Account Balance: " << res.accountBalance << endl;
			return;
		}
		
	}
	
	cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";
}

int main()
{
	vector<stData> result = getDataFromFile(fileName);
	printDataClient(result);

	return 0;
}
