#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
// ASSUMING NO ZERO-LENGTH SEGMENTS

ll sum(pair<ii,ii>x){return x.fst.fst+x.fst.snd+x.snd.fst+x.snd.snd;}
bool leq(ii a, ii b){return a.fst<=b.fst&&a.snd<=b.snd;}
bool in(pair<ii,ii>a, ii b){
	if(leq(a.fst,b)&&leq(b,a.snd))return 1;
	if(leq(a.snd,b)&&leq(b,a.fst))return 1;
	return 0;
}
string cv(ii a){return to_string(a.fst)+","+to_string(a.snd);}
int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){FIN;
	ll n; cin>>n;
	vector<pair<ii,ii>>a(n);
	fore(i,0,n)cin>>a[i].fst.fst>>a[i].fst.snd>>a[i].snd.fst>>a[i].snd.snd;
	map<ii,set<ll>>mp;
	auto dir=[&](ll i){
		auto [p,q]=a[i];
		if(p.fst==q.fst)return 1;
		return 0;
	};
	auto dire=[&](pair<ii,ii> ai){
		auto [p,q]=ai;
		if(p.fst==q.fst)return 1;
		return 0;
	};
	fore(i,0,n)fore(j,i+1,n){
		auto [p0,q0]=a[i];
		auto [p1,q1]=a[j];
		vector<ii>v={p0,q0,p1,q1};
		if(dir(i)==dir(j)){
			ii p; ll flag=0;
			fore(j,0,2)fore(k,2,4)if(v[j]==v[k])p=v[j],flag=1;
			if(flag){
				ll b=sum(a[i])<=sum(a[j]);
				mp[p].insert(2*b+dir(i));
				mp[p].insert(2*(b^1)+dir(i));
			}
		}
		else {
			ll x,y;
			if(dir(i))x=p0.fst;
			else x=p0.snd;
			if(dir(j))y=p1.fst;
			else y=p1.snd;
			ll sw=0;
			if(!dir(i))sw=1,swap(x,y);
			ii p={x,y};
			if(in(a[i],p)&&in(a[j],p)){
				auto put=[&](ll i){
					set<ll> &st=mp[p];
					if(leq(a[i].fst,p)&&leq(a[i].snd,p))
						st.insert(2+dir(i));
					else if(leq(p,a[i].fst)&&leq(p,a[i].snd))
						st.insert(dir(i));
					else st.insert(dir(i)),st.insert(dir(i)+2);
				};
				put(i);
				put(j);
			}
		}
	}
//	for(auto i:mp){cout<<cv(i.fst)<<": "; imp(i.snd);}
	map<ii,ll>idx;
	ll cnt=0;
	for(auto [p,dfg]:mp)idx[p]=cnt++;
	vector<vector<ll>>g(cnt,vector<ll>(4,-1));
	vector<ii>tmp;
	fore(i,0,n)tmp.pb(a[i].fst),tmp.pb(a[i].snd);
	ll k=0; // sides
	vector<pair<ii,ii>>seg;
	for(auto p:tmp){
		fore(d,0,2){
			vector<ii>ps;
			for(auto [q,fdg]:mp){
				if(d?p.fst==q.fst:p.snd==q.snd)ps.pb(q);
			}
			sort(ALL(ps));
			fore(i,0,SZ(ps)-1){
				if(mp[ps[i]].count(d)){
					assert(mp[ps[i+1]].count(d+2));
					auto u=idx[ps[i]],v=idx[ps[i+1]];
					if(g[u][d]!=-1)continue;
					seg.pb({ps[i],ps[i+1]});
					g[u][d]=k;
					g[v][d+2]=k;
					k++;
				}
			}
		}
	}
	fore(i,0,k)cout<<i<<": "<<cv(seg[i].fst)<<" "<<cv(seg[i].snd)<<"\n";
	uf_init();
	vector<ii>ed;
	auto build=[&](){
		vector<vector<ll>>go(k);
		for(auto [u,v]:ed)go[u].pb(v),go[v].pb(u);
		vector<ll>v;
		fore(i,0,k)if(SZ(go[i])&1)v.pb(i);
//		assert(SZ(v)==0||SZ(v)==2);
		vector<ll>vis(k),p;
		for(ll x=SZ(v)?v[0]:0;x!=-1;){
			ll y=-1;
			vis[x]=1,p.pb(x);
			for(auto z:go[x])if(!vis[z])y=z;
			x=y;
		}
		vector<pair<ii,ii>>path;
		for(auto i:p)path.pb(seg[i]);
		fore(i,0,SZ(path)-1){
			vector<ii>v={path[i].fst,path[i].snd,path[i+1].fst,path[i+1].snd};
			fore(j,0,2)fore(k,2,4)if(v[j]==v[k]){
				if(!j)swap(path[i].fst,path[i].snd);
				if(k)swap(path[i+1].fst,path[i+1].snd);
				goto end;
			}
			end:;
		}
		vector<pair<ii,ii>>res;
//		for(auto i:ed)cout<<cv(i)<<" ";;cout<<"\n";
//		for(auto [u,v]:path){
//			cout<<cv(u)<<" "<<cv(v)<<"\n";
//		}
//		cout<<"end\n"<<endl;
		for(auto i:path){
			if(SZ(res)&&dire(res.back())==dire(i))res.back().snd=i.snd;
			else res.pb(i);
		}
		cout<<SZ(res)<<"\n";
		for(auto [u,v]:res){
			cout<<u.fst<<" "<<u.snd<<" "<<v.fst<<" "<<v.snd<<"\n";
		}
	};
	vector<ll>per;
	fore(i,0,cnt)per.pb(i);
	srand(175); random_shuffle(ALL(per));
	for(auto i:per){
		auto did=[&](ll x, ll y, ll _x, ll _y){
			x=g[i][x],y=g[i][y];
			_x=g[i][_x],_y=g[i][_y];
			if(x==-1||y==-1)return 0;
			ll all=_x!=-1&&_y!=-1;
			if(uf_find(x)!=uf_find(y)&&(!all||uf_find(_x)!=uf_find(_y))){
				uf_join(x,y),ed.pb({x,y});
				if(all)uf_join(_x,_y),ed.pb({_x,_y});
				return 1;
			}
			return 0;
		};
		cout<<i<<": ";imp(g[i]); build();
		if(did(0,2,1,3))continue;
		if(did(1,3,0,2))continue;
		
		if(did(0,1,2,3))continue;
		if(did(2,3,0,1))continue;
		
		if(did(0,3,1,2))continue;
		if(did(1,2,0,3))continue;
		assert(0);
	}
	set<ll>st;
	fore(i,0,k)st.insert(uf_find(i));
	if(SZ(st)>1){
		cout<<"0\n";
		return 0;
	}
	//reconstruir
	
	return 0;
}
