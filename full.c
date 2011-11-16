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
typedef i*(*f)(vr void*);
typedef struct{i*a,r,m;f*F;}*ar;
#define W 9<<16
#define J(nm) i nm##s; i*nm(vr ar a){
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

#define A(x,y,z) O(x,y,z##1)O(x,y,z##2)O(x,y,z##3)
#define B(x,y) A(x,y,1)A(x,y,2)A(x,y,3)
#define C(x,y) B(x,y##1)B(x,y##2)B(x,y##3)
#define D(x) C(x,1)C(x,2)C(x,3)
#define E(x) D(x##1)D(x##2)D(x##3)
#define F() E(1)E(2)E(3)

#define O(x,y,z) J(j##x##y##z)a->r=(x*a->m+y)*a->m+z; a->F[2](a); } J(J##x##y##z)*a->a?(a->r=(x*a->m+y)*a->m+z):0; a->F[2](a); } e##x##y##z(){ }
F()

main(){
    i*h,C,ms,Rs,*R,*x;
    c*j,*e;
    ar ks=malloc(64);

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
    M(a,s)M(s,r)M(r,l)M(l,p)M(p,g)M(g,P)
#undef O
#define O(x,y,z) M(j##x##y##z,J##x##y##z)M(J##x##y##z,e##x##y##z)
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
#define O(x,y,z) if(C==x##y##z){K(j##x##y##z)}
            F()U
            T'?':ri(&C);
#undef O
#define O(x,y,z) if(C==x##y##z){K(J##x##y##z)}
            F()U
        }
        if(C=='!')break;
    }
    K(R)

    ks->a=t;
    ks->r=111111;
    ks->m=100;
    ks->F=(f*)L;
#ifdef JDEBUG
    fprintf(stderr, "%d %d\n", ms, Rs);
    fwrite(j, 4, 1000, stdout);
    fflush(stdout);
#endif
    w(J[ks->r]){ J[ks->r](ks); }

    return 0;
}
