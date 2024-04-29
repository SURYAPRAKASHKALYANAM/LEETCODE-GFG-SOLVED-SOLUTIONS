class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1=0,r2=0,c1=0,c2=0;
        bool pr1=0,pc1=0;
        int beg=0;
        if(num1[beg]=='-')
        {
            pr1=true;
            beg++;
        }
        while(num1[beg]!='+')
        {
            r1=r1*10+(num1[beg]-'0');
            beg++;
        }
        if(pr1) r1=-r1;
        beg++;
        if(num1[beg]=='-')
        {
            pc1=true;
            beg++;
        }
        while(num1[beg]!='i')
        {
            c1=c1*10+(num1[beg]-'0');
            beg++;
        }
        if(pc1) c1=-c1;
        beg=0;
        pr1=pc1=0;
        if(num2[beg]=='-')
        {
            pr1=true;
            beg++;
        }
        while(num2[beg]!='+')
        {
            r2=r2*10+(num2[beg]-'0');
            beg++;
        }
        if(pr1) r2=-r2;
        beg++;
        if(num2[beg]=='-')
        {
            pc1=true;
            beg++;
        }
        while(num2[beg]!='i')
        {
            c2=c2*10+(num2[beg]-'0');
            beg++;
        }
        if(pc1) c2=-c2;
        int a1=(r1*r2-c1*c2),a2=(r1*c2+r2*c1);
        return to_string(a1)+"+"+to_string(a2)+"i";
    }
};