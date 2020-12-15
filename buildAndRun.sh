#!/bin/bash

cmake CMakeLists.txt
make clean
make
./xml2html
