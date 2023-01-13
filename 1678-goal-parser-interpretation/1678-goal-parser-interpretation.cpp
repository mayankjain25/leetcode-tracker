class Solution {
public:
    string interpret(string command) {
        stack<char>s;
        
        int n=command.size();
        
        string ans="";
        
        for(int i=0;i<n;i++){
            if(command[i]!=')'){
                if(command[i]=='G') ans.append("G");
                s.push(command[i]);
                
            }
            else{
                char v=s.top();
                if(v=='('){
                    s.pop();
                    ans.append("o");
                    continue;
                }
                else{
                    s.pop();
                    s.pop();
                    s.pop();
                    ans.append("al");
                }
                
                
            }
        }
        
        return ans;
    }
};