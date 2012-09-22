class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for (int i = 0; i < n; ++i) {
            left[i] = i;
            while (left[i] > 0 && height[left[i] - 1] >= height[i]) {
                left[i] = left[left[i] - 1];
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            right[i] = i;
            while (right[i] + 1 < n && height[right[i] + 1] >= height[i]) {
                right[i] = right[right[i] + 1];
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = max(ret, height[i] * (right[i] - left[i] + 1));
        }
        return ret;
    }
};

