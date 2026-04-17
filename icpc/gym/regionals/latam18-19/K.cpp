#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const int K=18;
bool vis[1<<K];
vector<vv> rta;
vv rec;
void BT(ll n, vv &v){
	if(!n){
		if(!v[0])rta.pb(rec);
		return;
	}
	ll x=v.back()-v[SZ(v)-2];
	fore(i,0,1<<n) vis[i]=0;
	int j=0; bool f=true; vv aux;
	int N=1<<n;
	fore(i,0,N)if(!vis[i]){
		while(j<=i||(j<N&&(v[j]<v[i]+x||vis[j]))) j++;
		if(j==N||v[j]!=v[i]+x){f=false; break;}
		aux.pb(v[i]);
		vis[j]=1;vis[i]=1;
	}
	if(f){
		rec.pb(x);
		BT(n-1,aux);
		rec.pop_back();
	}
	aux.clear();
	
	if(!x) return;
	x=-x;
	
	j=N-1;f=true;
	fore(i,0,N) vis[i]=0;
	for(int i=N-1; i>=0; i--)if(!vis[i]){
		while(j>=0&&(v[j]>v[i]+x||vis[j])) j--;
		if(j<0||v[j]!=v[i]+x){f=false; break;}
		aux.pb(v[i]);
		vis[j]=1;vis[i]=1;
	}
	if(f){
		reverse(ALL(aux));
		rec.pb(x);
		BT(n-1,aux);
		rec.pop_back();
	}
}
int main(){
	JET
	ll n; cin>>n;
	vv s(1<<n);
	fore(i,0,1<<n) cin>>s[i];
	sort(ALL(s));
	BT(n,s);
	set<vv> S;
	for(auto v:rta){
		sort(ALL(v));
		// if(S.count(v)) continue;
		S.insert(v);
		// for(auto x:v) cout<<x<<" ";;cout<<"\n";
	}
	for(auto v:S){
		for(auto x:v) cout<<x<<" ";
		cout<<"\n";
	}
	return 0;
	
}