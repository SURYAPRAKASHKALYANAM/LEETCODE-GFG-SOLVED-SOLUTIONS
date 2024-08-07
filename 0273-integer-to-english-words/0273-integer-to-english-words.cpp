class Solution
{
    public:
       	string ones[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",                     "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
       	string tens[10] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string help(int n)
        {
            if (n / 1000000000) return help(n / 1000000000) + " Billion" + help(n % 1000000000);
            else if (n / 1000000) return help(n / 1000000) + " Million" + help(n % 1000000);
            else if (n / 1000) return help(n / 1000) + " Thousand" + help(n % 1000);
            else if (n / 100) return help(n / 100) + " Hundred" + help(n % 100);
            else if (n / 20) return " " + tens[n / 10 - 2] + help(n % 10);
            else if (n >= 1) return " " + ones[n];
            return "";
        }
    string numberToWords(int n)
    {
        if (n == 0) return "Zero";
        return help(n).substr(1);
    }
};