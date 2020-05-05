//recursive approach

#include <iostream>
  
int main(){
    
    int firstBadVersion(int n) {
        return fBV(1,n);
      }
    
    int fBV(int s, int e){
        if(s==e)              //if start = end (as end is bad it's given)
            return s;
    
        int mid =s+ (e-s)/2 ; //(s-e)/2 similar to this 1 but we have taken that way to escape negative values
         if(isBadVersion(mid))
             return fBV(s, mid); //if mid is bad then value should be in first half
        return  fBV(mid+1, e);    // else value would be in seconf half
    
    }