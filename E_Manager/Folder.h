#pragma once
#include"TaskCollection.h"

class Folder : public TaskCollection
{
private:

	string folderName;


public:

	Folder(string folderName) : TaskCollection{ folderName } {};
	Folder():TaskCollection(){}


	virtual void create();
	virtual void Remove();
	virtual void Copy();



	void SetFolder(const string& folder)
	{
		folderName = folder;
	}
	string GetFolder()
	{
		return folderName;
	}

	virtual ~Folder()=0 {}
};

