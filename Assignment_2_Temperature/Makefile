

CC = g++

main: Temperature.o main.o
	$(CC) Temperature.o main.o -o main

Tempurature.o: Temperature.cpp Tempurature.h
	$(CC) -c Tempurature.cpp

main.o: main.cpp Temperature.h
	$(CC) -c main.cpp

tarfile: 
	tar -cf assignment2.tar Temperature.cpp Temperature.h Makefile
        
clean:
	rm -rf main main.o Temperature.o assignment2.tar
	
kill:
	find ./ -name '*~' | xargs rm

