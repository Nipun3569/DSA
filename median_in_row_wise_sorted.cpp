class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        
        
        int mi=INT_MAX;
        int mx=INT_MIN;
        
        for(int i=0;i<R;i++){
            mi=min(mi,matrix[i][0]);
            mx=max(mx,matrix[i][C-1]);
        }
        int ans=0;
        while(mi<=mx){
            int mid=mi+(mx-mi)/2;
            
            int freq=0;
            for(int i=0;i<R;i++){
                freq+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            
            if(freq>=(R*C+1)/2){
                ans=mid;
                mx=mid-1;
            }
            else{
                mi=mid+1;
            }
        }
        return ans;
    }
};
