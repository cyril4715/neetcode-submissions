class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        nummap = {}
        for i, num in enumerate(numbers):
            compliment = target - num
            if compliment in nummap:
                return [nummap[compliment]+1,i+1]
            nummap[num] = i
        return []