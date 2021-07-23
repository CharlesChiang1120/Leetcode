class Solution:
    def prisonAfterNDays(self, cells: List[int], n: int) -> List[int]:
        return prisonAfterNDays(cells, n)

def prisonAfterNDays(cells, n):
    seen = []
    while n > 0:
        cellsNext = [0] * len(cells)
        for i in range(1, len(cells)-1):
            cellsNext[i] = 1 if cells[i-1] == cells[i+1] else 0
        cells =  cellsNext
        n -= 1
        if cells in seen:
            n %= len(seen)
        else:
            seen.append(cells)
        
    return cells