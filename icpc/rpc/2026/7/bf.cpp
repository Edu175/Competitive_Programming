#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll n;
vector<vv> fa;
vector<char> col;

string alp;

string s;

void check(){
	vector<string> all(n);
	fore(i,0,n)all[i]=s.substr(2*i,2);
	fore(i,0,n){
		if(all[i][0]!=col[i])return;
		if(all[i][0]>all[i][1])return;
		if(fa[i][0]==-1)continue;
		set<string> cand;
		fore(w0,0,2)fore(w1,0,2){
			string cur;
			cur.pb(all[fa[i][0]][w0]);
			cur.pb(all[fa[i][1]][w1]);
			sort(ALL(cur));
			cand.insert(cur);
		}
		if(!cand.count(all[i]))return;
	}
	fore(i,0,n)cout<<all[i]<<"\n";
	exit(0);
}

void f(){
	ll pos=SZ(s);
	if(pos==2*n){
		check();
		return;
	}
	ll i=pos/2,j=pos%2;
	auto cand=alp;
	if(!j)cand={col[i]};
	for(auto c:cand)if(c>=col[i]){
		s.pb(c);
		f();
		s.pop_back();
	}
}

int main(){FIN;
	cin>>n;
	fa=vector<vv>(n,vv(2));
	col=vector<char>(n);
	fore(i,0,n){
		cin>>fa[i][0]>>fa[i][1]>>col[i];
		fore(j,0,2)fa[i][j]--;
		alp.pb(col[i]);
	}
	sort(ALL(alp));
	alp.resize(unique(ALL(alp))-alp.begin());
	f();
	cout<<"-1\n";
	return 0;
}
