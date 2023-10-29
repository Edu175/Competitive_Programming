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

vector<ll>ax(5),ay(5);
ll h,w;
vector<vector<ll>>b;
vector<ii>dir={{-1,0},{0,-1},{1,0},{0,1}};
ii go(ll i, ll j, ll d){
    i+=dir[d].fst,j+=dir[d].snd;
    cout<<i<<" "<<j<<" "<<d<<endl;
    if(i<0||i>=h||j<0||j>=w||b[i][j])return {-1,-1};
    cout<<"paso"<<endl;
    return {i,j};
}

void dfs(ll i, ll j){
    b[i][j]=1;
    fore(d,0,4){
        auto [i1,j1]=go(i,j,d);
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
        auto [i1,j1]=go(i,j,d);
        if(i1==-1)continue;
        dfs2(i1,j1);
    }
}

inline ll idx(ll x, vector<ll>&a){
	return lower_bound(ALL(a),x)-a.begin();
}

//i=x,j=y
int main(){FIN;
    ifstream cin;  cin.open("agujeros.in" ,ios::in);
    ofstream cout;cout.open("agujeros.out",ios::out);
    ll n; cin>>n;
    pair<ii,ii> a[n];
    vector<ll>cx,cy;
    fore(i,0,n){
        ll x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        cx.pb(x1),cy.pb(y1);
        cx.pb(x2),cy.pb(y2);
        //x[x1]=-1,x[x2]=-1;
        //y[y1]=-1,y[y2]=-1;
        a[i]={{x1,y1},{x2,y2}};
    }
    sort(ALL(cx));
    fore(i,0,SZ(cx))if(!i||cx[i]!=cx[i-1])ax.pb(cx[i]);
    h=SZ(ax)+5;
    
    sort(ALL(cy));
    fore(i,0,SZ(cy))if(!i||cy[i]!=cy[i-1])ay.pb(cy[i]);
    w=SZ(ay)+5;
    cout<<h<<" "<<w<<endl;
    b.resize(h,vector<ll>(w));
    fore(k,0,n){
        auto [k1,k2]=a[k];
        auto [x1,y1]=k1;
        auto [x2,y2]=k2;
        x1=idx(x1,ax); y1=idx(y1,ay);
        x2=idx(x2,ax); y2=idx(y2,ay);
        fore(i,x1,x2)fore(j,y1,y2)b[i][j]=2;
    }
    ax.resize(h+5,0);
    ay.resize(w+5,0);
    
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
