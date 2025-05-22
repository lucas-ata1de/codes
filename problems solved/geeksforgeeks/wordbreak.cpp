
#define ll long long
class Solution {
  public:
    bool breaking(int i,string &s,vector<int> &dp,unordered_set<string> &dic){
        int n=s.size();
        if(dp[i]!=-1) return dp[i];
        if(i==n){
            return dp[i]=true;
        }
        
        string p="";
        for(int j=i;j<min(i+100,n);j++){
            p+=s[j];
            if(dic.count(p) and breaking(j+1,s,dp,dic)) return dp[i]=true;   
        }
        return dp[i]=false;
        
    }
    
    bool wordBreak(string &s, vector<string> &dictionary) {
        vector<int> dp(s.size()+1,-1);
        unordered_set<string> dic; for(auto &i : dictionary) dic.insert(i);
        return breaking(0,s,dp,dic);
    }
};
