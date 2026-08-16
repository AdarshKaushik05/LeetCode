class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int count = 0;

        for(char ch:s){
            if(ch == 'L'){
                balance++;
            }
            else{
                balance--;
            }
            if(balance == 0){
                count++;
            }
        }
        return count;
        
    }
};