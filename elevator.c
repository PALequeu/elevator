#include"stdlib.h"
#include"person.h"
#include"elevator.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons) {
    Elevator *e = malloc(sizeof(Elevator));
    e -> capacity=capacity;
    e -> currentFloor=currentFloor;
    e -> targetFloor=currentFloor;
    e -> persons=persons;

    return e
};

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists) {
    Building *b = malloc(sizeof(Building));
    b -> nbFloor=nbFloor;
    b ->elevator=elevator;
    b ->waitingLists=waitingLists;

    return b
};

PersonList* exitElevator(Elevator *e){
    PersonList *persons = *(e+3);

    PersonList newlist = NULL;

    while (*persons != NULL){
        person = *persons;
        if (*(person+1) != *(e+2)) {
            newlist = insert(person,newlist)
        }
        persons = *(persons+1)

    }
}