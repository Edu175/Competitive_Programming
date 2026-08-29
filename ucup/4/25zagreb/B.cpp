#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define dbg(x) {cerr<<#x<<": ";for(auto y:x)cout<<y%3000<<" ";cout<<"\n";}
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e16;

int main(){
	JET
	ll n; cin>>n;
	vv a(n+2); vector<char> dir(n+2);
	fore(i,1,n+1)cin>>a[i]>>dir[i];
	a[0]=a.back()=INF;
	auto _a=a;
	n=SZ(a);
	dir[0]='R';
	dir[n-1]='L';
	vv fa(n,-1);
	queue<ii> qu;
	vv L(n),R(n);
	fore(i,0,n)L[i]=i-1,R[i]=i+1;
	vv in(n,1);
	auto out=[&](ll p){
		in[p]=0;
		if(L[p]!=-1)R[L[p]]=R[p];
		if(R[p]!=n)L[R[p]]=L[p];
	};
	auto agr_if=[&](ll p){
		assert(in[p]);
		char ty=dir[p];
		ll t=ty=='L'?L[p]:R[p];
		if(t==-1||t==n||dir[t]!=(ty^'L'^'R'))return;
		if(p>t)swap(p,t);
		qu.push({p,t});
	};
	fore(i,0,n)agr_if(i);
	vv mn(n),mx(n);
	fore(i,0,n)mn[i]=mx[i]=i;
	while(SZ(qu)){
		auto [i,j]=qu.front(); qu.pop();
		if(!in[i]||!in[j])continue;
		// dbg(a)
		// cerr<<"par "<<i<<","<<j<<"\n";
		if(a[j]>a[i])swap(i,j);
		fa[j]=i; a[i]+=a[j];
		mn[i]=min(mn[i],mn[j]);
		mx[i]=max(mx[i],mx[j]);
		out(j);
		agr_if(i);
	}
	// dbg(fa)
	// dbg(mn)
	// dbg(mx)
	vv sp(n+1);
	fore(i,0,n)sp[i+1]=sp[i]+_a[i];
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r; r++;
		ll x=l-1,y=r;
		ll m=-1;
		while(x!=y){
			if(a[x]<a[y]){
				ll fx=fa[x];
				if(fx>=r)m=mx[x]+1;
				x=fx;
			}
			else {
				ll fy=fa[y];
				if(fy<l)m=mn[y];
				y=fy;
			}
		}
		// cerr<<"m "<<m<<"\n";
		cout<<sp[m]-sp[l]<<" "<<sp[r]-sp[m]<<"\n";
	}
	return 0;
}