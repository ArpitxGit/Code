class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //dp
        //length of two strings
        int m = s1.size(), n = s2.size();
        
        //if sum of length of two strings is not equal to third
        if((m+n) != s3.size()) return false;
        
        //2D table for our result
        bool il[m+1][n+1];
        
        //making all values false
        memset(il, 0, sizeof(il));
        
        //traversing all characters of s1 and s2
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                
                //base case
                if(i==0 && j==0) il[i][j] = true;
                
                //s1 empty
                else if(i==0){
                    if(s2[j-1] == s3[j-1]) il[i][j]=il[i][j-1];
                }
                
                //s2 epmty
                else if(j==0){
                    if(s1[i-1] == s3[i-1]) il[i][j]=il[i-1][j];
                }
                
                //kth of s3 and s1 matches but not s2
                else if(s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1])
                    il[i][j] = il[i-1][j];
                
                //kth of s3 and s2 matches but not s1
                else if(s1[i-1] != s3[i+j-1] && s2[j-1] == s3[i+j-1])
                    il[i][j] = il[i][j-1];
                
                //kth of s3 matches with both s1 and s2
                else if(s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1])
                    il[i][j] = (il[i-1][j] || il[i][j-1]);
                
            }
        }
        //returning the reult
        return il[m][n];
    }
};
