#include <iostream>
#include <sstream>
#include "XMLWriter.h"


namespace XML
{
	XMLWriter::XMLWriter()
	{
		_stream = &std::wostream(NULL);
	}

	XMLWriter::XMLWriter(std::wostream &stream):_stream(&stream)
	{
	
	}


	XMLWriter::~XMLWriter()
	{
	}

	std::wstring WriteProlog(XMLProlog *prolog)
	{
		if (prolog != NULL)
		{

			return prolog->ToWString();
		}
		return L"";
	}

	std::wstring WriteAttributes(const XML::AttibuteVector *attributes)
	{
		if (attributes != NULL)
		{
			std::wstring s = L" ";
			unsigned int size = attributes->size();
			for (unsigned int i = 0; i < size; i++)
			{
				s += attributes->at(i)->toWString();
				s += (i == size - 1) ? L"" : L" ";
			}
			return s;
		}
		return L"";
	}

	inline std::wstring GenerateTabs(int Count)
	{
		return std::wstring(Count, L'\t');
	}


	void XMLWriter::WriteNode(XMLNode *node, int Level)
	{
		int childSize = node->GetChildNodes()->size();
		int innerTextSize = node->inner_text_list->size();
		*_stream << std::endl;
		*_stream << GenerateTabs(Level);
		*_stream << L"<" << node->nameFull.toWString();
		*_stream << WriteAttributes(node->GetAttributes());
		*_stream << ">" ;
		
	
		for (int i = 0; i < innerTextSize; i++)
		{
			XMLNode::InnerTextStruct *its = node->inner_text_list->at(i);
			if (its->indexChildText == -1)
			{
				*_stream << its->text;
			}
			else
			{
				WriteNode(node->childNodes->at(its->indexChildText), Level + 1);
			}
		}
		if (childSize>0)
			*_stream << std::endl;
		*_stream << GenerateTabs((childSize > 0 ? Level : 0));
		*_stream << L"</" << node->nameFull.toWString() << L">";


	}

	
	void XMLWriter::WriteDocument(XMLDocument *document)
	{
		*_stream << WriteProlog(document->prolog);
		WriteNode(document->root, 0);
	}

}