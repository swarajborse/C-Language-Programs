#include <vector>
#include <algorithm>

class Solution {
public:
    // Optimal O(n log n) solution using binary search
    int lengthOfLIS(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        std::vector<int> tails;  // tails[i] = smallest tail of LIS with length i+1
        
        for (int num : nums) {
            // Binary search for position to insert/replace
            auto it = std::lower_bound(tails.begin(), tails.end(), num);
            
            if (it == tails.end()) {
                tails.push_back(num);  // Extend the sequence
            } else {
                *it = num;  // Replace to keep smallest tail
            }
        }
        
        return tails.size();
    }
    
    // Dynamic Programming O(n²) solution
    int lengthOfLIS_DP(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int n = nums.size();
        std::vector<int> dp(n, 1);  // dp[i] = length of LIS ending at i
        int maxLen = 1;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            maxLen = std::max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
    
    // Get actual LIS sequence (not just length)
    std::vector<int> getLIS(const std::vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        
        int n = nums.size();
        std::vector<int> dp(n, 1);
        std::vector<int> parent(n, -1);
        int maxLen = 1, maxIdx = 0;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }
        
        // Reconstruct LIS
        std::vector<int> lis;
        for (int i = maxIdx; i != -1; i = parent[i]) {
            lis.push_back(nums[i]);
        }
        std::reverse(lis.begin(), lis.end());
        
        return lis;
    }
};