//https://leetcode.com/problems/length-of-last-word/description
//Given a string s consisting of words and spaces, return the length of the last word in the string.
//A word is a maximal substring consisting of non-space characters only.

class Solution {
public:
    int lengthOfLastWord(string s) {

       stack<string> st;
       string temp="";

        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(temp!=""){
                    st.push(temp);
                    temp="";
                }
                continue;
            }else{
                temp+=s[i];
            }
        }
        if(temp!="") return temp.size();
        else if(!st.empty()) return st.top().size();
        else return 0;
    }
};
