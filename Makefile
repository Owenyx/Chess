# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Executable name
EXEC = chess

# Directories
SRCDIR = src
OBJDIR = obj
INCDIR = include

# Files
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

# Targets
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Phony targets
.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o $(EXEC)
