def arrangeCoins(n):
    return int(((1+8*n)**0.5)/2- 0.5)

class Solution:
    def arrangeCoins(self, n: int) -> int:
        return arrangeCoins(n)