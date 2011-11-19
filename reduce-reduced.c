#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    void *next;
    int len, count, savings;
    char **locs;
}*d;

d newSS(int len){
    d ret;
    ret=calloc(sizeof(*ret),1);
    ret->locs=calloc((len+1)*sizeof(char *),1);
    return ret;
}

void freeSS(d s){
    free(s->locs);
    free(s);
}

void link(d*h,d n){
    n->savings=(n->len-1)*(n->count-1);
    n->next=*h;
    *h=n;
}

int m(d*a, d*b){
    if ((*a)->savings < (*b)->savings){
        return-1;
    } else if ((*a)->savings > (*b)->savings){
        return 1;
    } else{
        return 0;
    }
}

int main(){
    d L=0,nl=0,C,N,*A;
    d S[0x100];
    int i,l,sl,n;
    char*f,c;

    /* read it in */
    f=calloc(9<<16,1);
    n=fread(f,1,9<<16,stdin);

    /* outright remove #lines */
    for(l=0;l<n;l++){
        if(f[l]=='#'){
            for(;l<n&&f[l]!='\n';l++)f[l]=0;
            f[l]=0;
        }
    }

    /* count all the initials */
    for(i=1;i<0x100;i++){
        S[i]=newSS(n);
        S[i]->len=1;
    }
    for(l=0;l<n;l++){
        c=f[l];
        if(!c)continue;
        C=S[c];
        C->locs[C->count++]=f+l;
    }
    for(i=1;i<0x100;i++){
        C=S[i];
        if(C->count>1){
            link(&L,C);
        } else{
            freeSS(C);
        }
    }

    /* then recurse */
    for(sl=2;sl<n-1;sl++){
        int ct=0;
        fprintf(stderr," %d/%d\r",sl,n-1);
        /* count all the greaters */
        for(N=L;N;N=N->next) {
            ct++;
            if(N->len!=sl-1)break;
            for (i=1;i<0x100;i++){
                S[i]=newSS(n);
                S[i]->len=sl;
            }
            for(l=0;N->locs[l];l++){
                c=N->locs[l][sl-1];
                if(!c)continue;
                if(isspace(c)&&isspace(N->locs[l][sl-2]))continue;
                C=S[c];
                C->locs[C->count++]=N->locs[l];
            }
            for(i=1;i<0x100;i++){
                C=S[i];
                if(C->count>1){
                    link(&L,C);
                } else{
                    freeSS(C);
                }
            }
        }
    }
    fprintf(stderr,"\n");

    /* put them all on an array */
    for(i=0,N=L;N;i++,N=N->next);
    A=calloc(sizeof(d)*(i+1),1);
    for(i=0,N=L;N;i++,N=N->next)A[i]=N;

    /* sort it */
    qsort(A,i,sizeof(d),m);

    /* for readability, remove newlines */
    for(l=0;l<n;l++){
        if(f[l]=='\n')f[l]='\\';
    }

    for(i=0;A[i];i++){
        N=A[i];
        printf("%d: %.*s: (%d*%d)\n",N->savings,N->len,N->locs[0],N->len-1,N->count-1);
    }

    return 0;
}
