class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int minProd = nums[0];
        int largestProd = nums[0];

        for(int  i = 1; i<n; i++){
            int prevMax = maxProd;
            int prevMin = minProd;
            maxProd = max(nums[i], max(nums[i] * prevMax, nums[i] * prevMin));
            minProd = min(nums[i], min(nums[i] * prevMax, nums[i] * prevMin));
            largestProd = max(largestProd, maxProd);

        }

        return largestProd;
    }
};