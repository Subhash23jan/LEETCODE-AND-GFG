class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        string str = "";
        for (int i = 0; i < needle.size(); i++) {
            str += haystack[i];
        }
        i = needle.size();
        if (str == needle)
            return i - str.size();
        while (i < haystack.size()) {
            str = str.substr(1);
            str += haystack[i++];
            if (str == needle)
                return i - str.size();
        }
        return -1;
    }
};