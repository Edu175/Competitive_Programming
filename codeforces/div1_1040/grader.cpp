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

bool isrbs(string s){
	ll c=0;
	for(auto i:s){
		if(i==')')c--;
		else c++;
		if(c<0)return 0;
	}
	return c==0;
}

ll cont(string s){
	ll n=SZ(s);
	ll res=0;
	fore(l,0,n)fore(r,l+1,n+1){
		string t;
		fore(i,l,r)t.pb(s[i]);
		if(isrbs(t)){
			cerr<<l<<","<<r<<"\n";
			res++;
		}
	}
	return res;
}

int main(){FIN;
	
	ifstream pre;   pre.open("pre", ios::in);
	
	ll n; pre>>n;
	string s; pre>>s;
	
	cout<<"1\n";
	cout<<n<<endl;
	ll cnt=0;
	while(1){
		if(++cnt>200){
			cerr<<" muchas queries\n";
			break;
		}
		char ty; cin>>ty;
		if(ty=='!'){
			string a; cin>>a;
			cerr<<"output: "<<a<<"\n";
			if(a!=s)cerr<<"WA\n";
			else cerr<<"AC\n";
			break;
		}
		ll k; cin>>k;
		vv ind(k);
		fore(i,0,k)cin>>ind[i],ind[i]--;
		string tmp;
		for(auto i:ind)tmp.pb(s[i]);
		cerr<<"asked ";
		for(auto i:ind)cerr<<i<<" ";
		cerr<<": "<<tmp<<":\n";
		ll c=cont(tmp);
		cerr<<"= "<<c<<"\n\n\n";
		cout<<c<<endl;
	}
	
	return 0;
}
