#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
 
ll jere = 0;
void newcase(){cout<<"Case #"<<++jere<<": ";}

typedef int tw; tw INF=1ll<<30;
struct edge{int u,v,id;tw len;};
struct ChuLiu{
	int n; vector<edge> e;
	vector<int> inc,dec,take,pre,num,id,vis;
	vector<tw> inw;
	void add_edge(int x, int y, tw w){
		inc.pb(0); dec.pb(0); take.pb(0);
		e.pb((edge){x,y,SZ(e),w});
	}
	ChuLiu(int n):n(n),pre(n),num(n),id(n),vis(n),inw(n){}
	tw doit(int root){
		auto e2=e;
		tw ans=0; int eg=SZ(e)-1,pos=SZ(e)-1;
		while(1){
			fore(i,0,n) inw[i]=INF,id[i]=vis[i]=-1;
			for(auto ed:e2) if(ed.len<inw[ed.v]){
				inw[ed.v]=ed.len; pre[ed.v]=ed.u;
				num[ed.v]=ed.id;
			}
			inw[root]=0;
			fore(i,0,n) if(inw[i]==INF) return -1;
			int tot=-1;
			fore(i,0,n){
				ans+=inw[i];
				if(i!=root)take[num[i]]++;
				int j=i;
				while(vis[j]!=i&&j!=root&&id[j]<0)vis[j]=i,j=pre[j];
				if(j!=root&&id[j]<0){
					id[j]=++tot;
					for(int k=pre[j];k!=j;k=pre[k]) id[k]=tot;
				}
			}
			if(tot<0)break;
			fore(i,0,n) if(id[i]<0)id[i]=++tot;
			n=tot+1; int j=0;
			fore(i,0,SZ(e2)){
				int v=e2[i].v;
				e2[j].v=id[e2[i].v];
				e2[j].u=id[e2[i].u];
				if(e2[j].v!=e2[j].u){
					e2[j].len=e2[i].len-inw[v];
					inc.pb(e2[i].id);
					dec.pb(num[v]);
					take.pb(0);
					e2[j++].id=++pos;
				}
			}
			e2.resize(j);
			root=id[root];
		}
		while(pos>eg){
			if(take[pos]>0) take[inc[pos]]++, take[dec[pos]]--;
			pos--;
		}
		return ans;
	}
};

int main(){
    JET
    ll t; cin>>t;
    while(t--){
        ll n,m; cin>>n>>m;
        newcase();
        ChuLiu ch(n);
        fore(i,0,m){
            ll x,y,w; cin>>x>>y>>w;
            ch.add_edge(x,y,w);
        }
        ll rta = ch.doit(0);
        cout<<(rta >= 0  ? to_string(rta):"Possums!")<<"\n";
    }
    return 0;
}
