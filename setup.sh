#!/bin/bash

sudo apt-get install build-essential
sudo apt-get install libgtest-dev
cd /usr/src/googletest/googletest
sudo cmake
sudo make install