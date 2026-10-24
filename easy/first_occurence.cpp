class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int j=0;
        int size=needle.size();

        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[j]){
                if(j!=size-1) j++;
                else return i-size+1;
            }else{
                i=i-j;
                j=0;
            }
        }
        return -1;
    }
};
