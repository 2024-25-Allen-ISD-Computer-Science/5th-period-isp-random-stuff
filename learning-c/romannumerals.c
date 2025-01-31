#include <stdio.h>
#include <string.h>
#include <ctype.h>

int roman()
{
    char inp[10];
    char numerals[7] = {'i', 'v', 'x', 'l', 'c', 'd', 'm'};
    int numvals[7] =   {1, 5, 10, 50, 100, 500, 1000};
    int value = 0;
    printf("enter roman numerals: ");
    scanf("%s", inp);
    
    int last_val;
    
    for (int i = 0; i < strlen(inp); i++){
        char current_char = tolower(inp[i]);
        for (int j = 0; j < 7; j++){
            if (numerals[j] == current_char){
                if (last_val >= numvals[j]){
                    value += last_val;
                } else {
                    value -= last_val;
                }
                
                last_val = numvals[j];
            }
        }
    }
    value += last_val;
    printf("%d", value);
    return 0;
}
