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
