#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        if(n==1 && x==0){
            cout << -1 << endl;
        }
        else{
            int num=n, ans=x;
            int temp=1;
            while(temp<=x && num){
                if(x & temp){
                    num--;
                }
                temp <<= 1;
            }
            temp=1;
            while(num){
                if(num%2==1) num++;
                int a=(x&temp)?(n-1):n;
                                    //cout << "a: " << a << endl;
                if(a%2==1) a--;
                if(a==0){
                    temp <<= 1;
                    continue;
                }
                                    //cout << "num: " << num << endl; 
                a=min(a,num);
                                    //cout << "a: " << a << endl; 
                num-=a;
                ans+=a*temp;
                temp <<= 1;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
