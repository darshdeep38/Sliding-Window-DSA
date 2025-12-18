class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;       // stores indices
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Remove indices which are out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(i);

            // Window becomes valid after i >= k - 1
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
