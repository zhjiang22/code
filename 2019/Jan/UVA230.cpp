#include <bits/stdc++.h>
using namespace std;

struct Book {
    string title;
    string author;
    bool operator<(const Book & p)const {
        if (author == p.author)
            return title < p.title;
        return author < p.author;
    }
};
vector<Book> b;
int n;

void init() {
    char a[105];
    while (fgets(a, 100, stdin) != NULL) {
        if (strlen(a) == 4 && a[0] == 'E' && a[1] == 'N' && a[2] == 'D')
            break;
        int cur = 0;
        int l = strlen(a);
        Book p;
        while (cur < l && a[cur - 1] != '\"')
            p.title += a[cur++];
        cur += 4;
        while (cur < l && a[cur] != '\n')
            p.author += a[cur++];
        b.push_back(p);
    }
    sort(b.begin(), b.end());
}

map<string,int> Map;
set<Book> shelve;
set<Book> table;

void Work_Borrow() {
    string d;
    cin >> d;
    int idx = Map[d];
    int k = shelve.count(b[idx]);
    if (k == 0) {
        table.erase(b[idx]);
    }
    else {
        shelve.erase(b[idx]);
    }
}

void Work_Return() {
    string d;
    cin >> d;
    int idx = Map[d];
    table.insert(b[idx]);
}

void Work_Shelve() {
    set<Book>::iterator it;
    for (it = table.begin(); it != table.end(); it++) {
        Book p = *it;
        set<Book>::iterator pit = shelve.insert(p).first;
        if (pit == shelve.begin())
            cout << "Put " << p.title << " first" << endl;
        else {
            cout << p.title << " " << (*pit).title << endl;
        }
    }
}

void work() {
    n = b.size();
    for (int i = 0; i < n; i++) {
        Map[b[i].title] = i + 1;
        shelve.insert(b[i]);
    }
    string c;
    while (cin >> c) {
        if (c == "END")
            break;
        if (c == "BORROW")
            Work_Borrow();
        else    if(c == "RETURN")
            Work_Return();
        else
            Work_Shelve();
    }
}

int main() {
    init();
    work();
    return 0;
}