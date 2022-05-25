#include "header.h"

int main() {
	int n, m;
	cout << "Enter the size of first array of objects: "; cin >> n;
	TDate1* arr1 = new TDate1[n];

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