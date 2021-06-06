// characterize the functions--- doooo stuff homie
#include "functions.h"

int random_planet_idx () {
    time_t ti;
    int random_num;
    srand((unsigned) time(&ti));
    random_num = rand() % PLANETS_COUNT;
    return random_num;
}

char *get_planet_name_entry(){
    char *entry = (char *) malloc(20);
    printf("Name the planet you would like to visit.\n");
    scanf("%[a-zA-Z]",entry);
    return entry;
}

void search_by_name (char *str, data_planet array[]) {
    int idx = 0;
    for (size_t i = 0; i < PLANETS_COUNT; i++)
    {
        if(strcmp(array[idx].name, str) == 0) {
            printf("Traveling to %s...\n", array[idx].name);
            printf("Arrived at %s. %s\n", array[idx].name, array[idx].description);
            break;
        } else if (idx == (PLANETS_COUNT - 1) ) {
            printf("Traveling to Null...\n");
            printf("Arrived at Null. Null\n");
        }
    }
    free(str);  
}

void search_by_index (int idx, data_planet array[]) {
    if ( 0 <= idx && idx < PLANETS_COUNT) {
        printf("Traveling to %s...\n", array[idx].name);
        printf("Arrived at %s. %s\n", array[idx].name, array[idx].description);
    }
}

void has_compiled_expression (int num) {
    if (num) {
        fprintf(stderr, "Regular Expression could not be compiled");
        exit(1);
    }
}

// return 0 for false
// return 1 for true
int assess_input (char *input, char *regex_str) {
    regex_t reg_y;
    int assessed_value = 0;
    int boolean = 0;
    // assessed_value = regcomp(&reg_y,"^[Yy]", 0 );
    assessed_value = regcomp(&reg_y, regex_str, 0 );
    has_compiled_expression(assessed_value);
    assessed_value = regexec(&reg_y, input, 0, NULL, 0);
    if (!assessed_value) {
        boolean = 1;
    } else if (assessed_value == REG_NOMATCH) {
        printf("No Match\n");
    } else {
        printf("Error Has Occured-- Regexec: %s, for Regex-Pattern: %s", input, regex_str);
        exit(1);
    }
    return boolean;
}