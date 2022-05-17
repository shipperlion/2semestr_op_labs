#include "header.h"

void inputData(const char* name) //Function to input clients` data
{
	struct Data		//Structure of data of client
	{
		string name;
		string start;
		string end;
	};

	char flag;

	ofstream outFile(name, ios_base::app);	//Opening the file

	if (!outFile) //Checking if file is opened
	{
		cout << "Cannot open file\n";
		return;
	}

	cout << "Input of data....\n";

	Data client, temp;	//Creating containers

	cout << "Surname: "; getline(cin, client.name);	//Input of client`s data
	cout << "Start(hh:mm): "; getline(cin, client.start);
	cout << "End(hh:mm): "; getline(cin, client.end);

	outFile << client.name << " " << client.start << " - " << client.end << "\n";

	cout << "==============\nContinue? Y/N "; cin >> flag;
	cout << "==============\n";
	cin.ignore();

	while (flag == 89 || flag == 121)	//Cheking the flag
	{
		string cldate = client.end;		//Extraction of end time of previous client
		int clhour = stoi(cldate.substr(0, 2));	//Extraction of hours
		int clmin = stoi(cldate.substr(3, 2));	//Extraction of minutes

		cout << "Surname: "; getline(cin, temp.name);	//Input of next client`s data
		cout << "Start(hh:mm): "; getline(cin, temp.start);
		cout << "End(hh:mm): "; getline(cin, temp.end);

		string tdate = temp.start;		//Extraction of start time of current client
		int thour = stoi(tdate.substr(0, 2));	//Extraction of hours
		int tmin = stoi(tdate.substr(3, 2));	//Extraction of minutes

		while ((clhour * 60 + clmin) > (thour * 60 + tmin)) //Checking for overlap
		{
			cout << "Visiting time overlap. Please, try again\n"; //Re-entry of time
			cout << "Start(hh:mm): "; getline(cin, temp.start);
			cout << "End(hh:mm): "; getline(cin, temp.end);

			tdate = temp.start;		//Extraction of start time of current client
			thour = stoi(tdate.substr(0, 2));	//Extraction of hours
			tmin = stoi(tdate.substr(3, 2));	//Extraction of minutes
		}
		outFile << temp.name << " " << temp.start << " - " << temp.end << "\n";
		client = temp;	//Current client becomes the previous one
		cout << "==============\nContinue? Y/N "; cin >> flag;
		cin.ignore();
	}
	outFile.close();	//Closing file
}

void blackList(const char* name1, const char* name2)	//Function to search for
{														//scandalous clients
	ofstream outFile(name2, ios_base::trunc);		//Opening files
	ifstream inFile(name1);

	if (!outFile || !inFile)		//Cheking if file is opened
	{
		cout << "Cannot open one of files\n";
		return;
	}

	while (!inFile.eof())	//Checking for end of file
	{
		string buf;		//Buffer string
		getline(inFile, buf);	//Getting strings from list

		if (buf != "")	//Checking for empty line
		{
			string start = buf.substr(buf.find_first_of("0123456789"), 5);	//Extraction of start time of the client
			string end = buf.substr(buf.find_last_of(" "), 6);	//Extraction of end time of the client

			int shour = stoi(start.substr(0, 2)); //Extraction of hours of start time
			int smin = stoi(start.substr(3, 2));	//Extraction of minutes of start time

			int ehour = stoi(end.substr(0, 3));		//Extraction of hours of end time
			int emin = stoi(end.substr(4, 2));		//Extraction of minutes of end time

			if ((ehour * 60 + emin) - (shour * 60 + smin) > 30)	//Checking if time of visit
			{													//more than 30 minutes
				outFile << buf << endl;
			}
		}
	}

	outFile.close();	//Closing files
	inFile.close();
}

void outputFile(const char* name)	//Function to output file
{
	ifstream inFile(name);	//Opening file
	string str;

	while (!inFile.eof())	//Checking file for end
	{
		getline(inFile, str);
		cout << str << endl;	//Output of string
	}

	inFile.close();		//Closing file
}

