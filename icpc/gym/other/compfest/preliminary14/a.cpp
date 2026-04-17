#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(v,a) memset((v),(a),sizeof(v))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
	ll n,d; cin>>n>>d;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	// reverse(ALL(a));
    
	ll res=0,l=0,r=n-1;
	while(l<=r){
		ll val=a[r--];
		ll tot=val;
		while(l<=r&&tot<=d)tot+=val,l++;
		if(tot>d)res++;
	}
	cout<<res<<"\n";
	return 0;
}