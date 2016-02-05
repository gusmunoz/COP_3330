

CC = g++

main: triangle.o main.o
	$(CC) triangle.o main.o -o main

triangle.o: triangle.cpp triangle.h
	$(CC) -c triangle.cpp

main.o: main.cpp triangle.h
	$(CC) -c main.cpp

tarfile: 
	tar -cf assignment1.tar triangle.cpp triangle.h Makefile
        
clean:
	rm -rf main main.o triangle.o assignment1.tar
	
kill:
	find ./ -name '*~' | xargs rm

