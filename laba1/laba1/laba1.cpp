#include <fstream>			//Standard libraries
#include <iostream>
#include <string>
using namespace std;

void createFile(const char*);		//Prototypes of functions
void outputFile(const char*);
void newFile(const char*, const char*, const char*);

int main()		//Main function
{
	const char *name1 = "Text1.txt";		//Name of the first file
	createFile(name1);

	const char* name2 = "Text2.txt";		//Name of the second file
	createFile(name2);

	const char* name3 = "Text3.txt";		//Name of the result file
	newFile(name1, name2, name3);

	outputFile(name1);						//Output of files
	outputFile(name2);
	outputFile(name3);
	system("pause");
}

void createFile(const char* name)		//Function to create file
{
	ofstream OutFile(name);

	if (!OutFile.is_open())			//Checking if file is open
	{
		cout << "Cannot open file\n";
		return;
	}

	cout << "Enter text:" << endl;
	string temp;
	while (temp != "end")			//Entering the text of file
	{
		getline(cin, temp);
		if (temp == "end")
			break;
		else
			OutFile << temp << "\n";
	}
	OutFile.close();				//Closing the file
}

void outputFile(const char* name)	//Function to output file
{
	cout << "File content:\n";
	ifstream InFile(name);
	string str;
	while (!InFile.eof())			//End checking
	{
		getline(InFile, str);
		cout << str << endl;
	}

	InFile.close();					//Closing the file
}

void newFile(const char* name1, const char* name2, const char* name3)
{										//Function to fill new file with
	ofstream OutFile(name3);			//repeating strings

	if (!OutFile.is_open())				//Checking if file is open
	{
		cout << "Cannot open new file\n";
		return;
	}

	ifstream InFile1(name1), InFile2(name2);

	string str1, str2;

	int num = 0;			//Number of repeating strings
	while (!InFile1.eof())	//End checking
	{
		getline(InFile1, str1);
		while (!InFile2.eof())	//End checking
		{
			getline(InFile2, str2);
			if (str1 == str2)	//Checking identity
			{
				OutFile << str1 << '\n';
				num++;
			}
		}
		InFile2.clear();
		InFile2.seekg(0, ios_base::beg);

	}

	cout << "\nNumber of identical strings in files: " << num - 1 << endl << endl;
													//Output of number of repeating
	OutFile.close();								//strings
	InFile1.close();
	InFile2.close();
}