class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
       long long score=0;
        priority_queue<int>pq(nums.begin(),nums.end());
        // for(auto it:nums){
        //     pq.push(it);
        // }
        
        while(k>0 and !pq.empty()){
            score+=pq.top();
            pq.push(ceil((double)pq.top()/3));
            pq.pop();
                k--;
        }
        
        return score;
    }
};