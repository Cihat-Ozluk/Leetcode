class Solution {
public:
    int romanToInt(string s) {
        
        int sum=0;
        if(s[0]=='M') sum+=1000;
        else if(s[0]=='D') sum+=500;
        else if(s[0]=='C') sum+=100;
        else if(s[0]=='L') sum+=50;
        else if(s[0]=='X') sum+=10;
        else if(s[0]=='V') sum+=5;
        else if(s[0]=='I') sum+=1;

        for(int i=1;i<s.size();i++){
            if(s[i]=='I') sum+=1;
            else if(s[i]=='V'){
                if(s[i-1]!='I') sum+=5;
                else sum+=3;
            }else if(s[i]=='X'){
                if(s[i-1]!='I') sum+=10;
                else sum+=8;
            }else if(s[i]=='L'){
                if(s[i-1]!='X') sum+=50;
                else sum+=30;
            }else if(s[i]=='C'){
                if(s[i-1]!='X') sum+=100;
                else sum+=80;
            }else if(s[i]=='D'){
                if(s[i-1]!='C') sum+=500;
                else sum+=300;
            }else if(s[i]=='M'){
                if(s[i-1]!='C') sum+=1000;
                else sum+=800;
            }
        }
        return sum;
    }
};
