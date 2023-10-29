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
const ll MAXN=3000;

map<ll,ll>x,y;
//ll ax[2*MAXN],ay[2*MAXN];
vector<ll>ax,ay;
ll h,w;
vector<vector<ll>>b;
vector<ii>dir={{-1,0},{0,-1},{1,0},{0,1}};
ii go(ll i, ll j, ll d){
    i+=dir[d].fst,j+=dir[d].snd;
    if(i<0||i>=h||j<0||j>=w||b[i][j])return {-1,-1};
    return {i,j};
}

void dfs(ll i, ll j){
    b[i][j]=1;
    fore(d,0,4){
        //auto [i1,j1]=go(i,j,d);
        ii k=go(i,j,d);
        ll i1=k.fst,j1=k.snd;
        if(i1==-1)continue;
        dfs(i1,j1);
    }
}
ll tam=0;
void dfs2(ll i, ll j){
    b[i][j]=3;
    ll sz=(ax[i+1]-ax[i])*(ay[j+1]-ay[j]);
    tam+=sz;
    fore(d,0,4){
        //auto [i1,j1]=go(i,j,d);
        ii k=go(i,j,d);
        ll i1=k.fst,j1=k.snd;
        if(i1==-1)continue;
        dfs2(i1,j1);
    }
}
//i=x,j=y
int main(){FIN;
    ifstream cin;  cin.open("agujeros.in" ,ios::in);
    ofstream cout;cout.open("agujeros.out",ios::out);
    ll n; cin>>n;
    pair<ii,ii> a[n];
    fore(i,0,n){
        ll x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        x[x1]=-1,x[x2]=-1;
        y[y1]=-1,y[y2]=-1;
        a[i]={{x1,y1},{x2,y2}};
    }
    ax.resize(5,0);
    ll j=5;
    for(auto &i:x){
        i.snd=j;
        ax.pb(i.fst);
        //ax[j]=i.fst;
        j++;
    }
    h=j+5;
    ay.resize(5,0);
    j=5;
    for(auto &i:y){
        i.snd=j;
        ay.pb(i.fst);
        //ay[j]=i.fst;
        j++;
    }
    w=j+5;
    while(SZ(ax)<h+5)ax.pb(0);
    while(SZ(ay)<w+5)ay.pb(0);
    b.resize(h,vector<ll>(w));
    fore(k,0,n){
        /*auto [k1,k2]=a[k];
        auto [x1,y1]=k1;
        auto [x2,y2]=k2;*/
        ll x1=a[k].fst.fst,y1=a[k].fst.snd,x2=a[k].snd.fst,y2=a[k].snd.snd;
        x1=x[x1],x2=x[x2];
        y1=y[y1],y2=y[y2];
        fore(i,x1,x2)fore(j,y1,y2)b[i][j]=2;
    }
    dfs(0,0);
    vector<ll>res;
    fore(i,0,h)fore(j,0,w){
        if(b[i][j])continue;
        tam=0;
        dfs2(i,j);
        res.pb(tam);
    }
    cout<<SZ(res)<<"\n";
    sort(ALL(res));
    for(auto i:res)cout<<i<<"\n";
    return 0;
}
