class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n=nums.size();
        int j=0;

        for(int i=0;i<n;i++){
            if(nums[i]==val){
                continue;
            }else{
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                j++;
            }
        }

        return j;
    }
};
