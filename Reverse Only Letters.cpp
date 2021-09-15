class Solution {
public:
    string reverseOnlyLetters(string s) {
        string a="";
        for(int i = 0 ;i < s.size(); i++)
        {
            if(s[i]>='a' && s[i]<='z')
                a= s[i] +a;
            else if(s[i]>='A' && s[i]<='Z')
                a= s[i] +a;
        }
        // sort(a.rbegin(),a.rend());
        // cout<<a<<endl;
        int point= 0;
        for(int i = 0; i < s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z'){
                s[i]=a[point];
                point++;
            }
            else if(s[i]>='A' && s[i]<='Z'){
                s[i]=a[point];
                point++;
            }else{
                s[i]=s[i];
            }
                

        }
        return s;
    }
};