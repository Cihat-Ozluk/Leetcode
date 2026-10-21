#include <sstream>
#include <stack>
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        vector<int> times(n,0);
        stack<int> st;

        int time1=0;
        int time2;

        for(string& log:logs){
            stringstream ss(log);
            string idStr, type, timeStr;
            getline(ss, idStr, ':');
            getline(ss, type, ':');
            getline(ss, timeStr, ':');
            int id = stoi(idStr);
            time2 = stoi(timeStr);

            if(type=="start"){
                if(!st.empty()) times[st.top()] += time2-time1;
                st.push(id);
                time1=time2;
            } else {
                times[st.top()] += time2-time1+1;
                st.pop();
                time1=time2+1;
            }
        }
        return times;
    }
};
