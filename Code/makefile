DEBUG=no
CXX=g++
ifeq ($(DEBUG), yes)
	CXXFLAGS=-ansi -pedantic -Wall -std=c++11 -g -DMAP
else
	CXXFLAGS=-ansi -pedantic -Wall -std=c++11 -g
endif
EXEC=sejours

all: $(EXEC)

sejours: Trajet.o TrajetSimple.o Catalogue.o Chainon.o ListeChainee.o TrajetCompose.o main.o
	$(CXX) -o sejours Trajet.o TrajetSimple.o Catalogue.o Chainon.o ListeChainee.o TrajetCompose.o main.o

Trajet.o: Trajet.cpp Trajet.h
	$(CXX) -o Trajet.o -c Trajet.cpp $(CXXFLAGS)

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h Trajet.h
	$(CXX) -o TrajetSimple.o -c TrajetSimple.cpp $(CXXFLAGS)

Catalogue.o: Catalogue.cpp Catalogue.h Trajet.h TrajetSimple.h TrajetCompose.h
	$(CXX) -o Catalogue.o -c Catalogue.cpp $(CXXFLAGS)

Chainon.o: Chainon.cpp Chainon.h Trajet.h
	$(CXX) -o Chainon.o -c Chainon.cpp $(CXXFLAGS)

ListeChainee.o: ListeChainee.cpp ListeChainee.h Chainon.h Trajet.h
	$(CXX) -o ListeChainee.o -c ListeChainee.cpp $(CXXFLAGS)

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h Trajet.h TrajetSimple.h ListeChainee.h
	$(CXX) -o TrajetCompose.o -c TrajetCompose.cpp $(CXXFLAGS)

main.o: main.cpp Trajet.h TrajetSimple.h TrajetCompose.h Chainon.h ListeChainee.h Catalogue.h
	$(CXX) -o main.o -c main.cpp $(CXXFLAGS)

clean:
	rm -rf *.o
	rm -rf $(EXEC)