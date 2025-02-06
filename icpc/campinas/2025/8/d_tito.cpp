#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=INT_MAX;
const ll MAXN=2e5+2;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
unordered_map<LL,ll> m;
unordered_map<ll,ll> LR;
unordered_map<ll,ll> AB;
unordered_map<ll,ll> RL;
unordered_map<ll,ll> BA;
set<ll> g[MAXN];
vv p;
ll pos[MAXN];
bitset<MAXN> vis,cer;
vector<pair<ii,ll>> rec;
ll n;
void dfs(ll i, ll ant){
    vis[i]=1;
    pos[i]=SZ(p);
    p.pb(i);
    //cout<<"visitamos "<<i<<" "<<(i<n?RL[i]:BA[i])<<" desde /"<<ant<<" "<<(ant<n?RL[ant]:BA[ant])<<endl;
	for(ll j: g[i]){
        if(!vis[j])while(!vis[j]&&vis[i]){
            dfs(j,i);
        }
        else if(vis[j]<2&&j!=ant){
        //    cout<<"ciclo a "<<j<<" "<<(j<n?RL[j]:BA[j])<<" desde "<<i<<" "<<(i<n?RL[i]:BA[i])<<endl;
			 //for(auto k: p)cout<<k<<" cord"<<(k<n?RL[k]:BA[k])<<" ";;cout<<" quedan en dfs"<<endl;
            p.pb(j);
            for(ll k=SZ(p)-2; k>=pos[j]; k--){
                vis[p[k]]=0;
                g[p[k]].erase(p[k+1]); g[p[k+1]].erase(p[k]);
                ll x=min(p[k],p[k+1]);
                ll y=max(p[k],p[k+1]);
      //          cout<<"añadimos "<<RL[x]<<" "<<BA[y]<<endl;
                rec.pb({{x,y},k&1});
                //cerra el orto edu cada uno comenta como se le salga de la *@&#&^@
                
                //no es para edu ˅
                //\\me cago en la puta 
                
            }
            p.pop_back();
            //for(auto k: p)cout<<k<<" cord"<<(k<n?RL[k]:BA[k])<<" ";;cout<<" quedan en dfs"<<endl;
        }
        if(!vis[i])break;
    }
    p.pop_back();
	if(vis[i])vis[i]=2;
}
void dfsu(ll i, ll ant, ll col){
    //cout<<"visitamos a "<<i<<" "<<(i<n?RL[i]:BA[i])<<" desde "<<ant<<" "<<(ant<n?RL[ant]:BA[ant])<<" con col"<<col<<endl;
    if(ant!=-1){
        ll x=min(i,ant);
        ll y=max(i,ant);
   //     cout<<"añadimos "<<RL[x]<<" "<<BA[y]<<" "<<col<<endl;
        rec.pb({{x,y},col});
    }
	col=!col;
    while(SZ(g[i])){
        ll j=*(g[i].begin());
        g[i].erase(j);
        g[j].erase(i);
        dfsu(j,i,col);
		col=!col;
    }
}
ll A[MAXN];
ll  main(){
	JET
	 cin>>n;
	ll lr=0,ab=n;
    string res=string(n,'L');
	ii gua[n];
	fore(i,0,n){
		LL x,y;
		cin>>x>>y;x--,y--;
		m[x+(y<<30)]=i;
//		cout<<x<<" "<<y<<" "<<m[x+(y<<30)]<<"\n";
		gua[i]={x,y};
		if(!LR.count(x)) {LR[x]=lr; RL[lr]=x; lr++;}
		if(!AB.count(y)) {AB[y]=ab; BA[ab]=y; ab++;}
		g[LR[x]].insert(AB[y]);
        g[AB[y]].insert(LR[x]);
	}

//	for(auto jere:rec){cout<<RL[jere.fst.fst]<<" "<<BA[jere.fst.snd]<<"\n";}
	fore(i,0,2*n)while(!vis[i]){vis&=cer;dfs(i,-1);}
    vis&=cer;
    fore(i,0,2*n)dfsu(i,-1,0);
	for(auto jere: rec){
	//	cout<<LL(RL[jere.fst.fst])<<" "<<((LL(BA[jere.fst.snd])))<<"\n";
	//	cout<<m[LL(RL[jere.fst.fst])+((LL(BA[jere.fst.snd]))<<30)]<<"\n";
		res[m[LL(RL[jere.fst.fst])+((LL(BA[jere.fst.snd]))<<30)]]=(jere.snd?'F':'L');
	}
//	res=string(n,'L');
	/*fore(i,0,n){
		A[LR[gua[i].fst]]+=(res[i]=='F'?1:-1);
		A[AB[gua[i].snd]]+=(res[i]=='F'?1:-1);
	}
	
	fore(i,0,2*n){
		if(A[i]>1||A[i]<-1)return 0;
	}*/
	cout<<res<<"\n";
	return 0;
}