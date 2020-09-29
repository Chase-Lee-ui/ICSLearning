project: user-interface.o llist.o duser-interface.o dllist.o
	g++ -o project user-interface.o llist.o
	g++ -o project_debug duser-interface.o dllist.o

user-interface.o: user-interface.cpp
	g++ -ansi -pedantic-errors -Wall -c user-interface.cpp
	g++ -o duser-interface.o -Ddebug -ansi -pedantic-errors -Wall -c user-interface.cpp

llist.o: llist.cpp
	g++ -ansi -pedantic-errors -Wall -c llist.cpp
	g++ -o dllist.o -Ddebug -ansi -pedantic-errors -Wall -c llist.cpp
