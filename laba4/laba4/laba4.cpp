#include "header.h"

int main()
{
    TDate date1, date2(15, 12, 1994), date3(date1);

    cout << "Please, enter Date1\n";
    date1.setDate();

    cout << "\nPlease, enter Date2\n";
    date2.setDate();

    cout << "\nPlease, enter Date3\n";
    date3.setDate();

    ++date1;
    cout << "\nIncrement the Date1 by one month: "
        << date1.getDay() << "." << date1.getMonth()
        << "." << date1.getYear() << endl;

    date2++;
    cout << "\nIncrement the Date2 by one day: "
        << date2.getDay() << "." << date2.getMonth()
        << "." << date2.getYear() << endl;

    cout << "\nCompare Date1 and Date2: ";
    if (date1 > date2)
        cout << "Date1 is later";
    else
        cout << "Date2 is later";

    cout << "\n\nLeft until the end of the year of Date3: ";
    date3.untilTheEnd();
    cout << endl;
    system("pause");
}
