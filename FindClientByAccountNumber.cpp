#include <iostream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
const string ClientFileName = "Clients.txt";

struct stClients
{
    string ClientName;
    string AccountNumber;
    string PINCODE;
    string Phone;
    double AccountBalance;
};
static vector<string> SplitString(string Str, string Delimeter)
{
    vector<string> vString;
    short pos = 0;
    string word;
    // use the find() func to find the position of the delimeter
    while ((pos = Str.find(Delimeter)) != std::string::npos)
    {
        word = Str.substr(0, pos);
        if (word != "")
        {
            vString.push_back(word);
        }
        Str.erase(0, pos + Delimeter.length());
    }
    if (Str != "")
    {
        vString.push_back(Str);
    }
    return vString;
}
static stClients ConvertRecordToLine(string Line, string separator = "|||") {
    stClients Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, separator);

    if (vClientData.size() <= 6) { // Ensure there are at least 6 elements in the vector
        Client.AccountNumber = vClientData[0];
        Client.PINCODE = vClientData[1];
        Client.ClientName = vClientData[2];
        Client.Phone = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]);
    }
    else {
        // Handle the case where the data doesn't have enough elements
        // For example:
        cerr << "Incomplete data in the record: " << Line << endl;
        // You might want to set default values for Client or handle the error accordingly
    }

    return Client;
}
static vector<stClients> LoadClientsDataFromFile(string FileName)
{
    vector<stClients> vClient;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string line;
        stClients Client;
        while (getline(MyFile, line))
        {
            Client = ConvertRecordToLine(line);
            vClient.push_back(Client);

        }
        MyFile.close();
    }
    return vClient;
}
static void PrintClientCard(stClients Client)
{

    cout << "\nThe following are the client details:\n";
    cout << "\nAccount Number  :" << Client.AccountNumber;
    cout << "\nPin Code        :" << Client.PINCODE;
    cout << "\nName            :" << Client.ClientName;
    cout << "\nPhone           :" << Client.Phone;
    cout << "\nAccount Balance :" << Client.AccountBalance;
}
static bool FindClientByAccountNumber(string AccountNumber, stClients& Client)
{
    vector<stClients> vClients = LoadClientsDataFromFile(ClientFileName);
    for (stClients C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
        
    }
    return false;
}
static string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter Account Number: ";
    cin >> AccountNumber;
    return AccountNumber;
}


int main()
{
    stClients Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient With Account Number(" << AccountNumber << ") is Not Found";

    system("pause>0");
    return 0;
}
