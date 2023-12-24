#include "Folder.h"



void Folder::create()
{
	string road;
	string name;
	cout << "Enter 'road' for creating Folder (Use // for move folder) " << endl;
	getline(cin,road);
	cout << " Enter Name of Folder " << endl;
	getline(cin, name);
	road += name;

	if (_mkdir(road.c_str()) == -1) 
	{
		cout << "Error folder can't be created" << std::endl;
	}
	else 
	{
		cout << "Folder was created" << std::endl;
	}
}

void Folder::Remove()
{
	string newRoad = "rmdir /s /q ";
	newRoad += GetName();
	
	if (system(newRoad.c_str()))
	{
		cout << "Folder don't remove" << endl;
	}
	else
	{
		cout << "folder was removed" << endl;
	}
}

void Folder::Copy()
{
	string newRoad;
	string copyName;
	cout << "Enter 'road' for creating Folder (Use // for move folder) " << endl;
	getline(cin, newRoad);
	copyName = folderName;
	newRoad += copyName;
	_mkdir(newRoad.c_str());
	cout << "copy" + GetName() + newRoad;
}
