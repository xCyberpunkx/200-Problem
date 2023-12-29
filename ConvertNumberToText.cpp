// FuckMicrosoft.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;

int readNumber() {
    int num;
    cout << "Enter the number: ";
    cin >> num;
    return num;
}

string convertNumberToText(int number) {

    if (number == 0) {
        return "";
    }

    if (number >= 1 && number <= 19) {
        string arr[]{ "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Elevn", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
        return arr[number];
    }

    if (number >= 20 && number <= 99) {
        string arr[]{ "", "", "Twenty", "Thrity", "Fourty", "Fifety", "Sixty", "Seventy", "Eighty", "Ninety" };
        return arr[number / 10] + ' ' + convertNumberToText(number % 10);
    }

    if (number >= 100 && number <= 999) {
        return  convertNumberToText(number / 100) + " Hundered " + convertNumberToText(number % 100);
    }

    if (number >= 1000 && number <= 999999) {
        return  convertNumberToText(number / 1000) + " Thousand " + convertNumberToText(number % 1000);
    }

    if (number >= 1000000 && number <= 999999999) {
        return  convertNumberToText(number / 1000000) + " Million " + convertNumberToText(number % 1000000);
    }

    if (number >= 1000000000 && number <= 999999999999) {
        return  convertNumberToText(number / 1000000000) + " Billion " + convertNumberToText(number % 1000000000);
    }
}

int main()
{

    int number = readNumber();

    cout << convertNumberToText(number);

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
