#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e8,R=sqrt(MAXN);

bitset<MAXN>cr;
void init_sieve(){
	fore(i,2,MAXN)if(!cr[i])for(ll j=1ll*i*i;j<MAXN;j+=i)cr[j]=1;
	cr[0]=1,cr[1]=1;
}

vector<bitset<R+1>> g(R+1);

vector<ll>a,p;
vector<vector<ll>>res;
const ll sz=5;

void f(ll s){
	if(SZ(p)>=sz){res.pb(p);return;}
	//cout<<s<<": "; imp(p);
	fore(i,s,SZ(a)){
		ll v=a[i];
		ll flag=1;
		for(auto u:p)if(!g[u][v]||!g[v][u])flag=0;
		//if(s==4&&v==7)cout<<flag<<"!!!!!\n";
		if(flag){
			p.pb(v);
			f(i+1);
			p.pop_back();
		}
	}
}

int main(){FIN;
	init_sieve();
	ll m=0;
	fore(x,0,MAXN)if(!cr[x]){
		string s=to_string(x);
		//if(x==37)cout<<"!!!!! "<<x<<" "<<s<<"\n";
		fore(e,1,SZ(s)){
			/*if(x==37){
				cout<<x<<" "<<e<<"\n";
			}*/
			string l,r;
			fore(i,0,SZ(s)){
				if(i<e)l.pb(s[i]);
				else r.pb(s[i]);
			}
			if(r[0]=='0')continue;
			ll a=stoll(l),b=stoll(r);
			/*if(x==37){
				cout<<x<<" "<<e<<": "<<l<<" "<<r<<": "<<a<<" "<<b<<"\n";
			}*/
			if(a<=R&&b<=R&&a!=b&&!cr[a]&&!cr[b]){
				g[a][b]=1;
				m++;
			}
		}
	}
	fore(i,0,R+1)if(g[i].count()>=sz-1)a.pb(i);
	cout<<m<<" "<<SZ(a)<<endl;
	//vector<ll>dbg={3,7,109,673};
	/*for(auto x:dbg){
		cout<<x<<": ";
		imp(g[x]);
	}*/
	/*for(auto i:dbg)for(auto j:dbg)if(i!=j){
		cout<<i<<" "<<j<<": "<<g[i].count(j)<<"\n";
	}*/
	//imp(a);
	f(0);
	//imp(res);
	cout<<SZ(res)<<"\n";
	vector<pair<ll,vector<ll>>>ans;
	for(auto i:res){
		ll s=0;
		for(auto j:i)s+=j;
		ans.pb({s,i});
	}
	sort(ALL(ans));
	if(SZ(ans)){
		cout<<ans[0].fst<<": ";
		imp(ans[0].snd);
	}
	return 0;
}
