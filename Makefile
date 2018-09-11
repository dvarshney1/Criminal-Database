EXENAME = crime
OBJS = crime.o main.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic

LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpthread -lm -lc++abi

all : $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $(OBJS) $(LFDLAGS) -o $(EXENAME)

main.o : main.cpp crime.h
	$(CXX) $(CXXFLAGS) main.cpp
crime.o : crime.cpp crime.h
	$(CXX) $(CXXFLAGS) crime.cpp

clean:
	rm -f *.o $(EXENAME)
