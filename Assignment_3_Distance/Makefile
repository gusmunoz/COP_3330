

CC = g++

main: distance.o main.o
	$(CC) distance.o main.o -o main

Tempurature.o: distance.cpp distance.h
	$(CC) -c distance.cpp

main.o: main.cpp distance.h
	$(CC) -c main.cpp

tarfile: 
	tar -cf assignment3.tar distance.cpp distance.h Makefile
        
clean:
	rm -rf main main.o distance.o assignment3.tar
	
kill:
	find ./ -name '*~' | xargs rm

