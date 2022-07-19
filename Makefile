
add-nbo: add-nbo.o
	g++ -o add-nbo add-nbo.o

add-nbo.o : 
	g++ -c add-nbo.cpp
clean:
	rm -f add-nbo.o
	rm -f add-nbo

