class Solution {
public:
    int mySqrt(int x) {
        int low=0;
        int high=x;
        while(low<=high){
            int mid=low+(high-low)/2;
            //use long long to avoid overflow as mid*mid can become larger than max int value
            long long square=1LL*mid*mid;
            if(square==x){
                return mid;
            }
            else if(square<x){
                low=mid+1;//search right
            }
            else{
                high=mid-1;//search left
            }
        }
        return high;
    }
};