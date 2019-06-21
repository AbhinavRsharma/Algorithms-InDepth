#include<stdio.h>
#include<string.h>

void longest_(int *longest, char* str, int i, int j, int l){
    if(i == 0 || j == l-2){
        if(str[i] == str[j+1])
            *(longest+(l-1)*i+j) = 1;
        else
            *(longest+(l-1)*i+j) = 0;
    }
    else if(str[i] == str[j+1])
        *(longest+(l-1)*i+j) = *(longest+(l-1)*(i-1)+j+1)+1;
    else
        *(longest+(l-1)*i+j) = 0;
}

int main(){
    char str[101];
    scanf("%s",str);
    int l = strlen(str), count = 0;
    int longest[l-1][l-1], pre[l-1][l-1], suf[l-1][l-1], palin[l-1][l-1] ;
    for(int i=0; i<l-1; i++){
        for(int j=0;j<l-1;j++){
            longest[i][j]=-1;
            pre[i][j]=-1;
            suf[i][j]=-1;
            palin[i][j]=-1;
        }
    }
    
    for(int i=0; i<l-1; i++){
        for(int j=i+1;j<l-1;j++){
            longest_(longest, str, i, j, l);
        }
    }    
    for(int i=0; i<l-1;i++){
        pre[i][i] = 2;
        suf[i][i] = 2;
        palin[i][i] = 1;
        if(i+1<l-1)
            palin[i+1][i] = 1;
    }
    
    for(int k=1; k<=l-2; k++){
        for(int i=0; i+k<l-1; i++){
            if(str[i+1] != str[i+k])
                palin[i][i+k] = 0;
            else
                palin[i][i+k] = palin[i+1][i+k-1];
            
            pre[i][i+k] = palin[i][i+k] + pre[i][i+k-1];
            suf[i][i+k] = palin[i][i+k] + suf[i+1][i+k];
            
        }
    }
    
    for(int i=0; i<l-1; i++){
        for(int j=i+1;j<l-1;j++){
            count += longest[i][j]*(pre[i][j]+suf[i][j]-1);
        }
    }
    printf("%d", count);
    return 0;
}
