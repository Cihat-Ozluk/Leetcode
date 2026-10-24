//my solution
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int size=prices.size();
        vector<int> ans(size,0);
        int i=0;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(j>i && prices[i]>=prices[j]) {
                    ans[i]=prices[i]-prices[j];
                    break;
                }
                else if(j==size-1 && prices[i]<=prices[j]){
                    ans[i]=prices[i];
                    break;
                }
            }
        }
        return ans;
    }
};

//best solution
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        stack<int> s;

        for(int i = prices.size() - 1; i>=0; i--){
            int original = prices[i]; 

            while(!s.empty() && s.top() > original){
                s.pop();
            }

            if (!s.empty()) { prices[i] -= s.top();
             } 
            s.push(original);
        }        

        return prices;
    }
};
