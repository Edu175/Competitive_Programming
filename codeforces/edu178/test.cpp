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
struct UnionFind {
	int n,comp;
	vector<int> uf,si,c;
	UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1){
		fore(i,0,n)uf[i]=i;}
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	bool join(int x, int y){
		if((x=find(x))==(y=find(y)))return false;
		if(si[x]<si[y])swap(x,y);
		si[x]+=si[y];uf[y]=x;comp--;c.pb(y);
		cout<<"push "<<y<<"\n";
		return true;
	}
	int snap(){return c.size();}
	void rollback(int snap){
		while(c.size()>snap){
			int x=c.back();c.pop_back();
			cout<<"pop "<<x<<"\n";
			si[uf[x]]-=si[x];uf[x]=x;comp++;
		}
	}
};
int main(){FIN;
	ll x=0,y=1,z=2,v=3;
	UnionFind dsu(8);
	dsu.join(x,4);
	dsu.join(x,5);
	dsu.join(x,6);
	dsu.join(y,7);
	dsu.join(v,y);
	int tim=dsu.snap();
	dsu.join(x,y);
	dsu.join(v,z);
	dsu.rollback(tim);
	cout<<dsu.uf[v]<<"\n";
	return 0;
}