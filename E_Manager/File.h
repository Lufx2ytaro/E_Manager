#pragma once
#include"TaskCollection.h"

class File : public TaskCollection
{
private:
	string nameOfFile;
	string roadOfFile;
public:
	File(string nameOfFile) : TaskCollection{ nameOfFile } {};
	File() :TaskCollection() {};


	int tick = 0;
	virtual void Create();
	virtual void deleteFile();
	virtual void Copy();
	virtual void Open();
	virtual void Rename();
	virtual void Move();
	virtual void Information();
	virtual void Search();




	string getFile()
	{
		return nameOfFile;
	}
	void setFile(const string& file)
	{
		nameOfFile = file;
	}

	virtual ~File()=0 {};
};

