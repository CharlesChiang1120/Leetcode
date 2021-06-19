//類似泡沫排序法

// void moveZeroes(int* nums, int numsSize){
// while(true) {
//     bool isOK = true;
//     for (int i = 0; i < numsSize - 1; i++) {
//         if (nums[i] == 0 && nums[i+1] != 0){
//             isOK = false;
//             nums[i] = nums[i+1];
//             nums[i+1] = 0;
//               }
//          }
//     if (isOK) {
//         break;
//        }
//     }  
// }

//直接改寫nums陣列 不用做排序
//因為i會比j快 所以不用再創一個矩陣寫入
void moveZeroes(int* nums, int numsSize){
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
         }
    }
    while(j < numsSize) {
        nums[j] = 0;
        j++;
    }
}