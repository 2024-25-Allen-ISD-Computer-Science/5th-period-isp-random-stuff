#include <stdio.h>
#include <string.h>


/**
there is an (x, y) set. x starts at (rows + (rows - 2)) and
y starts at 0.

they loop through the string and rotate adding themselves to the
index each time until x < 0.

after each loop, y increases by 2 and x decreases by 2.
*/


void convert(char* s, int numRows){
    int x = (numRows + (numRows - 2)); // 4
    int y = 0; // 0
    int idx = 0; // 0
    if (x <= 0){
        printf("%s", s);
    }
    while (x >= 0){ // true
        int new_idx = idx; // 0
        while(new_idx < strlen(s)){ // true, true
            if (x == 0){
                printf("%c", s[new_idx]);
                new_idx += y;
            } else if (y == 0){
                printf("%c", s[new_idx]);
                new_idx += x;
            } else {
                printf("%c", s[new_idx]);
                new_idx += x;
                printf("%c", s[new_idx]);
                new_idx += y;
            }
        }
        y += 2;
        x -=2;
        idx++;
    }
}

int main()
{
    convert("A", 1);
    return 0;

}
