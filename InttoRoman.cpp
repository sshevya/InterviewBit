

string Solution::intToRoman(int A) {
    int i=12;
    int val=A;
    string s="";
    string m[]={"", "M", "MM", "MMM"};
    string c[]={"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string t[]={"", "X", "XX", "XXX", "XL", "L","LX", "LXX", "LXXX","XC"};
    string u[]={"", "I", "II" , "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
string th=m[val/1000];
string h=c[(val%1000)/100];
string tn=t[(val%100)/10];
string un=u[(val%10)];
    
    s+=th+h+tn+un;
    
    return s;
}
