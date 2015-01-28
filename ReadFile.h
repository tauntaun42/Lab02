#if !defined READ_FILE
#define READ_FILE

#include "Text.h"

#include <fstream>
#include <string>
using namespace std;

class ReadFile{

private:
	ifstream input_file;
	bool _eof;
	bool closed;
	
public:
	ReadFile(const char* file_name)
	{
		ReadFile* rf;

		rf->input_file.open(file_name);
		rf->closed = false;
		rf->_eof = false;
	}
	
	void destroyReadFile(ReadFile* rf)
	{
		close(rf);
		delete rf;
	}
	
	String* readLine(ReadFile* rf)
	{
	   if (rf->closed) return NULL;
	   if (rf->_eof) return NULL;

	   string text;
	   rf->_eof = !(getline(rf->input_file, text));

	   String* str = new String((const char*) text.c_str());
	   return str;
	}
	
	bool eof(ReadFile* rf)
	{
	   return rf->_eof;
	}
	
	void close(ReadFile* rf)
	{
	   if (!rf->closed)
	   {
		  rf->input_file.close();
		  rf->closed = true;
	   }
	}
};

#endif