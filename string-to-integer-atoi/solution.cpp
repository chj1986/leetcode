class Solution {
public:
    int myAtoi(string str) {
        int length = str.size();
        int index=0;
        unsigned int ret=0;
        int sret=0;
        vector<char> digitStr;
        bool isMinus=false;
        bool isPlus=false;
        bool isOverflow=false;
        bool isDigitInput=false;
        
        while((str[index]>='0' && str[index]<='9') || str[index]==' ' || str[index]=='-' || str[index]=='+')   //check digit number OR white space
        {
            if(str[index]=='+')
            {
                if(isPlus==true || isMinus==true)
                    break;
                else if(isDigitInput==true)
                    break;
                else if(isMinus==true)
                    break;
                else
                    isPlus = true;
            }
            else if(str[index]=='-')
            {
                if(isMinus==true || isPlus==true)
                    break;
                else if(isDigitInput==true)
                    break;
                else if(isPlus==true)
                    break;
                else
                    isMinus = true;
            }
            else if(str[index]>='0' && str[index]<='9')
            {
                if(digitStr.size()==0 && str[index]=='0')
                    isDigitInput=true;
                else
                {
                    isDigitInput=true;
                    digitStr.push_back(str[index]);
                }
            }
            else    //character
            {
                if(digitStr.size()!=0 || isMinus==true || isPlus==true || isDigitInput==true)
                    break;
            }
            index++;
        }
        
        for(int j=0; j<digitStr.size(); j++)
        {
            double dec = (double)(digitStr.size()-1-j);
            if(pow(10.0, dec)<=INT_MIN)
            {
                isOverflow = true;
                break;                
            }
            else if(pow(10.0, dec)>=INT_MAX)
            {
                isOverflow = true;
                break;
            }
            
            int number = digitStr.at(j)-'0';
            if(number*(pow(10.0, dec)) >= INT_MAX)
            {
                isOverflow = true;
                ret = INT_MAX;
            }
            else if(number*(pow(10.0, dec)) <= INT_MIN)
            {
                isOverflow = true;
                ret = INT_MIN;
            }
            else 
                ret += number*(pow(10.0, dec));
        }
        
        if(isMinus==true)
        {
            if(isOverflow==true)
                ret = INT_MIN;
            else if(ret<=INT_MAX)
            {
                sret = -(ret);
                return sret;
            }
            else
            {
                return INT_MIN;
            }
            /*else if(ret<INT_MAX)
                ret = -(ret);
            else if(ret>=INT_MAX)
                ret = INT_MIN;*/
        }
        else
        {
            if(isOverflow==true)
                ret = INT_MAX;
            else if(ret>=INT_MAX)
            {
                return INT_MAX;
            }
        }
        
        return ret;
    }
};
