// FuckMicrosoft.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#include <string>

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

stClients ReadNewClient()
{
    stClients ClientInfo;
    cout << "Please Enter Your Name:\n";
    getline(cin >> ws, ClientInfo.ClientName);

    cout << ("Please Enter Your Account Name:\n");
    getline(cin, ClientInfo.AccountName);

    cout << ("Please Enter Your Pin Code:\n");
    getline(cin, ClientInfo.PINCODE);

    cout << ("Please Enter Your Phone Number:\n");
    getline(cin, ClientInfo.Phone);

    cout << ("Please Enter Your Account Balance:\n");
    cin >> ClientInfo.AccountBalance;
    
    return ClientInfo;
}

string ConvertLineToString(stClients Client, string seperator = "|||")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountName + seperator;
    stClientRecord += Client.ClientName + seperator;
    stClientRecord += Client.PINCODE + seperator;
    stClientRecord += Client.Phone + seperator;
    stClientRecord += to_string(Client.AccountBalance) + seperator;

    return stClientRecord;

}

void AddDataToFile(string FileName, string stLineData)
{
    ofstream MyFile; // Use ofstream for writing to a file
    MyFile.open(FileName, ios::app); // Open the file in append mode

    if (MyFile.is_open())
    {
        MyFile << stLineData << endl; // Write data to the file
        MyFile.close(); // Close the file
    }
    else
    {
        cout << "Unable to open the file: " << FileName << endl;
    }
}

void AddNewClient()
{
    stClients Client;
    Client = ReadNewClient();
    AddDataToFile(ClientFileName, ConvertLineToString(Client));
}

void AddClient()
{
    char answer = 'Y';
    do
    {
        system("cls");
        cout << "Adding New CLient\n\n";
        AddNewClient();
        cout << "Client Added Successfully, Do You Want To Add A new Client?\n";
        cin >> answer;

    } while (toupper(answer == 'y'));
    
}




int main()
{
    AddClient();
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
