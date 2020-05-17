/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

      public class Solution extends VersionControl {
        public int firstBadVersion(int n) {
             int s=1, e=n;
             while(s<e){
                 int mid = s +(e-s)/2;
                 if(isBadVersion(mid))
                     e= mid;    // for checking the first half only
                 else
                     s = mid+1;  // for checking second half
             }
             return s;  //if s=e 
        }
    }