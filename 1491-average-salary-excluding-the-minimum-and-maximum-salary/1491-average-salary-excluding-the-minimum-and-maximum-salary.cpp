class Solution {
public:
    double average(vector<int>& salary) {
        double mini = *min_element(salary.begin(),salary.end());
        double maxi = *max_element(salary.begin(),salary.end());

        int minMaxCount = 0;
        double sum=0;

        for(auto it:salary){
            if(it==mini or it==maxi) minMaxCount++;
            else sum+=it;
        }

        return (double)sum/(salary.size()-minMaxCount);
    }
};