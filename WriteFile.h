#if !defined WRITE_FILE
#define WRITE_FILE

#include "Text.h"

#include <fstream>
#include <sstream>
using namespace std;

class WriteFile
{
protected:
	bool closed;
	ofstream output_file;
		
public:

	WriteFile(const char* file_name)
	{
		output_file.open(file_name);
		closed = false;
	}

	~WriteFile()
	{
		close();
	}

	void close()
	{
		if (!closed)
		{
			output_file.close();
			closed = true;
		}
	}

	void writeLine(String* line)
	{
		if (!closed && line->length() > 0)
		{
			output_file << line->getText() << endl;
		}
	}
};

#endif