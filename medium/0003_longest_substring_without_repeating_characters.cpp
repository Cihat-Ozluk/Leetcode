//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//Given a string s, find the length of the longest substring without duplicate characters.

//my first solution
#include <string>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        string temp="";
        vector<string> set;

        if(s.size()==0) return 0;

        for(int i=0;i<s.size();i++){
            if(temp.size()!=0){
                bool found=false;             
                for(int j=0;j<temp.size();j++){
                    if(s[i]==temp[j]){
                        set.push_back(temp);
                        temp=temp.substr(j+1,temp.size()-1);
                        temp+=s[i];
                        found=true;                 
                        break; 
                    }
                }
                if(!found) temp+=s[i]; 
            }else temp+=s[i];   
        }

        set.push_back(temp); 

        int max=set[0].size();

        for(int i=0;i<set.size();i++){
            if(set[i].size()>max) max=set[i].size();
        }

        return max;

    }
};

//my second solution
#include <string>
#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();
        unordered_set<char> seen;
        int maxlen=0;
        int left=0;

        for(int right=0;right<n;right++){
            while(seen.contains(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxlen=max<int>(maxlen,seen.size());
        }

        return maxlen;
    }
};
