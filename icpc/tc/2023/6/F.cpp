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

ll ops[5][3][3]={
	{
		{0,0,0},
		{0,1,1},
		{0,1,2}
	},
	{
		{0,1,2},
		{1,1,2},
		{2,2,2}
	},
	{
		{2,2,2},
		{1,2,2},
		{0,1,2}
	},
	{
		{2,1,0},
		{2,2,1},
		{2,2,2}
	},
	{
		{2,0,0},
		{0,2,0},
		{0,0,2}
	}
};
typedef array<ll,9> elem;

ll vis[3][3][3][3][3][3][3][3][3];

ll* get(elem &a){
	return &vis[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]][a[8]];
}

elem oper(elem &a, elem &b, ll ty){
	elem c;
	fore(i,0,9)c[i]=ops[ty][a[i]][b[i]];
	return c;
}

int main(){FIN;
	vector<elem> all;
	all.pb({0,0,0,1,1,1,2,2,2});
	queue<elem> q;
	elem s={0,1,2,0,1,2,0,1,2};
	q.push(s);
	*get(s)=1;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto &y:all)fore(ty,0,5){
			auto z=oper(x,y,ty);
			auto ptr=get(z);
			if(*ptr)continue;
			*ptr=1;
			q.push(z);
		}
		all.pb(x);
	}
	// cout<<SZ(all)<<" sz\n";
	ll t; cin>>t;
	while(t--){
		string alp="FUT";
		elem a;
		fore(i,0,9){
			char c; cin>>c;
			a[i]=alp.find(c);
		}
		auto ptr=get(a);
		if(!(*ptr))cout<<"un";
		cout<<"definable\n";
	}
	return 0;
}
