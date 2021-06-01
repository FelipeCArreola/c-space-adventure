# include "functions.h"

// gcc -Wall -g main.c -o main
// ./main

// source : error handling : https://www.tutorialspoint.com/cprogramming/c_error_handling.htm
// source : line counter of a file : https://www.geeksforgeeks.org/c-program-count-number-lines-file/

extern int errno;

planet arr_planets[PLANETS_COUNT];

int main(int argc, char *argv[])
{
    FILE *pf;
    char *fPath = "./data/solar_system.txt";
    pf = fopen ( fPath, "r");
    char *line_buffer= (char *) malloc(150);
    // error handling: 
    if (pf == NULL) {
        fprintf(stderr, "Value of error: %d\n", errno);
        perror("Error Message");
        printf("Error Opening File: \'%s\'.\n", fPath);
        exit(1);
    }

    int line_count = count_of_lines_in_file(pf); 
    if ( line_count != PLANETS_COUNT) {
        printf("Error-file \'%s\' line count (%d) does not meet the required line count of %d.\n", fPath, line_count, PLANETS_COUNT);
        exit(1);
    } 

    // TODO : add ability to read line by line
    // --- BETTER yet work on cJSON and import- work and parse that
    // error-- not reading file?? 

    int line_idx = 0;
    while (fgets(line_buffer, sizeof(line_buffer), pf))
    {
        if (line_idx == 0) {
            arr_planets[line_idx].name = strtok(line_buffer, ":");
            arr_planets[line_idx].description = strtok(NULL, ":");    
        } else {
            arr_planets[line_idx].name = strtok(NULL, ":");
            arr_planets[line_idx].description = strtok(NULL, ":");
        }
        line_idx ++;
    }
        
    fclose(pf);

    // TESTING- printing array values
    for (size_t i = 0; i < PLANETS_COUNT; i++)
    {
        printf("name: %s , description: %s\n", arr_planets[i].name, arr_planets[i].description);
    }
    
    printf("Welcome to the Solar System!\n");
    printf("There are 9 planets to explore.\n");
    printf("What is your name?\n");
    char name[40];
    fgets(name,40,stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Nice to meet you, %s. My name is Eliza, I'm an old frind of Alexa.\n", name);
    printf("let's go on an adventure!\n");
    printf("Shall I randomly choose a planet for you to visit? (\'Y\' or \'N\')\n");
    char playerChoice[2];
    fgets(playerChoice,40,stdin);
    playerChoice[strcspn(playerChoice, "\n")] = 0;
    printf("Choice is %s\n", playerChoice);
    // TODO : if clause that assesses 
    // printf("entry: %s\n", get_planet_name_entry());
    search_planets_for_name( get_planet_name_entry(), arr_planets );
    printf("Random Number: %d\n", random_planet_idx());
    printf("Traveling to Pluto...\n");
    printf("Arrived at Pluto, it's very cold here.\n");
    
    return 0;
}