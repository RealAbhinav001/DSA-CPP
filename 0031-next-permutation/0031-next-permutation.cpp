class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){ pivot = i; break; }
        }
        if(pivot == -1){
            int left = 0, right = n-1;
            while(left<right){ swap(nums[left],nums[right]); left++; right--; }
            return;
        }
        for(int j = n-1; j>pivot; j--){
            if(nums[j] > nums[pivot]){ swap(nums[j],nums[pivot]); break; }
        }
        int left = pivot + 1, right = n-1;
        while(left<right){ swap(nums[left],nums[right]); left++; right--; }
    }
};