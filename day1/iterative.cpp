  
    //iterative approach  (faster than recursive approach)
    
    
// #include <iostream>
  
// int main(){

    class Solution {
public:

     int firstBadVersion(int n) {
         int s=1, e=n;
         while(s<e){
             int mid = s +(e-s)/2;
             if(isBadVersion(mid))
                 e= mid;     // for checking the first half only
             else
                 s = mid+1;  // for checking second half
         }
         return s;           //if s=e 
      }
    
};