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
#define vr volatile register
typedef i(*f)(vr void*);
typedef struct{i*a;i r;f*F;}*ar;
#define W 9<<16
#define J(nm) i nm##s; *nm(vr ar a){
#define ra return(i*)a;
u(){ }
J(m)a->F[2](alloca(8))?(a->r=9):0; a->F[2](0); }
J(n)alloca(8); }
J(a)(*a->a)++; ra} /* a_dd */
J(s)(*a->a)--; ra} /* s_ub */
J(r)a->a++; ra} /* r_ight */
J(l)a->a--; ra} /* l_eft */
J(p) a->F[0](a); a->F[2](a); } /* p_utchar */
J(g) a->F[1](a); a->F[2](a); } /* g_etchar */

P(ar a){ putchar(*a->a); }
G(ar a){ *a->a=getchar(); }
ri(i*C){ scanf("%d",C); }

i t[W];
void*L[]={P,G,u};
f J[W];

#define A(x) O(x##1)O(x##2)O(x##3)
#define B(x) A(x##1)A(x##2)A(x##3)
#define C(x) B(x##1)B(x##2)B(x##3)
#define D(x) C(x##1)C(x##2)C(x##3)
#define E(x) D(x##1)D(x##2)D(x##3)
#define F() E(1)E(2)E(3)

#define O(x) J(j##x)a->r=x; ra}
F()
#undef O
#define O(x) J(J##x)*a->a?(a->r=x):0; ra}
F()

main(){
    i*h,C,ms,Rs,*R,*x;
    c*j,*e;
    ar ks=malloc(32);

    /* get space */
    j=e=
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
    M(a,s); M(s,r); M(r,l); M(l,p); M(p,g); M(g,P); M(j111111,j111112);
#undef O
#define O(x) j##x##s=j111111s;
    F()
    M(J111111,J111112);
#undef O
#define O(x) J##x##s=J111111s;
    F()

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
            T'$':K(R)ri(&C);J[C]=(f)e;memcpy(e,(c*)m,ms);e+=ms;U
            T'^':ri(&C);
#undef O
#define O(x) if(C==x){K(j##x)}
            F()U
            T'?':ri(&C);
#undef O
#define O(x) if(C==x){K(J##x)}
            F()U
        }
        if(C=='!')break;
    }
    K(R)

    ks->a=t;
    ks->r=111111;
    ks->F=(f*)L;
#ifdef JDEBUG
    fprintf(stderr, "%d %d\n", ms, Rs);
    fwrite(j, 4, 1000, stdout);
    fflush(stdout);
#endif
    w(J[ks->r]){ J[ks->r](ks); }

    return 0;
}
