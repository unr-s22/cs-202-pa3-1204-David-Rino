program: main.o Money.o Account.o
	g++ -o program main.o Money.o Account.o

main.o: main.cpp
	g++ -c main.cpp

Money.o: Money.cpp
	g++ -c Money.cpp

Account.o: Account.cpp
	g++ -c Account.cpp

clean:
	rm program *.o