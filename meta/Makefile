tCXX = g++
CXXFLAGS = -std=c++14 -Wall
EXEC = a
MAINOBJ = FHC2022R1B1.cpp
OBJECTS = ${MAINOBJ}


${EXEC}: ${OBJECTS}
		${CXX} ${CXXFLAGS} -g ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
		rm ${OBJECTS} ${EXEC} 