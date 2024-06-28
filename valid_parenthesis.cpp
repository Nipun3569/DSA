
bool isValidParenthesis(string s)
{
   stack<char> st;

   for(int i=0;i<s.length();i++){
       if(s[i]=='('||s[i]=='{'||s[i]=='['){
           st.push(s[i]);
       }else{
           if(!st.empty()){
               char ch=st.top();

               if (ch == '(' && s[i] == ')' || ch == '{' && s[i] == '}' || 
                  ch=='['&& s[i]==']'){
                      st.pop();
                  }else{
                      return false;
                  }
           }else{
               return false;
           }
       }

       
   }
   if(st.empty()){
           return true;
       }else{
           return false;
       }
}
