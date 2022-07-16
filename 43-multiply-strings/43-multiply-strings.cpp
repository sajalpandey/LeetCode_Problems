class Solution {
public:
    string addStrings(string first , string second){
        int i = size(first) - 1, j = size(second) - 1, carry = 0, sum = 0;
        string res = "";
        while(i >= 0 || j >= 0){
            if(i >= 0)
                sum += first[i--] - '0';
            if(j >= 0)
                sum += second[j--] - '0';
            sum += carry;
            if(sum > 9){
                sum %= 10;
                carry = 1;
            }
            else
                carry = 0;
            
            res = to_string(sum) + res;
            sum = 0;
        }
        if(carry)
            return ("1"+res);
        return res ;
    }
    string multiply(string num1, string num2) {
        string res = "" , tempSum = "";
        if(num1 == "0" || num2 == "0")
            return "0";
        int i =  0;
        while(i < size(num2)){
            int digit  = num2[i] - '0';
            tempSum = "";
            while(digit > 0){
                tempSum  = addStrings(tempSum, num1);              
                digit--;
            }
            res = addStrings(res, tempSum);
            if(i != size(num2) - 1)
                res += "0";
            i++;
        }
        
        return res;
    }
};