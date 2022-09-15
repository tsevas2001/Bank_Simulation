CC = g++ -g3 -g -std=c++11 

Ask2: main.o bank.o cashier.o

	$(CC) -o Ask2 main.o cashier.o bank.o -lm

main.o: main.cpp cashier.cpp bank.cpp

	$(CC) -c main.cpp bank.cpp cashier.cpp 

bank.o: bank.cpp

	$(CC) -c bank.cpp

cashier.o: cashier.cpp

	$(CC) -c cashier.cpp

run:

	./Ask2 5 3 20 30

valgrind:

	valgrind --leak-check=yes ./Ask2 5 15 10 10

clean: 

	rm -f *.o

	