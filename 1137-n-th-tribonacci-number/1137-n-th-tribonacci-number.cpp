class Solution {
public:
    int tribonacci(int n) {
        int a=1,b=1,c=2;
        if(n==0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 1;
        else if(n==3) return 2;
        int sum=2;
        
        for(int i=4;i<=n;i++){
            sum=a+b+c;
            a=b;
            b=c;
            c=sum;
        }
        
        return sum;
    }
};