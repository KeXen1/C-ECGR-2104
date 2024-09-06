test : main.o student.o
	g++ -o test main.o student.o
	
main.o : main.cpp student.h
	g++ -c main.cpp -std=c++11
	
student.o : student.cpp student.h
	g++ -c student.cpp -std=c++11