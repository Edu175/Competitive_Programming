#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef double ld;
const ld eps=1e-8;
// struct cpx{
//     ld a,b;
//     cpx(ld a, ld b=0): a(a), b(b) {}
//     cpx() {}
//     ld norm() {return a*a+b*b;}
//     cpx inv(){
        // assert(norm()>=eps);
//         return cpx(a/norm(),-b/norm());}
//     cpx operator+(cpx c){return cpx(a+c.a,b+c.b);}
//     cpx operator-(cpx c){return cpx(a-c.a,b-c.b);}
//     cpx operator*(cpx c){return cpx(a*c.a-b*c.b,a*c.b+b*c.a);}
//     cpx operator/(cpx c){return *this*c.inv();}
// };
typedef complex<ld> cpx;
cpx m[3][4];
cpx rta[4];
// void verma(){
//      fore(i,0,3){
//             fore(j,0,4){
//                 // cout<<m[i][j].imag()<<"+"<<m[i][j].b<<"i  ";
//             }
//             cout<<"\n";
//         }
//         cout<<"\n\n";
//     }
ll pi[3]; 
void redx(){
    iota(pi,pi+3,0);
    // verma();

    fore(i,0,3){
        fore(j,i+1,3){
            // assert(pi[i]<3);
            // assert(pi[j]<3);
            // assert(pi[i]>=0);
            // assert(pi[j]>=0);
            if(abs(m[pi[i]][i])<abs(m[pi[j]][i])) swap(pi[i],pi[j]); //al pedo el &
        }
        // cout<<p[i]<<"i\n";
        if(abs(m[pi[i]][i])<eps) continue;
        // cout<<"dividire por "<<m[p[i]][i].a<<"+"<<m[p[i]][i].b<<"i  \n";
        fore(k,i+1,4){
            
            m[pi[i]][k]=m[pi[i]][k]/m[pi[i]][i];
        }
        m[pi[i]][i]=cpx(1);
        fore(j,i+1,3){
            // assert(pi[i]<3);
            // assert(pi[j]<3);
            // assert(pi[i]>=0);
            // assert(pi[j]>=0);
            fore(k,i+1,4){
                m[pi[j]][k]=m[pi[j]][k]-(m[pi[i]][k]*m[pi[j]][i]);
            }
            m[pi[j]][i]=cpx(0);
        }
        // verma();

    }
    
    // verma();
    if(abs(m[pi[2]][3])<eps){
        rta[3]=cpx(1);
        rta[2]=cpx(0);
    }
    else if(abs(m[pi[2]][2])<eps){
        rta[2]=cpx(1);
        rta[3]=cpx(0);
    }
    else {
        rta[3]=cpx(1);
		// assert(abs(m[pi[2]][2])>=eps);
        rta[2]=m[pi[2]][3]*cpx(-1)/m[pi[2]][2];
    }
    fore(i,0,2){
        ll ix=1-i;
        // assert(pi[ix]<3);
        // assert(pi[ix]>=0);
        // cout<<p[ix]<<"ix\n";
        if(abs(m[pi[ix]][ix])<eps) {
            rta[ix]=cpx(0);
            continue;
        }
        rta[ix]=cpx(0);    
        fore(j,ix+1,4){rta[ix]=rta[ix]-(rta[j]*m[pi[ix]][j]);}
        // cout<<rta[ix].a<<"+"<<rta[ix].b<<"i  \n";
        
    }
}

int main(){
    JET
	cout<<fixed<<setprecision(16);
    ll _; cin>>_; while(_--){
		fore(i,0,3){
			ld p,q,r,s; cin>>p>>q>>r>>s;
            cpx z(p,q),w(r,s);
            m[i][3]=z; //a
            m[i][1]=cpx(1); // b
            m[i][2]=z*w*cpx(-1); //c
            m[i][0]=w*cpx(-1); //d
        }
        redx();
        cpx a=rta[3], b=rta[1], c=rta[2];
        cpx d=rta[0];
        ld p,q; cin>>p>>q;
        cpx z(p,q);
		// assert(abs(a)<INFINITY);
		// assert(abs(b)<INFINITY);
		// assert(abs(c)<INFINITY);
		// assert(abs(d)<INFINITY);
        cpx r=(a*z+b)/(c*z+d);
		cout<<r.real()<<" "<<r.imag()<<"\n";
    }
    return 0;
}

    