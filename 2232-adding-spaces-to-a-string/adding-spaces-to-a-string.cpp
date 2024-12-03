class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str;
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(i==spaces[k])
            {
                k++;
                str+=" ";
                if(k==spaces.size())
                k=0;
            }
            str+=s[i];
        }
        return str;
    }
};