#include "header.h"

void TEmployee::setInfo()		//Method to input data of employee
{
	cout << "Input of employee`s data.....\n==============================\n";
	cout << "Full name: "; 
	getline(cin, name);
	cout << "Date of birth:\n";
	cout << "Day: "; cin >> day;
	cout << "Month: "; cin >> month;
	cout << "Year: "; (cin >> year).ignore();
}

void TEmployee::getOldest(TEmployee* arr, int num)	//Method to find oldest
{
	int d = arr[0].getDay();		//Date of birth of the oldest employee
	int m = arr[0].getMonth();
	int y = arr[0].getYear();
	int oldest = 0;
	for (int i = 1; i < num; i++)
	{
		int dcur = arr[i].getDay();		//Data to compare with
		int mcur = arr[i].getMonth();
		int ycur = arr[i].getYear();

		if (ycur < y)
		{
			oldest = i;
			d = arr[i].getDay();
			m = arr[i].getMonth();
			y = arr[i].getYear();
			continue;
		}
		else if (ycur == y)
		{
			if (mcur < m)
			{
				oldest = i;
				d = arr[i].getDay();
				m = arr[i].getMonth();
				y = arr[i].getYear();
				continue;
			}
			else if (mcur == m)
			{
				if (dcur < d)
				{
					oldest = i;
					d = arr[i].getDay();
					m = arr[i].getMonth();
					y = arr[i].getYear();
				}
			}
		}
	}

	cout << "\nThe oldest employee: " << arr[oldest].getName() << setw(10) <<
		d << "." << m << "." << y;		//Output of oldest employee
}
