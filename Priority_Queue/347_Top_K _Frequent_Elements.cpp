#include<bits/stdc++.h>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       for(auto ele : nums){
        mp[ele]++;
       }
       
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       for(auto [key,value] : mp){
        pq.push({value,key});
        if(pq.size()>k){
            pq.pop();
        }
       }
       vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

//373. Find K Pairs with Smallest Sums

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       vector<vector<int>>ans;
       priority_queue<pair<int,vector<int>>>pq;
       for(int i=0;i<nums1.size();i++)
       {
            for(int j=0;j<nums2.size();j++)
            {
                int sum=nums1[i]+nums2[j];
                vector<int>ops;
                ops.push_back(nums1[i]);
                ops.push_back(nums2[j]);
                if(pq.size()<k)
                {
                    pq.push(make_pair(sum,ops));
                }
                else if(sum<pq.top().first)
                {
                    pq.pop();
                     pq.push(make_pair(sum,ops));
                }
                else
                {
                    break;
                }
            }
       }
       while(!pq.empty())
       {
          ans.push_back(pq.top().second);
          pq.pop();
       }
       return ans;
        
    }
};
