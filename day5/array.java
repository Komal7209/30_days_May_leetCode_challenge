class Solution {
    public int firstUniqChar(String s) {
        
        int[] count= new int[26]; //initialised to 0 // as characters are less thus array used else unordered map would have been used
        
        for(char c: s.toCharArray())      // iterating the character array
            count[c-'a'] +=1; // if value is a then ascii value becomes 0 as 'a-a' // here count array is ready for checking uniqueness of character occurrence
        
        
        //for traversing and need to return the index not character
        for(int i =0; i<s.length(); ++i)
            if(count[s.charAt(i)- 'a']==1)
                return i;
        
        return -1;
    }
}