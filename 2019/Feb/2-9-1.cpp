#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int k = emails.size();
        set<string> s;
        string a;
        for (int i = 0; i < k; i++) {
            int l = emails[i].size();
            int cur = 0;
            while (cur < l && emails[i][cur] != '@' && emails[i][cur] != '+') {
                if (emails[i][cur] != '.')
                    a += emails[i][cur]; 
                cur++;
            }
            while (emails[i][cur] != '@' && cur < l)   cur++;
            cur++;
            while (cur < l) a += emails[i][cur++];
            if (!s.count(a))
                cout << a << endl, s.insert(a);
            a = "";
        }
        return s.size();
    }
}ppp;

int main() {
    vector<string> s;
    s.push_back("test.email+alex@leetcode.com");
    s.push_back("test.e.mail+bob.cathy@leetcode.com");
    s.push_back("testemail+david@lee.tcode.com");
    cout << s.size() << endl;
    cout << ppp.numUniqueEmails(s) << endl;
}
