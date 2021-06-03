class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        //sorting both vectors to get largest slice
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        //https://www.geeksforgeeks.org/modulo-1097-1000000007/
        const unsigned int M = 1000000007;
        
        // max of horizontal and vertical 
        int maxh = max(horizontalCuts[0], h - horizontalCuts.back());
        int maxv = max(verticalCuts[0], w - verticalCuts.back());
        
        //max difference
        for (int i = 1; i < horizontalCuts.size(); i++)
            maxh = max(maxh, horizontalCuts[i] - horizontalCuts[i-1]);
        
        for (int i = 1; i < verticalCuts.size(); i++)
            maxv = max(maxv,verticalCuts[i] - verticalCuts[i-1]);
        
        return (int)((long)maxh * maxv % M);
    }
};
