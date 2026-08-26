class Solution {
public:
    bool splitHelper(vector<int>&nums,int k,int m){
        int count =1;
        int sum = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(sum + nums[i]>m){
                count++;
                sum = nums[i];
            }
            else{
                sum = sum + nums[i];
            }
        }
        return count <=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;

        while(low<=high){
            int mid = low + (high -low)/2;

            if(splitHelper(nums ,k,mid)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};