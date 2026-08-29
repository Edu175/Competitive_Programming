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

set<string> st;
void bfs(string s){
	st.insert(s);
	queue<string> q;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		fore(l,0,SZ(x)-1)if(x[l]=='1')fore(r,l+1,SZ(x))if(x[r]=='0'){
			auto t=x;
			fore(i,l,r+1)t[i]^=1;
			if(!st.count(t)){
				st.insert(t);
				q.push(t);
			}
		}
	}
	vector<string> out;
	for(auto x:st)if(x[0]=='1'||x.back()=='0')out.pb(x);
	for(auto x:out)st.erase(x);
	cout<<SZ(st)<<":\n";
	for(auto s:st){
		cout<<s<<"\n";
	}
}

int main(){FIN;
	string s; cin>>s;
	bfs(s);
	return 0;
}
