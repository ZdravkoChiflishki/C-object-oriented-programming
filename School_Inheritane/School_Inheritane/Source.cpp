#include<iostream>
#include<cstring>
using namespace std;
const int MAX_SIZE = 20;

class Student
{
private:
	char *S_Name;
	char *S_FatherName;
	char *S_Surname;
	int age;
	int facNumber;
public:
	string getStudentsFirstName() const
	{
		return S_Name;
	}
	string getStudentsMiddleName() const
	{
		return S_FatherName;
	}
	string getStudentsLastName() const
	{
		return S_Surname;
	}
	int getAge() const
	{
		return age;
	}
	int getFacNumber() const
	{
		return facNumber;
	}

	Student(char *_firstName = "", char *_middleName = "", char *_lastName = "", int _age = 0, int _facNumber = 0) : age(_age), facNumber(_facNumber)
	{
		S_Name = new char[strlen(_firstName) + 1];
		strcpy_s(S_Name, strlen(S_Name), _firstName);
		S_FatherName = new char[strlen(_middleName) + 1];
		strcpy_s(S_FatherName, strlen(S_FatherName), _middleName);
		S_Surname = new char[strlen(_lastName) + 1];
		strcpy_s(S_Surname, strlen(S_Surname), _lastName);
	}
	Student(const Student& stu)
	{
		this->age = stu.age;
		this->facNumber = stu.facNumber;
		S_Name = new char[strlen(stu.S_Name) + 1];
		S_FatherName = new char[strlen(stu.S_FatherName) + 1];
		S_Surname = new char[strlen(stu.S_Surname) + 1];
		strcpy_s(S_Name, strlen(S_Name), stu.S_Name);
		strcpy_s(S_FatherName, strlen(S_FatherName), stu.S_FatherName);
		strcpy_s(S_Surname, strlen(S_Surname), stu.S_Surname);
	}
	Student& operator=(const Student& other)
	{
		if (this != &other)
			S_Name = new char[strlen(other.S_Name) + 1];
		strcpy_s(S_Name, strlen(S_Name), other.S_Name);
		S_FatherName = new char[strlen(other.S_FatherName) + 1];
		strcpy_s(S_FatherName, strlen(S_FatherName), other.S_FatherName);
		S_Surname = new char[strlen(other.S_Surname) + 1];
		strcpy_s(S_Surname, strlen(S_Surname), other.S_Surname);
		age = other.age;
		facNumber = other.facNumber;
		return (*this);

	}
	~Student()
	{
		delete[] S_Name;
		delete[] S_FatherName;
		delete[] S_Surname;
	}

	void printStudents()
	{
		cout << "Student's name: " << S_Name << " " << S_FatherName << " " << S_Surname;
		cout << endl;
	}
};

class Teacher
{
private:
	char *T_Name;
	char *T_FatherName;
	char *T_Surname;
	char *discipline;
public:
	string getFirstName() const
	{
		return T_Name;
	}
	string getMiddleName() const
	{
		return T_FatherName;
	}
	string getLastName() const
	{
		return T_Surname;
	}
	string getDiscipline() const
	{
		return discipline;
	}
	Teacher(const char *_firstName = "", const char *_middleName = "", const char *_lastName = "", const char *_discipline = "")
	{
		T_Name = new char[strlen(_firstName) + 1];
		strcpy_s(T_Name, strlen(T_Name), _firstName);
		T_FatherName = new char[strlen(_middleName) + 1];
		strcpy_s(T_FatherName, strlen(T_FatherName), _middleName);
		T_Surname = new char[strlen(_lastName) + 1];
		strcpy_s(T_Surname, strlen(T_Surname), _lastName);
		discipline = new char[strlen(_discipline) + 1];
		strcpy_s(discipline, strlen(discipline), _discipline);
	}
	Teacher(const Teacher& teach)
	{
		T_Name = new char[strlen(teach.T_Name) + 1];
		T_FatherName = new char[strlen(teach.T_FatherName) + 1];
		T_Surname = new char[strlen(teach.T_Surname) + 1];
		strcpy_s(T_Name, strlen(T_Name), teach.T_Name);
		strcpy_s(T_FatherName, strlen(T_FatherName), teach.T_FatherName);
		strcpy_s(T_Surname, strlen(T_Surname), teach.T_Surname);
		discipline = new char[strlen(teach.discipline) + 1];
		strcpy_s(discipline, strlen(discipline), teach.discipline);
	}
	Teacher& operator=(const Teacher& other)
	{
		if (this != &other)
			T_Name = new char[strlen(other.T_Name) + 1];
		strcpy_s(T_Name, strlen(T_Name), other.T_Name);
		T_FatherName = new char[strlen(other.T_FatherName) + 1];
		strcpy_s(T_FatherName, strlen(T_FatherName), other.T_FatherName);
		T_Surname = new char[strlen(other.T_Surname) + 1];
		strcpy_s(T_Surname, strlen(T_Surname), other.T_Surname);
		discipline = new char[strlen(other.discipline) + 1];
		strcpy_s(discipline, strlen(discipline), other.discipline);
		return (*this);
	}
	~Teacher()
	{
		delete[] T_Name;
		delete[] T_FatherName;
		delete[] T_Surname;
		delete[] discipline;

	}
	void printTeacher()
	{
		cout << "Teacher's name: " << T_Name << " " << T_FatherName << " " << T_Surname << endl;
	}
};

class School
{
private:
	Teacher *teachers;
	Student *students;
	int StudentsCount;
	int TeachersCount;
public:
	School(Student* students, int StudentsCount, Teacher* teachers, int TeachersCount)
	{
		this->StudentsCount = StudentsCount;
		this->TeachersCount = TeachersCount;
		this->students = new Student[StudentsCount];
		this->teachers = new Teacher[TeachersCount];

		for (int i = 0; i < StudentsCount; i++)
		{
			this->students[i] = students[i];
		}
		for (int j = 0; j < TeachersCount; j++)
		{
			this->teachers[j] = teachers[j];
		}
	}
	School(const School& s)
	{
		School(s.students, s.StudentsCount, s.teachers, s.TeachersCount);
	}
	School& operator =(School& other)
	{
		delete[] students;
		delete[] teachers;

		School *templ = new School(other);
		*this = *templ;
		return *this;
	}
	~School()
	{
		delete[] students;
		delete[] teachers;
	}
	Student studentByFacultyNumber(int facNumber) const
	{
		for (int i = 0; i < StudentsCount; i++)
		{
			if (students[i].getFacNumber() == facNumber)
			{
				return students[i];
			}
		}
	}
	void printStudentsInfo(string S_NAME, string S_FATHERNAME, string S_SURNAME)
	{

		for (int i = 0; i < StudentsCount; i++)
		{
			if ((students[i].getStudentsFirstName().compare(S_NAME) == 0) && (students[i].getStudentsMiddleName().compare(S_FATHERNAME) == 0) && (students[i].getStudentsLastName().compare(S_SURNAME) == 0));
			{
				students[i].printStudents();
			}

		}
	}
	void printTeachersInfo(string discipline)
	{
		for (int i = 0; i < TeachersCount; i++)
		{
			if (teachers[i].getDiscipline().compare(discipline) == 0)
			{
				teachers[i].printTeacher();
			}
		}
	}
};

int main()
{
	Student students[5] = {
		Student("Zdravko", "Ivanov" , "Chiflishki", 19 , 71626),
		Student("Simeon", "Petrov", "Petrov",19,89001),
		Student("Ivan", "Petkanov", "Stoqnov", 21, 44908),
		Student("Marin", "Markov", "Stamenov",20, 78112),
		Student("Stanislava", "Ilieva", "Ilcheva", 19, 19022)
	};

	Teacher teachers[5] = {
		Teacher("Dragana", "Aleksandrova", "Chiflishka", "Matematika"),
		Teacher("Dimitrina", "Rachkova", "Mielva", "Matematika"),
		Teacher("Mariq", "Petkova", "Chiflishka","InformaticSystems"),
		Teacher("Petar", "Ivanov", "Kalimanov", "Programirane"),
		Teacher("Georgi", "Ivanov", "Chiflishki", "Geometriq")
	};
	School school(students, (sizeof(students) / sizeof(*students)), teachers, (sizeof(teachers) / sizeof(*teachers)));
	school.printTeachersInfo("InformaticSystems");
	school.printStudentsInfo("Ivan", "Petkanov", "Chiflishki");
	system("pause");
	return 0;
}