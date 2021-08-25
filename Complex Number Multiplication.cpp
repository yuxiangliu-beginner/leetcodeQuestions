class Solution {
public:
    pair<int,int> parse(string num)
    {
        int i = num.find('+');
        double real = stoi(num.substr(0,i));
        double img = stoi(num.substr(i+1,num.size()-i-2));
        pair<int,int> res(real,img);
        return res;
        
    }
    string complexNumberMultiply(string num1, string num2) {
        pair<int,int> a = parse(num1);
        pair<int,int> b = parse(num2);
        
        int real_a = a.first,img_a = a.second;
        int real_b = b.first,img_b = b.second;
        
        return to_string(real_a*real_b-img_a*img_b)+'+'+to_string(real_a*img_b+real_b*img_a)+'i';
    }
};