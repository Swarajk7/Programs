#include<stdio.h>
#include<string.h>
void proc(char *s) {
    int len=strlen(s);
    int i=0,j=0,k=0;
    printf("%d\n",len);
    for( i=1;i<=len;i++) {
        while((s[i]==s[j]) && j>=0) {
            i++;
            j--;
        }
        s[++j]=s[i];
    }
    printf("%s\n",s);
}
char c[30];
int main() {
    strcpy(c,"A");//ABCCBCBA";
    proc(c);
    printf("%s\n",c);
    return 0;
}
