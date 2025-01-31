#include <stdio.h>
#include <limits.h>

int main()
{
    // given
    int nums1[] = {1, 3};
    int nums2[] = {2, 4};
    
    int length1 = sizeof(nums1) / sizeof(nums1[0]);
    int length2 = sizeof(nums2) / sizeof(nums2[0]);
    int length = length1 + length2;
    int combined[length];
    int final[length];
    int max = INT_MIN;
    int center = length / 2;
    
    
    for (int i = 0; i < length1; i++){ // combining arrays
        combined[i] = nums1[i];
    }
    
    for (int i = 0; i < length2; i++){
        combined[i + length1] = nums2[i];
    }
    
    
    for (int i = 0; i < length; i++){ // finding max value of array
        if (max < combined[i]){
            max = combined[i];
        }
    }
    
    
    
    for (int j = 0; j < length; j++){ // finding lowest value and appending
        int lowest = INT_MAX;
        int idx;
        for (int i = 0; i < length; i++){
            if (lowest > combined[i]){
                lowest = combined[i];
                idx = i;
            }
        }
        
        combined[idx] = max + 5;
        final[j] = lowest;
    }
    
    
    if (length % 2 == 1){ // if odd
        printf("%f", (float) final[center]);
    } else { // if even
        float end = ((float) final[center] + (float) final[center - 1]) / 2.0;
        printf("%f", end);
    }
    
}
