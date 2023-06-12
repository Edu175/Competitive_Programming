#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;

ll inf=1000000000;
ll n,k;
vector<ll> a(MAXN);
pair<ll,ll>srt[MAXN];
bool solve(ll x){
	vector<ll> ai(n);
	fore(i,0,n)ai[i]=a[i];
	ll ki=k;
	fore(i,0,k){
		if(2*srt[i].fst>=x)break;
		else ai[srt[i].snd]=inf,ki--;
	}
	if(k+1<=n&&2*srt[k].fst<x){
		return 0;
	}
	ll maxp=0,maxi=0;
	fore(i,0,n){
		maxi=max(maxi,ai[i]);
		if(i)maxp=max(maxp,min(ai[i],ai[i-1]));
	}
	//cout<<ki<<" "<<maxi<<" "<<maxp<<"\n";
	if(ki>=2)maxi=inf;
	if(ki>=1)return maxi>=x;
	else return maxp>=x;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		fore(i,0,n){
			cin>>a[i];
			srt[i].fst=a[i];
			srt[i].snd=i;
		}
		//cout<<"return";return 0;
		sort(srt,srt+n);
		//fore(i,0,n)cout<<srt[i].fst<<" ";
		//while(1){ll q; cin>>q; cout<<solve(psb[q])<<endl;}
		vector<ll> psb;
		fore(i,0,n)psb.pb(srt[i].fst), psb.pb(srt[i].fst*2);
		psb.pb(inf);
		sort(ALL(psb));
		ll l=0, r=SZ(psb)-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(solve(psb[m]))l=m+1;
			else r=m-1;
		}
		cout<<psb[r]<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
