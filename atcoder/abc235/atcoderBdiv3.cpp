#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
int main(){FIN;
	ll n;cin>>n;ll h[n];
	fore(i,0,n)cin>>h[i];
	ll res;
	fore(i,0,n){
		res=h[i];
		if(i+1==n){
			break;
		}
		if(h[i]>=h[i+1]){
			break;
		}
	}
	cout<<res;
	return 0;
}
