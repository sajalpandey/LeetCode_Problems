class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        
        int i = num1.size()-1, j = num2.size()-1, carry = 0;
        while(i>=0 && j>=0){
            int sum  = carry + num1[i] -'0' + num2[j]-'0' ;
            
            if(sum > 9){
                sum = sum%10;
                carry = 1;
            }
            else
            carry = 0;
            ans = to_string(sum) + ans ;
            --i , --j;
        }
        while(i >= 0){
            
            int sum = carry + num1[i]-'0';
            
            if(sum > 9){
                sum = sum%10;
                carry = 1;
            }
            else
            carry = 0;
            ans = to_string(sum) + ans ;
            --i;
        }
        
        while(j >= 0){
            
            int sum = carry + num2[j]-'0';
            
            if(sum > 9){
                sum = sum%10;
                carry = 1;
            }
            else
            carry = 0;
            ans = to_string(sum) + ans ;
            --j;
        }
        if(carry)
            return ("1"+ans);
        return ans;
    }
};