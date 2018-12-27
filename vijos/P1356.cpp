/*
这种题目就是比谁会写代码？
然后看到一个写的挺好的代码~
直接抄了Orz
*/
#include <iostream>
using namespace std;
bool flag;
void print(string s){
    while(s.length()!=3)s=" "+s;
    char c=s[0];
    //cout<<c<<endl;
    switch(c){
        case'1':cout<<"one";break;
        case'2':cout<<"two";break;
        case'3':cout<<"three";break;
        case'4':cout<<"four";break;
        case'5':cout<<"five";break;
        case'6':cout<<"six";break;
        case'7':cout<<"seven";break;
        case'8':cout<<"eight";break;
        case'9':cout<<"nine";break;
    }
    if(c>'0')cout<<" hundred ";
    if((s[1]>'0'||s[2]>'0')&&c>'0'||flag&&c=='0')cout<<"and ";
    flag=0;
    c=s[1];
    switch(c){
        case'2':cout<<"twenty";break;
        case'3':cout<<"thirty";break;
        case'4':cout<<"forty";break;
        case'5':cout<<"fifty";break;
        case'6':cout<<"sixty";break;
        case'7':cout<<"seventy";break;
        case'8':cout<<"eighty";break;
        case'9':cout<<"ninety";break;
        case'1':
            switch(s[2]){
                case'0':cout<<"ten";break;
                case'1':cout<<"eleven";break;
                case'2':cout<<"twelve";break;
                case'3':cout<<"thirteen";break;
                case'4':cout<<"fourteen";break;
                case'5':cout<<"fifteen";break;
                case'6':cout<<"sixteen";break;
                case'7':cout<<"seventeen";break;
                case'8':cout<<"eighteen";break;
                case'9':cout<<"nineteen";break;
                }
    }
    if(c>'1'&&s[2]!='0')cout<<'-';else
    if(c=='1')
    return;
    c=s[2];
    switch(c){
        case'1':cout<<"one";break;
        case'2':cout<<"two";break;
        case'3':cout<<"three";break;
        case'4':cout<<"four";break;
        case'5':cout<<"five";break;
        case'6':cout<<"six";break;
        case'7':cout<<"seven";break;
        case'8':cout<<"eight";break;
        case'9':cout<<"nine";break;
    }
}
int main(){
    string s,t="";
    cin>>s;
    if(s=="0"){
        cout<<"zero"<<endl;
        return 0;
    }
    string a[5];
    int n=s.length()+2;
    n/=3;
    int p=n;
    for(int i=s.length()-1;i>=0;i--){
        t=s[i]+t;
        //cout<<t<<endl;
        if(t.length()==3){
            a[p--]=t;
            //cout<<p+1<<' '<<t<<endl;
            t="";
        }
    }
    if(t.length()>0)
    a[1]=t;
    for(int i=1;i<=n;i++){
        //cout<<a[i]<<endl;
        if(a[i]=="000"){
            continue;
        }
        print(a[i]);
        //if(a[i].length()==3)
        flag=1;
        //cout<<n<<endl;
        switch(n){
            case 1:
                cout<<endl;
                return 0;
            case 2:
                if(i==1)
                cout<<" thousand ";else{
                    cout<<endl;
                    return 0;
                }
                break;
            case 3:
                switch(i){
                    case 1:
                        cout<<" million ";break;
                    case 2:
                        cout<<" thousand ";break;
                    case 3:
                        cout<<endl;
                        return 0;
                }break;
            case 4:
                switch(i){
                    case 1:
                        cout<<" billion ";break;
                    case 2:
                        cout<<" million ";break;
                    case 3:
                        cout<<" thousand ";break;
                    case 4:
                        cout<<endl;
                        return 0;
                }
        }
    }
}