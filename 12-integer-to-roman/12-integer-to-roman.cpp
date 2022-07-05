class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        string romanValues [] = {"M" ,"CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> arr {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        int i = 0, freq;
        while(num>0){
            freq = num / arr[i] ;
            num %= arr[i];
            while(freq--)
                result += romanValues[i];
            i++;
        }
        return result;
    }
};