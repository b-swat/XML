#pragma once
#include <iostream>
#include "XMLparser.h"
#include "XMLDocument.h"
#include "../stdafx.h"

namespace XML
{
	class XMLWriter
	{
		std::wostream* _stream;
		void WriteNode(XMLNode *node, int Level);
	public:

		XMLWriter();		
		XMLWriter(std::wostream &stream);
		~XMLWriter();

		void WriteDocument(XMLDocument *document);

	};
}
