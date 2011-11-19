#define _GNU_SOURCE
#ifdef AH
#include<alloca.h>
#endif
#include<math.h>
#include<setjmp.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if !NOMMAP
#include<sys/mman.h>
#endif
#define vo volatile
#define A(x,y,z) O(x,y,z##1)O(x,y,z##2)O(x,y,z##3)
#define B(x,y) A(x,y,1)A(x,y,2)A(x,y,3)
#define C(x,y) B(x,y##1)B(x,y##2)B(x,y##3)
#define D(x) C(x,1)C(x,2)C(x,3)
#define E(x) D(x##1)D(x##2)D(x##3)
#define G E(1)E(2)E(3)
#define S d->
#define R(x) ;S r(#x);
#define L(x,y) S l[x](d)R(y)
#define F(x) void l##x(vo dat d) {
#define Q(x) S a[-1] x##=*S a;S a--;R(x)
#define O(x,y,z) x##y##z,
#define q typedef
#define H 9<<16

q char k;
q void o;
q int u;

u m[]={G 0};
u n[H];

q o (*f)(vo o*);
q struct { u*a,*t,h,*m; k**s; f*j,*l,r; }*dat;

o t(vo dat d) {
    R(1)/*R(F)*/Q(+)Q(-)Q(*)*S a=-*S a;R(_)L(1,/)L(2,P)L(3,p)L(4,v)
#undef O
#define O(x,y,z) *++S a=S m[(x*S h+y)*S h+z];S r("");
    G S l[0](d);
}

o T() {}

dat st;
u sk[H];
k*w;
o*x[H];
u y[H];
k*j,*e;

o rsubd(u v) {
    k*a=0,**b=&a;
    x[v]=w;
    while (*b<w||*b>(k*)T||*b==(k*)(long)v)b++;
    y[v]=*b-w-y['F'];
    w=*b;
}

q o(*rsubt)(u);
vo rsubt rsub=rsubd;

o recorder(vo k*rec) {
    static u i=0;
    jmp_buf j;
    *(st->a=sk+9)=0;
    setjmp(j);
    rsub(*rec?*rec:m[i++]);
}

F(d)S a[-1]/=*S a;S a--; }
F(P)printf("%d",*S a); fflush(stdout); }
F(p)printf("%d\n",*S a); }
F(v)*S a=sqrt(*S a); }

o*lib1[]={T,T,T,T,T};
o*lib2[]={T,ld,lP,lp,lv};

#define W(c) memcpy(e,x[(u)c],y[(u)c]);e+=y[(u)c];

o g(u v) {
    if (v>256) {
        g(v/256);
        g(256);
        W('*');
    } else {
        W(m[v]);
    }
}

u main() {
    u i;
    k c;
    dat d=st=malloc(64);
    S a=sk+9;
    S h=0;
    S m=n;
    S l=(f*)lib1;
    S r=(f)recorder;
    for (i=0;m[i];i++)n[m[i]]=i;
    w=(k*)t;
    t(d);
    y['1']-=y['F'];
    x['2']=w;
    y['2']=(k*)T-w+8;

    S h=100;
    S l=(f*)lib2;
    S r=(f)T;

    /* get space */
    j=e=
#if NOMMAP
    malloc(H);
#else
    mmap(0,H,-1,MAP_PRIVATE|MAP_ANON,-1,0);
#endif

    W('1')
    while (!feof(stdin)) {
        if (scanf("%d",&i)>0) {
            g(i);
        } else if (scanf("%c",&c)>0) {
            switch(c){
                case '_':
                    scanf("%d",&i);
                    g(i);
                    break;
            }
            W(c)
        } else break;
    }
    W('2')

#ifdef JDEBUG
    fwrite(j, 1, e-j, stdout);
    fflush(stdout);
#endif
    ((f)j)(d);

    return 0;
}
