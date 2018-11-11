#include "XMLString.h"
#include "XMLCommon.h"

namespace XML
{
	XMLString::XMLString()
	{
		text = NULL;
		lenght = 0;
	}

	XMLString::XMLString(const char * _text, int _lenght)
	{
		text =  _text;
		lenght = _lenght;
	}

	XMLString::~XMLString()
	{
		if (text)
			delete text;
		text = NULL;
	}

	XMLString::XMLString(XMLString && v):text(v.text),lenght(v.lenght)
	{
		v.text = NULL;
		v.lenght = 0;		
	}

	XMLString & XMLString::operator=(XMLString && v)
	{
		if (text)
			delete text;
		text = v.text;
		lenght = v.lenght;
		v.text = NULL;
		v.lenght = 0;
		return *this;
	}

	std::wstring XMLString::toWString()
	{
		return GetWString(text, lenght);
	}

	const char*  XMLString::getText()
	{
		return text;
	}

	int         XMLString::getLenght()
	{
		return lenght;
	}

}
