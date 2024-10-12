CXX = g++
CXXFLAGS = -std=c++17 -Wall
EXEC = a
MAINOBJ = ${NAME}
OBJECTS = ${MAINOBJ}


${EXEC}: ${OBJECTS}
		${CXX} ${CXXFLAGS} -g ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
		rm ${OBJECTS} ${EXEC} 