#define _GNU_SOURCE
#ifdef AH
#include<alloca.h>
#endif
#include<ctype.h>
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
#define R(x) ; S r(#x);
#define L(x,y) S l[x](d)R(y)
#define F(x) void l##x(vo dat d) {
#define Q(x); S a[-1] x##=*S a; S a--; R(x)
#define O(x,y,z) x##y##z,
#define q typedef
#define H 9<<16

q char k;
q void o;
q int u;
q o (*f)(vo o*);
q struct { u*a,**R,*m,h,c; k**s; f*l,*j,r; } *dat;

u m[]={G 0};
u n[H];
dat st;
u sk[H];
k*w;
o*x[H];
u y[H];
k*j,*e;

#define W(c) memcpy(e,x[(u)c],y[(u)c]); e+=y[(u)c];

o g(u v){
    if(v>256){
        g(v/256);
        g(256);
        W('*')
    }else{
        W(m[v])
    }
}

f K(k*p,dat d){
    k c;
    f r=(f)e;
    W(1)
    while((c=*p)){
        switch(c){
            case'#':
                while(*++p!=10);
                break;
            case'[':
                c=1;
                S s[S c]=++p;
                for(;c;p++){
                    if(*p=='[')c++;
                    else if(*p==']')c--;
                }
                p[-1]=0;
                g(S c++);
                break;
            case's':
            case'S':
            case'l':
            case'L':
            case'=':
                g(*++p);
                W(c)
                p++;
                break;
            case'_':
                p++;
            default:
                if(isdigit(*p)){
                    g(atoi(p));
                    while(isdigit(*p))p++;
                } else p++;
                W(c)
        }
    }
    W(2)
#ifdef JDEBUG
    fwrite(j, 1, e-j, stdout);
    fflush(stdout);
#endif
    return r;
}

o t(vo dat d) {
    S r("\01")/*R(F)*/
    Q(+)Q(-)Q(*)*S a=-*S a; R(_)
    S a--;R(@)
    S a[-1]^=*S a; *S a^=S a[-1]R(r)
    S a[1]=*S a; S a++R(d)
    *S R[*S a]=S a[-1]; S a--; R(s)
    *++S R[*S a]=S a[-1]; S a--; R(S)
    *S a=*S R[*S a]; R(l)
    *S a=*S R[*S a]--; R(L)
    L(1,/)L(2,P)L(3,p)L(4,x)L(5,v)L(6,=)
#undef O
#define O(x,y,z) *++S a=S m[(x*S h+y)*S h+z]; S r("");
    G S l[0](d);
}

o T(){ }

o rsubd(u v){
    k*a=0,**b=&a,**c=b+32;
    x[v]=w;
    for(;b<c&&(*b<w||*b>(k*)T||*b==(k*)(long)v);b++);
    if(b==c){
        jmp_buf*j=alloca(sizeof(jmp_buf));
        setjmp(*j);
        rsubd(v);
    } else{
        y[v]=*b-w-y['F'];
        w=*b;
    }
}

q o(*rsubt)(u);
vo rsubt rsub=rsubd;

o recorder(vo k*rec){
    static u i=0;
    *(st->a=sk+9)=0;
    rsub(*rec?*rec:m[i++]);
}

F(d)S a[-1]/=*S a;S a--; }
F(P)printf("%d",*S a); fflush(stdout); }
F(p)printf("%d\n",*S a); }
F(x)u n=*S a--;if(!S j[n])S j[n]=K(S s[n],d);S j[n](d); }
F(v)*S a=sqrt(*S a); }
F(e)S a-=3; if(S a[1]==S a[2]){ S a[1]=*S R[S a[3]]; S a++; S l[4](d); } }

o*lib1[]={T,T,T,T,T,T,T};
o*lib2[]={T,ld,lP,lp,lx,lv,le};

u main(){
    u i;
    k*b;
    dat d=st=calloc(1,sizeof(*st));
    S a=sk+9;
    S R=calloc(256,sizeof(k*));
    for(i=0;i<256;i++)S R[i]=calloc(H,1);
    S m=n;
    S s=calloc(H,1);
    S l=(f*)lib1;
    S j=calloc(H,1);
    S r=(f)recorder;
    for (i=0;m[i];i++)n[m[i]]=i;
    w=(k*)t;
    t(d);
    y[1]-=y['F'];
    x[2]=w;
    y[2]=(k*)T-w+8;

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
    b=malloc(H);
    b[fread(b,1,(H)-1,stdin)]=0;
    K(b,d);

    ((f)j)(d);

    return 0;
}
