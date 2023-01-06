class Solution {
public:
    string intToRoman(int num) 
    {
        unordered_map<int,string> m;
        m[1]="I";
        m[4]="IV";
        m[5]="V";
        m[9]="IX";
        m[10]="X";
        m[40]="XL";
        m[50]="L";
        m[90]="XC";
        m[100]="C";
        m[400]="CD";
        m[500]="D";
        m[900]="CM";
        m[1000]="M";
        string ans="";
        while(num)
        {
            if(num>=1000)
            {
                ans+=m[1000];
                num-=1000;
            }
            else if(num>=900) 
            {
                ans+=m[900];
                num-=900;    
            }
            else if(num>=500)
            {
                ans+=m[500];
                num-=500;
            }
            else if(num>=400)
            {
                ans+=m[400];
                num-=400;
            }
            else if(num>=100)
            {
                ans+=m[100];
                num-=100;
            }
            else if(num>=90)
            {
                ans+=m[90];
                num-=90;
            }
            else if(num>=50)
            {
                ans+=m[50];
                num-=50;
            }
            else if(num>=40)
            {
                ans+=m[40];
                num-=40;
            }
            else if(num>=10)
            {
                ans+=m[10];
                num-=10;
            }
            else if(num>=9)
            {
                ans+=m[9];
                num-=9;
            }
            else if(num>=5)
            {
                ans+=m[5];
                num-=5;
            }
            else if(num>=4)
            {
                ans+=m[4];
                num-=4;
            }
            else if(num>=1)
            {
                ans+=m[1];
                num-=1;
            }
        }
        return ans;
    }
};