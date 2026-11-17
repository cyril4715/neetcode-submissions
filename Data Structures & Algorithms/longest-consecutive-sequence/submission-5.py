class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
            
        longest = 0
        numsS = set(nums)
        length = 0

        for n in nums:
            if (n-1) not in numsS:
               length = 1
               while (n + length) in numsS:
                    length +=1
            
            
            longest = max(length, longest)
        return longest