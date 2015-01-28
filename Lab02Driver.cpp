#include "ReadFile.h"
#include "WriteFile.h"
#include "String.h"
#include "Tokens.h"

#include <iostream>
int main()
{
   ReadFile* rf = new ReadFile("cds.txt");
   WriteFile* wf = new WriteFile("out.txt");

   while(!rf->eof(rf))
   {
      String* line = rf->readLine(rf);
      wf->writeLine(line);
      delete line;
   }

   rf->close(rf);
   wf->close();
   delete rf;
   delete wf;

   return 0;
}