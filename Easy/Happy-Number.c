#include<stdio.h>


int next_n(int n){
    int r = 0;
    while(n != 0){
        int d = n % 10;
        n = n / 10;
        r += d * d;
    }
    return r;
}

// bool constain(int *history, int size, int n){
//      for (int i = 0; i <=size; i++){
//          if (history[i] == n){
//              return true;
//          }
//     }return false;
// }

// bool isHappy(int n){
//     int history[1000];
//     int size = 0;
//     n = next_n(n);
        
//     while (!(constain(history, size, n))){
//             history[size] = n;
//             size++;
//             n = next_n(n);
//         }
//     return n == 1;
// }


// Cycle detection
bool isHappy(int n){
    int slow = n;
    int fast = n;
    do {
        slow = next_n(slow);
        fast = next_n(next_n(fast));
    }while(slow != fast);

    return fast == 1;
}

