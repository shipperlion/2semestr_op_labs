//Створити клас TDate, який містить трійку цілих чисел, що представляють число, місяць та рік,
//і методи для порівняння дат, заданих різними форматами, їх збільшення/зменшення на вказану величину.
//На основі цього класу створити класи нащадки TDate1 та Tdate2, що представляють дати в форматі "чч.мм.рррр" та "мм-чч-рррр"
//відповідно. Створити n об'єктів TDate1 та m об'єктів TDate2. Визначити саму пізню дату, а також дати, що належать заданому періоду дат

#include "header.h"

int main() {
	int n, m;
	cout << "Enter the size of first array of objects: "; cin >> n;
	TDate1 *arr1 = new TDate1[n];

	cout << "Enter the size of second array of objects: "; cin >> m;
	TDate2* arr2 = new TDate2[m];
	
	cout << "Enter two dates for increasing and decreasing: " << endl;
	TDate1 obj1; TDate2 obj2;
	obj1.increaseDate();
	obj1.showDate();

	obj2.decreaseDate();
	obj2.showDate();

	arr1->latestDate(arr2, n, m);
	arr1->inInterval(arr2, n, m);
	delete[] arr1;
	delete[] arr2;
	system("pause");
}
