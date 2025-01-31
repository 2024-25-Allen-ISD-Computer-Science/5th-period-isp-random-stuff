// given an array of random numbers, there is only one solution that leads to the target number using two of the numebers. return those indices

#include <stdio.h>

int main(){
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int arraysize = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < arraysize; i++){
        for (int j = 0; j < arraysize; j++){
            int value = nums[i] + nums[j];
            if (value == target){
                printf("nums[%d] + nums[%d] = %d + %d = %d", i, j, nums[i], nums[j], target);
                return 0;
            }
        }
    }
}
