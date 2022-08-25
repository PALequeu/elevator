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
    b ->nbFloor=nbFloor;
    b ->elevator=elevator;
    b ->waitingLists=waitingLists;

    return b
};

int lengthOf(PersonList* list){
    if (list->next != NULL)
        {return 1 + lengthOf(list->next)}
    else
        {return 1}
};


PersonList* exitElevator(Elevator *e){
    PersonList *persons = e->persons;
    PersonList newlist = NULL;

    while (*persons != NULL){
        person = persons->person;
        if (person->src != e->currentFloor) {
            newlist = insert(person,newlist);
        }
        persons = persons->next;
    }

    return newlist
};

PersonList* enterElevator(Elevator *e, PersonList *list){
    PersonList* personsElevator = e->persons;
    PersonList* personsFloor = list
    
    while (lengthOf(personsElevator) < e->capacity){
        personsElevator= insert(personsFloor->person,personsElevator);
        personsFloor = personsFloor->next;   
    }

    return personsElevator
};

void stepElevator(Building *b){
    Elevator* elevator = b->elevator;

    while(elevator->currentFloor != elevator->targetFloor){
        if (elevator->currentFloor > elevator->targetFloor){
            elevator->currentFloor = elevator->currentFloor - 1
        }
        else{
            elevator->currentFloor = elevator->currentFloor + 1
        }
    }

    exitElevator(elevator);
    enterElevator(elevator,(e->waitingLists)[(elevator->currentFloor)-1])
};



