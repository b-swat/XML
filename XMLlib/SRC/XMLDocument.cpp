#include "XMLDocument.h"
#include "XMLCommon.h"

namespace XML
{

	XMLDocument::XMLDocument()
	{
		prolog = NULL;
		root = NULL;
		namespaces = new NameSpaceVector();
	}


	XMLDocument::~XMLDocument()
	{
		if (prolog)
			delete prolog;
		prolog = NULL;

		if (root)
			delete root;
		root = NULL;

		if (namespaces)
			DestoryVector<NameSpaceVector>(namespaces);
		namespaces = NULL;
	}

	void XMLDocument::SetProlog(XMLProlog *Prolog)
	{
		if (prolog)
			delete prolog;
		prolog = Prolog;
	}


	void XMLDocument::SetRoot(XMLNode* _root)
	{
		if (root)
			delete root;
		root = _root;
	}

	XMLNode* XMLDocument::Root()
	{
		return root;
	}


	bool XMLDocument::AddNameSpaces(NameSpaceVector *_vector)
	{
		namespaces->insert(namespaces->end(), _vector->begin(), _vector->end());
		return true;
	}


}