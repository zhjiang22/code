#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int k = A.size();
        int ans = 0, s = 0;
        int l = 0, r = 0;
        while (l <= r || (l == 0 && r == 0)) {
            while (r < k && s < S) {
                cout << "*" << l << " " << r  << " " << s << endl;
                s += A[r++];
                if (s == S)     ans++;
            }
            if (s == S) {
                ans++;
                while (A[r] == 0) {
                    r++;
                    ans++;
                }
            }
            cout << "*" << l << " " << r  << " " << s << endl;
            while (l < r && s > S) {
                cout << "*" << l << " " << r  << " " << s << endl;
                s -= A[l++];
            }
            if (s == S) {
                ans++;
                while (A[l] == 0 && l < r) {
                    l++;
                    ans++;
                }
                s -= A[l++];
            }
            if (l == r && l == k)
                break;
            cout << l << " " << r << " " << s << endl;
        }
        return ans;
    }
}powderhan;

int main() {
    vector<int> A = {1, 0, 1, 0, 1};
    cout << powderhan.numSubarraysWithSum(A, 1) << endl;
    return 0;
}
