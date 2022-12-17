class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int>s;
        for(auto it:tokens){
            if(it=="+" or it=="-" or it=="*" or it=="/"){
                long long int v1=s.top();
                s.pop();
                long long int v2=s.top();
                s.pop();
                long long int v3=0;
                if(it=="+") v3=v1+v2;
                else if(it=="-") v3=v2-v1;
                else if(it=="/") v3=v2/v1;
                else v3=v1*v2;
                s.push(v3);
            }
            else{
                s.push(stoi(it));
            }
        }
        
        return s.top();
    }
};