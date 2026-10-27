//https://leetcode.com/problems/zigzag-conversion
//turn a string into zigzag string

//my solution

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows==1) return s;
        
        vector<string> rows(numRows+1);

        int j=1;
        bool direction=1;

        for(int i=0;i<s.size();i++){
            rows[j].push_back(s[i]);
            
            if(direction) j++;
            else j--;
            if(j==numRows) direction=0;
            else if(j==1) direction=1;

        }

        string ans="";

        for(int i=1;i<=numRows;i++){
            ans+=rows[i];
        }

        return ans;
    }
};

//best solution

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string ans;
        int left=0,right=numRows-1;
        int n = s.size();
        int ind = 0;
        while(left<numRows)
        {
            int currInd=ind,flip=1;
            while(currInd < n){
                ans += s[currInd];
                if(flip){
                    if(right == 0){
                        currInd += (2*left);
                    }
                    else{
                        currInd += (2*right);
                    }
                }
                else{
                    if(left){
                        currInd += (2*left);
                    }
                    else{
                        currInd += (2*right);
                    }
                }
                flip^=1;
            }
            right--;
            left++;
            ind++;
        }
        return ans;
    }
};
