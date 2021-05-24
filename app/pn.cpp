#include "_text.h"
#include <iostream>
#include <iterator>
void pn(text txt, std::string contents)
{
    txt->cursor->line++;
    txt->myList->insert(txt->cursor->line--,contents);
   
	}
