person.o : person.c person.h
	gcc -c person.c

elevator.o : elevator.c elevator.h
	gcc -c elevator.c

main.o : main.c person.o elevator.o
	gcc -c main.c -lncurses

main: main.o person.o elevator.o
	gcc -o TDelev person.o elevator.o main.o -lncurses

run :
	./TDelev

clean:
	rm -f main *.o
