class Solution {
public:
    bool isPowerOfTwo(int n) {
        //base case :1 is power of 2
        if(n==1){
            return true;
        }
        //negative numbers and 0 cannot be power of 2
        if(n<=0){
            return false;
        }
        //if odd, it cannot be a power of 2
        if(n%2!=0){
            return false;
        }
        //divide by 2 and check recursively
        return isPowerOfTwo(n/2);
    }
};