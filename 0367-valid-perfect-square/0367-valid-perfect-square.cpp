class Solution {
public:
    bool isPerfectSquare(int num) {
       int low=1;
       int high=num;
       while(low<=high){
        int mid=low+(high-low)/2;
        //calculate square safely
        long long square =1LL*mid*mid;
        if(square==num){
            return true;
        }
        else if(square<num){
            low=mid+1;//search right half
        }
        else{
            high=mid-1;//search left half
        }
       } 
       return false;//no perfect square found
    }
};