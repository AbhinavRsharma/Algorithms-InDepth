#include<stdio.h>
#include<stdlib.h>

struct envl{
    int w;
    int h;
};
typedef struct envl envl;

envl* merge_sort(envl* list, int n){
    if(n==1)
        return list;
    envl* list1 = (envl*)malloc((n/2)*sizeof(envl));
    envl* list2 = (envl*)malloc((n-n/2)*sizeof(envl));

    for(int i=0;i<n/2;i++)
        list1[i] = list[i];
    for(int i=n/2;i<n;i++)
        list2[i-n/2] = list[i];
    
    list1 = merge_sort(list1, n/2);
    list2 = merge_sort(list2, n-n/2);

    int i=0, j=n/2, k=0;

    while(k<n){
        if(j==n){
            list[k] = list1[i];
            k++;i++;
        }
        else if(i==n/2){
            list[k] = list2[j-n/2];
            j++;k++;
        }
        else if(list1[i].w<list2[j-n/2].w){
            list[k] = list1[i];
            k++;i++;
        }
        else if(list1[i].w>list2[j-n/2].w){
            list[k] = list2[j-n/2];
            j++;k++;
        }
        else if(list1[i].h<list2[j-n/2].h){
            list[k] = list1[i];
            k++;i++;
        }
        else{
            list[k] = list2[j-n/2];
            k++;j++;
        }
    }
    
    free(list1);
    free(list2);
    return list;
}

int main(){
    int n, w, h, cnt=0;
    scanf("%d %d %d", &n, &w, &h);
    envl* list = (envl*)malloc(n*sizeof(envl));
    int *inc = (int*)malloc(n*sizeof(int));
    int *min = (int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n;i++){
        scanf("%d %d", &(list[cnt].w), &(list[cnt].h));
        if(list[cnt].w>w&&list[cnt].h>h)cnt++;
    }
    n=cnt;
    list = merge_sort(list, n);
    
    for(int i=0; i<n; i++){
        printf("%d %d\n", list[i].w, list[i].h);
    }

    inc[n-1]=1;
    min[n-1]=list[n-1].h;
    int j;
    for(int i=n-2; i>=0; i--){
        j=i+1;
        inc[i]=0;
        while(n-j>inc[i]&&j<n){
            if(list[i].w!=list[j].w&&list[i].h<list[j].h&&inc[i]<inc[j])
                inc[i] = inc[j];
            j++;
        }
        inc[i]++;
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(max<inc[i])
            max = inc[i];
    }

    printf("%d\n", max);

    return 0;
}
