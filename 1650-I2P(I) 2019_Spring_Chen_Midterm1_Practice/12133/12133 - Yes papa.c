#include <stdio.h>
char A[100000];
char B[100000];

bool is_equal(char *a,char *b,int start,int end){
    /// �����۵�
    // a1==b1 a2==b2
    bool all_same=true;
    for(int i=start;i<=end;i++){
        if(a[i]!=b[i]) all_same=false;
    }
    if(all_same) return true;
    /// �S��W�h
    // a1==b2 a2==b1
    if((start-end)%2)//���׬����ơA�~�i����
    {
        return(is_equal(a,b,))
    }
    else return false;



}

