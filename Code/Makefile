#		Makefile - Compile a set of code in C
#
#This Makefile compiles C codes based on file organization described below:
#	- inc: Folder with all headers.
#	- src: Folder with implementations of headers.
#	- bin: The binary file will be put on this folder.
#	- obj: Objects file of project. 
#Basically this Makefile first generate all the object files and next generate
#the binary file. This Makefile has a target for compile unitary tests.

# Initialize the variables used

#Folders
BINPACK		= 	bin
INCPACK		=	inc
SRCPACK		=	src
MODELPACK	=	$(SRCPACK)/model
VIEWPACK	=	$(SRCPACK)/view
CONTROLPACK	=	$(SRCPACK)/control
UTILPACK	=	$(SRCPACK)/util
OBJPACK		=	obj
OTHERPACK	= 	others
TESTPACK	= 	test

#Flags
CC			= g++ -Wall
IFLAG		= -I./$(INCPACK)/model -I./$(INCPACK)/view -I./$(INCPACK)/control -I./$(INCPACK)/util 
CVFLAG		= `pkg-config --cflags opencv pkg-config --libs opencv`
CPPUNITFLAG	= -lcppunit -ldl
#Create one list with all sources
MODELSOURCES	= $(wildcard src/model/*cpp)
VIEWSOURCES		= $(wildcard src/view/*cpp)
CONTROLSOURCES	= $(wildcard src/control/*cpp)
UTILSSOURCES	= $(wildcard src/util/*cpp)
TESTSOURCE		= $(wildcard test/*cpp)

# TRAGETS

all: sacai

# Main target, whose the objective is generate binary files. 
# Dependencies are inserted by: $(CSOURCES:src/%.c=obj/%.o)
#	*Basically capture all the elements of list and change the pieces
#	 with "src/%.c" by "obj/%.o".
sacai: modelObj controllerObj viewObj utilObj
	$(CC) $(IFLAG) $(CVFLAG) obj/*.o src/main.cpp -o bin/app/$@ $(IFLAG)

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
