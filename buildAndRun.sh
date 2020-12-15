#!/bin/bash

cmake CMakeLists.txt
make clean
make
./xml2html data/cd_catalog.xml
