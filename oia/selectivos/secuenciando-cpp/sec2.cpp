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
const ll MAXN=1005;

int medir(string cad);
map<string,ll>did;
ll ask(string s){
	if(did[s])return did[s]-1;
	did[s]=medir(s)+1;
	return did[s]-1;
}
ll n;
string res;
char c;
string merge(ll s, ll e, ll q){
	string l,r;
	fore(i,0,s)l.pb(res[i]);
	fore(i,e-1,SZ(res))r.pb(res[i]);
	string m(q,c);
	return l+m+r;
}
ll qan(ll s, ll e, ll q){
	ll l=1,r=q;
	while(l<=r){
		ll m=(l+r)/2;
		if(ask(merge(s,e,m)))l=m+1;
		else r=m-1;
	}
	return r;
}
vector<pair<ll,ll>>upd;
void f(ll s, ll e, ll q){
	//cout<<s<<" "<<e<<" "<<q<<" "<<c<<"\n";
	if(q==0)return;
	if(s+1==e){upd.pb({s,q});return;}
	ll m=(s+e)/2;
	ll a,b;
	a=qan(s,m,q);
	b=q-a;
	f(s,m,a);
	f(m,e,b);
}
string secuenciar(int N, string s){
	n=N;
	if(s=="AC"){
		ll l=1,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			string cad(m,s[0]);
			if(ask(cad))l=m+1;
			else r=m-1;
		}
		string a(r,s[0]),b(n-r,s[1]);
		return a+b;
	}
	vector<pair<ll,char>>oc;
	ll sum=0;
	for(auto i:s){
		ll q=0;
		c=i;
		if(c!=s[SZ(s)-1])q=qan(0,SZ(res)+1,n-sum);
		else q=n-sum;
		sum+=q;
		//cout<<q<<" "<<i<<"\n";
		oc.pb({q,i});
	}
	random_shuffle(ALL(oc));
	for(auto i:oc){
		//cout<<i.fst<<","<<i.snd<<"\n";
		c=i.snd;
		//cout<<c<<":\n";
		if(SZ(res)==n)break;
		ll q=i.fst;
		upd.clear();
		f(0,SZ(res)+1,q);
		ll d=0;
		//cout<<SZ(upd)<<":\n";
		sort(ALL(upd));
		for(auto j:upd){
			res=merge(j.fst+d,j.fst+d+1,j.snd);
			d+=j.snd;
			//cout<<i.fst<<" "<<i.snd<<"\n";
		}
		//cout<<res<<"\n";
	}
    return res;
}
