#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(X) ((ll)X.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll MAXP=456976+100;
struct Trie{ // lowercase
	ll tr[MAXP][26],qidx=0;
	// ll cant[MAXP];
	Trie(){mset(tr,-1);}
	ll add(ll x, char c){
		auto &res=tr[x][c-'a'];
		if(res!=-1)return res;
		return res=++qidx;
	}
	void add_string(string s){
		ll x=0;
		for(auto i:s)x=add(x,i);
		// cant[x]++;
	}
};

ll n,m;
Trie ver,hor;
ll res=0;

vv col,row;

void f(ll i, ll j){
	if(j==m){f(i+1,0);return;}
	if(i==n){res++;return;}
	fore(c,0,26){
		ll pv=ver.tr[col[j]][c];
		ll ph=hor.tr[row[i]][c];
		if(pv!=-1&&ph!=-1){
			ll av=col[j];
			ll ah=row[i];
			col[j]=pv;
			row[i]=ph;
			
			f(i,j+1);
			
			col[j]=av;
			row[i]=ah;
		}
	}
}

int main(){
    JE
	ll a,b;
	cin>>n>>a;
	cin>>m>>b;
	auto doit=[&](ll q, Trie &t){
		fore(i,0,q){
			string s; cin>>s;
			t.add_string(s);
		}
	};
	doit(a,ver);
	doit(b,hor);
	
	col=vv(m);
	row=vv(n);
	
	f(0,0);
	
	cout<<res<<"\n";
    return 0;
}