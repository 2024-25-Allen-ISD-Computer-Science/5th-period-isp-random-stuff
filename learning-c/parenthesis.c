#include <stdio.h>
#include <string.h>

int main()
{
    char* s = "";
    
    int val[2];
    int open = 0;
    
    for (int i = 0; i < strlen(s); i++){ 
        if (s[i] == '(' && open == 0){
            open = 1;
            val[0] = i;
        }
        
        if (s[i] == ')' && open == 1){
            val[1] = i;
        }
    }
    printf("%d", val[1] - val[0]);
    
}
