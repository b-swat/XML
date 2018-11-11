#pragma once
#include <locale>
#include "../stdafx.h"

namespace XML
{
	std::wstring GetWString(const char* buff, int size);
	bool IsSpaceChar(char ch);
	bool IsPunctuationChar(wchar_t ch);
	bool IsNumber(char ch);

	struct UTF8Char
	{
		char B1 = 0;
		char B2 = 0;
		char B3 = 0;
		char B4 = 0;
		
		char Lenght = 0;
	};

	class UTF8Buffer
	{
		char *buffer;
		int   lenght;
		int   bytePosition;		
	public:
		UTF8Buffer(char *Buffer,int BufSize);
		~UTF8Buffer();
		bool     ReadBOM();
		UTF8Char NextRead();
		UTF8Char NextRead(int BytePosition) {};
		void     Seek(int BytePosition);
		int      GetPosition();
		void     First();
		void     End();
		void     MoveNext(int Count);
		void     MovePred(int Count);
		bool     IsEnd();		
		bool     CheckUTF8Buffer();
		char*    GetSubBuffer(int Start, int Lenght);
		void     WriteToBuffer(char *Buffer, int SizeBuff);

		// If char is ANSI to return code else return 0;
		char     ReadANSI();
		char     ReadNextANSI();
		char*    ReadANSI(int Count);
		char*    ReadNextANSI(int Count);
		int      ReadNextSkipChars();
		

		int      FindSubANSIString(const char *Substr, int LenghtSubString);
		int      FindSubANSIChar(const char Subchar);

		void     TrimRight();
		
	};

	
}

