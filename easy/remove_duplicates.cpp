//solution for memory

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==1) return 1;

        int i=0;
        while(i+1<nums.size()){
            if(nums[i]==nums[i+1]) nums.erase(nums.begin()+i);
            else i++;
        }
        return nums.size();
    }
};

//solution for speed

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0) return 0;

        int i=0;
        for(int j=1;j<n;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }

        return i+1;

    }
};
