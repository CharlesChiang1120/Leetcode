class Solution:
    def nthUglyNumber(self, N: int) -> int:
        cache = [None] * (N+1)
        cache[1] = 1

        min2i = min3i = min5i = 1

        for n in range(2, N+1):
            minNumber2 =  cache[min2i] * 2
            minNumber3 =  cache[min3i] * 3
            minNumber5 =  cache[min5i] * 5

            cache[n] = min(minNumber2, minNumber3, minNumber5)

            if minNumber2 == cache[n]:
                min2i += 1
            if minNumber3 == cache[n]:
                min3i += 1
            if minNumber5 == cache[n]:
                min5i += 1
        
        return cache[N]