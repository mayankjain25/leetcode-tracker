class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>visit;
        queue<int>to_visit;
        
        to_visit.push(0);
        while(!to_visit.empty()){
            int curr=to_visit.front();
            to_visit.pop();
            visit.insert(curr);
            for(int key:rooms[curr]){
                if(visit.find(key)==visit.end()){
                    to_visit.push(key);
                }
            }
        }
        
        return visit.size()==rooms.size();
    }
};