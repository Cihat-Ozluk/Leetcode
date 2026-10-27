//https://leetcode.com/problems/add-binary/description
//Given two binary strings a and b, return their sum as a binary string.

//my solution
class Solution {
public:
    string addBinary(string a, string b) {
        deque<string> sum;
        int hold=0;
        
        int i=0;

        // DÜZELTME 1: && yerine || (uzun olan string bitene kadar devam)
        while(i<a.size() || i<b.size()){

            // DÜZELTME 2: string bittiyse o basamağı '0' say
            char x = i<a.size() ? a[a.size()-1-i] : '0';
            char y = i<b.size() ? b[b.size()-1-i] : '0';

            // DÜZELTME 3: 0 ve 1 yerine '0' ve '1' (char karşılaştırması)
            if(x=='0' && y=='0'){
                sum.push_front(to_string(hold+0));
                hold=0;
            }else if(x=='1' && y=='0'){
                if(hold==0){
                    sum.push_front("1");
                    hold=0;
                }else{
                    sum.push_front("0");
                    hold=1;
                } 
            }else if(x=='0' && y=='1'){
                if(hold==0){
                    sum.push_front("1");
                    hold=0;
                }else{
                    sum.push_front("0");
                    hold=1;
                }
            }else{
                if(hold==0){
                    sum.push_front("0");
                    hold=1;
                }else{
                    sum.push_front("1");
                    hold=1;
                }
            }
            i++;
        }
        if(hold==1) sum.push_front("1");

        string sumStr="";
        
        for(int i=0;i<sum.size();i++) sumStr+=sum[i];

        return sumStr;
    }
};

//best solution
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size() - 1, j = b.size() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            ans += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
