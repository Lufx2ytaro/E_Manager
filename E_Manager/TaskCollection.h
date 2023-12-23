#pragma once
#include<iostream>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <fstream>
using namespace std;

class TaskCollection
{
private:
	string maxSizeOfName;
public:

	TaskCollection(string filename) : maxSizeOfName(filename) {};

	TaskCollection() {};

	virtual void Open() {}

	virtual void Create() {}

	virtual void Remove() {}

	virtual void Rename() {}

	virtual void Move() {}

	virtual void Copy() {}

	virtual void Information() {}

	virtual void Search() {}



	string GetName() 
	{
		return maxSizeOfName; 
	}
	void SetName(const std::string& filename)
	{
		maxSizeOfName = filename;
	}

	virtual ~TaskCollection() = 0 {}


};

