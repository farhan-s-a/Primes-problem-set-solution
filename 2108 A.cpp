#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt=n/2;
        int ans=0;
        int i=n-1;
        while(cnt--){
            ans+=i;
            i-=2;
        }
        cout << ans+1 << endl;
    }
    return 0;
}