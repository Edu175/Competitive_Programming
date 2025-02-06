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
const ll MAXN=5005*5005/2+5005;

ll tr[MAXN][2],qidx=0;
ii w[MAXN];
ll add(ll x, ll c){
	auto &res=tr[x][c];
	if(res!=-1)return res;
	return res=qidx++;
}

int main(){FIN;
	mset(tr,-1);
	ll t; cin>>t;
	while(t--){
		while(qidx>0)tr[qidx][0]=tr[qidx][1]=-1,qidx--;
		string s; cin>>s;
		ll n=SZ(s);
		fore(l,0,n){
			ll x=0;
			fore(i,0,l)x=add(x,0);
			fore(r,l,n){
				x=add(x,s[r]-'0');
				w[x]={l,r};
			}
		}
		cout<<"1 "<<n<<" ";
		ll x=0;
		fore(i,0,n){
			ll go=s[i]-'0';
			cout<<go<<" -> ";
			if(tr[x][go^1]!=-1)go^=1;
			ll y=tr[x][go];
			if(y==-1)break;
			cout<<go<<"\n";
			x=y;
		}
		cout<<w[x].fst+1<<" "<<w[x].snd+1<<"\n";
	}
	return 0;
}
