#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXV=1e6+5;
ll L[MAXV],R[MAXV];

ll ini=MAXV-1,fin=MAXV-2;

void add(ll x, ll y){ // x - y, x is the new one
	R[L[y]]=x;
	L[x]=L[y];
	R[x]=y;
	L[y]=x;
}

void remove(ll x){
	R[L[x]]=R[x];
	L[R[x]]=L[x];
	L[x]=-1;
}

int main(){
	JET
	mset(L,-1);
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	R[ini]=fin; L[fin]=ini;
	fore(i,0,n)add(a[i],fin);
	ll q; cin>>q;
	while(q--){
		char ty; cin>>ty;
		if(ty=='-'){
			ll x; cin>>x;
			remove(x);
		}
		if(ty=='+'){
			ll x,y; cin>>x>>y;
			add(x,y);
		}
		if(ty=='?'){
			R[L[fin]]=R[ini];
			L[R[ini]]=L[fin];
			// circular ^
			ll n; cin>>n;
			vv a(n);
			fore(i,0,n)cin>>a[i];
			// set<ll>st;
			// cout<<"\nask\n";
			// for(ll i=R[ini];!st.count(i);i=R[i])cout<<i<<" ",st.insert(i);
			// cout<<"\n";
			// for(auto i:a)cout<<i<<" ";;cout<<"\n";
			ll res=0,cur=0,ant=-1;
			fore(i,0,2*n+5){
				ll x=a[i%n];
				if(L[x]==-1){
					res=max(res,cur),cur=0,ant=-1;
					continue;
				}
				if(L[x]==ant)cur++;
				else res=max(res,cur),cur=1;
				ant=x;
			}
			res=max(res,cur);
			// cerr<<res<<": ";
			if(res>=n+3)cout<<"*\n";
			else cout<<res<<"\n";
			L[R[ini]]=ini;
			R[L[fin]]=fin;
		}
	}
	return 0;
}