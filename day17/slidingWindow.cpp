class Solution {
public:
    
    bool hashEquals(int a[], int b[]){
        for(int i=0;i<26;++i) if(a[i]!=b[i]) return false;
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> result;
        int m = s.size(), n = p.size();
        if(m<n) return result;
        
        
        //method 1 : sliding window + hash
        //O(m+n) time & O(n) space, where m is size of string s & n is size of string p
        int patt[26] = {0};
        for(int i=0;i<n;++i) ++patt[p[i]-'a'];
        
        int text[26] = {0};
        for(int i=0;i<n;++i) ++text[s[i]-'a'];
        if(hashEquals(patt, text)) result.push_back(0);
        
        for(int i=0;i<m-n;++i){
            --text[s[i]-'a'];
            if(i+n<m) ++text[s[i+n]-'a'];
            if(hashEquals(patt, text)) result.push_back(i+1);
        }
        return result;
    }
};


// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         //unoptimised method for traversing all 26 characters
        
//         //base case when pattern is larger than string
//         vector<int>result;
//         if(p.length() > s.length())
//             return result;
        
//         vector<int> pchars(26,0); // fixed size where initialised to 0
//         for (char c: p)
//             pchars[c - 'a'] += 1; // keeps track of count all the characters and tells how many character are required
        
//         int start = 0; //start index will be 0
//         for(int i = 0; i<p.length(); ++i) //p.length gives the windows size
//             pchars[s[i]-'a'] -= 1; //we have to decrease when encounter that character
        
// //         bool match = true;
// //         for(int pc: pchars){  //while scanning all 25 characters if we find mismatch early then we'll return
// //             if(pc!= 0){
// //                 match = false;
// //                 break;
// //             }
// //         }
// //         if(match)
// //             result.push_back(start);
// //         start++; //irrespective of match or not we'll increment start
        
        
// //         //from second till n-1 character 
// //         while(start <= s.length() - p.length()){
// //             int idx1 = s[start-1] -'a';  // -1 for previous character
// //             int idx2 = s[start + p.length()-1] -'a';
// //             pchars[idx1] += 1; //this character comes in so uncremented by 1
// //             pchars[idx2] -= 1; //goes out thus decremented by 1
            
// //             match = true;
// //             for(int pc: pchars){
// //                 if(pc != 0){
// //                     match = false;
// //                     break;
// //                 }
// //             }
// //             if(match)
// //                 result.push_back(start);
// //             start++;
// //         }
// //         return result;
        
//         //for optimisation we are using mismatch count instead of bool match 
        
//         int  mismatch_count = 0;
//         for(int pc: pchars){  //while scanning all 25 characters if we find mismatch early then we'll return
//             if(pc!= 0){
//                 mismatch_count += 1;
//         }
//         if( mismatch_count == 0)
//             result.push_back(start);
//         start++; //irrespective of match or not we'll increment start
//         }  
        
//         //from second till n-1 character 
//         while(start <= s.length() - p.length()){
//             int idx1 = s[start-1] -'a';  // -1 for previous character
//             int idx2 = s[start + p.length()-1] -'a';
//             pchars[idx1] += 1; //this character comes in so uncremented by 1
//             if (pchars[idx1] ==1)
//                 mismatch_count+=1;
//             else if(pchars[idx1] ==0)
//                  mismatch_count -=1;
                
//             pchars[idx2] -= 1; //goes out thus decremented by 1
//             if(pchars[idx2]==1)
//                  mismatch_count +=1;
//             else if(pchars[idx1] ==0)
//                  mismatch_count -=1;
            
//             // for(int pc: pchars){
//             //     if(pc != 0){
//             //         match = false;
//             //         break;
//             //     }
//             // }
//             if (mismatch_count==0)
//                 result.push_back(start);
//             start++;
//         }
//         return result;
//     }
// };