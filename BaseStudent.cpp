#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"BaseStudent.h";

using namespace std;
double BaseStudent::getTotalGrdeForstudents(BaseStudent* stu)
{
	return 0;
}
int BaseStudent::getId() {
	return id;
}

int  BaseStudent::getGrade2() {
	return grade2;
}

int BaseStudent::getGrade3() {
	return grade3;
}

string BaseStudent::getName() {
	return name;
}

int  BaseStudent::getGrade1() {
	return grade1;
}

void BaseStudent::setId(int id)
{
	this->id = id;
}

void BaseStudent::setName(string name)
{
	this->name = name;
}

void BaseStudent::setGrade1(int grade11)
{
	this->grade1 = grade11;
}

void BaseStudent::setGrade2(int grade22)
{
	this->grade2 = grade22;
}

void BaseStudent::setGrade3(int grade33)
{
	this->grade3 = grade33;
}

int  BaseStudent::mainList()
{
	cout << "\t\t\t\t\t\t\tStudent System\t\t\t\t\t\t\t" << endl;
	cout << "The following services , choose one : " << endl << "_________________________________________________________________________________" << endl << endl;
	cout << " 1.print the content of the file on screen. " << endl << endl;
	cout << " 2.print the total grade of a student in an exam." << endl << endl;
	cout << " 3.Print the average grade in a certain exam." << endl << endl;
	cout << " 4.Print the average of total grade for all students." << endl << endl;
	cout << " 5.Update student information." << endl << endl;;
	cout << " 6.Store the updated content of the array into the file." << endl << endl;
	cout << " 7.Reload the content of the file." << endl << endl;
	cout << " 8.display records according to the total grade in descending order." << endl << endl;
	cout << " 9.Exit\t." << endl << "_________________________________________________________________________________" << endl << endl;
	cout << "Enter your choise" << endl ;
	return 0;
}

void BaseStudent::myfile(BaseStudent* stu)
{
	ifstream myFile;
	myFile.open("course.csv");
	if (!myFile.is_open())
	{
		cout << "File Did Not Open " << endl;
	}
	int j = 0;
	string  name[20], idnumber[20], grade1[20], grade2[20], grade3[20], line;
	for (int i = 0; getline(myFile, line); i++)
	{
		stringstream j(line);
		getline(j, idnumber[i], ',');
		getline(j, name[i], ',');
		getline(j, grade1[i], ',');
		getline(j, grade2[i], ',');
		getline(j, grade3[i], ',');
	}
	for (int i = 0; i < 21; i++)
	{
		istringstream(idnumber[i]) >> stu[i].id;
		stu[i].name = name[i];
		istringstream(grade1[i]) >> stu[i].grade1;
		istringstream(grade2[i]) >> stu[i].grade2;
		istringstream(grade3[i]) >> stu[i].grade3;

	}
}

void  BaseStudent::inFile(BaseStudent* stu)
{
	ofstream myFile;
	myFile.open("course.csv");
	for (int i = 0; i < 20; i++)
	{
		myFile << stu[i].getId() << "," << stu[i].getName() << "," << stu[i].getGrade1() << "," << "," << stu[i].getGrade3() << endl;
	}
	myFile.close();
}

void BaseStudent::PrintFile(BaseStudent*stu)
{
	for (int i = 0; i <21; i++)
	{
		cout << stu[i].id << "\t";
		cout << stu[i].name << "\t";
		cout << stu[i].grade1 << "\t";
		cout << stu[i].grade2 << "\t";
		cout << stu[i].grade3 << endl;
	}
}