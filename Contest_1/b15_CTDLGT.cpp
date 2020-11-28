#include<iostream>

using namespace std;

void next_Permutation(string &str){
    int n=str.size();
    int i=n-1;
    while((str[i]-'0')>=(str[i+1]-'0')) --i;
    if(i>=0){
         int j=n;
         while((str[i]-'0')>=(str[j]-'0')) --j;
         swap(str[i],str[j]);
         int s=i+1,k=n-1;
         while(s<k){
           swap(str[s],str[k]);
           s++;k--;
        }
    } else str="BIGGEST";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str="";
        cin>>str;
        next_Permutation(str);
        cout<<n<<" "<<str<<endl;
    }
    return 0;
}
