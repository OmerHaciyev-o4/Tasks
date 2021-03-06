#include <iostream>
#include <string>
#include "ColorCode.h"
using namespace eku;
using namespace std;

class Students
{
protected:
	char* _name{};
	char* _lastName{};
	char* _fatherName{};
	int	_day_of_birth{};
	int	_month_of_birth{};
	int _year_of_birth{};
public:
	Students() {}
	Students(char* name, char* lastName, char* fatherName, int day_of_birth, int month_of_birth, int year_of_birth) : _name(name), _lastName(lastName), _fatherName(fatherName), _day_of_birth(day_of_birth), _month_of_birth(month_of_birth), _year_of_birth(year_of_birth) {}
	char* searchStudents(char* lAN, char** search, char** groups, int size)
	{
		FILE* fptr; fopen_s(&fptr, "Groups.txt", "r");
		if (fptr != NULL)
		{
			for (int i = 0; i < 500; i++)
			{
				fgets(groups[i], 50, fptr);
			}
			fclose(fptr);
		}
		for (int i = 0; i < 500; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				if (groups[i][j] == '\t')
				{
					for (int k = j; k < 50; k++) { groups[i][k] = '\0'; }	break;
				}
			}
		}
		int count = 0;
		bool yAndN = false;
		char groupName[50]{};
		for (int i = 0; i < 500; i++)
		{
			fopen_s(&fptr, groups[i], "r");
			if (fptr != NULL)
			{
				for (int j = 0; j < 50; j++) { fgets(search[j], 200, fptr); };
				fclose(fptr);
			}
			for (int j = 0; j < 50; j++)
			{
				for (int k = 0; k < 200; k++)
				{
					if (search[j][k] == lAN[k]) { count++; }
					else break;
				}
				if (count == size) { yAndN = true; for (int k = 0; k < 50; k++) { groupName[k] = groups[i][k]; } break; }
				else { count = 0; }
			}
			if (yAndN == true) { break; }
		}
		int c = 0;
		while (c != 5)
		{
			setcolor(red, black);
			cout << "Loading"; system("cls");
			cout << "Loading."; system("cls");
			cout << "Loading.."; system("cls");
			cout << "Loading..."; system("cls");
			c++;
		}
		return groupName;
	}
	char* searchTeacher(char* lAN, char** search, char** groups, int size)
	{
		FILE* fptr; fopen_s(&fptr, "Groups.txt", "r");
		if (fptr != NULL)
		{
			for (int i = 0; i < 500; i++)
			{
				fgets(groups[i], 50, fptr);
			}
			fclose(fptr);
		}
		for (int i = 0; i < 500; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				if (groups[i][j] == '\t')
				{
					for (int k = j; k < 50; k++) { groups[i][k] = '\0'; }	break;
				}
			}
		}
		int count = 0;
		bool yAndN = false;
		char groupName[50]{};
		for (int i = 0; i < 500; i++)
		{
			fopen_s(&fptr, groups[i], "r");
			if (fptr != NULL)
			{
				for (int j = 0; j < 50; j++) { fgets(search[j], 200, fptr); };
				fclose(fptr);
			}
			for (int j = 0; j < 1; j++)
			{
				for (int k = 22, l = 0; (k < 200) && (l < size); k++)
				{
					if (search[j][k] == lAN[l]) { count++; l++; }
					else break;
				}
				if (count == size)
				{
					yAndN = true;
					for (int k = 0; k < 50; k++) { groupName[k] = groups[i][k]; }
					break;
				}
				else count = 0;
			}
			if (yAndN == true) { break; }
		}
		int c = 0;
		while (c != 5)
		{
			setcolor(red, black);
			cout << "Loading"; system("cls");
			cout << "Loading."; system("cls");
			cout << "Loading.."; system("cls");
			cout << "Loading..."; system("cls");
			c++;
		}
		return groupName;
	}
};

class Koordinator : public Students
{
public:
	Koordinator() {}
	Koordinator(char* name, char* lastName, char* fatherName, int day_of_birth, int month_of_birth, int year_of_birth) : Students(name, lastName, fatherName, day_of_birth, month_of_birth, year_of_birth) {}
	void newStudent()
	{
		FILE* fptr; fopen_s(&fptr, "Students.txt", "a");
		if (fptr != NULL)
		{
			fprintf_s(fptr, "%s %s %s    %d,%d,%d\n", _lastName, _name, _fatherName, _day_of_birth, _month_of_birth, _year_of_birth);
			fclose(fptr);
		}
		int count = 0; system("cls");
		while (count != 5)
		{
			setcolor(red, black);
			cout << "Loading"; system("cls");
			cout << "Loading."; system("cls");
			cout << "Loading.."; system("cls");
			cout << "Loading..."; system("cls");
			count++;
		}
		system("cls");
		cout << "The data was successfully stored in memory" << endl;
		setcolor(white, black);
		system("PAUSE");
		setcolor(white, black);
	}
	void newGroup(char* groupName, char* teacherName, char* teacherLastName, char** students, int size, char* specialty, int semester)
	{
		FILE* fptr; fopen_s(&fptr, groupName, "a");
		if (fptr != NULL)
		{
			fprintf(fptr, "Teacher of the group: %s %s\t\t%s\\%d\n\n", teacherLastName, teacherName, specialty, semester);
			for (int i = 0; i < size; i++)
			{
				fprintf_s(fptr, "%s\n", students[i]);
			}
			fclose(fptr);
		}
		fopen_s(&fptr, "Groups.txt", "a");
		if (fptr != NULL)
		{
			fprintf_s(fptr, "%s\t\t%s\n", groupName, teacherName);
			fclose(fptr);
		}
		char gmail[60]{}, domainName[20] = "@itstep.edu.az";
		_strlwr_s(teacherLastName, 50);
		for (int i = 0, j = 0; (i < 50) && (j < 50); i++) { if (teacherLastName[i] != '\0') { gmail[j] = teacherLastName[i]; j++; } else break; }
		for (int i = 0, j = 0; (i < 60) && (j < 60); i++) { if (gmail[i] == '\0') { gmail[i] = domainName[j]; j++; } }
		fopen_s(&fptr, gmail, "a");
		if (fptr != NULL)
		{
			fprintf_s(fptr, "Dear %s teacher, the name of your new group is %s.\n\n", teacherName, groupName);
			fclose(fptr);
		}
		int count = 0; system("cls");
		while (count != 5)
		{
			setcolor(red, black);
			cout << "Loading"; system("cls");
			cout << "Loading."; system("cls");
			cout << "Loading.."; system("cls");
			cout << "Loading..."; system("cls");
			count++;
		}
		system("cls");
		cout << "The data was successfully stored in memory" << endl;
		setcolor(white, black);
		system("PAUSE");
		setcolor(white, black);
	}
	void deleteGroup(char* deleteGroupName)
	{
		int size = 0;
		for (int i = 0; i < 100; i++) { if (deleteGroupName[i] != '\0') { size++; } else break; }
		char groups[150][100]{};
		FILE* fptr; fopen_s(&fptr, "Groups.txt", "r");
		if (fptr != NULL)
		{
			for (int i = 0; i < 150; i++)
			{
				fgets(groups[i], 100, fptr);
			}
			fclose(fptr);
		}
		int count = 0;
		for (int i = 0; i < 150; i++)
		{
			for (int j = 0; j < size; j++) { if (deleteGroupName[j] == groups[i][j]) { count++; } else break; }
			if (count == size) { for (int j = 0; j < 100; j++) { groups[i][j] = '\0'; } break; }
			else count = 0;
		}
		fopen_s(&fptr, "Groups.txt", "w");
		if (fptr != NULL)
		{
			for (int i = 0; i < 150; i++) { if (groups[i] != "\0") { fprintf_s(fptr, "%s", groups[i]); } }
			fclose(fptr);
		}
		int c = 0; system("cls");
		while (c != 5)
		{
			setcolor(red, black);
			cout << "Loading"; system("cls");
			cout << "Loading."; system("cls");
			cout << "Loading.."; system("cls");
			cout << "Loading..."; system("cls");
			c++;
		}
		system("cls");
		int removed = remove(deleteGroupName);
		if (removed == 0)
		{
			setcolor(red, black);
			cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
			cout << "The group whose name you entered has been deleted :)" << endl;
			setcolor(white, black);
			system("PAUSE");
		}
	}
	void addAStudentToTheGroup(char* GroupName, char** students, int size)
	{
		FILE* fptr; fopen_s(&fptr, GroupName, "a");
		if (fptr != NULL)
		{
			for (int i = 0; i < size; i++)
			{
				fprintf_s(fptr, "%s\n", students[i]);
			}
			fclose(fptr);
		}
		int c = 0; system("cls");
		while (c != 5)
		{
			setcolor(red, black);
			cout << "Loading"; system("cls");
			cout << "Loading."; system("cls");
			cout << "Loading.."; system("cls");
			cout << "Loading..."; system("cls");
			c++;
		}
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		cout << "The group you entered included the information of the students shown :)" << endl;
		setcolor(white, black);
		system("PAUSE");
	}
	void deleteStudentFromTheGroup(char* GroupName, char* deleteStudents)
	{
		char** countStudents = new char* [1000]{};
		int size = 0;
		for (int i = 0; i < 1000; i++) { if (deleteStudents[i] != '\0') { size++; } else break; }
		for (int i = 0; i < 1000; i++) { countStudents[i] = new char[100]{}; }
		FILE* fptr; fopen_s(&fptr, GroupName, "r");
		if (fptr != NULL)
		{
			for (int i = 0; i < 1000; i++)
			{
				fgets(countStudents[i], 100, fptr);
			}
			fclose(fptr);
		}
		int count = 0;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < size + 1; j++) { if (countStudents[i][j] == deleteStudents[j]) { count++; } }
			if (count == size) { for (int j = 0; j < size; j++) { countStudents[i][j] = '\0'; } break; }
			else count = 0;
		}
		fopen_s(&fptr, GroupName, "w");
		if (fptr != NULL)
		{
			for (int i = 0; i < 100; i++) { fprintf_s(fptr, "%s", countStudents[i]); }
			for (int i = 0; i < 100; i++) { delete countStudents[i]; }
			delete[]countStudents;
			fclose(fptr);
		}
		int c = 0; system("cls");
		while (c != 5)
		{
			setcolor(red, black);
			cout << "Loading"; system("cls");
			cout << "Loading."; system("cls");
			cout << "Loading.."; system("cls");
			cout << "Loading..."; system("cls");
			c++;
		}
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		cout << "The information of the students shown to the group you entered has been deleted :)" << endl;
		setcolor(white, black);
		system("PAUSE");
	}
	void addNewTeacher(char* teacherName, char* teacherLastName, char* teacherFatherName, char* teacherPhoneNumber, char* specialty)
	{
		FILE* fptr; fopen_s(&fptr, "Teachers.txt", "a");
		if (fptr != NULL)
		{
			fprintf_s(fptr, "%s %s %s %s %s\n", teacherLastName, teacherName, teacherFatherName, specialty, teacherPhoneNumber);
			fclose(fptr);
		}
		int size = 0;
		for (int i = 0; i < 50; i++) { if (teacherLastName[i] != '\0') { size++; } else break; }
		char tteacherName[20]{};
		for (int i = 0; i < 20; i++) { tteacherName[i] = teacherName[i]; }
		char gmail[60]{}, domainName[20] = "@itstep.edu.az";
		_strlwr_s(teacherLastName, 50);
		for (int i = 0, j = 0; (i < 50) && (j < 50); i++) { if (teacherLastName[i] != '\0') { gmail[j] = teacherLastName[i]; j++; } else break; }
		for (int i = 0, j = 0; (i < 60) && (j < 60); i++) { if (gmail[i] == '\0') { gmail[i] = domainName[j]; j++; } }
		int c = 0; system("cls");

		fopen_s(&fptr, gmail, "a");
		if (fptr != NULL)
		{
			fprintf_s(fptr, "Dear %s teacher, you already work at STEP IT Academy. Good luck to you :)\n\n", tteacherName);
			fclose(fptr);
		}
		while (c != 5)
		{
			setcolor(red, black);
			cout << "Loading"; system("cls");
			cout << "Loading."; system("cls");
			cout << "Loading.."; system("cls");
			cout << "Loading..."; system("cls");
			c++;
		}
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		cout << "A new teacher has been added to the Academy :)" << endl;
		setcolor(white, black);
		system("PAUSE");
	}
};


void logo();
void menuAll();
void workKoordinator(int select);
void places_of_work();

int main()
{
	logo(); Sleep(2000); system("cls");
	setcolor(red, black);
	cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl; Sleep(2000); system("cls");
	setcolor(white, black);
	places_of_work();
}

void logo()
{
	concolinit();
	setcolor(blue, black);
	cout << R"(__      __                  __      __   ____________    ____            _____________    _______________   __              __   ____________  )" << endl;
	cout << R"(\ \     \ \                / /     / /  |            |  |    |          /             |  |  ___________  | |  \            /  | |            | )" << endl;
	cout << R"( \ \     \ \              / /     / /   |   _________|  |    |         /    __________|  | |           | | |   \          /   | |   _________| )" << endl;
	cout << R"(  \ \     \ \            / /     / /    |  |            |    |         |   |             | |           | | | |\ \        / /| | |  |           )" << endl;
	cout << R"(   \ \     \ \          / /     / /     |  |            |    |         |   |             | |           | | | | \ \      / / | | |  |           )" << endl;
	cout << R"(    \ \     \ \        / /     / /      |  |            |    |         |   |             | |           | | | |  \ \    / /  | | |  |           )" << endl;
	cout << R"(     \ \     \ \      / /     / /       |  |_________   |    |         |   |             | |           | | | |   \ \  / /   | | |  |_________  )" << endl;
	cout << R"(      \ \     \ \    / /     / /        |            |  |    |         |   |             | |           | | | |    \ \/ /    | | |            | )" << endl;
	cout << R"(       \ \     \ \  / /     / /         |   _________|  |    |         |   |             | |           | | | |     \__/     | | |   _________| )" << endl;
	cout << R"(        \ \     \ \/ /     / /          |  |            |    |         |   |             | |           | | | |              | | |  |           )" << endl;
	cout << R"(         \ \     \  /     / /           |  |            |    |         |   |             | |           | | | |              | | |  |           )" << endl;
	cout << R"(          \ \    /  \    / /            |  |            |    |         |   |             | |           | | | |              | | |  |           )" << endl;
	cout << R"(           \ \  / /\ \  / /             |  |_________   |    |_______  |   |__________   | |           | | | |              | | |  |_________  )" << endl;
	cout << R"(            \ \/ /  \ \/ /              |            |  |            | \              |  | |___________| | | |              | | |            | )" << endl;
	cout << R"(             \__/    \__/               |____________|  |____________|  \_____________|  |_______________| |_|              |_| |____________| )" << endl;
	setcolor(white, black);
}

void menuAll()
{
	setcolor(red, black);
	cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
	setcolor(blue, black);
	cout << "1) Teachers Login." << endl;
	setcolor(red, black);
	cout << "2) Students Login." << endl;
	setcolor(green, black);
	cout << "3) Koordinator Login." << endl << endl;
	cout << "0) Exit." << endl;
	setcolor(yellow, black);
	cout << "Make a choice: ";
	setcolor(white, black);
}

void menuKoordinator()
{
	setcolor(red, black);
	cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
	setcolor(blue, black);
	cout << "1) To add a new student to the Academy" << endl;
	setcolor(red, black);
	cout << "2) Create a new group" << endl;
	setcolor(green, black);
	cout << "3) Delete the group" << endl;
	setcolor(blue, black);
	cout << "4) Add a student to the group" << endl;
	setcolor(red, black);
	cout << "5) Delete a student from the group" << endl;
	setcolor(green, black);
	cout << "6) Add new Teacher" << endl;
	setcolor(blue, black);
	cout << "7) Teachers Print" << endl;
	setcolor(red, black);
	cout << "8) Students Print" << endl;
	setcolor(green, black);
	cout << "9) Groups Print" << endl;
	setcolor(dark_green, black);
	cout << "0) Exit" << endl;
	setcolor(yellow, black);
	cout << "Make a choice: ";
}

void places_of_work()
{
	int select;
	menuAll(); cin >> yellow >> select; system("cls");
	if (select == 1)
	{
		cin.ignore();
		char** search = new char* [50]{};
		char** groups = new char* [500]{};
		for (int i = 0; i < 50; i++) { search[i] = new char[200]{}; }
		for (int i = 0; i < 500; i++) { groups[i] = new char[50]{}; }
		string name{}; string lastName{}; setcolor(dark_blue, black);
		cout << "Enter your name: "; setcolor(yellow, black); getline(cin, name); setcolor(dark_blue, black);
		cout << "Enter your last name: "; setcolor(yellow, black); getline(cin, lastName); system("cls");
		char lastAndName[100]{}; char count[50]{}; int size = 0;
		for (int i = 0, j = 0; (i < 50) && (j < 50); i++) { if (lastName[i] != '\0') { lastAndName[j] = lastName[i]; j++; } else break; }
		for (int i = 0; i < 50; i++) { if (lastAndName[i] == '\0') { lastAndName[i] = ' '; break; } }
		for (int i = 0; i < 50; i++) { if (lastAndName[i] == '\0') { for (int j = i, k = 0; (j < 50) && (k < 50); j++) { if (name[k] != '\0') { lastAndName[j] = name[k]; k++; } else break; } break; } }
		for (int i = 0; i < 50; i++) { count[i] = lastAndName[i]; }
		for (int i = 0; i < 50; i++) { if (count[i] != '\0') { size++; } else break; }
		Students s;
		char* countt = new char[50]{};
		countt = s.searchTeacher(count, search, groups, size);
		char groupName[50]{};
		for (int i = 0; i < 50; i++) { groupName[i] = countt[i]; }
		for (int i = 0; i < 50; i++) { for (int j = 0; j < 200; j++) { search[i][j] = '\0'; } }
		FILE* fptr; fopen_s(&fptr, groupName, "r");
		system("cls");
		setcolor(red, black);
		char yAndN{};
		cout << "Want to look at your e-mail(y/n): "; cin >> yellow >> yAndN;
		if (yAndN == 'y' || yAndN == 'Y')
		{
			system("cls"); string emailAdrress; char* lastname = new char[40]{};
			char gmail[40]{}, domainName[20] = "@itstep.edu.az"; string ggmail;
			for (int i = 0; i < 40; i++) { if (lastName[i] != '\0') { lastname[i] = lastName[i]; } else break; }_strlwr_s(lastname, 40);
			for (int i = 0, j = 0; (i < 40) && (j < 40); i++) { if (lastname[i] != '\0') { gmail[j] = lastname[i]; j++; } else break; }
			for (int i = 0, j = 0; (i < 40) && (j < 40); i++) { if (gmail[i] == '\0') { gmail[i] = domainName[j]; j++; } } cin.ignore();
			cout << "Enter your email address: "; setcolor(yellow, black); getline(cin, emailAdrress); ggmail = gmail;
			if (emailAdrress == gmail)
			{
				system("cls");
				fopen_s(&fptr, gmail, "r");
				if (fptr != NULL)
				{
					char** pochlar = new char* [6000]{};
					for (int i = 0; i < 6000; i++) { pochlar[i] = new char[200]{}; }
					for (int i = 0; i < 6000; i++) { fgets(pochlar[i], 200, fptr); }
					for (int i = 0; i < 6000; i++)
					{
						if (pochlar[i][0] == '\0') { break; }
						for (int j = 0; j < 200; j++) { cout << pochlar[i][j]; }cout << endl;
					}
					cout << endl << endl;
					for (int i = 0; i < 6000; i++) { delete pochlar[i]; } delete[]pochlar;
					fclose(fptr);
				}
				fopen_s(&fptr, groupName, "r");
				if (fptr != NULL)
				{
					for (int i = 0; i < 50; i++) { fgets(search[i], 200, fptr); }
					for (int i = 0; i < 50; i++)
					{
						for (int j = 0; j < 200; j++) { if (search[i][j] != '\0') { cout << search[i][j]; } else break; } cout << endl;
					}
					setcolor(white, black);
					fclose(fptr);
				}
				system("PAUSE");
			}
			else
			{
				setcolor(dark_red, black);
				cout << "You entered the wrong gmail address." << endl;
				system("PAUSE");
			}
		}
		else
		{
			if (fptr != NULL)
			{
				for (int i = 0; i < 50; i++) { fgets(search[i], 200, fptr); }
				for (int i = 0; i < 50; i++)
				{
					if (search[i][0] == '\0') { break; }
					for (int j = 0; j < 200; j++)
					{
						cout << search[i][j];
					}
					cout << endl;
				}
				setcolor(white, black);
				system("PAUSE");
				fclose(fptr);
			}
			else
			{
				setcolor(dark_red, black);
				cout << "You are not in any group."; system("PAUSE");
			}
		}

		system("cls");
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); places_of_work(); }
		else { system("cls"); return; }
	}
	else if (select == 2)
	{
		cin.ignore();
		char** search = new char* [50]{};
		char** groups = new char* [500]{};
		for (int i = 0; i < 50; i++) { search[i] = new char[200]{}; }
		for (int i = 0; i < 500; i++) { groups[i] = new char[50]{}; }
		string name{}; string lastName{}; setcolor(dark_red, black);
		cout << "Enter your name: "; setcolor(yellow, black); getline(cin, name); setcolor(dark_red, black);
		cout << "Enter your last name: "; setcolor(yellow, black); getline(cin, lastName); system("cls");
		char lastAndName[100]{}; char count[50]{}; int size = 0;
		for (int i = 0, j = 0; (i < 50) && (j < 50); i++) { if (lastName[i] != '\0') { lastAndName[j] = lastName[i]; j++; } else break; }
		for (int i = 0; i < 50; i++) { if (lastAndName[i] == '\0') { lastAndName[i] = ' '; break; } }
		for (int i = 0; i < 50; i++) { if (lastAndName[i] == '\0') { for (int j = i, k = 0; (j < 50) && (k < 50); j++) { if (name[k] != '\0') { lastAndName[j] = name[k]; k++; } else break; } break; } }
		for (int i = 0; i < 50; i++) { count[i] = lastAndName[i]; }
		for (int i = 0; i < 50; i++) { if (count[i] != '\0') { size++; } else break; }
		Students s;
		char* countt = new char[50]{};
		countt = s.searchStudents(count, search, groups, size);
		char groupName[50]{};
		for (int i = 0; i < 50; i++) { groupName[i] = countt[i]; }
		for (int i = 0; i < 50; i++) { for (int j = 0; j < 200; j++) { search[i][j] = '\0'; } }
		FILE* fptr; fopen_s(&fptr, groupName, "r"); setcolor(blue, black);
		if (fptr != NULL)
		{
			for (int i = 0; i < 50; i++) { fgets(search[i], 200, fptr); }
			for (int i = 0; i < 50; i++)
			{
				if (search[i][0] == '\0') { break; }
				for (int j = 0; j < 200; j++)
				{
					cout << search[i][j];
				}
				cout << endl;
			}
			setcolor(white, black);
			system("PAUSE");
			fclose(fptr);
		}
		else
		{
			setcolor(dark_red, black);
			cout << "You are not in any group."; system("PAUSE");
		}
		system("cls");
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); places_of_work(); }
		else { system("cls"); return; }
	}
	else if (select == 3)
	{
		string login = "admin", loginl{}, password{};
		system("cls"); setcolor(dark_green, black); cin.ignore();
		cout << "Login: "; setcolor(yellow, black); getline(cin, loginl); setcolor(dark_green, black);
		cout << "Password: "; setcolor(yellow, black); getline(cin, password);
		if (loginl == login && password == login)
		{
			workKoordinator(select);
		}
		else
		{
			setcolor(red, black);
			cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
			cout << "Not correct your choice :(" << endl; Sleep(3000); system("cls");
			cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
			setcolor(green, black);
			cout << "0) Exit." << endl;
			cout << "1) Continue." << endl;
			setcolor(yellow, black);
			cout << "Make a choice: "; cin >> yellow >> select;
			setcolor(white, black);
			if (select == 0) { system("cls"); places_of_work(); }
			else { system("cls"); return; }
		}
	}
	else if (select == 0)
	{
		setcolor(white, black);
		system("cls");
		return;
	}
	else
	{
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		cout << "Not correct your choice :(" << endl; Sleep(3000); system("cls");
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); places_of_work(); }
		else { system("cls"); return; }
	}

}

void workKoordinator(int select)
{
	system("cls"); menuKoordinator(); cin >> select; setcolor(white, black);
	if (select == 1)
	{
		cin.ignore();
		system("cls");
		char name[30], lastName[30], fatherName[30];
		int day_of_birth{}, month_of_birth{}, year_of_birth{};
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(dark_green, black);
		cout << "Enter the student's name: "; setcolor(yellow, black); cin.getline(name, 30); cout << endl;
		setcolor(dark_green, black);
		cout << "Enter the student's last name: "; setcolor(yellow, black); cin.getline(lastName, 30); cout << endl;
		setcolor(dark_green, black);
		cout << "Enter the student's father's name: "; setcolor(yellow, black); cin.getline(fatherName, 30); cout << endl;
		setcolor(dark_green, black);
		cout << "Enter the student's birthday: "; cin >> yellow >> day_of_birth; cout << endl;
		setcolor(dark_green, black);
		cout << "Enter the month of the student's birth: "; cin >> yellow >> month_of_birth; cout << endl;
		setcolor(dark_green, black);
		cout << "Enter the student's year of birth: "; cin >> yellow >> year_of_birth; cout << endl;
		setcolor(white, black);
		Koordinator k(name, lastName, fatherName, day_of_birth, month_of_birth, year_of_birth);
		k.newStudent();
		system("cls");
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); workKoordinator(select); }
		else { system("cls"); return; }
	}
	else if (select == 2)
	{
		cin.ignore();
		system("cls");
		char groupName[50]{}, teacherName[30]{}, teacherLastName[50]{}, specialty[100]{}; int semester = 0;
		setcolor(red, black); cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(dark_green, black);
		cout << "Enter the name of the new group: "; setcolor(yellow, black); cin.getline(groupName, 50); setcolor(dark_green, black);
		cout << "Enter the name of the teacher: "; setcolor(yellow, black); cin.getline(teacherName, 30); setcolor(dark_green, black);
		cout << "Enter the teacher's last name: "; setcolor(yellow, black); cin.getline(teacherLastName, 50); setcolor(dark_green, black);
		cout << "Enter specialty: "; setcolor(yellow, black);  cin.getline(specialty, 100); setcolor(dark_green, black);
		cout << "Enter the semester: "; cin >> yellow >> semester; cin.ignore(); setcolor(dark_green, black);
		cout << "Enter the number of students to be included: "; cin >> yellow >> select;
		cin.ignore(); system("cls");
		setcolor(red, black); cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		char** students = new char* [select + 1]{};
		for (int i = 0; i < select; i++) { students[i] = new char[100]{}; }
		for (int i = 0; i < select; i++)
		{
			setcolor(dark_green, black);
			cout << i + 1 << ") Enter the student's last name, first name, and father name: "; setcolor(yellow, black);
			cin.getline(students[i], 100);
		}
		Koordinator k1;
		k1.newGroup(groupName, teacherName, teacherLastName, students, select, specialty, semester);
		system("cls");
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); workKoordinator(select); }
		else { system("cls"); return; }
	}
	else if (select == 3)
	{
		cin.ignore(); system("cls");
		setcolor(red, black); cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(dark_green, black); char deleteGroupName[50]{};
		cout << "Enter the name of the group to be deleted: "; setcolor(yellow, black); cin.getline(deleteGroupName, 50);
		Koordinator k2;
		k2.deleteGroup(deleteGroupName);
		system("cls");
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); workKoordinator(select); }
		else { system("cls"); return; }
	}
	else if (select == 4)
	{
		cin.ignore(); system("cls");
		setcolor(red, black); cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(dark_green, black); char GroupName[50]{};
		cout << "The group to which the student will be added: "; setcolor(yellow, black); cin.getline(GroupName, 50); setcolor(dark_green, black);
		cout << "How many students will you include?: "; cin >> yellow >> select;  setcolor(dark_green, black); cin.ignore();
		char** students = new char* [select] {};
		for (int i = 0; i < select; i++) { students[i] = new char[100]{}; }
		for (int i = 0; i < select; i++)
		{
			setcolor(dark_green, black);
			cout << i + 1 << ") Enter the student's last name, first name, and father name: "; setcolor(yellow, black);
			cin.getline(students[i], 100);
		}
		Koordinator k2;
		k2.addAStudentToTheGroup(GroupName, students, select);
		system("cls");
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); workKoordinator(select); }
		else { system("cls"); return; }
	}
	else if (select == 5)
	{
		cin.ignore(); system("cls");
		setcolor(red, black); cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(dark_green, black); char GroupName[50]{}; char deleteStudents[80]{};
		cout << "In which group are the requirements to be deleted: "; setcolor(yellow, black); cin.getline(GroupName, 50); setcolor(dark_green, black);
		cout << "Enter the last name, first name and father name of the student to be removed from the group: ";  setcolor(yellow, black); cin.getline(deleteStudents, 80); setcolor(dark_green, black);
		Koordinator k3; k3.deleteStudentFromTheGroup(GroupName, deleteStudents);
		system("cls");
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); workKoordinator(select); }
		else { system("cls"); return; }
	}
	else if (select == 6)
	{
		cin.ignore(); system("cls");
		setcolor(red, black); cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(dark_green, black); char teacherName[20]{}, teacherLastName[20]{}, teacherFatherName[20]{}, teacherPhoneNumber[15]{}, specialty[15]{};
		cout << "Enter the name of the new teacher: "; setcolor(yellow, black); cin.getline(teacherName, 20); setcolor(dark_green, black);
		cout << "Enter the new teacher's last name: ";  setcolor(yellow, black); cin.getline(teacherLastName, 20); setcolor(dark_green, black);
		cout << "Enter the father's name of the new teacher: ";  setcolor(yellow, black); cin.getline(teacherFatherName, 20); setcolor(dark_green, black);
		cout << "Enter the new teacher's phone number: ";  setcolor(yellow, black); cin.getline(teacherPhoneNumber, 15); setcolor(dark_green, black);
		cout << "What a teacher you are(JCA/PCE/Design Teacher): ";  setcolor(yellow, black); cin.getline(teacherPhoneNumber, 15); setcolor(dark_green, black);
		Koordinator k4; k4.addNewTeacher(teacherName, teacherLastName, teacherFatherName, teacherPhoneNumber, specialty);
		system("cls");
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); workKoordinator(select); }
		else { system("cls"); return; }
	}
	else if (select == 7)
	{
		cin.ignore(); system("cls");
		char** count = new char* [3000]{};
		for (int i = 0; i < 3000; i++) { count[i] = new char[300]{}; }
		FILE* fptr; fopen_s(&fptr, "Teachers.txt", "r");
		if (fptr != NULL)
		{
			for (int i = 0; i < 3000; i++) { fgets(count[i], 300, fptr); }
			for (int i = 0; i < 3000; i++) { if (count[i][0] == '\0') { break; } else printf_s("%s\n", count[i]); }
			for (int i = 0; i < 3000; i++) { delete count[i]; } delete[] count;
			fclose(fptr);
		}
		system("PAUSE"); system("cls");
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); workKoordinator(select); }
		else { system("cls"); return; }
	}
	else if (select == 8)
	{
		cin.ignore(); system("cls");
		char** count = new char* [5000]{};
		for (int i = 0; i < 5000; i++) { count[i] = new char[500]{}; }
		FILE* fptr; fopen_s(&fptr, "Students.txt", "r");
		if (fptr != NULL)
		{
			for (int i = 0; i < 5000; i++) { fgets(count[i], 500, fptr); }
			for (int i = 0; i < 5000; i++) { if (count[i][0] == '\0') { break; } else printf_s("%s\n", count[i]); }
			for (int i = 0; i < 5000; i++) { delete count[i]; } delete[] count;
			fclose(fptr);
		}
		system("PAUSE"); system("cls");
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); workKoordinator(select); }
		else { system("cls"); return; }
	}
	else if (select == 9)
	{
		cin.ignore(); system("cls");
		char** count = new char* [3000]{};
		for (int i = 0; i < 500; i++) { count[i] = new char[50]{}; }
		FILE* fptr; fopen_s(&fptr, "Groups.txt", "r");
		if (fptr != NULL)
		{
			for (int i = 0; i < 500; i++) { fgets(count[i], 50, fptr); }
			for (int i = 0; i < 500; i++)
			{
				if (count[i][0] == '\0') { break; }
				printf_s("%s\n", count[i]);
			}
			for (int i = 0; i < 500; i++) { delete count[i]; } delete[] count;
			fclose(fptr);
		}
		system("PAUSE"); system("cls");
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); workKoordinator(select); }
		else { system("cls"); return; }
	}
	else if (select == 0)
	{
		system("cls"); places_of_work();
	}
	else
	{
		setcolor(red, black);
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		cout << "Not correct your choice :(" << endl; Sleep(3000); system("cls");
		cout << "\t\tSTEP Portal-a xosgelmishsiniz :)" << endl;
		setcolor(green, black);
		cout << "0) Exit." << endl;
		cout << "1) Continue." << endl;
		setcolor(yellow, black);
		cout << "Make a choice: "; cin >> yellow >> select;
		setcolor(white, black);
		if (select == 0) { system("cls"); workKoordinator(select); }
		else { system("cls"); return; }
	}
}
