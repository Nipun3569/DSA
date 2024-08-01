
#approach 1
string longestCommonPrefix(vector<string> &arr, int n)
{  string ans="";
    //for traversing all characters of first string 
    for(int i=0;i<arr[0].length() ;i++){
    char ch=arr[0][i];// 0 string ka ith character
    bool match=true;
   //for remaining strings
   //for comparing character with rest of the strings
    for(int j=1;j<n;j++){
    
    //not match
    if(arr[j].size()<i || ch!=arr[j][i]){//j string ka ith character
        match=false;
        break;
    }
    }


    if(match==false){
        break;
    }
    else{
        ans.push_back(ch);
    }
    }
    return ans;

}



#approach 2

class TrieNode{
    
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
    
    data=ch;

    for(int i=0;i<26;i++){
        children[i]=NULL;
    }
    childCount=0;
    isTerminal=false;
    }
};
class Trie{

    public:
    TrieNode* root;

    Trie(char ch){
        root=new TrieNode(ch);
    }

    void insertUtil(TrieNode* root,string word){
		//base case
		if(word.length()==0){
			root->isTerminal=true;
			return;
		}
		
		
		int index=word[0]-'a';
		
		TrieNode* child;
		//present
		if(root->children[index]!=NULL){
			child=root->children[index];
		}
		else{
			//absent
			child=new TrieNode(word[0]);
            root->childCount++;
			root->children[index]=child;
		}
		//recursion
		//first character ko chod k agla pass krdiya
		insertUtil(child,word.substr(1));
	}
	void insertWord(string word){
		insertUtil(root,word);
	}
	 void lcp(string str,string &ans){
     
     for(int i=0;i<str.length();i++){
         char ch=str[i];

         if(root->childCount==1){
             ans.push_back(ch);

             //aage badh jao;

             int index=ch-'a';

             root=root->children[index];
         }
         else{
             break;
         }

         if(root->isTerminal){
             break;
         }
     }
     }

};
string longestCommonPrefix(vector<string> &arr, int n)
{  
    Trie *t=new Trie('\0');

    //insert all strings into trie

    for(int i=0;i<n;i++){
        t->insertWord(arr[i]);
    }

    string first=arr[0];
    string ans="";

    t->lcp(first,ans);

    return ans;




}
