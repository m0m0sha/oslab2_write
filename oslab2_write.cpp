#include <iostream>
#include<windows.h>
#include<string>

using namespace std;
void Write();

int main()
{
	Write();
	return 0;
}

void Write()
{
	string file;
	string FileMap;
	HANDLE FileHandle;
	HANDLE HandleMap;
	char* str = new char[5000];
	LPVOID Memory;
	cout << "Enter file path: ";
	cin >> file;
	cout << "Enter file name: ";
	cin >> FileMap;
	FileHandle = CreateFileA(file.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	HandleMap = CreateFileMappingA(FileHandle, NULL, PAGE_READWRITE, 0, 1024, FileMap.c_str());
	Memory = MapViewOfFile(HandleMap, FILE_MAP_ALL_ACCESS, 0, 0, 0); //projecting a fragment of a file into memory
	if (Memory)
	{
		cout << "Enter the string: ";
		cin >> str;
		memcpy(Memory, str, strlen(str) * sizeof(char));
		cout << "Run a reader to read data from input\n";
		cout << "Waiting: ";
		cin >> file;
		UnmapViewOfFile(Memory); //file projection completion
	}
	else
	{
		cout << "ERROR";
	}
}