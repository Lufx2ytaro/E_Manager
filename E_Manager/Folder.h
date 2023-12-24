#pragma once
#include"TaskCollection.h"

class Folder : public TaskCollection
{
private:

	string folderName;
	string roadOfFolder;


public:

	Folder(string folderName) : TaskCollection{ folderName } {};
	Folder():TaskCollection(){}


	virtual void create();
	virtual void Remove();
	virtual void Copy();
	virtual void Open();
	virtual void Rename();
	virtual void Move();
	virtual void Search();
	virtual void Information();



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

