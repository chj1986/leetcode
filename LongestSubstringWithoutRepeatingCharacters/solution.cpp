class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        vector<char> c;
        for(int i=0; i<s.size(); i++)
        {
            c.push_back(s[i]);
            if(length==0)
                length=1;
            for(int j=i+1; j<s.size(); j++)
            {
                if( find(c.begin(), c.end(), s[j])!=c.end() )   //Find character in vector
                {
                    length = max(length, j-i);
                    break;
                }
                else
                {
                    c.push_back(s[j]);
                }
                if(j==s.size()-1)   //Didn't find character set in vector
                    length = max(length, j-i+1);
            }
            while(c.size())
                c.pop_back();
        }
        return length;
    }
};
