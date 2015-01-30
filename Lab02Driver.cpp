#include "ReadFile.h"
#include "WriteFile.h"
#include "String.h"
#include "Tokens.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	ReadFile* rf = new ReadFile("cds.txt");
	WriteFile* wf = new WriteFile("out.txt");

	while(!rf->eof())
	{
		String* line = rf->readLine();
		wf->writeLine(line);
		delete line;
	}

	rf->close();
	wf->close();
	delete rf;
	delete wf;

	return 0;
}