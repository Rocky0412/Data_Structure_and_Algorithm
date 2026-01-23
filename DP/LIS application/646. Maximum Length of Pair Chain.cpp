class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(),pairs.end(),[&](auto a ,auto b){
            return a[0] < b[0];
        });
        vector<int>LIS;
        for(auto ele : pairs){
            if(LIS.empty() || LIS.back()<ele[0]){
                LIS.push_back(ele[1]);
            }
            else{
                int id =lower_bound(LIS.begin(),LIS.end(),ele[0]) - LIS.begin();
                if(id<LIS.size()){
                    LIS[id]= min(LIS[id],ele[1]);
                }
            }
        }
        return LIS.size();
    }
};