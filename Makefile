Joust: Knight.o Weapon.o Random.o
	g++ j.cpp Knight.o Weapon.o Random.o -o Joust

Knight.o: Knight.cpp Knight.h Weapon.cpp Random.cpp
	g++ -c Knight.cpp Weapon.cpp Random.cpp

Weapon.o: Weapon.cpp Weapon.h Random.cpp
	g++ -c Weapon.cpp Random.cpp 

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

clean:
	rm *.o Joust
