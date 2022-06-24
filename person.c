#include"person.h"

Person* createPerson(int src, int dest) {
    Person *p = malloc(sizeof(Person));
    p -> src=src;
    p -> dest=dest;

    return p;
};

PersonList* insert(Person *p, PersonList *list) {
    PersonList *new_list = malloc(sizeof(PersonList));
    new_list -> person=p;
    new_list -> next=list;

    return new_list;
};