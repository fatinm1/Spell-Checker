CXX = g++
CXXFLAGS = -g -Wall
driver: Trie.o Trie.cpp
	$(CXX) $(CXXFLAGS) Trie.o driver.cpp -o driver
Trie.o: Trie.cpp Trie.h
	$(CXX) $(CXXFLAGS) -c Trie.cpp
remake:
	make driver
	make run

clean:
	rm *.o*
	rm *~ 

run:
	./driver
