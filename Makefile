# Konstanty
CXX ?= g++
CXXFLAGS ?= -std=c++14
CPPFLAGS ?= -Wall -pedantic -Wextra -g
CPPLIBS ?= -pthread
#-lncurses

MKDIR ?= mkdir
RM ?= rm

SOURCE_DIR ?= src
BUILD_DIR ?= build
DOC_DIR ?= doc

SOURCE_FILES := $(shell find $(SOURCE_DIR) -name "*.cpp")
SOURCE_FILES_NAMES := $(shell find $(SOURCE_DIR) -name "*.cpp" | sed -n 's|^$(SOURCE_DIR)/||p')

OBJECT_FILES_TEMP = $(patsubst %.cpp, %.o, $(SOURCE_FILES))
OBJECT_FILES = $(patsubst $(SOURCE_DIR)/%, $(BUILD_DIR)/%, $(OBJECT_FILES_TEMP))

DIRECTORIES_GET := $(shell find $(SOURCE_DIR) -type d)
DIRECTORIES = $(patsubst $(SOURCE_DIR)%, $(BUILD_DIR)%, $(DIRECTORIES_GET))
#DIRECTORIES = "$(BUILD_DIR)/Entities/Players" "$(BUILD_DIR)/Entities/Players/Heuristics" "$(BUILD_DIR)/Exceptions" "$(BUILD_DIR)/Game"

# PŘÍKAZY
## Spuštění `main`
.PHONY: main
main: $(BUILD_DIR)/main
	$(BUILD_DIR)/main

## Spuštění `valgrind`
.PHONY: valgrind
valgrind: $(BUILD_DIR)/main
	valgrind $(BUILD_DIR)/main

## Spuštění `doxygen`
.PHONY: doxygen
doc:
	@echo "Generating Documentation"
	doxygen Doxyfile
	@echo "DOC OK"

## Spuštění `depend`
.PHONY: depend
depend:
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $(SOURCE_FILES)>>./.depend;

## Odstranění vygenerovatelných souborů
.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) -r $(DOC_DIR)

## Zobrazení počtu řádků
.PHONY: line
line:
	find src -type f -print0 | xargs -0 cat | wc -l

# Pravidla
## Adresář
$(BUILD_DIR):
	make depend
	$(MKDIR) -p $(BUILD_DIR)

## Programy
$(BUILD_DIR)/%: $(BUILD_DIR)/%.o $(OBJECT_FILES) | $(BUILD_DIR)
	$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS) $(CPPLIBS)

## Moduly
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp | $(BUILD_DIR)
	${MKDIR} -p ${DIRECTORIES}
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@ $(CPPLIBS)

# Závislosti (vygenerováno: g++ -MM src/**/*.cpp)
## Třídy

## Moduly
include .depend














