#include "header.h"

int main()
{
    const int size = 10;        //Max number of employees
    char flag = 89;
    int num = 0;                //Number of employees

    TEmployee people[size];     //Array of objects

    while (flag == 89 || flag == 121) {     //Input of employee`s data
        if (num != 0)
            cin.ignore();
        people[num].setInfo();
        num++;
        cout << "==============================\n" <<
            "Add another employee? (Y/N) :\n";
        cin >> flag;
        cout << "\n\n";
    }

    cout << "==============================" << endl;

    for (int i = 0; i < num; i++) {         //Output of employees` data
        cout << setw(25) << people[i].getName() << setw(10) << people[i].getDay()
            << "." << people[i].getMonth() << "." << people[i].getYear() << "\n";
    }
    cout << "==============================" << endl;

    people[0].getOldest(people, num);       //Show the oldest employee

    return 0;
}

