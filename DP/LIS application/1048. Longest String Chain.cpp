class Solution {
public:
    bool isPrecedor(string s1 , string s2){
        if(s1.size()!=s2.size()+1) return false;
        int cnt =0;
        int j=0;
        for(int i=0;i<s2.size();){
            if(s1[j]!=s2[i]){
                cnt++;
                j++;
                if(cnt>1) return false;
                continue;
            }
            i++;
            j++;
        }
        return true;   
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n,1);
        sort(words.begin(),words.end(),[&](auto a , auto b){
            return a.size() < b.size();
        });
        int ans=1;
        for(int i=1;i<n;i++){

            for(int j=0;j<i;j++){
                if(isPrecedor(words[i],words[j])){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }

        }
        return ans;
    }
};