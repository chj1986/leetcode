class Solution {
public:
    string convert(string s, int numRows) {
        string *s_arr = new string[numRows];
        string ret;
        int i=0;
        while(i<s.size())
        {
            int row=0;
            for(row=0 ; (row<numRows && i<s.size()); row++)
            {
                s_arr[row].push_back(s[i++]);
            }
            for(row=numRows-2; (row>0 && i<s.size()); row--)
            {
                s_arr[row].push_back(s[i++]);
            }
        }
        for(int j=0; j<numRows; j++)
        {
            ret += s_arr[j];
        }
        delete[] s_arr;
        return ret;
    }
};
