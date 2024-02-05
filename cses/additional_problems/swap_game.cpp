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

string des="123456789";
vector<ii>mv;
ll bfs(string s){
	unordered_map<string,ll>d;
	unordered_map<string,ll>d2;
	queue<string>q;
	queue<string>q2;
	d[s]=0;
	d2[des]=0;
	q.push(s);
	q2.push(des);
	while(SZ(q)&&SZ(q2)){
		auto x=q.front(); q.pop();
		auto x2=q2.front(); q2.pop();
		if(d.count(x2))return d[x2]+d2[x2];
		if(d2.count(x))return d2[x]+d[x];
		for(auto [i,j]:mv){
			auto y=x;
			swap(y[i],y[j]);
			auto y2=x2;
			swap(y2[i],y2[j]);
			if(!d.count(y))d[y]=d[x]+1,q.push(y);
			if(!d2.count(y2))d2[y2]=d2[x2]+1,q2.push(y2);
			//if(y==des)return d[y];
		}
	}
	assert(0);
	//cout<<SZ(d)<<"\n";
	return d[des];
}

int main(){FIN;
	fore(i,0,9){
		if(i/3)mv.pb({i,i-3});
		if(i%3)mv.pb({i,i-1});
	}
	string s;
	fore(i,0,9){
		char c; cin>>c;
		s.pb(c);
	}
	cout<<bfs(s)<<"\n";
	return 0;
}
