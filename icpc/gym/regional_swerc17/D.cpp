#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXL=52,MAXK=200,INF=1e18;

#define maxig(a,b) a=max(a,b)

struct vertex{
	int next[26],go[26];
	int p,link;
	ll gan,can;
	char pch;
	// vector<int> leaf;
	vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1),gan(0),can(0){
		mset(next,-1);
		mset(go,-1);
	}
};
vector<vertex> t;
void aho_init(){
	t.clear(); t.pb(vertex());
}
void add_string(string s, ll gan){
	int v=0;
	for(char c:s){
		c-='a';
		if(t[v].next[c]==-1){
			t[v].next[c]=SZ(t);
			t.pb(vertex(v,c));
		}
		v=t[v].next[c];
	}
	// t[v].leaf.pb(id)
	maxig(t[v].gan,gan);
	t[v].can=1;
}
int go(int v, char c);
int get_link(int v){
	if(t[v].link<0){
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	}
	return t[v].link;
}
int go(int v, char c){
	// auto _c=c; c-='a';
	if(t[v].go[c]==-1){
		if(t[v].next[c]!=-1)t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	}
	return t[v].go[c];
}

ll dp[MAXL][MAXL][MAXK*MAXL*2];

int main(){
    JET
	string s; cin>>s;
	aho_init();
	ll k; cin>>k;
	fore(i,0,k){
		string t; ll gan; cin>>t>>gan;
		add_string(t,gan);
		reverse(ALL(t));
		add_string(t,gan);
	}
	ll n=SZ(s);
	for(ll l=n;l>=0;l--)for(ll r=l;r<=n;r++)fore(x,0,SZ(t)){
		auto &res=dp[l][r][x];
		res=-INF;
		if(t[x].can)res=t[x].gan+dp[l][r][0];
		if(l==r){
			if(r==n||!x)maxig(res,0ll);
			continue;
		}
		ll prox=go(x,s[l]-'a');
		if(r<n)prox=t[x].next[s[l]-'a'];
		if(prox!=-1)maxig(res,dp[l+1][r][prox]); // lo uso
		fore(m,l+1,r)maxig(res,dp[l][m][0]+dp[m][r][x]);
		// if(res){
		// 	cout<<l<<","<<r<<" "<<x<<": "<<res<<"\n";
		// }
	}
	ll res=dp[0][n][0];
	cout<<res<<"\n";
    return 0;
}