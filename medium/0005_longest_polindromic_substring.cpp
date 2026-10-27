//https://leetcode.com/problems/longest-palindromic-substring/description/
//Given a string s, return the longest palindromic substring in s.

//my solution

class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen=0;
        string answer="";
        int n = s.size();

        for(int right=0; right<n; right++){
            for(int left=n-1; left>=right; left--){

                int tempLeft=left, tempRight=right;

                while(s[tempLeft]==s[tempRight]){
                    if(tempLeft<=tempRight){ 
                        if(left-right+1 > maxlen){ 
                            maxlen = left-right+1;
                            answer = s.substr(right, maxlen);
                        }
                        break; 
                    }
                    tempLeft--;
                    tempRight++;
                }
            }
        }
        return answer;
    }
};

//best solution

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int maxcount = 0;

        for (int i = 0; i < s.size(); i++) {
            for (int j = s.size() - 1; j >= i; j--) {

                if (s[i] == s[j]) {

                    // Check whether s[i...j] is a palindrome
                    bool isPalindrome = true;

                    int left = i;
                    int right = j;

                    while (left < right) {
                        if (s[left] != s[right]) {
                            isPalindrome = false;
                            break;
                        }
                        left++;
                        right--;
                    }

                    if (isPalindrome && (j - i + 1) > maxcount) {
                        maxcount = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return ans;
    }
};
