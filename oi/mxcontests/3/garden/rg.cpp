#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,hgfmdg=b;i<hgfmdg;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sldhg:v)cout<<sldhg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll N,M,Q,K; cin>>N>>K;
	ll n=rng()%(N-1)+2;
	set<ii>st;
	fore(i,0,n){
		ll j=rng()%(n-1);
		if(j>=i)j++;
		ll u=i,v=j;
		if(u>v)swap(u,v);
		st.insert({u,v});
	}
	ll m=rng()%(n*(n-1)/2+1-SZ(st));
	vector<ii>all;
	fore(i,0,n)fore(j,i+1,n)if(!st.count({i,j}))all.pb({i,j});
	shuffle(ALL(all),rng);
	fore(i,0,m)st.insert(all[i]);
	vector<ii>ed;
	for(auto i:st)ed.pb(i);
	shuffle(ALL(ed),rng);
	cout<<n<<" "<<SZ(ed)<<" "<<rng()%n<<"\n";
	for(auto i:ed)cout<<i.fst<<" "<<i.snd<<"\n";
	cout<<"1\n";
	cout<<rng()%K+1<<"\n";
	cout<<"0\n";
	return 0;
}