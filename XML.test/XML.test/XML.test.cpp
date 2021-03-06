#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <crtdbg.h>

#include "UTF8Buffer.h"
#include "XMLReader.h"
#include "XMLWriter.h"


#define PATH_SEP '\\'
#define GETCWD _getcwd
#define CHDIR _chdir

using namespace std;



void ReadXML()
{
	int length;
	char * buffer;

	ifstream is;
	is.open("..\\Debug\\4.txt", ios::binary);
	// get length of file:
	is.seekg(0, ios::end);
	length = is.tellg();
	is.seekg(0, ios::beg);
	// allocate memory:
	buffer = new char[length];
	// read data as a block:
	is.read(buffer, length);
	is.close();

	XML::UTF8Buffer buff(buffer, length);
	cout << "Check UTF8 " << buff.CheckUTF8Buffer() << endl;

	buff.First();
	while (!buff.IsEnd())
	{
		XML::UTF8Char charu8 = buff.NextRead();
		if (charu8.Lenght == 1)
		{
			cout << charu8.B1 << endl;
		}
		else
			cout << "Read UTF8 code lenght " << (int)charu8.Lenght << endl;
	}
	delete buffer;
}

void ReadXML2()
{
	std::locale rus("rus_rus.866");

	std::wcout.imbue(rus);

	int length;
	char * buffer;

	ifstream is;
	is.open("..\\Debug\\4.xml", ios::binary);
	// get length of file:
	is.seekg(0, ios::end);
	length = is.tellg();
	is.seekg(0, ios::beg);
	// allocate memory:
	buffer = new char[length];
	// read data as a block:
	is.read(buffer, length);
	is.close();
	
	XML::XMLReader *reader = new XML::XMLReader();
	
	XML::XMLDocument *doc = reader->XMLReadString(buffer, length);

	cout << "Error code = " << reader->GetError() << std::endl;
	for (auto str : reader->GetErrorList())
	{
		wcout << L"Error string = " << str << std::endl;
		
	}

	XML::XMLWriter *writer = new XML::XMLWriter(wcout);
	if (doc!= NULL && reader->GetError()== 0)
		writer->WriteDocument(doc);

	delete writer;
	delete reader;
	delete buffer;
	delete doc;
}

int main()
{

	
	_CrtMemState _ms;
	_CrtMemCheckpoint(&_ms);
//	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	

	
	for (int i = 0; i < 1; i++)
	{
		
		ReadXML2();
		//cout << i << endl;
		//getchar();
	}

	_CrtMemDumpAllObjectsSince(&_ms);
	getchar();
    return 0;
}

