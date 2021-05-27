#include "_text.h"

/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text()
{
    text txt;


    if ((txt = (_list *) malloc(sizeof(_list))) == NULL)
    {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
    txt = new _list;

<<<<<<< HEAD

=======
    
>>>>>>> 8589d0521c2306385f15fc2d1b12623460a2851d


    if ((txt->cursor = (_crsr *) malloc(sizeof(_crsr))) == NULL)
    {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    txt->myList = new std::list<std::string>();


    txt->cursor->line = txt->myList->end();
    txt->cursor->position = 0;


<<<<<<< HEAD
    return txt;
    free(txt);



=======
    
>>>>>>> 8589d0521c2306385f15fc2d1b12623460a2851d
}

