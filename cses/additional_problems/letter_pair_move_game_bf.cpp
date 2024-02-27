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
const ll INF=1e4;

map<string,string> pa;
string bfs(string s){
	queue<string>q;
	q.push(s);
	pa[s]="END";
	while(SZ(q)){
		auto a=q.front(); q.pop();
		ll B=0,fl=1,p=-1;
		fore(i,0,SZ(a)){
			if(a[i]=='B')B=1;
			if(a[i]=='A'&&B)fl=0;
			if(a[i]=='.'&&p==-1)p=i;
		}
		if(fl)return a;
		fore(i,0,SZ(a)-1)if(a[i]!='.'&&a[i+1]!='.'){
			s=a;
			swap(s[i],s[p]);
			swap(s[i+1],s[p+1]);
			if(pa.count(s))continue;
			pa[s]=a;
			q.push(s);
		}
	}
	return "NO";
}
vector<string> bf(string s){
	pa.clear();
	string a=bfs(s);
	if(a=="NO"){
		cout<<"-1\n";
		exit(0);
	}
	vector<string>res;
	while(a!="END")res.pb(a),a=pa[a];
	res.pop_back();
	reverse(ALL(res));
	return res;
}
int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	auto res=bf(s);
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i<<"\n";
	return 0;
}
