// Hazel_uEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

static short readNumber() {
    short year;
    cout << "Please Enter a year to check\n";
    cin >> year;
    return year;
}

bool isLeapYear(short year) {
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return true;
    else
        return false;
}

static short ConvertToDays(short year) {
    if (isLeapYear(year))
        return 366;
    else
        return 365;
}

static int ConvertToHours(short Days) {
    return Days * 24;
}

static int ConvertToMinuts(short Hours) {
    return Hours * 60;
}

static int ConvertToSeconds(short Minuts) {
    return Minuts * 60;
}

static void PrintYearInfo(short year) {
    short daysInYear = ConvertToDays(year);
    int hoursInYear = ConvertToHours(daysInYear);
    int minutesInYear = ConvertToMinuts(hoursInYear);
    int secondsInYear = ConvertToSeconds(minutesInYear);

    cout << "The Number Of Days In The Year [" << year << "] is: " << daysInYear << endl;
    cout << "The Number Of Hours In The Year [" << year << "] is: " << hoursInYear << endl;
    cout << "The Number Of Minutes In The Year [" << year << "] is: " << minutesInYear << endl;
    cout << "The Number Of Seconds In The Year [" << year << "] is: " << secondsInYear << endl;
}

int main() {
    short year = readNumber();
    PrintYearInfo(year);

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
