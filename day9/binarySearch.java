class Solution {
    public boolean isPerfectSquare(int num) {
         int ld = num%10;    //ld- last digit because here num is square not square root
        if(ld ==2 || ld == 3 || ld == 7 || ld == 8 )
            return false;
        
        //binary search
        
        int l=1;
        int r = num;
        while(l<= r){
            long mid = l +(r-l)/2;
            long sq = mid*mid;
            
            if(sq ==num)
                return true;
            else if(sq< num)
                l = (int)mid+1;
            else
                r = (int)mid-1;        
        }
        return false;
        
    }
}