//https://leetcode.com/problems/climbing-stairs/description
//You are climbing a staircase. It takes n steps to reach the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//fibonacci

//my solution
class Solution {
public:
    int climbStairs(int n) {
        
        int steps=n/2;
        int total=0;

        while(steps>=0){
            int twos=steps;
            int ones=n-2*steps;
            double top=1;
            double under1=1;
            double under2=1;

            for(long i=twos+ones;i>1;i--) top*=i;
            for(long i=twos;i>1;i--)  under1*=i;
            for(long i=ones;i>1;i--) under2*=i;

            total+=round(top/(under1*under2));
            steps--;
        }

        return total;

    }
};

//best solution
class Solution {
public:
    int climbStairs(int n) {
       vector<int>dp(n+1);
       if(n<=2) return n;
       dp[1]=1;
       dp[2]=2;
       for(int i=3;i<=n;i++){
          dp[i]=dp[i-1]+dp[i-2];
       } 
       return dp[n];
    }
};
