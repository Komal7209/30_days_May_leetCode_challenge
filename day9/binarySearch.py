class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        ld = num%10;  #ld- last digit because here num is square not square root
        if(ld ==2 or ld == 3 or ld == 7 or ld == 8 ):
            return False
        
        #binary search
        
        l=1
        r = num
        while(l<= r):
            mid =int(l +(r-l)/2)
            sq = int(mid*mid)
            
            if(sq ==num):
                return True
            elif(sq< num):
                l = mid+1
            else:
                r = mid-1        
        
        return False
        
    