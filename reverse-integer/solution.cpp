class Solution {
public:
    int reverse(int x) {
        string buffer = to_string(x);
        int ret=0;
        //cout << buffer << endl;
        
        for(int i=0;i<(buffer.size()/2);i++)
        {
            int j=buffer.size()-1-i;
            char temp=0;
            temp = buffer[j];
            buffer[j] = buffer[i];
            buffer[i] = temp;
        }
        string::size_type sz;   // alias of size_t
        try{    //If overflows
            ret = stoi (buffer,&sz);
        }
        catch(...){
            ret=0;
        }
        if(x<0)
            ret = -(ret);
        return ret;
    }
};
