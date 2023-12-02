#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=3000,INF=1e10;

//ll ax[MAXN],ay[MAXN];
vector<ll>ax,ay;
ll h,w;
//ll b[MAXN][MAXN];
vector<vector<ll>>b;
vector<ii>dir={{-1,0},{0,-1},{1,0},{0,1}};
ii go(ll i, ll j, ll d){
    i+=dir[d].fst,j+=dir[d].snd;
    if(i<0||i>=h||j<0||j>=w||b[i][j])return {-1,-1};
    return {i,j};
}

ll tam=0;
void bfs(ll i0, ll j0, ll bt){
    queue<ii>q;
    q.push({i0,j0});
    b[i0][j0]=(!bt?1:3);
    while(SZ(q)){
		auto f=q.front(); q.pop();
		ll i=f.fst,j=f.snd;
		if(bt){
			ll sz=(ax[i+1]-ax[i])*(ay[j+1]-ay[j]);
			tam+=sz;
		}
		fore(d,0,4){
		    ii k=go(i,j,d);
		    ll i1=k.fst,j1=k.snd;
		    if(i1==-1)continue;
		    q.push({i1,j1});
		    b[i1][j1]=(!bt?1:3);
		}
    }
}

ll E=3;

//i=x,j=y
int main(){FIN;
    ifstream cin;  cin.open("agujeros.in" ,ios::in);
    ofstream cout;cout.open("agujeros.out",ios::out);
    ll n; cin>>n;
    pair<ii,ii> a[n];
    vector<ll>x,y;
    fore(i,0,n){
        ll x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        x.pb(x1),x.pb(x2);
        y.pb(y1),y.pb(y2);
        a[i]={{x1,y1},{x2,y2}};
    }
    sort(ALL(x)); sort(ALL(y));
    fore(i,0,E)ax.pb(-INF),ay.pb(-INF);
    for(auto i:x)if(i!=ax.back())ax.pb(i);
    fore(i,0,E)ax.pb(INF);
    for(auto i:y)if(i!=ay.back())ay.pb(i);
    fore(i,0,E)ay.pb(INF);
    h=SZ(ax),w=SZ(ay);
    b.resize(h,vector<ll>(w));
    fore(k,0,n){
        ll x1=a[k].fst.fst,y1=a[k].fst.snd,x2=a[k].snd.fst,y2=a[k].snd.snd;
        x1=lower_bound(ALL(ax),x1)-ax.begin();
        x2=lower_bound(ALL(ax),x2)-ax.begin();
        y1=lower_bound(ALL(ay),y1)-ay.begin();
        y2=lower_bound(ALL(ay),y2)-ay.begin();
        fore(i,x1,x2)fore(j,y1,y2)b[i][j]=2;
    }
    bfs(0,0,0);
    vector<ll>res;
    fore(i,0,h)fore(j,0,w){
        if(b[i][j])continue;
        tam=0;
        bfs(i,j,1);
        //cout<<i<<" "<<j<<": "<<ax[i]<<" "<<ay[j]<<" = "<<tam<<"\n";
        res.pb(tam);
    }
    /*for(ll j=w-1;j>=0;j--){
    	fore(i,0,h){
    		if(b[i][j]==1)cout<<".";
    		else if(b[i][j]==2)cout<<"x";
    		else if(b[i][j]==3)cout<<"#";
    		else cout<<"-";
    	}
    	cout<<"\n";
    }*/
    cout<<SZ(res)<<"\n";
    sort(ALL(res));
    for(auto i:res)cout<<i<<"\n";
    return 0;
}
