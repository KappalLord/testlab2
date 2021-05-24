#include <stdio.h>
#include <string.h>
#include "_text.h"

int mklb(text txt, int line_num)
{
    /*Если заданный номер строки или позиция курсора меньше 0 */
    if (line_num < 0)
        return -1;

    /* Итератор строки, в которой должен стоять курсор */
    std::list<std::string>::iterator current = txt->myList->begin();
    int index = 0;


    /*Идём до заданной строки */
    bool find_flag = false;
    while (current != txt->myList->end()) {
        if (line_num == index) {
            find_flag = true;
            break;
        }
        current++;
        index++;
    }

    /*Если заданный номер строки больше строк в файле */
    if (!find_flag)
        return -1;


    /*Присваиваем новые позиции строки и курсора */
    txt->cursor->line = current;
    txt->cursor->position = 0;

    return 0;
}


