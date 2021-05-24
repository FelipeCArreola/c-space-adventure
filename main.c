#include <stdio.h>
#include <string.h>

// gcc -Wall -g main.c -o main
// ./main

struct planet
{
    char name[20];
    char description[127];
};

struct planet arr_planets[9];

int main(int argc, char *argv[])
{
    printf("Welcome to the Solar System!\n");
    printf("There are 9 planets to explore.\n");
    printf("What is your name?\n");
    char name[40];
    fgets(name,40,stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Nice to meet you, %s. My name is Eliza, I'm an old frind of Alexa.\n", name);
    printf("let's go on an adventure!\n");

    return 0;
}