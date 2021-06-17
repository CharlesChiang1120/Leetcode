// Recursive

// int maxProfit(int* prices, int pricesSize){
//     if (pricesSize <= 1) {
//         return 0;
//     }else{
//         int profit;
//         int max = 0;
    
//         // 假設最後一天不賣：
//         // [7,1,5,3,6,4] = maxProfit([7,1,5,3,6,4], 6)
//         // [7,1,5,3,6]   = maxProfit([7,1,5,3,6,4], 5)
    
//         profit = maxProfit(prices, pricesSize-1);
//         if (profit > max) {
//             max = profit;
//         }
    
//         // 假設最後一天要賣
//         for (int i = 1; i <= pricesSize-1; i++) {
//             profit = maxProfit(prices, i) + prices[pricesSize-1] - prices[i-1];
//             if (profit > max) {
//                 max = profit;
//             } 
//         }
//         return max;
//     }
// }

// Dynamic Programming

// int maxProfit(int* prices, int pricesSize){
//     if (pricesSize <= 1) {
//          return 0;
//     }else{
//         int profits[pricesSize+1];
//         profits[1] = 0;
        
//         for (int k = 2; k <= pricesSize; k++) {
//             int profit;
//             int max = 0;
            
//             profit = profits[k-1];
            
//             if (profit > max) {
//                 max = profit;
//             }
            
//             for (int i = 1; i <= k-1; i ++) {
//                 profit = profits[i] + prices[k-1] - prices[i-1];
//                 if (profit > max) {
//                 max = profit;
//                 } 
//             }
//          profits[k] = max;
//         }
//         return profits[pricesSize];
//       }
// }

// Thinking:兩天比較，第二天比較高就賣

int maxProfit(int* prices, int pricesSize){
    int total = 0;
    for (int i = 0; i+1 < pricesSize; i++) {
        if (prices[i] < prices[i+1]) {
            total += prices[i+1] - prices[i];
        }
    }
    return total;
}