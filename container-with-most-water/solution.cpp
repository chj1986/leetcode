class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret=0;

        int l=0;
        int r=height.size()-1;
        while(l<r)
        {
            int w = r-l;
            int h = min(height.at(l), height.at(r));
            ret = max(ret, w*h);
            if(height.at(l)>height.at(r))
                r--;
            else
                l++;
        }
        return ret;
    }
};
