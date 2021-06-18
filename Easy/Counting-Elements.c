// Example 1:

// Input: arr = [1,2,3]
// Output: 2
// Explanation: 1 and 2 are counted cause 2 and 3 are in arr.


// Example 2:

// Input: arr = [1,1,3,3,5,5,7,7]
// Output: 0
// Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.


// Example 3:

// Input: arr = [1,3,2,3,5,0]
// Output: 3
// Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.


// Example 4:

// Input: arr = [1,1,2,2]
// Output: 2
// Explanation: Two 1s are counted cause 2 is in arr.

// ========================================================

// Space : O(range), range[1002]
// Time : O(arrsize + range) 

// int countElements(int *arr, int arrSize) {
//     int countOfNUmber[1002] = {0};

//     for (int i = 0; i < arrSize; i++) {
//         countOfNUmber[arr[i]]++;
//     }

//     int count = 0;
//     for (int j = 0; j < arrSize; j++) {
//         if (countOfNUmber[j+1] > 0) {
//             count += countOfNUmber[j];
//         }
//     }
//     return count;
// }

// ========================================================

// 能夠統計次數就能排序
// Space : O(1)
// Time : O(arrSize * log(arrSize)

int cmp (const void *a, const void *b) {
    return *(const int*)a - *(const int*)b;
}

int countElements(int *arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);

    int count = 0;
    int number = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] != arr[i-1]) {
            if (arr[i] == arr[i-1] + 1) {
                count += number;
            }
            number = 1;
        } else {
            number++;
        }
    }
    return count;
}