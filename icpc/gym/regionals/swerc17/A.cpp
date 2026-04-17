#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;


int main(){
    JET
	ll n,m; cin>>n>>m;
	vv a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	vv all;
	fore(i,0,n)fore(j,0,m)all.pb(b[j]-a[i]);
	sort(ALL(all));
	ll res=0,wh=0;
	ll q=0;
	fore(i,0,SZ(all)){
		q++;
		if(i==SZ(all)-1||all[i]!=all[i+1]){
			if(all[i]>=0&&q>res)res=q,wh=all[i];
			q=0;
		}
	}
	// cerr<<res<<": ";
	cout<<wh<<"\n";
    return 0;
}