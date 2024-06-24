class Solution {
    string solve(int n,string str,int &k,char ch)
    {
        if(n==0){
             k--;
        }
        if(k==0 && n==0) return str;
        if(n<0) return "";
        string ans="";
        for(char i='a';i<='c';i++)
        {
            if(ch!=i){
                ans=solve(n-1,str+i,k,i);
                if(ans!=""){
                    break;
                }
            }
        }
        return ans;
    }
public:
    string getHappyString(int n, int k) {
        string ans= solve(n,"",k,'#');
        return ans;
    }
};