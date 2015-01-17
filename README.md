# SACAI

[![Build Status](https://travis-ci.org/rodrigosiqueira/Sacai.svg)](https://travis-ci.org/rodrigosiqueira/Sacai)

----
# What is Sacai?

> **Originally**: Firstly, Sacai was created for working as a low cost black 
box to be embedded on bicycles. Basically the main algorithm should receive an 
input from a camera, processing it to find a car, calculates the distance 
between the cyclist and the vehicle, finally if the car was close of the 
cyclist the black box have to take a picture of the car and saved it. The idea 
was help to find some drivers which crash the cyclist and flee without provide 
any help. 

> **Currently**: The project was frozen more than one year and now it is 
restarted to be part of another project that needs camera calibration, car or 
hand recognition, and distance calculation with one camera.

----
## What is the the meaning of "Sacai"?

> The name was inspired on Tupi Guarani language (the language used by old 
native people in Brazil). The original name is "ça-cai" and means restless 
eyes, usually the indigenous used this name for some monkeys. The idea of use 
"restless eyes" was applied here, in the sense of giving one more eye for the 
cyclists.

----
# Development
sudo apt-get install build-essential checkinstall cmake pkg-config yasm
* System Dependencies (Kubuntu/Ubuntu)
 * build-essential
 * checkinstall
 * cmake
 * pkg-config
 * yasm
* GCC 4.8
* OpenCV 2.4
* Doxygen
* Google test

----
# Install

----
## Install openCV
 * Download openCV 2.4. 
 * First, install basic tools:
 
 ```
 sudo apt-get install build-essential checkinstall cmake pkg-config yasm
 ```
 
 * Install basic package for image and Video
 
 ```
 sudo apt-get install libtiff4-dev libjpeg-dev libjasper-dev
 ```
 ```
 sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev 
 libdc1394-22-dev libxine-dev libgstreamer0.10-dev 
 libgstreamer-plugins-base0.10-dev libv4l-dev
 ```
 
 * Install python packages
 
 ```
 sudo apt-get install python-dev python-numpy
 ```
 
 * Install some extra package
 
 ```
 sudo apt-get install libtbb-dev
 ```
 
 * Install GUI
 
 ```
 sudo apt-get install libqt4-dev libgtk2.0-dev
 ```
 
 * Now it is time to compile. Untar the openCV:
 
 ```
 tar -xvf OpenCV-2.4.0.tar.bz2
 ```
 
 * Entry in openCV directory, create build directory:
 
 ```
 cd OpenCV-2.4.0/
 mkdir build
 cd build
 ```
 
 * Inside of build directory, execute te command below:
 
 ```
 cmake -D WITH_QT=ON -D WITH_XINE=ON -D WITH_OPENGL=ON -D WITH_TBB=ON -D BUILD_EXAMPLES=ON ..
 ```
 
 * After the process finish, compile it:
 
 ```
 make
 ```
 
 * After the compilation, install openCV libraries.
 
 ```
 sudo make install
 ```
 
 * Use an editor of your preference, and open:
 
 ```
 sudo vim /etc/ld.so.conf
 ```
 
 * Add the line below to /etc/ld.so.conf:
 
 ```
 /usr/local/lib
 ```
 
 * Run:
 
 ```
 sudo ldconfig
 ```
 
 * Finally, test openCV:
 
 ```
 cd <yourOpenCVDirectory>/build/bin/
 ./opencv_test_core
 ```
 
## Compile Sacai

 * Just execute:
 
 ```
 make clean
 ```
 ```
 make
 ```
 
 * Go to bin/app/, and execute:
 ```
 sacai
 ```

----
# Author

* Rodrigo Siqueira de Melo
 * rodrigosiqueiramelo@gmail.com
