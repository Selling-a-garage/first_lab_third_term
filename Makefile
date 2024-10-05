CFLAGS := -std=c++17 -Wall -I./ 

SRC = $(wildcard src/*.cpp) #берем все .cpp
SRC_EXCLUDED = EXCLUDE_ME.cpp #исключение
SRC_FILTERED = $(filter-out src/$(SRC_EXCLUDED), $(SRC)) #исключаем исключение

OBJ = $(SRC_FILTERED:src/%.cpp=obj/%.o) #генерим список необходимых .o

TARGET = bin/main.exe

all: $(TARGET)

$(TARGET): $(OBJ) # $@ - ссылается на target, $^ - ссылкается на obj
	g++ $(OBJ) -o $(TARGET)

obj/%.o: src/%.cpp
	g++ -c $< -o $@ $(CFLAGS)

clean:
	rm -f obj/*.o $(TARGET)
