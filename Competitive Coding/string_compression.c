#include<stdio.h>
#include<string.h>
void compress(const char *s,char *cs) {
    int k=0,i=1,cnt=1;
    while(i<strlen(s)) {
        if(s[i]==s[i-1]) {
            cnt++;
        } else {
            cs[k++]=s[i-1];
            char c[10],cc=0;
            while(cnt!=0) {
                int p=cnt%10;
                c[cc++]=p+'0';
                cnt/=10;
            }
            while(--cc>=0) {
                cs[k++]=c[cc];
            }
            cnt=1;
        }
        i++;
    }
    cs[k++]=s[i-1];
    char c[10],cc=0;
    while(cnt!=0) {
        int p=cnt%10;
        c[cc++]=p+'0';
        cnt/=10;
    }
    while(--cc>=0) {
        cs[k++]=c[cc];
    }
    cs[k]='\0';
}
void rev(char *s) {
    char *p=s,*q=s;
    while(*q!='\0') {
        printf("%c\n",*q);
        q++;
    }
    q--;
    printf("%c %c\n",*p,*q);
    while(p<q) {
        char c=*p;
        *p=*q;
        *q=c;
        p++;
        q--;
    }
}
int main() {
    char s[]="abcdaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char *cs=(char *)malloc(sizeof(int)*strlen(s));
    compress(s,cs);
    char c[20]="abc";
    rev(s);
    printf("%s  %s",s,cs);
    int z=-192732;
    int v=(z&(1<<31));
    printf("%d\n",v);
    return 0;
}
