class Solution {
private:

void solve(vector<string>& ans,string output,string digits, int index,string mapping[]){
     //base case
     if(index>=digits.length()){
         ans.push_back(output);
         return;
     }
                //give character
      int number=digits[index]-'0';

      string value=mapping[number];//number k corresponding value nikaal li
      for(int i=0;i<value.length();i++){
          output.push_back(value[i]);
          solve(ans,output,digits,index+1,mapping);
          output.pop_back();//"a","b",c" add hua hoga usse htana hai which is an example of backtracing taaki wo answer mei na aaye
      }

}
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        int index=0;
        if(digits.length()==0){
            return ans;
        }
        //creating mapping
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(ans,output,digits,index,mapping);
        return ans;
    }
};
