
game: main.o menu.o utility.o space.o plantStore.o house.o catToyStore.o cleaningStore.o postOffice.o bank.o game.o
	g++ -g -std=c++11 main.o menu.o utility.o space.o plantStore.o house.o catToyStore.o cleaningStore.o postOffice.o bank.o game.o -o game

menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp
	
utility.o: utility.cpp utility.hpp
	g++ -c -std=c++11 utility.cpp

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

space.o: space.cpp space.hpp
	g++ -c -std=c++11 space.cpp
	
house.o: house.cpp house.hpp
	g++ -c -std=c++11 house.cpp
	
catToyStore.o: catToyStore.cpp catToyStore.hpp
	g++ -c -std=c++11 catToyStore.cpp
	
plantStore.o: plantStore.cpp plantStore.hpp
	g++ -c -std=c++11 plantStore.cpp
	
cleaningStore.o: cleaningStore.cpp cleaningStore.hpp
	g++ -c -std=c++11 cleaningStore.cpp
	
postOffice.o: postOffice.cpp postOffice.hpp
	g++ -c -std=c++11 postOffice.cpp
	
bank.o: bank.cpp bank.hpp
	g++ -c -std=c++11 bank.cpp
	
game.o: game.cpp game.hpp
	g++ -c -std=c++11 game.cpp
	
clean:
	rm *.o game
	
