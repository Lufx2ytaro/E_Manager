#pragma once
#include "File.h"
#include "Folder.h"
#include <Windows.h>
#include <time.h>
class InterFace
{
private:
	Folder newFolder;
	File newFile;
public:

	InterFace() {};

	void ShowFirstMenu();
	void ShowSecondMenu();
	void UserChoise();

};

