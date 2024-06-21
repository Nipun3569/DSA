class Solution {
public:
     bool check(vector<int> base,vector<int> newBox){
        if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<=base[2]){
            return true;
        }else{
            return false;
        }
     }
     int solveTab(int n,vector<vector<int>> &a){
        // Initialize dp table with 0s
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);

        // Fill the dp table from the bottom up
        for (int curr = n-1; curr >= 0; curr--) {
            for (int prev = curr-1; prev >= -1; prev--) {
                // Take the current element if it is larger than the previous element in the subsequence
                int take = 0;
                if (prev == -1 || check(a[curr], a[prev])) {
                    take = a[curr][2] + nextRow[curr+1];
                    //instead of doing 1 + we will do height + and height is a[2]
                }

                // Not take the current element
                int notTake = 0 + nextRow[prev+1];

                // Store the result in the dp table
                currRow[prev+1] = max(take, notTake);
            }
            nextRow=currRow;
        }
        return nextRow[0];
        
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        //sort all dimension for every cuboids
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
        }

        //step 2: sort all cuboid babis on width or length
        sort(cuboids.begin(),cuboids.end());

        //use LIS logic
       return solveTab(cuboids.size(),cuboids);

    }
};
