#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());
const ll MAXV=2e5+5;
int cr[MAXV];
void cribonha(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
vv pot;
const ll B=100;
ll get(ll n){
	if(!n)return 0;
	ll p=rng()%n;
	return (rng()%(B-1)+1)*pot[p]+get(p);
}
int main(){FIN;
	cribonha();
	ll n,V; cin>>n>>V;
	cout<<n<<"\n";
	vector<ii> all;
	fore(i,1,V+1){
		ll fg=1;
		ll x=i;
		map<ll,ll>mp;
		while(x>1){
			ll p=(cr[x]==-1?x:cr[x]);
			fg&=(++mp[p])<=1;
			x/=p;
		}
		// cout<<i<<": ";
		// for(auto i:mp)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		if(fg)all.pb({SZ(mp),i});
	}
	pot.pb(1);
	while(pot.back()<SZ(all))pot.pb(pot.back()*B);
	ll len=SZ(pot);
	sort(ALL(all));
	reverse(ALL(all));
	vv ans;
	while(all.back().fst<=1)ans.pb(all.back().snd),all.pop_back();
	// for(auto i:all){
	// 	cerr<<i.fst<<","<<i.snd<<" ";
	// }cerr<<"\n";
	// imp(all)
	// vv nums;
	fore(i,0,n-SZ(ans)){
		ll p=get(len)%SZ(all);
		// ll p=rng()%SZ(all);
		// cerr<<len<<" "<<p<<" len p\n";
		ans.pb(all[p].snd);
		cerr<<all[p].fst<<" ";
	}
	cerr<<"\n";
	shuffle(ALL(ans),rng);
	imp(ans);
	return 0;
}
