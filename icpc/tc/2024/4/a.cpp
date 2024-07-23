#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll n,k;

vector<vector<ii>> g;
vector<ii> d;
vv nodos;
vector<ii> puntos;
map<ll,ll> mc;
map<ll,ll> mf;
set<ll> columnas;
set<ll> filas;
ll parsec (ll x){
	return k+2+x;
}
ll parsef (ll x){
	return k+2+SZ(columnas)+x;
}
//primeros k+2 son nodos, dps tengo c espacios para las columnas y dps tengo f espacios para las filas
ll dist(ll x,ll y){
	return (abs(puntos[x].fst-puntos[y].fst)+abs(puntos[x].snd-puntos[y].snd));
}

void dijkstra(ll x){
	d[x]={0,-1};
	priority_queue<ii,vector<ii>,greater<ii>> q;
	q.push({0,x});
	while(SZ(q)){
		x=q.top().snd; auto c=q.top().fst;
		q.pop();
		if(d[x].fst!=c) continue;
		for(auto i:g[x]){
			ll y=i.fst,c=i.snd;
			if(d[y].fst==-1||d[x].fst+c<d[y].fst){
				d[y].fst=d[x].fst+c;
				q.push({d[y].fst,y});
				d[y].snd=x;
			}
		}
	}
	
}

int main(){
	JET
	cin>>n>>k;
	ll x,x1,y,y1;
	cin>>x>>y>>x1>>y1;
	x--;y--;x1--;y1--;
	nodos.pb(0); nodos.pb(1);
	puntos.pb({x,y});
	puntos.pb({x1,y1});
	
	
	vector<ii> aux;
	vector<ii> aux1;
	
	fore(i,0,k){
		ll x,y; cin>>x>>y;
		x--; y--;
		puntos.pb({x,y});
		nodos.pb(i+2);
		filas.insert(y);
		columnas.insert(x);
		aux.pb({x,i+2});
		aux1.pb({y,i+2});
		
	}
	// cout<<"\n\n\n\n";
	g.resize(k+2+SZ(filas)+SZ(columnas));
	d.resize(k+2+SZ(filas)+SZ(columnas));
	fore(i,0,SZ(d))d[i]={-1,0};
	sort(ALL(aux));
	sort(ALL(aux1));
	ll cnt=0,cnt1=0;
	fore(i,0,k){
		if(!mc.count(aux[i].fst)){
			mc[aux[i].fst]=cnt;
			cnt++;	
		}
		g[parsec(mc[aux[i].fst])].pb({aux[i].snd,0});
		// cout<<"columnasss "<<mc[aux[i].fst]<<"   "<<aux[i].snd<<"\n";
		if(!mf.count(aux1[i].fst)){
			mf[aux1[i].fst]=cnt1;
			cnt1++;	
		}
		g[parsef(mf[aux1[i].fst])].pb({aux1[i].snd,0});
		g[i+2].pb({1,dist(i+2,1)});
	}
	g[0].pb({1,dist(1,0)});
	fore(i,0,SZ(puntos)){
		ii x=puntos[i];
		auto up=columnas.lower_bound(x.fst);
		if(i>=2) up++;
		if(up!=columnas.end()) g[i].pb({parsec(mc[*up]),abs(*up-x.fst)});
		// if(up!=columnas.end()) cout<<*up<<" "<<x.fst<<"\n";
		auto down=columnas.upper_bound(x.fst);
		if(down!=columnas.begin()){
			down--;
			if(i>=2 && down!=columnas.begin()){
				down--;
				g[i].pb({parsec(mc[*down]),abs(*down-x.fst)});
			}
			if(i<2) g[i].pb({parsec(mc[*down]),abs(*down-x.fst)});
		}
		
		up=filas.lower_bound(x.snd);
		if(i>=2) up++;
		if(up!=filas.end()) g[i].pb({parsef(mf[*up]),abs(*up-x.snd)});
		down=filas.upper_bound(x.snd);
		if(down!=filas.begin()){
			down--;
			if(i>=2 && down!=filas.begin()){
				down--;
				g[i].pb({parsef(mf[*down]),abs(*down-x.snd)});
			}
			
			if(i<2) g[i].pb({parsef(mf[*down]),abs(*down-x.snd)});
		}
	}
	dijkstra(0);
	cout<<d[1].fst<<"\n";
	// cout<<"\n\n";
	// ll auxx=d[1].snd;
	// while(auxx!=-1){
		// cout<<auxx<<" ";
		// auxx=d[auxx].snd;
	// }
	// cout<<"\n";
	
	// fore(i,0,SZ(g)){
	// 	fore(j,0,SZ(g[i])){
	// 		cout<<g[i][j].fst<<"-"<<g[i][j].snd<<"  ";
	// 	}
	// 	cout<<"\n";
	// }
	//cout<<"\n\n";
	//fore(i,0,SZ(d)) cout<<d[i]<<" ";
	//cout<<"\n\n";
	return 0;
}


/*

84 5
67 59 41 2
39 56
7 2
15 3
74 18
22 7




columnasss 0   3
columnasss 1   4
columnasss 2   6
columnasss 3   2
columnasss 4   5
44


1-83  11-7  10-28  16-3  
11-33  10-2  12-0  12-0  
1-56  11-35  9-17  15-38  
1-34  8-8  13-1  
1-27  9-7  7-8  14-4  12-1  
1-49  10-35  16-38  14-11  
1-24  10-17  8-7  15-11  13-4  
3-1  
4-1  
6-1  
2-1  
5-1  
3-1  
4-1  
6-1  
5-1  
2-1  


0 44 4 27 25 8 20 33 27 21 28 7 26 24 19 31 3 


*/