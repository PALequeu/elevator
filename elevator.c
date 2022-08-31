#include"stdlib.h"
#include"person.h"
#include"elevator.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList* persons) {
    Elevator *e = malloc(sizeof(Elevator));
    e -> capacity=capacity;
    e -> currentFloor=currentFloor;
    e -> targetFloor=currentFloor;
    e -> persons=persons;

    return e;
};



Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists) {
    Building *b = malloc(sizeof(Building));
    b ->nbFloor=nbFloor;
    b ->elevator=elevator;
    b ->waitingLists=waitingLists;

    return b;
};


int size(PersonList* list){
    int n=0;
    while(list){
        n++;
        list = list -> next;
    }
    return n;
};


PersonList* exitElevator(Elevator *e){
    PersonList *persons = e->persons;
    PersonList *newlist = NULL;

    while (persons){
        Person *person = persons->person;
        if (person->src != e->currentFloor) {
            newlist = insert(person,newlist);
        }
        persons = persons->next;
    }

    return newlist;
};


PersonList* enterElevator(Elevator *e, PersonList *list){
    PersonList* personsElevator = e->persons;
    PersonList* personsFloor = list;
    
    while (size(personsElevator) < e->capacity){
        personsElevator= insert(personsFloor->person,personsElevator);
        personsFloor = personsFloor->next;   
    }

    return personsElevator;
};

void stepElevator(Building *b){
    Elevator* elevator = b->elevator;
    
    if (elevator->currentFloor > elevator->targetFloor){
            elevator->currentFloor = elevator->currentFloor - 1;
        }
    else if(elevator->currentFloor < elevator->targetFloor){
            elevator->currentFloor = elevator->currentFloor + 1;
        }
    
    if(elevator->currentFloor == elevator->targetFloor)
    {exitElevator(elevator);
    enterElevator(elevator,(b->waitingLists)[(elevator->currentFloor)-1]);};
};



