class Solution:
    def firstUniqChar(self, s: str) -> int:
        count=[0]*26
        
        for c in s:     #iterating the character array
            count[ord(c)- ord('a')] += 1 
            # if value is a then ascii value becomes 0 as 'a-a' // here count array is ready for checking uniqueness of character occurrence # moreover directly ascii values cant be subtracted so first ascii value of given charater is found and then subbtracted a from it
        
        
        #for traversing and need to return the index not character
        for i in range(len(s)):
            if(count[ord(s[i])- ord('a')]==1):
                return i
        
        return -1;