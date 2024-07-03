/*You are required to complete this method*/

class Solution{
    private:
    vector<int> nextSmallerelement(int *heights,int n){
    stack<int> s;
    s.push(-1);

    vector<int>ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=heights[i];
        while(s.top()!=-1 && heights[s.top()]>=curr){
            s.pop();
        }
        //ans is stack ka top
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
    }

     vector<int> prevSmallerelement(int *heights,int n){
    stack<int> s;
    s.push(-1);

    vector<int>ans(n);

    for(int i=0;i<n;i++){
        int curr=heights[i];
        while(s.top()!=-1 && heights[s.top()]>=curr){
            s.pop();
        }
        //ans is stack ka top
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
    }
    
     int largestRectangularArea(int * heights,int n) {
        

        vector<int>next(n);
        next=nextSmallerelement(heights,n);

        vector<int>prev(n);
        prev=prevSmallerelement(heights,n);
       
       int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            
           //when all elements are equal then next will be -1
           if(next[i]==-1){
               next[i]=n;
           }
           int b=next[i]-prev[i]-1;
           int newArea=l*b;
           area=max(area,newArea);

        }
        return area;
    }

  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        //step 1 pehli row mei answer nikaal lo
        //compute area for first row
        
        int area=largestRectangularArea(M[0],m);
        
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                //new update: by adding previous row values
                if(M[i][j]!=0){
                M[i][j]=M[i-1][j]+M[i][j];
            }
            else{
                M[i][j]=0;
            }
            
            }
            //entire row is updated now
            area=max(area,largestRectangularArea(M[i],m));
            
            
        }
        return area;
        
    }
};
