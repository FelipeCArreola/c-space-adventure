#!/bin/bash

gcc -Wall -g functions.c cJSON.c main.c -o main
./main planetarySystem.json
