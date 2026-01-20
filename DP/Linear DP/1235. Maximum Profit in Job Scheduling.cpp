/*

Job either taken or not taken
if the job taken then find the next valid job
Binary search is used to find the next job whose begining is greater
than end of current (lower bound give the index as it sorted based on first)


*/


class Solution {
public:
    vector<int>dp;
    int solve(int id,vector<vector<int>>&arr,vector<int>&small){
        if(id>=arr.size()) return 0;
        if(dp[id]!=-1) return dp[id]; 
        int no_taken=solve(id+1,arr,small);
        int taken=0;
        taken+=arr[id][2];
        int nextid=lower_bound(small.begin(),small.end(),arr[id][1]) - small.begin();
        if(nextid>=0){

            taken+=solve(nextid,arr,small);

        }
        return dp[id]=max(taken,no_taken);

    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n=endTime.size();
        dp.resize(n,-1);

        vector<vector<int>>arr;
        for(int i=0;i<startTime.size();i++){
            vector<int>temp;
            temp.push_back(startTime[i]);
            temp.push_back(endTime[i]);
            temp.push_back(profit[i]);
            arr.push_back(temp);     
        }
        sort(arr.begin(),arr.end(),[&](auto a , auto b){

            return a[0]<b[0];

        });
        vector<int>small;
        for(int i=0;i<arr.size();i++){
            small.push_back(arr[i][0]);
        }
        int id=0;
        return solve(id,arr,small);
    }
};