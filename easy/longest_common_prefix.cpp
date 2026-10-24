class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string match=strs[0];
        string temp="";
        
        for(int i=1;i<strs.size();i++){
            string current=strs[i];
            int j=0;
            while(j<current.size() && j<match.size()){
                if(current[j]==match[j]){
                    temp+=current[j];
                    j++;
                }
                else break;
            }
            match=temp;
            temp="";
        }
        return match;
    }
};
