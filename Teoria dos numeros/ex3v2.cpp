#include <stdio.h>
int main() {
    char x;
    long long respo = 0;


    while(scanf("%c", &x)!=EOF) {
        if(x == -1){
            break;
        }
        if(x == '1' || x == '0') {
            respo = (respo<<1)+x-'0';
            if(respo >= 131071)
                respo %= 131071;
        }
         else if(x == '#') {
            puts(respo ? "NO" : "YES");
            respo = 0;
        }
    }
    return 0;
}
