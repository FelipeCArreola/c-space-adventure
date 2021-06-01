#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <regex.h>

#define PLANETS_COUNT 9

typedef struct planet
{
    char *name;
    char *description;
} planet;

int random_planet_idx ();

// line counter of a file :
int count_of_lines_in_file (FILE *f);

char *get_planet_name_entry();

void search_planets_for_name (char *str, planet array[]) ;

void has_compiled_expression (int num);

int assess_input (char *input, char *regex_str);



#endif