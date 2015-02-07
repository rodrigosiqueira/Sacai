#		Makefile - Sacai
#
# Compiles Sacai source code based on file organization described below:
#	- inc: Folder with all headers.
#	- src: Folder with implementations of headers.
#	- bin: The binary file will be put on this folder.
#	- obj: Objects file of project. 
# Basically this Makefile first generate all the object files and next generate
# the binary file.

# Initialize variables

#Folders
BINPACK := bin
INCPACK := inc
SRCPACK := src
MODELPACK := src/model
VIEWPACK := src/view
CONTROLPACK := src/control
UTILPACK := src/util
OBJPACK := obj
OTHERPACK :=  others

TESTPACK :=  test
MODELTESTCPPFILES = $(wildcard test/model/*cpp)
VIEWTESTCPPFILES = $(wildcard test/view/*cpp)
CNTLTESTCPPFILES = $(wildcard test/controller/*cpp)
UTILTESTCPPFILES = $(wildcard test/util/*cpp)

#Flags
CC := g++ -Wall -Wextra -pedantic -Wshadow -Wredundant-decls -Woverloaded-virtual -Wsynth
IFLAG := -I./$(INCPACK)/model -I./$(INCPACK)/view -I./$(INCPACK)/control -I./$(INCPACK)/util 
CVFLAG := `pkg-config --cflags --libs opencv`
GOOGLETESTFLAG := -lgtest -lgtest_main

#Create one list with all sources
MODELSOURCES	= $(wildcard src/model/*.cpp)
VIEWSOURCES	= $(wildcard src/view/*.cpp)
CONTROLSOURCES	= $(wildcard src/control/*.cpp)
UTILSSOURCES	= $(wildcard src/util/*.cpp)
TESTSOURCE	= $(wildcard test/*.cpp)

# TRAGETS

all: sacai

# Dependencies are inserted by: $(CSOURCES:src/%.c=obj/%.o)
sacai: modelObj controllerObj viewObj utilObj
	$(CC) obj/*.o src/main.cpp -o bin/app/$@ $(IFLAG) $(CVFLAG) 

# Model
modelObj: $(MODELSOURCES:src/model/%.cpp=obj/%.o)
obj/%.o: src/model/%.cpp
	$(CC) -c $< -o $@ $(IFLAG)

# Controller
controllerObj: $(CONTROLSOURCES:src/control/%.cpp=obj/%.o)
obj/%.o: src/control/%.cpp
	$(CC) -c $< -o $@ $(IFLAG)

# View
viewObj: $(VIEWSOURCES:src/view/%.cpp=obj/%.o)
obj/%.o: src/view/%.cpp
	$(CC) -c $< -o $@ $(IFLAG)

# Util
utilObj: $(UTILSSOURCES:src/util/%.cpp=obj/%.o)
obj/%.o: src/util/%.cpp
	$(CC) -c $< -o $@ $(IFLAG)

#=============================================================================
# Testing
# About: The command test compile all tests and put it in the folder bin/test.
#       You should have a file in the src folder mapped into test. To make it
#       organized, you should keep the same folder structure in test folder.
# Example:
#               make test  -> Compile all the tests
#               make testModel -> Compile all the tests in model folder.
#==============================================================================

test: testModel testView testController testUtil

# Test Model
testModel: $(MODELTESTCPPFILES:test/model/%Test.cpp=bin/test/%)

bin/test/%: test/model/%Test.cpp src/model/%.cpp
	$(GPP) $^ -o $@ $(IFLAG) $(GOOGLETESTFLAG)

#Test View
testView: $(VIEWTESTCPPFILES:test/view/%Test.cpp=bin/test/%)

bin/test/%: test/view/%Test.cpp src/view/%.cpp
	$(GPP) $^ -o $@ $(IFLAG) $(GOOGLETESTFLAG)

#Test Controller
testController: $(MODELTESTCPPFILES:test/controller/%Test.cpp=bin/test/%)

bin/test/%: test/controller/%Test.cpp src/controller/%.cpp
	$(GPP) $^ -o $@ $(IFLAG) $(GOOGLETESTFLAG)

#Test Util
testUtil: $(UTILTESTCPPFILES:test/util/%Test.cpp=bin/test/%)

bin/test/%: test/util/%Test.cpp src/util/%.cpp
	$(GPP) $^ -o $@ $(IFLAG) $(GOOGLETESTFLAG)

clean:
	rm -f obj/*
	rm -fr bin/test/*
	rm -fr bin/app/*
	cp conf/default.yaml bin/test/
	cp conf/default.yaml bin/app/
