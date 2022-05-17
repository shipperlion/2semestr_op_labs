//Створити файл зі списком клієнтів, обслугованих менеджером протягом дня: прізвище, час приходу та час закінчення прийому.
//При введенні даних перевіряти їхню допустимість(чи не перетинаються клієнти з наявними).
// Створити новий файл, який містить інформацію про клієнтів, з якими менеджер спілкувався понад 30 хв.

#include "header.h"

int main()
{
    const char* data = "data.bin";      //Name of file with list

    const char* black_list = "blist.bin";   //Name of file with served more than 30 min

    inputData(data);       //Input of data of clients

    cout << "\n==============\n" << 
        "List of clients served today\n"
        << "==============" << endl;
    outputFile(data);       //Output of served clients

    blackList(data, black_list);
    cout << "\n==============\n" <<
        "Blacklist\n"
        << "==============" << endl;
    outputFile(black_list);     //Output of file with served more than 30 min
    system("pause");
}

