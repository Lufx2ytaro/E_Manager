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

void Folder::Open()
{
	string copyName;
	string newRoad;
	vector<char>fillText;
	cout << "Enter 'road' for copy File (Use // for move folder) " << endl;
	getline(cin, newRoad);
	copyName = folderName;
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
		cout << "I can't to copy Folder" << endl;
	}
	else
	{
		cout << "Folder was copied" << endl;
	}
	inFile.close();
	outFile.close();
}

void Folder::Rename()
{
	string newFile;
	string road;
	road = roadOfFolder;
	cout << "Enter New Name for Folder" << endl;
	getline(cin, newFile);
	road += newFile;
	if (rename(GetName().c_str(), road.c_str()) != 0)
	{
		cout << "Error  I can't rename Folder" << endl;
	}
	else
	{
		cout << "Folder was renamed" << endl;
	}
}

void Folder::Move()
{
	string name;
	string newRoad;
	name = GetName();
	cout << "Enter new 'road' to move Folder (Use // for move folder) " << endl;
	newRoad += folderName;
	if (rename(name.c_str(), newRoad.c_str()) != 0)
	{
		cout << " I can't to move Folder" << endl;
	}
	else
	{
		cout << "Folder was movied" << endl;
	}
}

void Folder::Search()
{
	_finddata_t fileInfo;
	string road;
	string fileMask;
	cout << "Enter (road) with(\\\\) at the end" << endl;
	getline(cin, road);
	cout << "pls, Enter Mask of Folder((*.txt))" << endl;
	getline(cin, fileMask);
	road += fileMask;
	auto res = _findfirst(road.c_str(), &fileInfo);
	cout << "\n\t\t\t\tI FOUND these Files" << endl;

	if (res != 0)
	{
		do
		{
			if (res != -1)
			{
				cout << fileInfo.name << endl;
			}
		} while (_findnext(res, &fileInfo) != 0);
		cout << endl;
	}
	else
	{
		cout << "I can't find Folder sorry" << endl;
	}
}

void Folder::Information()
{
	_finddata_t fileInfo;
	auto res = _findfirst(GetName().c_str(), &fileInfo);
	if (res != -1)
	{
		cout << "\t\t\t Folder Information" << endl;
		cout << ((fileInfo.attrib & _A_HIDDEN) ? "\t\t\tHIDDEN" : "\t\t\tNOT HIDDEN") << endl;
		cout << ((fileInfo.attrib & _A_RDONLY) ? "\t\t\tREAD ONLY" : "\t\t\tNOT READ ONLY") << endl;
		cout << "\n\t\t\FolderName: " << fileInfo.name << endl;
		cout << "\n\t\t\tSIZE: " << fileInfo.size << " BYTES" << endl;
	}
	else
	{
		cout << "\t\t\tCANT FIND ANY Folder\n";
	}
}
