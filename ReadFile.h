#if !defined READ_FILE
#define READ_FILE

#include "Text.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReadFile{

protected:
	ifstream input_file;
	bool _eof;
	bool closed;
	
public:

	ReadFile(const char* file_name)
	{
	   input_file.open(file_name);
	   closed = false;
	   _eof = false;
	}

	~ReadFile()
	{
	   close();
	}

	bool eof()
	{
	   return _eof;
	}

	void close()
	{
	   if (closed)
	   {
		  input_file.close();
		  closed = true;
	   }
	}

	String* readLine()
	{
	   if (closed) return NULL;
	   if (_eof) return NULL;

	   string text;
	   _eof = !(getline(input_file, text));

	   String* str = new String((const char*) text.c_str());
	   return str;
	}
};

#endif