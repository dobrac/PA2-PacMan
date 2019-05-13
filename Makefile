#.SECONDARY:
# Konstanty
CXX ?= g++
CXXFLAGS ?= -std=c++14
CPPFLAGS ?= -Wall -pedantic -Wextra
# -g
CPPLIBS ?=
#-fsanitize=address

MKDIR ?= mkdir
RM ?= rm

SOURCE_DIR ?= src
BUILD_DIR ?= build
DOC_DIR ?= doc

PROGRAM_NAME ?= dobryjak

SOURCE_FILES := $(shell find $(SOURCE_DIR) -name "*.cpp")
#SOURCE_FILES_NAMES := $(shell find $(SOURCE_DIR) -name "*.cpp" | sed -n 's|^$(SOURCE_DIR)/||p')

#HEADER_FILES := $(shell find $(SOURCE_DIR) -name "*.h")
#HEADER_FILES_NAMES := $(shell find $(SOURCE_DIR) -name "*.h" | sed -n 's|^$(SOURCE_DIR)/||p')

OBJECT_FILES_TEMP = $(patsubst %.cpp, %.o, $(SOURCE_FILES))
OBJECT_FILES = $(patsubst $(SOURCE_DIR)/%, $(BUILD_DIR)/%, $(OBJECT_FILES_TEMP))

DIRECTORIES_GET := $(shell find $(SOURCE_DIR) -type d)
DIRECTORIES = $(patsubst $(SOURCE_DIR)%, $(BUILD_DIR)%, $(DIRECTORIES_GET))
#DIRECTORIES = "$(BUILD_DIR)/Entities/Players" "$(BUILD_DIR)/Entities/Players/Heuristics" "$(BUILD_DIR)/Exceptions" "$(BUILD_DIR)/Game"


all: compile

# PŘÍKAZY

## Spuštění programu
.PHONY: run
run: $(PROGRAM_NAME)
	./$(PROGRAM_NAME)

## Spuštění s `valgrind`
.PHONY: valgrind
valgrind: $(PROGRAM_NAME)
	valgrind ./$(PROGRAM_NAME)

## Spuštění `doxygen`
.PHONY: doc
doc:
	doxygen Doxyfile

## Otevření dokumentace
.PHONY: opendoc
opendoc:
	google-chrome $(DOC_DIR)/index.html

## Spuštění `.depend` generace
.PHONY: depend
depend:
	$(RM) .depend
	$(CXX) $(CPPFLAGS) -MM $(SOURCE_FILES)>>./.depend;

## Odstranění vygenerovaných souborů
.PHONY: clean
clean:
	make cleandoc
	$(RM) -r $(BUILD_DIR)
	$(RM) $(PROGRAM_NAME)


## Odstranění vygenerované dokumentace
.PHONY: cleandoc
cleandoc:
	$(RM) -r $(DOC_DIR)

## Zobrazení počtu řádků
.PHONY: line
line:
	find src -type f -print0 | xargs -0 cat | wc -l

# Pravidla
# Vytvoření souboru .depend
.depend:
	touch .depend

## Adresář
$(BUILD_DIR):
	make depend
	$(MKDIR) -p $(BUILD_DIR)

## Programy
compile: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) $^ -o $(PROGRAM_NAME) $(LDLIBS) $(CPPLIBS)

## Moduly
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	${MKDIR} -p ${DIRECTORIES}
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@ $(CPPLIBS)

## Moduly
include .depend














