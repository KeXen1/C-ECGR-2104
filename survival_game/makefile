test : main.o survival_game.o
	g++ -o test main.o survival_game.o
	
main.o : main.cpp survival_game.h
	g++ -c main.cpp -std=c++11
	
student.o : survival_game.cpp survival_game.h
	g++ -c survival_game.cpp -std=c++11

clean :
	rm *.o test