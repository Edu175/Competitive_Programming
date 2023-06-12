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
const ll MAXN=2e4+5;
ll q=0;
map<pair<ll,ll>,ll> did;
ll ask(ll i, ll j){
	//ll &ret=did[{i,j}];
	//if(ret>0)return ret;
	ll ret;
	i++,j++,q++;
	cout<<"? "<<i<<" "<<j<<endl;
	cin>>ret;
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		//did.clear();
		q=0;
		ll ans;
		/*if(n==2){
			cout<<"! 1 2"<<endl;
			cin>>ans;
			continue;
		}*/
		vector<ll>v;
		fore(i,0,n)v.pb(i);
		ll c=1;
		while(SZ(v)>2){
			//cout<<c<<": ";
			//imp(v);
			set<ll>p;
			ll a=ask(v[0],v[1]),b=ask(v[1],v[2]);
			if((a%(1ll<<c))==0)p.insert(v[0]),p.insert(v[1]);
			if((b%(1ll<<c))==0)p.insert(v[2]),p.insert(v[1]);
			if((a%(1ll<<c))&&(b%(1ll<<c))){
				//cout<<"none ";
				if(ask(v[0],v[2])%(1ll<<c))p.insert(v[1]);//,cout<<"medio\n";
				else p.insert(v[0]),p.insert(v[2]);//,cout<<"bordes\n";
			}
			ll x=*(p.begin());
			fore(i,3,SZ(v))if((ask(x,v[i])%(1ll<<c))==0)p.insert(v[i]);
			v.clear();
			for(auto i:p)v.pb(i);
			c++;
		}
		assert(q<=2*n);
		cout<<"! "<<v[0]+1<<" "<<v[1]+1<<endl;
		cin>>ans;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
