# Makefile for monte
monte: monte.o
	g++ -o monte monte.cpp
	./monte
	
clean:
	rm -f *.o monte
	
