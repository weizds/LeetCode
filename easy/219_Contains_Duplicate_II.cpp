class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        int n=arr.size();
         unordered_map<int,int>mp;
            for(int i=0;i<n;i++)
            {
                if(mp.find(arr[i])!=mp.end())
                   { return true;}
                mp[arr[i]]++;
                 if(i>=k)
                   { mp.erase(arr[i-k]); }
            }
              return false;
        
    }
};