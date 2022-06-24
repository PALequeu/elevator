#include"person.h"
#include<stdlib.h>

Person* createPerson(int src, int dest) {
    Person *per = malloc(sizeof(Person));
    per -> src=src;
    per -> dest=dest;

    return p;
};

PersonList* insert(Person *p, PersonList *list) {
    PersonList *newlist = malloc(sizeof(PersonList));
    newlist -> person=p;
    newlist -> next=list;

    return newlist;
};