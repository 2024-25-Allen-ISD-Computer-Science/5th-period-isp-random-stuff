#include <stdio.h>
#include <string.h>

int main()
{
    char* s = "pwwkew";
    int nums[strlen(s)];
    int cin = 0;
    char result[strlen(s)];
    for (int i = 0; i < strlen(s); i++){
        for (int j = 0; j < strlen(result); j++){
            if (s[i] == result[j]){
                nums[cin] = strlen(result);
                for (int k = 0; k < strlen(result); k++){
                    result[k] = NULL;
                }
                cin++;
            }
        }
        strcat(result, (char[]){s[i], '\0'});
    }
    int large;
    for (int i = 0; i < cin; i++){
    if (nums[i] > large){
        large = nums[i];
    }
}
    
    printf("%d", large);
}
