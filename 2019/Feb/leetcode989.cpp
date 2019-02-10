class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int l1 = A.size();
        vector<int> b;
        while (K) {
            b.push_back(K % 10);
            K /= 10;
        }
        reverse(A.begin(), A.end());
        int l2 = b.size();
        int l = max(l1, l2);
        vector<int> c;
        int cur = 0;
        for (int i = 0; i < l; i++) {
            int x;
            if (i >= l1)
                x = b[i] + cur;
            else    if (i >= l2)
                x = A[i] + cur;
            else
                x = A[i] + b[i] + cur;
            cur = x / 10;
            x %= 10;
            c.push_back(x);
        }
        if (cur)    c.push_back(cur);
        reverse(c.begin(), c.end());
        return c;
    }
};

