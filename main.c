#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// gcc -Wall -g main.c -o main
// ./main

// source : error handling : https://www.tutorialspoint.com/cprogramming/c_error_handling.htm

#define PLANETS_COUNT 9

extern int errno;

typedef struct planet
{
    char (*name)[20];
    char (*description)[127];
} planet;

planet arr_planets[PLANETS_COUNT];

int random_planet () {
    time_t ti;
    int random_num;
    srand((unsigned) time(&ti));
    random_num = rand() % PLANETS_COUNT;
    return random_num;
}

int main(int argc, char *argv[])
{
    FILE *pf;

    char *fPath = "./data/solar_system.txt";
    
    pf = fopen ( fPath, "r");

    // error handling: 
    if (pf == NULL) {
        fprintf(stderr, "Value of error: %d\n", errno);
        perror("Error Message");
        printf("Error Opening File: \'%s\'.\n", fPath);
        exit(1);
    }

    printf("Welcome to the Solar System!\n");
    printf("There are 9 planets to explore.\n");
    printf("What is your name?\n");
    char name[40];
    fgets(name,40,stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Nice to meet you, %s. My name is Eliza, I'm an old frind of Alexa.\n", name);
    printf("let's go on an adventure!\n");
    printf("Shall I randomly choose a planet for you to visit? (\'Y\' or \'N\') ");
    char playerChoice[2];
    fgets(playerChoice,40,stdin);
    playerChoice[strcspn(playerChoice, "\n")] = 0;
    printf("Choice is %s\n", playerChoice);
    // TODO : if clause that assesses 
    printf("Random Number: %d\n", random_planet());
    printf("Traveling to Pluto...\n");
    printf("Arrived at Pluto, it's very cold here.\n");
    
    return 0;
}