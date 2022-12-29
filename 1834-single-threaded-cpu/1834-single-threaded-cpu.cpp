class Solution {
public:
    
    // static bool cmp(pair<int,int)
    vector<int> getOrder(vector<vector<int>>& tasks) {
      
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=tasks.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin(),tasks.end());
        
        long time = tasks[0][0];
        
        int i=0;
        
        while(i<n or !pq.empty()){
            while(i<n and time >=tasks[i][0]){
                pq.push(make_pair(tasks[i][1],tasks[i][2]));
                i++;
                
            }
            
            if(pq.empty()){
                time = tasks[i][0]; //idle
            }
            else{
                auto [pTime,index]=pq.top();
                ans.push_back(index);
                time += pTime;
                pq.pop();
            }
        }
        
        return ans;
    
    }
};