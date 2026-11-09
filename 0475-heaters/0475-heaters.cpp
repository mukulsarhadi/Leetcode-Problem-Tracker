class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {// TC : O(MlogM+NlogM) & SC : O(1)
        
        
        // N = size of houses
        // M = size of heaters
        
        sort(heaters.begin(),heaters.end());// TC : O(MlogM)
        int ans = INT_MIN;
        
        for(auto house : houses){// TC : O(N)
            
            auto it = lower_bound(heaters.begin(), heaters.end(),house);// TC : O(logM)
            
            int right = INT_MAX;
            int left = INT_MAX;
            
            //right heaters 
            if(it != heaters.end()){
                right = *it - house;
            }
            
            //left heaters 
            if(it != heaters.begin()){
                it--;
                left = house - *it;
            }
            
            int nearest = min(right, left);
            ans = max(ans,nearest);
            
        }
        
        return ans;
        
    }
};