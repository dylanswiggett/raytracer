eCXX = g++
FLAGS = -Wall -g -std=c++11

LIBS = main Scene SceneObjects

main: $(foreach file, $(LIBS), $(file).o)
	$(CXX) $(FLAGS) -o main $(foreach file, $(LIBS), $(file).o) `libpng-config --ldflags` 

main.o: main.cpp Scene.hpp SceneObjects.hpp Material.hpp
	$(CXX) $(FLAGS) -c -o main.o main.cpp `libpng-config --cflags` 

Scene.o: Scene.cpp Scene.hpp SceneObject.hpp SceneObjects.hpp Ray.hpp Material.hpp
	$(CXX) $(FLAGS) -c -o Scene.o Scene.cpp

SceneObjects.o: SceneObjects.cpp SceneObjects.hpp SceneObject.hpp Ray.hpp Material.hpp
	$(CXX) $(FLAGS) -c -o SceneObjects.o SceneObjects.cpp
