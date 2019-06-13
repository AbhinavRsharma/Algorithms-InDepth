#include<stdio.h>
#include<string.h>

int main(){
    char str[1001], sub[51];
    int pattern[51], i_ = -1;         // i_ is index of first appearance of match 
    int i=0, j=1;

    scanf("%s\n%s", str, sub);
    pattern[0] = 0;

    while (sub[j]){
        if(sub[i] == sub[j]){
            pattern[j] = j+1;
            i++;
            j++;
        }
        else{
            pattern[j] = 0;
            i=0;
            j++;
        }
    }

    i = 0; 
    j = 0;
    while(str[i]){
        if(!sub[j]){
            i_ = i;
            break;
        }

        if(str[i] == sub[j]){
            i++;
            j++;
        }
        else{
            if(j==0)
                i++;
            else{
                j = pattern[j-1];
            }
        }
    }
    printf("%d", i_-strlen(sub));

    return 0;
}
