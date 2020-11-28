#include<iostream>

using namespace std;
char x[16];
int stop; // chi so xem so luong chu so 
long long int res;// ghi ket qua
int n; 
int final_end;

// khoi tao mang voi 0
void init(){
    for(int i=0;i<16;++i){
        x[i]='0';
    }
}
// sinh ke tiep cua 0 va 1
void next_Gen(){
    int i=15;
    while(i>=0&&x[i]-'0'==1){
        x[i]='0';
        --i;
    }
    if(i>=0) x[i]='1';
    else final_end=1;
}
// chuyen doi tu mang sang xau,
// roi chuyen xau ve long long int
void convertToLongInt(){
    string str="";
    for(int i=0;i<16;++i){ // vong lap loai bo so 0 thua dang truoc
        // den khi gap so 1 thi dung
        if(x[i]-'0'==1) {
            stop=i;
            break;
        }
    }
    // dua cac mang vao thanh 1 xau 
    for(int i=stop;i<16;++i){
        str+=x[i];
    } 
    // chuyen tu xau ve long long int
    // res=stoll(str);
    res=0;
    for(int i=0;i<str.length();++i){
        res=res*10+(str[i]-'0');
    }
}

// kiem tra res co chia het cho n khong
bool check_Div(){
    res=res*9; // tu 0 va 1 dua ve 0 va 9
    if(res%n==0) return true;
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        res=-1;
        final_end=0;
        init();
        while(final_end==0){
            next_Gen();
            convertToLongInt();
            if(check_Div()) break;
        }
        cout<<res<<endl;
    }
    return 0;
}