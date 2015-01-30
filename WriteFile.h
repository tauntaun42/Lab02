#if !defined WRITE_FILE
#define WRITE_FILE

#include "Text.h"

#include <fstream>
using namespace std;

class WriteFile
{
	private:
		ofstream output_file;
		bool closed;
		
	public:
	
		WriteFile(const char* file_name);
		~WriteFile();
		void writeLine(String* line);
		void close ();
};

#endif
