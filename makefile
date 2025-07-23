CXX = g++
CXXFLAGS = -Wall

proj: load_proj.cpp Organization.o Person.o FriendFinder.o
	$(CXX) $(CXXFLAGS) proj.cpp Organization.o Person.o FriendFinder.o -o proj

FriendFinder.o: FriendFinder.h FriendFinder.cpp Organization.o Person.o
	$(CXX) $(CXXFLAGS) -c FriendFinder.cpp

Organization.o: Organization.h Organization.cpp Person.o
	$(CXX) $(CXXFLAGS) -c Organization.cpp

Person.o: Person.h Person.cpp
	$(CXX) $(CXXFLAGS) -c Person.cpp

run:
	./load_proj

clean:
	rm *~
