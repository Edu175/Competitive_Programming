#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long double ld;
const ld eps=1e-9,DINF=2e5;
struct pt{
    ld x, y;
    pt(ld x,ld y): x(x),y(y) {}
    pt() {}
    ld norm2(){return *this**this;}
    ld norm(){return sqrt(norm2());}
    pt operator+(pt p){return pt(x+p.x,y+p.y);}
    pt operator-(pt p){return pt(x-p.x,y-p.y);}
    pt operator/(ld t){return pt(x/t,y/t);}
    pt operator*(ld t){return pt(x*t,y*t);}
    ld operator*(pt p){return x*p.x+y*p.y;}
    ld operator%(pt p){return x*p.y-y*p.x;}
};
struct ln{
    pt p,pq;
    ln(pt p, pt q): p(p), pq(q-p){}
    pt operator^(ln l){
        pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
        return r;
    }
};
typedef vector<pt> poly;
ld area(poly &p){
    ld r=0.;
    int n=SZ(p);
    fore(i,0,n) r+=p[i]%p[(i+1)%n];
    return abs(r)/2;
}
poly mk(const poly &p, ld M){
    int n=SZ(p);
    bool left=(p[0].x<=M+eps);
    poly np;
    fore(i,0,n){
        if(!left) {
            if(p[(i+1)%n].x>M+eps) continue;

            np.pb(ln(p[i],p[(i+1)%n])^ln(pt(M,DINF),pt(M,-DINF)));
            np.pb(p[(i+1)%n]);
            left=true;
        }
        else{
            if(p[(i+1)%n].x>M+eps) {
                left=false;
                np.pb(ln(p[i],p[(i+1)%n])^ln(pt(M,DINF),pt(M,-DINF)));
            }
            else{
                np.pb(p[(i+1)%n]);
            }
        }
    }
    return np;
}
int main(){
    JET
    int n,k; cin>>n>>k;
    poly p(n);
    fore(i,0,n) cin>>p[i].x>>p[i].y;
    ld T=area(p)/(k+1);
    ld L=-DINF,R=DINF;
    poly np=p;
    while(R-L>eps){
        ld M=(L+R)/2;
        np=mk(p,M);
        if(area(np)>T) R=M;
        else L=M;
    }
    cout<<fixed<<setprecision(10)<<L<<"\n";
    return 0;
}
