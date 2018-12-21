#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

int myprintf(const char* format,...) {
	int argv_int[50];
	va_list ap;
	va_start(ap,format);
	int l = strlen(format);
	int cur = 0;
	int cnt = 0;
	while(cur < l) {
		if(format[cur] == '%') {
			if(format[++cur] == 'd' || format[cur] == 'i') {
				int p = va_arg(ap,int);
				if(p < 0)	putchar('-'), p = -p;
				int pos = 0;
				while(p) {
					argv_int[pos++] = p % 10;
					p /= 10;
				}
				for(int i = pos - 1; i >= 0; i--)	putchar(argv_int[i] + '0'), ++cnt;
			}
			else	if(format[cur] == 'o' || format[cur] == 'x'
						|| format[cur] == 'X' || format[cur] == 'u') {
				unsigned int p = va_arg(ap,unsigned int);
				int pas;
				if(format[cur] == 'o')	pas = 8;
				else	if(format[cur] == 'u') pas = 10;
				else	pas = 16;
				int pos = 0;
				while(p) {
					argv_int[pos++] = p % pas;
					p /= pas;
				}
				for(int i = pos - 1; i >= 0; i--) {
					if(argv_int[i] >= 10 && format[cur] == 'x')	putchar('a' + argv_int[i] - 10);
					else	if(argv_int[i] >= 10)	putchar('A' + argv_int[i] - 10);
					else	putchar('0' + argv_int[i]);
					++cnt;
				}
			}
			else	if(format[cur] == 'c') {
				char ch = va_arg(ap,int);
				putchar(ch);	cnt++;
			}
			else	if(format[cur] == 'p') {
				void* pp = va_arg(ap,void*);
				unsigned long long p = (unsigned long long)pp;
				int pos = 0;
				while(p) {
					argv_int[pos++] = p % 16;
					p /= 16;
				}
				putchar('0');	putchar('x');	cnt += 2;
				for(int i = pos - 1; i >= 0; i--) {
					if(argv_int[i] >= 10)	putchar('a' + argv_int[i] - 10);
					else	putchar('0' + argv_int[i]);
					++cnt;
				}
			}
			else	if(format[cur] == '%') {
				putchar('%');
				++cnt;
			}
			else	if(format[cur] == '') {

			}
		}
		else {
			putchar(format[cur]);
			++cnt;
		}
		cur++;
	}
	return cnt;
}

int main() {
	int a = 20, b = 30, n = -3221;
	int c = 15, d = 240;
	void *p = &c, *q = &d;
	myprintf("%u %i\n", a, a+b);
	printf("%u %i\n", a, a+b);
	myprintf("%d %o %x %X\n",n,c,d,d);
	myprintf("%c %c %c %c\n",'a','b','c','d');
	myprintf("%c %c %c %c\n",'a','b','c','d');
	myprintf("%p %p\n",p,q);
	printf("%p %p\n",p,q);
	return 0;
}
