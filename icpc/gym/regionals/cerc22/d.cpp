#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int MAXN = 1e5+100;
ll w, res = 0;
ll ar[MAXN];
vv g[MAXN], v[MAXN];

void f(int x, int fat){
	for(auto y:g[x])if(y!=fat){
		f(y,x);
		// cout<<"cierro "<<y<<" y es "<<res<<"\n";
	}
	sort(ALL(v[x]));
	reverse(ALL(v[x]));
	ll acc = 0; 
	while(SZ(v[x])&& acc+v[x].back() <= w){
		acc+=v[x].back();
		v[x].pop_back();
	}	
	res+=SZ(v[x]);
	if(!x){
		res += (acc > 0);
		return ;
	}
	ll k = w-acc;
	if(ar[x] < k)v[fat].pb(acc+ar[x]);
	else{
		ll d = ar[x] - k;
		res ++;
		res+=d/w;
		v[fat].pb(d%w);
	}
}

int main(){
	JET
	stack<ll> st;
	cin>>w;
	st.push(0);
	ll i = 1;
	while(SZ(st)){
		g[st.top()].pb(i);
		st.pop();
		cin>>ar[i];
		ll h; cin>>h;
		fore(j,0,h) st.push(i);
		i++;
	}
	f(0,-1);
	cout<<res<<"\n";
	return 0;
}

