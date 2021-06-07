/*
    Author: Felipe C Arreola
    Class: SE201
    Term: Spring 2021
    Project: C Space Adventure
*/
# include "functions.h"

// gcc -Wall -g main.c -o main
// ./main

// source : cJSON.c & cJSON.h :https://github.com/DaveGamble/cJSON 
// source : error handling : https://www.tutorialspoint.com/cprogramming/c_error_handling.htm

extern int errno;

data_planet array_planets[PLANETS_COUNT];

int main(int argc, char *argv[])
{
    FILE *pf;
    if ( (pf = fopen ( argv[1], "r")) == NULL) {
        fprintf(stderr, "Value of error: %d\n", errno);
        perror("Error Message");
        printf("Error Opening File: \'%s\'.\n", argv[1]);
        exit(1);
    }

    char buffer[2048] = {0};
    fread(buffer, 1, sizeof(buffer), pf);
    cJSON *json_file_root = cJSON_Parse(buffer);

    s_system = cJSON_GetObjectItemCaseSensitive(json_file_root, "name");
    
    if (cJSON_IsString(s_system) && (s_system->valuestring != NULL) ) {
        printf("Welcome to the %s!\n", s_system->valuestring);
    }

    planet = NULL;
    planets = cJSON_GetObjectItemCaseSensitive(json_file_root, "planets");
    int idx = 0;
    cJSON_ArrayForEach(planet, planets) {
        name = cJSON_GetObjectItemCaseSensitive(planet, "name");
        description = cJSON_GetObjectItemCaseSensitive(planet, "description");
        array_planets[idx].name = name->valuestring;
        array_planets[idx].description= description->valuestring;
        idx ++; 
    }
    
    fclose(pf);

    printf("There are %d planets to explore.\n", PLANETS_COUNT);
    printf("What is your name?\n");
    char name[40];
    fgets(name,40,stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Nice to meet you, %s. My name is Eliza, I'm an old frind of Alexa.\n", name);
    printf("let's go on an adventure!\n");

    int run = 0;
    char playerChoice[2];
    while (!run) {
        printf("Shall I randomly choose a planet for you to visit? (\'Y\' or \'N\')\n");
        fgets(playerChoice,40,stdin);
        playerChoice[strcspn(playerChoice, "\n")] = 0;
        run = assess_input(playerChoice, "^[YyNn]");
        if (run == 0) {
            printf("Sorry, I didn\'t get that.\n");
        }
    }
    if (assess_input(playerChoice, "^[Yy]")) {
        search_by_index( random_planet_idx(), array_planets);
    } else {
        search_by_name( get_planet_name_entry(), array_planets );
    }
    
    cJSON_Delete(json_file_root);
    return 0;
}
