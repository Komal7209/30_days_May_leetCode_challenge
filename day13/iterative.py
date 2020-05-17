class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        s=1
        e=n
        while(s<e):
            mid = int(s +(e-s)/2)
            if(isBadVersion(mid)):
                e= mid                  #for checking the first half only
            else:
                s = mid+1               #for checking second half
        return s                         #if s=e 