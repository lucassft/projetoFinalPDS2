# feito com base no link 
# https://stackoverflow.com/questions/30573481/how-to-write-a-makefile-with-separate-source-and-header-directories

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin # or . if you want it in the current directory

EXE := $(BIND_DIR)/projetoFinal

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

CXXFLAGS := -Iinclude -MMD -MP # -I is a preprocessor flag, not a compiler flag
CFLAGS   := -Wall              # some warnings about bad code
LDFLAGS  := -Llib              # -L is a linker flag
LDLIBS   := -lm                # Left empty if no libs are needed

all: $(EXE)
.PHONY: all

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR) # The @ disables the echoing of the command

-include $(OBJ:.o=.d) # The dash silences errors when files don't exist (yet)