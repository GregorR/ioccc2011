#define _GNU_SOURCE
#include<alloca.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef NOMMAP
#include<sys/mman.h>
#endif
#define i int
#define c char
#define w while
#define S switch
#define T case
#define U break;
#define b volatile register
#define d o->
#define k d F[2](o);
#define W 9<<16
#define J(nm) i nm##s; i*nm(b ar o){
#define q return(i*)o;
#define A(x,y,z) O(x,y,z##1)O(x,y,z##2)O(x,y,z##3)
#define B(x,y) A(x,y,1)A(x,y,2)A(x,y,3)
#define C(x,y) B(x,y##1)B(x,y##2)B(x,y##3)
#define D(x) C(x,1)C(x,2)C(x,3)
#define E(x) D(x##1)D(x##2)D(x##3)
#define G E(1)E(2)E(3)
#define O(x,y,z) J(j##x##y##z)d r=(x*d m+y)*d m+z; k} J(J##x##y##z)*d a?(d r=(x*d m+y)*d m+z):0; k} e##x##y##z(){ }

typedef i*(*f)(b void*);
typedef struct{i*a,r,m;f*F;}*ar;
J(a)(*d a)++; q} /* a_dd */
J(s)(*d a)--; q} /* s_ub */
J(r)d a++; q} /* r_ight */
J(l)d a--; q} /* l_eft */
J(p) d F[0](o); k} /* p_utchar */
J(g) d F[1](o); k} /* g_etchar */
u(){ }
J(m)d F[2](alloca(8))?(d r=9):0; k}
J(n)alloca(8); }

P(b ar o){ putchar(*d a); }
R(b ar o){ *d a=getchar(); }
v(i*C){ scanf("%d",C); }

i t[W];
void*L[]={P,R,u};
f J[W];

G

main(){
    i*R,*x,C,ms,Rs;
    c*e;
    ar o=malloc(64);

    /* get space */
    e=
#ifndef NOMMAP
    mmap(0,9<<25,-1,MAP_PRIVATE|MAP_ANON,-1,0);
#else
    malloc(9<<25);
#endif

    /* figure out the size of the pro/epilogue */
    if(((c*)m-(c*)u)%4==0&&((c*)s-(c*)a)%4==0){
        R=(i*)u-1;
        x=(i*)m-1;
        w(*++R==*++x);
        ms=(c*)R-(c*)u;
        R=(i*)m;
        x=(i*)n;
        w(*--R==*--x);
        Rs=(c*)m-(c*)++R;
        R=(i*)((c*)R-ms);
    } else {
        ms=0;
        R=(i*)((c*)n-1);
        Rs=1;
    }

    /* figure out the sizes of functions */
#define M(x,y) x##s=(c*)y-(c*)x-ms-Rs;
    M(a,s)M(s,r)M(r,l)M(l,p)M(p,g)M(g,P)
#undef O
#define O(x,y,z) M(j##x##y##z,J##x##y##z)M(J##x##y##z,e##x##y##z)
    G

    /* JIT */
#define K(f)memcpy(e,(c*)f+ms,f##s);e+=f##s;
    w((C=getchar())>=0){
        S(C){
            T'+':K(a)U
            T'-':K(s)U
            T'>':K(r)U
            T'<':K(l)U
            T'.':K(p)U
            T',':K(g)U
            T'$':K(R)v(&C);J[C]=(f)e;memcpy(e,(c*)m,ms);e+=ms;U
            T'^':v(&C);
#undef O
#define O(x,y,z) if(C==x##y##z){K(j##x##y##z)}
            G U
            T'?':v(&C);
#undef O
#define O(x,y,z) if(C==x##y##z){K(J##x##y##z)}
            G U
        }
        if(C=='!')U
    }
    K(R)

    d a=t;
    d r=111111;
    d m=100;
    d F=(f*)L;
#ifdef JDEBUG
    fprintf(stderr, "%d %d\n", ms, Rs);
    fwrite(j, 4, 1000, stdout);
    fflush(stdout);
#endif
    w(J[d r]){ J[d r](o); }

    return 0;
}
