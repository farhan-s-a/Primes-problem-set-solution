#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int binary_gcd(int a,int b){
    if(a==0) return b;
    if(b==0) return a;

    int shift=__builtin_ctz(a|b);
    a>>=__builtin_ctz(a);

    while(b){
        b>>=__builtin_ctz(b);
        if(a>b) swap(a,b);
        b-=a;
    }
    return a << shift;
}

int NOD(int n){
    int total=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(i*i==n) 
                total++;
            else 
                total+=2;
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m;

        cout << NOD(binary_gcd(n, m)) << "\n";
    }

    return 0;
}