#include "XMLAttribute.h"
#include "debug.h"
#include "UTF8Buffer.h"
#include <iostream>



namespace XML
{

	XMLAttribute::~XMLAttribute()
	{
		DEBUG_OUT_ATTR(L"Destroy XMLAttribte: " + Name())
	}

	XMLAttribute::XMLAttribute(XMLString &_name, XMLString &_value, char _quote)
	{
		m_name = std::move(_name);
		m_value = std::move(_value);
		m_quote = _quote;
		DEBUG_OUT_ATTR(L"Create XMLAttribte: " + Name())
	}

	std::wstring XMLAttribute::toWString()
	{
		wchar_t wch(m_quote);
		return m_name.toWString() + L" = " + wch + m_value.toWString() + wch;
	}

	std::wstring XMLAttribute::Name()
	{
		return m_name.toWString();
	}

	std::wstring XMLAttribute::Value()
	{
		return m_value.toWString();
	}
}