class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m = len(word1)
        n = len(word2)
        dp = [[0 for j in range(n+1)] for i in range(m +1)]
        
        for i in range (m +1):
            for j in range (n+1):
                if i ==0:
                    dp[i][j] = j
                elif j ==0:
                    dp[i][j] = i
                else: 
                    if word1[i-1] == word2[j -1]:
                        dp[i][j] = dp[i-1][j-1]
                    else:
                        dp[i][j] = 1 + min(min(dp[i-1][j-1], dp[i-1][j] ), dp[i][j-1])
                
        return dp[m][n]