#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

int print_short(int out_fmt,int signd, int width, int precision, int pas,int xorX, int p) {
	int cnt = 0;
	short x = p;
	if(signd && p < 0) {
		putchar('-'),++cnt;
		x = -x;
	}
	int argv_int [50];
	int pos = 0;
	while(x) {
		argv_int[pos++] = x % pas;
		x /= pas;
	}
	int maxk = width < precision? precision : width;
	if(maxk <= pos) {
		for(int i = pos - 1; i >= 0; i--) {
			if(argv_int[i] >= 10 && xorX == 1)	putchar('A' + argv_int[i] - 10),++cnt;
			else	if(argv_int[i] >= 10)	putchar('a' +argv_int[i] -10),++cnt;
			else	putchar('0' + argv_int[i]),++cnt;
		}
	}
	else {
		int sum1 = width - (precision > pos ? precision : pos);
		if(sum1 < 0)		sum1 = 0;
		int sum2 = precision - pos;
		if(sum2 < 0)		sum2 = 0;
		if(out_fmt == -1) {
			while(sum1--)	putchar(' '),++cnt;
		}
		while(sum2--)	putchar('0'),++cnt;
		if(out_fmt == 1) {
			while(sum1--)	putchar(' '),++cnt;
		}
	}
	return cnt;
}

int print_long(int out_fmt,int signd, int width, int precision, int pas,int xorX, int x) {
	int cnt = 0;
	if(signd && x < 0) {
		putchar('-'),++cnt;
		x = -x;
	}		
	int argv_int [50];
	int pos = 0;
	while(x) {
		argv_int[pos++] = x % pas;
		x /= pas;
	}
	int maxk = width < precision? precision : width;
	if(maxk <= pos) {
		for(int i = pos - 1; i >= 0; i--) {
			if(argv_int[i] >= 10 && xorX == 1)	putchar('A' + argv_int[i] - 10),++cnt;
			else	if(argv_int[i] >= 10)	putchar('a' +argv_int[i] -10),++cnt;
			else	putchar('0' + argv_int[i]),++cnt;
		}
	}
	else {
		int sum1 = width - (precision > pos ? precision : pos);
		if(sum1 < 0)		sum1 = 0;
		int sum2 = precision - pos;
		if(sum2 < 0)		sum2 = 0;
		if(out_fmt == -1) {
			while(sum1--)	putchar(' '),++cnt;
		}
		while(sum2--)	putchar('0'),++cnt;
		for(int i = pos - 1; i >= 0; i--)	putchar('0' + argv_int[i]),++cnt;
		if(out_fmt == 1) {
			while(sum1--)	putchar(' '),++cnt;
		}
	}
	return cnt;
}

double eps = 1e-9;

int myprintf(const char* format,...) {
	int argv_int[50];
	va_list ap;
	va_start(ap,format);
	int l = strlen(format);
	int cur = 0;
	int cnt = 0;
	int out_format = -1;
	int min_width = -1;
	int float_format = -1;
	int long_format = -1;
	int working = -1;
	while(cur < l) {
		if(format[cur] == '%' || working == 1) {
			working = 1;
			if(format[cur] == '%')	++cur;
			if(format[cur] == '-') {
				out_format = 1;	cur++;
				continue;
			}
			else	if(format[cur] <= '9' && format[cur] >= '0') {
				int ans = 0;
				while(format[cur] <= '9' && format[cur] >= '0') {
					ans *= 10;
					ans += format[cur++] - '0';
				}
				min_width = ans;
				continue;
			}
			else	if(format[cur] == '.') {
				++cur;
				int ans = 0;
				while(format[cur] <= '9' && format[cur] >= '0') {
					ans *= 10;
					ans += format[cur++] - '0';
				}
				float_format = ans;
				continue;
			}
			else	if(format[cur] == 'h' || format[cur] == 'l') {
				if(format[cur] == 'h')	long_format = 1;
				else	long_format = 2;
				continue;
			}
			if(format[cur] == 'd' || format[cur] == 'i') {
				int p = va_arg(ap,int);
				if(long_format == 1)	cnt += print_short(out_format,1,min_width,float_format,10,0,p);
				else	cnt += print_long(out_format,1,min_width,float_format,10,0,p);
			}
			else	if(format[cur] == 'o' || format[cur] == 'x'
					|| format[cur] == 'X' || format[cur] == 'u') {
				unsigned int p = va_arg(ap,unsigned int);
				int pas;
				if(format[cur] == 'o')	pas = 8;
				else	if(format[cur] == 'u') pas = 10;
				else	pas = 16;
				int k = format[cur] == 'X' ? 1 : 0;
				if(long_format == 1)	cnt += print_short(out_format,0,min_width,float_format,pas,k,p);
				else	cnt += print_long(out_format,0,min_width,float_format,pas,k,p);
			}
			else	if(format[cur] == 'c') {
				char ch = va_arg(ap,int);
				if(min_width == -1 || min_width == 0) {
					putchar(ch);	++cnt;
				}
				else {
					int sum = min_width - 1;
					if(out_format == 1) {
						putchar(ch),++cnt;
						while(sum--)	putchar(' '),++cnt;
					}
					else {
						while(sum--)	putchar(' '),++cnt;
						putchar(ch),++cnt;
					}
				}
			}
			else	if(format[cur] == 'p') {
				void *pp = va_arg(ap,void*);
				unsigned long long p = (unsigned long long)pp;
				int pos = 0;
				while(p) {
					argv_int[pos++] = p % 16;
					p /= 16;
				}
				if(min_width == -1 || min_width <= pos + 2) {
					putchar('0');	putchar('x');	cnt += 2;
					for(int i = pos - 1; i >= 0; i--) {
						if(argv_int[i] >= 10)	putchar('a' + argv_int[i] - 10);
						else	putchar('0' + argv_int[i]);
						++cnt;
					}
				}
				else {
					int sum = min_width - pos - 2;
					if(out_format == -1)
						while(sum--)	putchar(' '),++cnt;
					putchar('0'),++cnt;	putchar('x'),++cnt;
					for(int i = pos - 1; i >= 0; i--) {
						if(argv_int[i] >= 10)	putchar('a' + argv_int[i] - 10),++cnt;
						else	putchar('0' + argv_int[i]),++cnt;
					}
					cnt += min_width;
				}
			}
			else	if(format[cur] == 's') {
				char *pp = va_arg(ap,char*);
				int l = strlen(pp);
				if(min_width > l && out_format == -1) {
					int sum = min_width - l;
					while(sum--)	putchar(' '),++cnt;
				}
				for(int i = 0; i < l; i++)	putchar(pp[i]),++cnt;
				if(min_width > l && out_format == 1) {
					int sum = min_width - l;
					while(sum--)	putchar('-'),++cnt;
				}
			}
			else	if(format[cur] == 'f') {
				double k = va_arg(ap,double);
                if(k < 0)   putchar('-'),++cnt,k = -k;
				if(float_format == -1)	float_format = 6;
				long long x = k;	double y = k - x;
				int pos = 0;
				while(x) {
					argv_int[pos++] = x % 10;
					x /= 10;
				}
				int sum = pos + float_format + 1;
			   	if(sum < min_width && out_format == -1) {
					int kk = min_width - sum;
					while(kk--)	putchar(' '),++cnt;
				}
				for(int i = pos - 1; i >= 0; i--)	putchar(argv_int[i] + '0'),++cnt;
				putchar('.'),++cnt;
				for(int i = 1; i <= float_format; i++) {
                    argv_int[i] = (int)((y + eps) * 10);
					y = (y * 10 - (int) ((y + eps) * 10));
				}
				if((y + eps) * 10 >= 5)	argv_int[float_format]++;
                int cur = float_format;
                while(argv_int[cur] == 10) argv_int[cur] = 0, argv_int[cur - 1]++, cur--;
                for(int i = 1; i <= float_format; i++)  putchar(argv_int[i] + '0'), ++cnt;
				if(sum < min_width && out_format == 1) {
		        	int kk = min_width - sum;
					while(kk--)	putchar(' '),++cnt;
				}
			}
            else    if(format[cur] == 'e' || format[cur] == 'E') {
                double k = va_arg(ap,double);
                if(k < 0)   putchar('-'),++cnt,k = -k;
                if(float_format == -1)  float_format = 6;
                int pos = 0, q = 0;
                long long x = k;  double y = k - x;
                argv_int[pos] = 0;
                while(x) {
                    argv_int[pos++] = x % 10;
                    x /= 10;
                }
                if(pos == 0)    ++pos;
                if(pos >= 1 && argv_int[0] != 0) {
                    int minw = pos < (float_format + 1) ? pos :float_format + 1;
                    putchar('0' + argv_int[pos-1]);
                    putchar('.');   ++cnt;
                    int coo = 1;
                    for(int i = pos - 2; i >= 0 && coo < minw; i++)   putchar('0' + argv_int[i]),++cnt,++coo;
                    if(pos < float_format + 1) {
                        int rest = float_format - pos + 1;
                        for(int i = 1; i < rest; i++) {
                            putchar((int)((y + eps) * 10) + '0'),++cnt;
                            y = (y * 10 - (int) ((y + eps) * 10));
                        }
                    }
                    int last_one = (y + eps) * 10;  y = (y * 10 - (int) ((y + eps) * 10));
                    if((y + eps) * 10 >= 5) last_one++;
                    putchar(last_one + '0'),++cnt;
                    if(format[cur] == 'e')  putchar('e'),++cnt;
                    else    putchar('E');
                    putchar('+');
                    cnt += myprintf("%d",pos - 1);
                }
            }
            else	if(format[cur] == '%') {
                putchar('%');
                ++cnt;
            }
        }
        else {
            putchar(format[cur]);
            ++cnt;
        }
        working = out_format = min_width = float_format = long_format = -1;	
        cur++;
    }
    return cnt;
}

int main() {
        double k = 222.2345698;
        printf("%f\n",k);
        myprintf("%f\n",k);
        myprintf("%e\n",k);
        printf("%e",k);
    //	char a[50] = "formatf";
    //    printf("jkfdjlasfjdsa\n");
    //    return 0;
    //	myprintf("%s %14s",a,a);
    //	int a = 5;
    //	char b = 'a';
    //	double c = 1.2345678, d = 3223.122345623;
    //	myprintf("%d %-.5f %14f %c",a,c,d,b);
    //	int a = 20, b = 30, n = -3221;
    //	int c = 15, d = 240;
    //	void *p = &c, *q = &d;
    //	myprintf("%u %i\n", a, a+b);
    //	printf("%u %i\n", a, a+b);
    //	myprintf("%d %o %x %X\n",n,c,d,d);
    //	printf("%d %o %x %X\n",n,c,d,d);
    //	myprintf("%c %c %c %c\n",'a','b','c','d');
    //	myprintf("%c %c %c %c\n",'a','b','c','d');
    //	myprintf("%p %p\n",p,q);
    //	printf("%p %p\n",p,q);
    //	int a = 5;
    //	int* p = &a;
    //	myprintf("%16p\n", p);
    //	printf("%16p\n", p);
    //	char c = 'a', b = 'd';
    //	myprintf("%-3c %6c\n",c,b);
    //	printf("%-3c %6c\n",c,b);
    //	int a = 5, b = 16;
    //	int x = myprintf("%5.3d\n",a);
    //	int y = printf("%5.3d\n",a);
    //	myprintf("%d %d\n",x,y);
    return 0;
}
