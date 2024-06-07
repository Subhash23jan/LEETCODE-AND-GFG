class Solution
{
    bool isInitialString (string s1,string s2)
    {
        int i=0,j=0;
        if(s1.size()<s2.size()) return false;
        while(j<s2.size() && s1[j]==s2[j]){
            j++;
        }
        return j==s2.size();
    }
    public:
        string replaceWords(vector<string> &dictionary, string sentence)
        {
            sort(dictionary.begin(), dictionary.end(), [](string a, string b)
            {
                return a.size() < b.size(); });
            string ans = "";
            int k=0;
            while (k<sentence.size())
            {
                string str="";
                while(k<sentence.size() && sentence[k]!=' '){
                    str+=sentence[k];
                    k++;
                }
                k++;
                bool isFound = false;
                for (auto word: dictionary)
                {
                    if(isInitialString(str,word)){
                        ans+=word;
                        isFound=true;
                        break;
                    }
                }
                if(!isFound){
                    ans+=str;
                }
                if(k<sentence.size()){
                    ans+=" ";
                }
            }
            return ans;
        }
};