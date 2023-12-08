// FuckMicrosoft.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

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
    string AccountName;
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
static stClients ConvertRecordToLine(string Line, string seperator = "|||")
{

    stClients Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, seperator);
    Client.ClientName = vClientData[0];
    Client.AccountName = vClientData[1];
    Client.AccountNumber = vClientData[2];
    Client.PINCODE = vClientData[3];
    Client.Phone = vClientData[4];
    Client.AccountBalance = stod(vClientData[5]);

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
        while (getline(MyFile,line))
        {
            Client = ConvertRecordToLine(line);
            vClient.push_back(Client);

        }
        MyFile.close();
    }
    return vClient;
}
static void PrintClientRecord(stClients Client)
{
    std::cout << "| " << setw(15) << left << Client.ClientName;
    std::cout << "| " << setw(10) << left << Client.AccountName;
    std::cout << "| " << setw(30) << left << Client.AccountNumber;
    std::cout << "| " << setw(20) << left << Client.PINCODE;
    std::cout << "| " << setw(15) << left << Client.Phone;
    std::cout << "| " << setw(15) << left << Client.AccountBalance;
}
static void PrintAllClientsRecord(vector<stClients> vClients)
{
    std::cout << "\n\t\t\t\tClient List (" << vClients.size() << ")Clients(s)";
    std::cout << "\n_______________________________________________________";
    std::cout << "_______________________________________________________\n";
    std::cout << "| " << left << setw(15) << "Accout Number";
    std::cout << "| " << left << setw(10) << "Pin Code";  
    std::cout << "| " << left << setw(40) << "Client Name";
    std::cout << "| " << left << setw(12) << "Phone";
    std::cout << "| " << left << setw(12) << "Balance";
    std::cout << "\n_______________________________________________________";
    std::cout << "_______________________________________________________\n";

    for (stClients Client : vClients)
    {
        PrintClientRecord(Client);
        std::cout << endl;
    }
    std::cout << "\n_______________________________________________________";
    std::cout << "_______________________________________________________\n";
}

int main()
{
    vector<stClients> vClient =  LoadClientsDataFromFile(ClientFileName);
    PrintAllClientsRecord(vClient);
   
    system("pause>0");
    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
