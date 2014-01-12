CXX=g++
CXXFLAGS=-std=c++11
RM=rm -f

WB=worldBuilding/
RM=resourceManagers/
GS=gameStates/
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

SRCS=main.cpp Engine.cpp config.cpp $(GS)GameState.cpp $(GS)Camera.cpp $(WB)LayerGroup.cpp $(WB)MapFactory.cpp $(WB)Map.cpp $(WB)Tile.cpp $(WB)World.cpp $(RM)ImageManager.cpp $(RM)TextureManager.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: downfallEngine

Engine.o: Engine.cpp engine.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

config.o : config.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(GS)Camera.o : $(GS)Camera.cpp $(GS)camera.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(GS)GameState.o : $(GS)GameState.cpp $(GS)gamestate.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(WB)LayerGroup.o : $(WB)LayerGroup.cpp $(WB)layergroup.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(WB)Map.o : $(WB)Map.cpp $(WB)map.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(WB)MapFactory.o : $(WB)MapFactory.cpp $(WB)mapfactory.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(WB)Tile.o : $(WB)Tile.cpp $(WB)tile.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(WB)World.o : $(WB)World.cpp $(WB)world.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(RM)TextureManager.o : $(RM)TextureManager.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(RM)ImageManager.o : $(RM)ImageManager.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

downfallEngine: $(OBJS)
	@echo "** Building..."
	$(CXX) $(CXXFLAGS) -o Downfall $(OBJS) $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	$(RM) $(OBJS)

install:
	@echo "** Installing..."
	cp downfall /usr/bin/

uninstall:
	@echo "** Uninstalling..."
	$(RM) /usr/bin/downfall
