#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;


#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Sequence {
public:
	Sequence();
	~Sequence();
	int size();
	bool empty();
	bool find(int value);
	int &at(int pos);
	int front(); 
	int back(); 
	void insert(int value); 
	void insert(int pos, int value); 
	void clear();
	void reverse(); 
	void reverse(int fir, int las); 
	void replace(int value1, int value2);
	void swap(Sequence &seq2);
	int *a;
	int msize;
	bool mempty;
};
#endif

Sequence::Sequence() {
    msize = 0;  mempty = 1;
    a = new int[100006];
}

Sequence::~Sequence() {
    msize = 0; mempty = 1;
    delete []a;
  	a = NULL;
}

int Sequence::size() {return this -> msize;}

bool Sequence::empty() {return this -> msize == 0;}

int& Sequence::at(int pos) {return (*(a + pos));}

int Sequence::front() {return *(a);}

int Sequence::back() {return *(a + msize - 1);}

bool Sequence::find(int x) {
    for (int i = 0; i < msize; i++)
        if (*(a + i) == x)
            return true;
    return false;
}

void Sequence::insert(int value) {
    *(a + msize) = value;
    msize++;
}

void Sequence::insert(int k, int value) {
    for (int i = msize - 1; i >= k; i--)
        *(a + i + 1) = *(a + i);
    *(a + k) = value;
    msize++;
	mempty = 0;
}

void Sequence::clear() {
    msize = 0;
 	mempty = 1;
}

void change(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void Sequence::reverse() {
   int tmp[100005];
    for(int i=0;i<msize;i++) tmp[i]=a[i];
    for(int i=0;i<msize;i++) 
        a[i]=tmp[msize-1-i];
}

void Sequence::reverse(int fir, int las) {
     int tmp[100005],tl=0;
    for(int i=fir;i<las;i++) tmp[++tl]=a[i];
    for(int i=fir;i<las;i++) a[i]=tmp[tl--];
}

void Sequence::replace(int v1, int v2) {
    for (int i = 0; i < msize; i++)
        if (*(a + i) == v1)
            *(a + i) = v2;
}

void Sequence::swap(Sequence &seq2) {
int tmp[100005];
    for(int i=0;i<msize;i++) tmp[i]=a[i];
    for(int i=0;i<seq2.msize;i++) a[i]=seq2.a[i];
    for(int i=0;i<msize;i++) seq2.a[i]=tmp[i];
    int t;
    t=msize;msize=seq2.msize;seq2.msize=t;
    t=mempty;mempty=seq2.mempty;seq2.mempty=t;
}

int main() {
	Sequence seq;
	string st;
	int tot = 0;
	int x, y, number, number1, number2, pos;
	seq.insert(1); seq.insert(2); seq.insert(3);
	while (cin >> st) {
		if (st == "size") {
			cout << seq.size() << endl;
			++tot;
		}
		else
			if (st == "at") {
				cin >> number;
				cout << seq.at(number) << endl;
				++tot;
			}
			else
				if (st == "insert1") {
					cin >> number;
					seq.insert(number);
					++tot;
				}
				else
					if (st == "insert2") {
						cin >> pos >> number;
						seq.insert(pos, number);
						++tot;
					}
					else
						if (st == "reverse1") {
							seq.reverse();
							++tot;
						}
						else
							if (st == "reverse2") {
								cin >> x >> y;
								seq.reverse(x, y);
								++tot;
							}
							else
								if (st == "replace") {
									cin >> number1 >> number2;
									seq.replace(number1, number2);
									++tot;
								}
								else
									if (st == "find") {
										cin >> number;
										cout << seq.find(number) << endl;
										++tot;
									}
									else
										if (st == "empty") {
											cout << seq.empty() << endl;
											++tot;
										}
										else
											if (st == "front") {
												cout << seq.front() << endl;
												++tot;
											}
											else
												if (st == "back") {
													cout << seq.back() << endl;
													++tot;
												}
	}
	for (int i = 0; i<seq.size(); i++) cout << seq.at(i) << endl;
	Sequence tmp;
	tmp.insert(3);
	tmp.swap(seq);
	cout << tmp.size() << endl;
	for (int i = 0; i<tmp.size(); i++) cout << tmp.at(i) << endl;
	return 0;
}