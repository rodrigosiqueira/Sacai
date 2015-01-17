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
BINPACK		:= bin
INCPACK		:= inc
SRCPACK		:= src
MODELPACK	:= src/model
VIEWPACK	:= src/view
CONTROLPACK	:= src/control
UTILPACK	:= src/util
OBJPACK		:= obj
OTHERPACK	:=  others
TESTPACK	:=  test

#Flags
CC		:= g++ -Wall -Wextra -pedantic -Wshadow -Wredundant-decls -Woverloaded-virtual -Wsynth
IFLAG		:= -I./$(INCPACK)/model -I./$(INCPACK)/view -I./$(INCPACK)/control -I./$(INCPACK)/util 
CVFLAG		:= `pkg-config --cflags --libs opencv`
CPPUNITFLAG	:= -lcppunit -ldl

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

#####################################
#Test
obj/mainTest.o: test/mainTest.cpp
	$(CC) -c $< -o $@ $(IFLAG) $(CPPUNITFLAG)
	
settingTest: test/SettingTest.cpp
	$(CC) $(FLAGS) -c $< -o obj/$@ $(IFLAG) $(CPPUNITFLAG)
	$(CC) $(IFLAG) $^ obj/mainTest.o obj/Setting.o -o bin/test/$@ $(CPPUNITFLAG) $(CVFLAG)

calibrationTest: test/CalibrationTest.cpp
	$(CC) $(FLAGS) -c $< -o obj/$@ $(IFLAG) $(CPPUNITFLAG)
	$(CC) $(IFLAGS) $^ obj/mainTest.o obj/Calibration.o obj/Setting.o -o bin/test/$@ $(CPPUNITFLAG) $(CVFLAG)

tests: obj/mainTest.o $(CSOURCES:src/%.cpp=obj/%.o) settingTest calibrationTest

clean:
	rm -f obj/*
	rm -fr bin/test/*
	rm -fr bin/app/*
	cp conf/default.yaml bin/test/
	cp conf/default.yaml bin/app/
