#include<stdio.h>
#include<string.h>

void longest_(int *longest, char* str, int i, int j, int l){
    if(i == 0){
        if(str[i] == str[j+1])
            *(longest+(l-1)*i+j) = 1;
        else
            *(longest+(l-1)*i+j) = 0;
    }
    else if(j == l-2){
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
    int l = strlen(str);
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
    for(int i=0; i<l-1; i++){
        for(int j=i+1;j<l-1;j++){
            printf("%d ",longest[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for(int i=0; i<l-2;i++){
        pre[i][i] = 0;
        suf[i][i] = 0;
        palin[i][i] = 1;
        if(i+1<l-2)
            palin[i][i+1] = 1;
    }
    
    for(int k=1; k<l-2; k++){
        for(int i=0; i+k<l-2; i++){
            if(str[i+1] != str[i+k])
                palin[i][i+k] = 0;
            else
                palin[i][i+k] = palin[i][i+k];
            pre[i][i+k] = palin[i][i+k] + pre[i][i+k-1];
            suf[i][i+k] = palin[i][i+k] + suf[i+1][i+k];
            
        }
    }
    
    for(int i=0; i<l-1; i++){
        for(int j=i+1;j<l-1;j++){
            printf("%d ",palin[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<l-1; i++){
        for(int j=i+1;j<l-1;j++){
            printf("%d ",suf[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<l-1; i++){
        for(int j=i+1;j<l-1;j++){
            printf("%d ",pre[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}
