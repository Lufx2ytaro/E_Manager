#include "InterFace.h"

void InterFace::ShowFirstMenu()
{
	cout << "\t\t\tPlease, Choose action: " << endl;
	cout << "1 - Show Disk Information" << endl;
	cout << "2 - Create File" << endl;
	cout << "3 - Create Folder" << endl;
	cout << "4 - Search " << endl;
	cout << "0 - EXIT" << endl;
}

void InterFace::ShowSecondMenu()
{
	cout << "1 -> RENAME" << endl;
	cout << "2 -> DELETE" << endl;
	cout << "3 -> MOVE" << endl;
	cout << "4 -> GET INFO" << endl;
	cout << "5 -> COPY" << endl;
	cout << "0 -> BACK MAIN MENU" << endl;
}

void InterFace::UserChoise()
{
    int firstChoise = 0;
    int secondChoise = 0;

    std::wstring wideString;  // ���������: ������ LPCWSTR � ������ ���������� wstring

    do
    {
        ShowFirstMenu();
        std::cin >> firstChoise;  // ���������: ������������� std::cin ������ cin
        switch (firstChoise)
        {
        case 1:
        {
            system("CLS");
            newFile.Open();
            if (newFile.tick > 0)  // ���������: ����������� ���������� ���������� "tick"
            {
                newFile.tick = 0;
            }
            do {
                ShowSecondMenu();
                std::cin >> secondChoise;  // ���������: ������������� std::cin ������ cin
                switch (secondChoise)
                {
                    // ... (��������� ��� �� �������)
                }
            } while (secondChoise != 0);
            break;
        }
        case 2:
        {
            system("CLS");
            newFile.Create();
            break;
        }
        case 3:
        {
            system("CLS");
            newFolder.Create();  // ���������: ����� ������ Create() ������� newFolder
            break;
        }
        case 4:
        {
            system("CLS");
            newFile.Search();
            break;
        }
        case 0:
            system("CLS");
            std::cout << "\n\t\t\t\tCLOSING THE APPLICATION\n";
            std::cout << "\t\t\t\t       .";
            Sleep(500);
            std::cout << ".";
            Sleep(500);
            std::cout << ".";
            Sleep(500);
            std::cout << ".\n";
            break;
        default:
            system("CLS");
            std::cout << "\t\t\tWRONG COMMAND";
            Sleep(1000);
            system("CLS");
            break;
        }
    } while (firstChoise != 0);
}