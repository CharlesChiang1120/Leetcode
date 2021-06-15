// int maxSubArray(int* nums, int numsSize){
//     int max = nums[0];
//     for (int i = 0; i < numsSize; i++) {
//         int sum = 0;
//         for (int j = i; j < numsSize; j ++) {
//             sum = sum + nums[j];
//             if ( sum >= max){
//                 max = sum;
//             }
//         }
//     }
//     return max;
// }

// Kadane (Dynamic Programming)

int maxSubArray(int* nums, int size)
{
    int sum = 0;
    int max = INT_MIN;
    for(int i = 0; i < size; i++)
    {
        if(sum >= 0)
            sum += nums[i];
        else
            sum = nums[i];
        if(sum > max)
            max = sum;
    }
    return max;
}