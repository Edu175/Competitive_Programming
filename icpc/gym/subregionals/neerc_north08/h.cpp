#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
    ifstream cin;   cin.open("holes.in", ios::in);
	ofstream cout; cout.open("holes.out", ios::out); 
    ll n; cin>>n;
    string r;
    if(n<=1){
        if(n==0)cout<<"1\n";
        if(n==1)cout<<"0\n";
    }
    else {
        if(n&1)cout<<"4";
        fore(i,0,n/2)cout<<"8";
        cout<<"\n";
    }
    return 0;
}
