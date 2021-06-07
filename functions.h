#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <regex.h>

#include "cJSON.h"

#define PLANETS_COUNT 9

cJSON *s_system;
cJSON *planet;
cJSON *planets;
cJSON *name;
cJSON *description;

typedef struct data_planet 
{
    char *name;
    char *description;
} data_planet;


int random_planet_idx ();

// line counter of a file :
int count_of_lines_in_file (FILE *f);

char *get_planet_name_entry();

void search_by_name (char *str, data_planet[]) ;

void search_by_index (int idx, data_planet[]);

void has_compiled_expression (int num);

int assess_input (char *input, char *regex_str);

#endif
