#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto edu:v)cout<<edu<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll MOD;
ll n,res=0;
vv a;

void check(){
	vv A=a,B; A.resize(n);
	fore(i,0,n)B.pb(a[i+n]);
	vv id(n); iota(ALL(id),0);
	fore(mk,0,1ll<<n){
		vv sa(n);
		fore(i,0,n)sa[i]=(mk>>i&1?B:A)[i];
		sort(ALL(sa));
		if(sa==id){
			res++;
			// print if dbging
			// imp(A)
			// imp(B)
			// cout<<"\n";
			return;
		}
	}
}

void f(){
	if(SZ(a)==2*n){check();return;}
	fore(i,SZ(a)>=n?a[SZ(a)-n]+1:0,n){
		a.pb(i);
		f();
		a.pop_back();
	}
}

int main(){FIN;
	cin>>n>>MOD;
	f();
	fore(i,0,n)res=res*2;
	cout<<res<<"\n";
	return 0;
}
