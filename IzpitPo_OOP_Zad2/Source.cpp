/*Да се реализира абстрактен базов клас, представляващ обект от файловата система. Този обект се характеризира с име. Класът да предоставя метод за определяне на заеманото от обекта дисково пространство.
- Да се реализира наследник на този клас, представляващ файл. Файлът трябва да пази информация за размера си.
- Да се реализира наследник на този клас, представляващ директория. Директорията съхранява масив от обекти от файловата система.
- Напишете програма, която да създаде директория, съдържаща поне една поддиректория и поне един файл, и след това да изведе на екрана размера на тази директория.
*/
#include<iostream>
using namespace std;
class Object {
public:
	virtual double getFileSize() const = 0;
	virtual ~Object() {};
};
class File : public Object {
private:
	char *Fname;
	double FileSize;
public:
	File(const char* _Fname = "KB", double FS = 1024) : FileSize(FS), Object() {
		Fname = new char[strlen(_Fname) + 1];
		strcpy(Fname, _Fname);
	};
	double getFileSize() const {
		return FileSize;
	}
	~File() {
		delete[] Fname;
	}
};
class Directory : public Object {
private:
	char *Dname;
	Object **files;
	int count;
public:
	Directory() = default;
	Directory(Object *_files[], const char* _Dname = " ", int count = 0) :count(count) {
		Dname = new char[strlen(_Dname) + 1];
		strcpy(Dname, _Dname);
		files = new Object*[count];
		for (int i = 0; i < count; i++) {
			files[i] = _files[i];
		}
	};
	~Directory() {
		delete[] files;
		delete[] Dname;
	}
	double getFileSize() const {
		double sum = 0;
		for (int i = 0; i < count; i++) {
			sum += files[i]->getFileSize();
		}
		return sum;
	}
};
int main() {
	File  file;
	Directory  dir;
	Object* Object[] = { &file, &dir };
	file.getFileSize();
	dir.getFileSize();

	system("pause");
	return 0;
}