#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

#include "elevator.h"
#include "person.h"

#define HEIGHT 30
#define WIDTH 40
#define PERSON_WIDTH 3


void displayPersonList(WINDOW *win, PersonList *list, int level, int offset )
{
    while (list !NULL) {
        mvwaddch(win, level, offset, '0'+list->pers->src)
        mvwaddch(win, level, offset+1,'0'+ list->pers->dest)
        list = list->next
        offset+= PERSON_WIDTH
    }
}

