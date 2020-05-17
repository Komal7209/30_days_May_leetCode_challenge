class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        _mag  = Counter(magazine) #<char-> count> hashmap (inbuilt counter which creates map in the string)
        
        for c in ransomNote:
            if _mag[c] ==0:  #if character is not present thern it would have key with count=0
                return False
            else:
                _mag[c] -=1
        return True