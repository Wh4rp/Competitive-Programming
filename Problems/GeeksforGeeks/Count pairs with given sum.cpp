class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        sort(arr, arr + n);
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            ans += upper_bound(arr + i + 1, arr + n, k - arr[i]) - arr;
			ans -= lower_bound(arr + i + 1, arr + n, k - arr[i]) - arr;
        }
        return ans;
    }
};