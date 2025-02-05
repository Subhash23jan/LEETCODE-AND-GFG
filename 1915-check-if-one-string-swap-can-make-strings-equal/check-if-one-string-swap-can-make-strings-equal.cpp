class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size())
                return false;
        int indx1,flag=0;
            if(s1==s2)
                    return true;
            for(int i=0;i<s1.size();i++)
            {
                    if(s1[i]!=s2[i] && flag==0)
                    {
                            flag=1;
                            indx1=i;
                    }else if(flag==1)
                    {
                            swap(s2[indx1],s2[i]);
                            if(s2==s1)
                                    return true;
                            swap(s2[indx1],s2[i]);
                    }
            }
            return false;
    }
};