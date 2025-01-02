#define link target
linkTarget = qbRay

#define flags
CFLAGS = -std=c++17
#extra
EXTRAARG = $$(sdl2-config --cflags --libs)


#define object files needed
objects = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

#define rebuildables
rebuildables = $(objects) $(linkTarget)

#rule to perform build
$(linkTarget): $(objects)
	g++ -o $(linkTarget) $(objects) $(CFLAGS) $(EXTRAARG)

#Rule to create .o (object) files.
%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS) $(EXTRAARG)

.PHONEY:
clean:
	rm: $(rebuildables)
			


