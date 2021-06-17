#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start = 0;
    int end = 0;
    int population = 0;
    int years = 0;
    
    // TODO: Prompt for start size
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    
    // TODO: Prompt for end size
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    population = start;
    
    while(population < end)
    {
        int lost = population / 4;
        int gained = population / 3;
        
        population = population + gained;
        population = population - lost;
        
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}