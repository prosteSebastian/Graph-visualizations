CXX = g++
CXX_FLAGS = -g -std=c++17 -Wall -pedantic -fsanitize=undefined
LD = g++
NAME = prokoseb

SRC = $(wildcard  src/*.cpp src/*/*.cpp)
OBJ = $(patsubst src/%.cpp, build/*.o, ${SRC})
DPS = $(patsubst src/%.cpp, build/%.dep, ${SRC})

.PHONY: compile clean

compile: ${NAME}

${NAME}: ${OBJ}
	@mkdir -p build/
	${CXX} ${CXX_FLAGS} $^ -o $@

build/%.o : src/%.cpp
	@mkdir -p build/
	${CXX} ${CXX_FLAGS} -c $< -o $@

build/%.dep : src/%.cpp
	@mkdir -p $(@D)
	${CXX} -MM -MT $(patsubst src/%.cpp, build/%.o, $<) $< > $@

clean:
	rm -rf build
	rm -rf ${NAME}

include ${DPS}
