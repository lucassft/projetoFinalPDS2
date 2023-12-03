SRC_DIR     := src
BIN_DIR     := bin
LIB_DIR        := lib
INC_DIR        := include
OBJ_DIR        := obj

TARGETS        := $(BIN_DIR)/projetoFinalPDS2
SOURCES        := $(shell find src -name "*.cpp")
HEADERS        := $(shell find include -name "*.hpp")
HEADERDIRS     := $(sort $(dir $(HEADERS)))
OBJECTS        := $(patsubst src/%.cpp,obj/%.o,$(SOURCES))

CXX         = g++
CXXFLAGS     = -std=c++17 -c -g -Wall

.PHONY: all clean

all: $(TARGETS)

$(TARGETS): $(OBJECTS)
	$(CXX) $^ -o $@

INCLUDEFLAGS := $(addprefix -I,$(HEADERDIRS))
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $< -c $(INCLUDEFLAGS) -o $@

clean:
	rm -f $(OBJECTS) $(TARGETS)