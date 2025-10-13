#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

map<string,ii> dict;
vector<string> cand;
vector<string> frase;
set<string> superset;
vector<pair<string,ii>> v;

void search(vector<string>& q, int k){
	ll m = SZ(frase);
	string obj[k];
	fore(i,0,k) obj[i] = q[SZ(q) - 1 - i];
	reverse(obj,obj+k);
	// cout<<"mi obj es ";
	// for(auto x:obj) cout<<x<<" ";
	// cout<<"\n";
	fore(i,k,m){
		bool b = true;
		fore(j,0,k){
			if(frase[i-k+j] != obj[j]){
				b = false;
				// cout<<"la posicion "<<i<<" ("<<frase[i]<<") pincho  por la pos "<<i-k+j<<" ("<<frase[i-k+j]<<")\n";
				break;
			}
		}
		if(b) cand.pb(frase[i]);
	}
}

ii suma(ii a, ii b){
	return {a.fst+b.fst,a.snd+b.snd};
}

ii calc(){
	ii res = {0,0};
	for(auto x:cand)if(dict.count(x)) res = suma(res,dict[x]);
	return res;
}

const ll inf = 1e17;
string final(ii c){
	ll ss = -inf;
	string r = "";
	for(auto [s,xy] : v){
		ll loc = xy.fst * c.fst + xy.snd * c.snd;
		if(loc > ss){
			ss = loc;
			r = s;
		}
	}
	return r;
}

int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n){
		string s; cin>>s;
		ll x,y; cin>>x>>y;
		dict[s] = {x,y};
		v.pb({s,{x,y}});
	}
	ll m; cin>>m;
	fore(i,0,m){
		string s; cin>>s;
		frase.pb(s); 
		if(i!=m-1)superset.insert(s);	
	}
	ll q,K; cin>>q>>K;
	while(q--){
		ll x; cin>>x;
		vector<string> query(x);
		fore(i,0,x) cin>>query[i];
		if(!superset.count(query[x-1])){
			for(auto x:query) cout<<x<<" ";
			cout<<"*\n";
			continue;
		}
		ll k = K;
		cand.clear();
		while(!SZ(cand)){
			search(query,k);
			k --;
		}
		assert(k>=0);
		// cout<<"CANDIDATOS: "<<k<<"\n";
		// for(auto x:cand) cout<<x<<" ";
		// cout<<"\n";
		ii mul = calc();
		// cout<<"mi multi es "<<mul.fst<<" "<<mul.snd<<"\n";
		string rta = final(mul);
		for(auto x:query) cout<<x<<" ";
		cout<<rta<<"\n";
	}
	return 0;
}