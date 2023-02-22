class Solution {
public:
    bool acceptedCapacity(int capacity, int days,vector<int>&weights){
        int total = 0,day=1;

        for(auto weight:weights){
            total +=weight;
            if(total>capacity){
                day++;
                total = weight;
                if(day>days) return false;
            }
        }

        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(),weights.end()), right = accumulate(begin(weights),end(weights),0);

        while(left<=right){
            long long mid = left + (right-left)/2;
            if(acceptedCapacity(mid,days,weights)){
                right = mid - 1;
            }
            else left = mid+1;
        }

        return left;
    }
};