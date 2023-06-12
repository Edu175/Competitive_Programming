#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5;

vector<ll>divs[MAXN];
void divisores(){
	fore(i,1,MAXN)for(int j=i;j<MAXN;j+=i)divs[j].pb(i);
}
int main(){FIN;
	divisores();
	/*fore(i,1,MAXN){
		for(auto d:divs[i])assert(i%d==0&&d!=0);
	}*/
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		vector<ll> oc(26,0);
		for(auto i:s)oc[i-'a']++;
		ll res=1e9,x=-1;
		for(auto d:divs[n]){
			//assert(n%d==0);
			vector<ll>v=oc;
			sort(ALL(v)); reverse(ALL(v));
			ll resi=0;
			if(n/d>26)continue;
			fore(i,0,n/d)if(v[i]<d)resi+=d-v[i];
			if(resi<res)res=resi,x=d;
		}
		//cout<<res<<" "<<x<<"\n";
		vector<ll>roc(26,0),is(26,0),ch,vis(n,0);
		vector<pair<ll,ll>>v;
		fore(i,0,26)v.pb({oc[i],i});
		sort(ALL(v));reverse(ALL(v));
		fore(i,0,n/x)is[v[i].snd]=1,ch.pb(v[i].snd);
		/*for(auto i:ch)cout<<char('a'+i)<<" ";
		cout<<"\n";
		imp(is);*/
		ll j=0;
		string ans(n,'-');
		fore(i,0,n){
			ll c=s[i]-'a';
			//cout<<i<<","<<s[i]<<": "<<is[c]<<" "<<roc[c]<<" "<<x<<"\n";
			if(is[c]&&roc[c]<x){
				roc[c]++,ans[i]=char('a'+c),vis[i]=1;
			}
		}
		//cout<<"\n";
		fore(i,0,n){
			if(vis[i])continue;
			while(oc[ch[j]]>=x)j++;
			s[i]='a'+ch[j];
			oc[ch[j]]++;
			ans[i]='a'+ch[j];
		}
		cout<<res<<"\n"<<ans<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
