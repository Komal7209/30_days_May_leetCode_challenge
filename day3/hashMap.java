class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
           //space complexity: order: m+n m-characters of magazine, n- size  of note
        
        Map<Character,Integer> _mag =new HashMap<>();
        // unordered_map<char, int> _mag;  //hashmap thus key value pair

        for (char c :magazine.toCharArray()){
            if(_mag.containsKey(c)){   //i.e if found because end hasnt reached so just increment the count
                int count= _mag.get(c)+1;
                _mag.put(c,count);
            }else
                _mag.put(c, 1);
        }
        
        //for iterating characters of ransom note
        
        for (char c: ransomNote.toCharArray()){
            if(_mag.containsKey(c)== false)
                return false;
            int count= _mag.get(c);
            if (count ==0)
                return false;
            _mag.put(c,count -1);
            
        }

return true;

    }
}