#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5,MAXK=105;

ll p[MAXN];
ll a[MAXK][MAXK];
ll f(ll x, ll y, ll d){ //d>=30 --> res=0
	return a[p[x]][p[y]]/(1ll<<d);
}
int main(){FIN;
	ll n,k,q; cin>>n>>k>>q;
	map<string,ll>id;
	ll L[n],R[n];
	fore(i,0,n){
		string s; cin>>s;
		id[s]=i;
		ll x; cin>>x;
		p[i]=x; p[i]--;
		L[i]=i-1; R[i]=i+1;
	}
	R[n-1]=-1;
	fore(i,0,k)fore(j,0,k)cin>>a[i][j];
	while(q--){
		ll ty; cin>>ty; ty--;
		if(ty==0){ // x va a la izquierda de y
			string s,t; cin>>s>>t;
			ll x=id[s], y=id[t];
			if(x==y)continue;
			// saco x
			if(R[x]!=-1)L[R[x]]=L[x];
			if(L[x]!=-1)R[L[x]]=R[x];
			// pongo x
			L[x]=L[y],R[x]=y;
			if(L[y]!=-1)R[L[y]]=x;
			L[y]=x;
		}
		if(ty==1){
			string s; cin>>s;
			ll x=id[s]; cin>>p[x]; p[x]--;
		}
		if(ty==2){ //calcula valor para x
			string s; cin>>s;
			ll x=id[s];
			ll res=0;
			for(ll y=L[x],d=0;y!=-1&&d<30;y=L[y],d++)res+=f(x,y,d);
			for(ll y=R[x],d=0;y!=-1&&d<30;y=R[y],d++)res+=f(x,y,d);
			cout<<res<<"\n";
		}
	}
	return 0;
}
