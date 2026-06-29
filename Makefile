CXX := g++

CXXFLAGS := -Wall -Wextra -std=c++17 -g -Iinclude

SRC := $(wildcard src/*.cpp)

OBJ := $(patsubst src/%.cpp,build/%.o,$(SRC))

DEP := $(OBJ:.o=.d)

TARGET := bin/DeliverySystem.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

build:
	mkdir -p build

bin:
	mkdir -p bin

$(TARGET): | bin

-include $(DEP)

clean:
	rm -rf build
	rm -f $(TARGET)

run: all
	./$(TARGET)