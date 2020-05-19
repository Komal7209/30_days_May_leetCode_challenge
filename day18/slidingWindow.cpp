class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int count[26] ={0};
        for (char c: s1) 
            count[c-'a'] +=1;
        int start =0;
        for(int i =0; i< s1.length(); ++i)
            count[s2[i]-'a']-=1;
        
        bool match = true;
        for (int c: count){
            if(c!=0){
                match = false;
                break;
            }
        }
        if(match)return true;
        start ++;
        
        while(start <= s2.length() -s1.length()){
            int idx1 =s2[start -1] - 'a';
            int idx2 = s2[start +s1.length()-1] -'a';
            count[idx1] +=1;
            count[idx2] -=1;
            match =true;
            for(int c: count){
                if (c!=0){
                    match = false;
                    break;
                }
            }
           if(match)  return true;
            start++;
        }
      return false; 
}
};
