#include "File.h"

void File::Create()
{
	string newName;
	string road;
	cout << "Enter 'road' for creating File (Use // for move folder) " << endl;
	getline(cin, road);
	cout << "Enter name of File" << endl;
	getline(cin, newName);
	road += newName;
	fstream newFile;
	newFile.open(road, ios::out);
	if (!newFile.is_open())
	{
		cout << "Error I can't create File" << endl;
	}
	else
	{
		cout << " File was created" << endl;
	}
}

void File::deleteFile()
{
	string name;
	name = GetName();
	if (remove(name.c_str()) != 0)
	{
		cout << "I can't delete File";
	}
	else
	{
		cout << "File was deleted" << endl;
	}
}

void File::Copy()
{
	string copyName;
	string newRoad;
	vector<char>fillText;
	cout << "Enter 'road' for copy File (Use // for move folder) " << endl;
	getline(cin, newRoad);
	copyName = nameOfFile;
	newRoad += copyName;
	ifstream inFile(GetName(), ios::binary);
	ofstream outFile(newRoad, ios::binary);

	char ch;
	while (inFile.get(ch))
	{
		fillText.push_back(ch);
	}

	outFile.write(&fillText[0], fillText.size());
	if (!outFile.is_open())
	{
		cout << "I can't to copy File" << endl;
	}
	else
	{
		cout << "File was copied" << endl;
	}
	inFile.close();
	outFile.close();

}

void File::Open()
{
	_finddata_t fileInfo;
	string fullRoad;
	string file;
	string search;

	cout << "Enter Road " << endl;
	getline(cin, search);
	roadOfFile = search;
	fullRoad = search;
	search += "*.*";
	auto res = _findfirst(search.c_str(), &fileInfo);
	if (res != -1)
	{
		do
		{
			if (res != -1)
			{
				cout << fileInfo.name << endl;
			}
		} while (_findnext(res, &fileInfo) != -1);
		cout << "choose File" << endl;
		getline(cin, file);
		setFile(file);
		nameOfFile = file;
		fullRoad += file;
		SetName(fullRoad);
		cout << nameOfFile << "Choosed" << endl;
	}
	else
	{
		tick++;
		cout << "Wrong road!!!" << endl;
	}
}
