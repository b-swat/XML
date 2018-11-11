#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <crtdbg.h>

namespace XML
{
	class XMLString
	{
		const char *text;
		int   lenght;
		XMLString(const XMLString &v) = delete;
		XMLString& operator = (XMLString &v) = delete;
	public:
		XMLString();
		XMLString(const char *_text, int _lenght);
		~XMLString();

		XMLString(XMLString &&v);
		XMLString& operator=(XMLString&& v);

		const char* getText();
		int         getLenght();
		std::wstring toWString();
	};
}

