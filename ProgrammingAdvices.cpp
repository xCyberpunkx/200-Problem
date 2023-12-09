// ProgrammingAdvices.cpp : This file contains the 'main' function. Program execution begins and ends there.

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
    bool MarkForDelete = false;
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
static bool FindClientByAccountNumber(string AccountNumber,vector<stClients> vClients ,stClients& Client)
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
static bool MarkClientForDelete(string AccountNumber, vector<stClients>& vClients)
{
    for (stClients& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}
static vector<stClients> SaveClientsDataToFile(string FileName, vector<stClients> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (stClients C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }

        }
        MyFile.close();
    
    }

    return vClients;
}
static bool DeleteClientByAccountNumber(string AccountNumber, vector<stClients>& vClients)
{
    stClients Client;
    char answer = 'n';

    if (FindClientByAccountNumber(AccountNumber,vClients,Client))
    {
        PrintClientCard(Client);
         cout << "\nAre You Sure You Want To Delete This Client? y/n?";
         cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        MarkClientForDelete(AccountNumber, vClients);
    
        SaveClientsDataToFile(ClientFileName, vClients);
        //refresh Clients
        vClients = LoadClientsDataFromFile(ClientFileName);

        cout << "\n\nClient Deleted Successfully.";
        return true;
    }
}
    else
    {
        cout << "\nClient With Account Number (" << AccountNumber << ") is Not Found!)";
        return false;
    }
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
    vector<stClients> vClient = LoadClientsDataFromFile(ClientFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClient);

    system("pause>0");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
