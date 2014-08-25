CXX = g++
FLAGS = -Wall -g -std=c++11 -pg

LIBS = main Scene SceneObjects PathTracer RayMapper

main: $(foreach file, $(LIBS), $(file).o)
	$(CXX) $(FLAGS) -o main $(foreach file, $(LIBS), $(file).o) `libpng-config --ldflags` 

main.o: main.cpp Scene.hpp SceneObjects.hpp Material.hpp PathTracer.o RayMapper.o
	$(CXX) $(FLAGS) -c -o main.o main.cpp `libpng-config --cflags` 

Scene.o: Scene.cpp Scene.hpp SceneObject.hpp SceneObjects.hpp Ray.hpp Material.hpp
	$(CXX) $(FLAGS) -c -o Scene.o Scene.cpp

SceneObjects.o: SceneObjects.cpp SceneObjects.hpp SceneObject.hpp Ray.hpp Material.hpp
	$(CXX) $(FLAGS) -c -o SceneObjects.o SceneObjects.cpp

PathTracer.o: PathTracer.cpp PathTracer.hpp Scene.hpp
	$(CXX) $(FLAGS) -c -o PathTracer.o PathTracer.cpp

RayMapper.o: RayMapper.cpp RayMapper.hpp Scene.hpp Ray.hpp
	$(CXX) $(FLAGS) -c -o RayMapper.o RayMapper.cpp

clean:
	rm -f *.o