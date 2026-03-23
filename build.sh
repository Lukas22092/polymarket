#!/bin/bash

cmake --build build

if [ $? -eq 0 ]; then
    echo "Build successful. Running program now..."
    cd build && ./polymarket
else
    echo "Build failed. exiting."
    exit 1
fi