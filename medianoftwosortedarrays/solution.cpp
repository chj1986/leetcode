class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double medianVal=0.0;
        int m = nums1.size();
        int n = nums2.size();
        int medIndex = (m+n)/2;
        int length=m+n;
        if(length%2==0) //Even case
        {
            cout << "evencase! medIndex=" << medIndex <<endl;
            int candidate1=0;
            int candidate2=0;
            for(int i=0,j=0; i+j <= medIndex ; )
            {
                candidate1 = candidate2;
                if(i>=m || m==0)
                {
                    candidate2=nums2.at(j++);   //i index overflow
                    continue;
                }
                else if(j>=n || n==0)
                {
                    candidate2=nums1.at(i++);   //j index overflow
                    continue;
                }
                
                if(nums1.at(i) < nums2.at(j))   //pick i
                {
                    candidate2=nums1.at(i++);
                }
                else    //pick j
                {
                    candidate2=nums2.at(j++);
                }
            }            
            medianVal = (double)(candidate1+candidate2)/2;
        }
        else    //Odd case
        {
            for(int i=0,j=0; i+j <= medIndex ; )
            {
                if(i>=m || m==0)
                {
                    medianVal=nums2.at(j++);   //i index overflow
                    continue;
                }
                else if(j>=n || n==0)
                {
                    medianVal=nums1.at(i++);   //j index overflow
                    continue;
                }
                if(nums1.at(i) < nums2.at(j))   //pick i
                {
                    medianVal=nums1.at(i++);
                }
                else    //pick j
                {
                    medianVal=nums2.at(j++);
                }
            }
        }
        return medianVal;
    }
};
