#include<stdio.h>


int Josepus_postive(int m,int n);
int Josepus_negative(int m,int n);

/*int Josepus_try(int m,int n){
    int people[m];
    for (int i=0;i<m;i++) people[i]=1;

    int now_knife=0;
    int count=0;
    for (int i=1;i<m;i++) {
        if(i%2){//�_�Ʀ�
            while(count<n){
                //�p�G�U�@�ӤH����
                if (people[(now_knife+1)%m]){
                    count++;//�ǻ�1��
                    now_knife=(now_knife+1)%m;//��U�@�Ӧa��
                }
                else{//�_�h�A�Y�U�@�ӤH�S����
                    now_knife=(now_knife+1)%m;//��U�@�Ӧa��
                }
            }
            people[now_knife]=0;
            while(people[(now_knife+1)%m]!=1){
               now_knife= (now_knife+1)%m;//����ǵ��U�@�ӤH�A����U�@�ӬO���ۦ�m
            }
            now_knife= (now_knife+1)%m;//�ǵ����Ӭ��۪��H
            count=0;
        }
        else{//���Ʀ�
            while(count<n){
                // �p�G�e�@�ӤH����
                if (people[(now_knife-1)%m]){
                    count++;
                    now_knife=(now_knife-1)%m;//��U�@�Ӧa��
                }
                else{
                    now_knife=(now_knife-1)%m;
                }
            }
            people[now_knife]=0;
            while(people[(now_knife-1)%m]!=1){
               now_knife= (now_knife-1)%m;//����ǵ��U�@�ӤH�A����U�@�ӬO���ۦ�m
            }
            now_knife= (now_knife-1)%m;//�ǵ����Ӭ��۪��H
            count=0;
        }
    }

    for(int i=0;i<m;i++){
        if(people[i]==1){
            return (i+1);
        }
    }
}
*/
int main(){

//    printf("%d\n",Josepus_postive(5,4)+1);
//    printf("%d\n",Josepus_postive(4,4)+1);
    int T,N,M,SUM=0;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        scanf("%d %d",&N,&M);
        SUM+=Josepus_postive(N,M+1)+1;
    }
    printf("%d\n",SUM);
    return 0;
}

Josepus_postive(m,n){
    if (m==1) return 0;
        else return (Josepus_negative(m-1,n)+n+1)%m;
}
Josepus_negative(m,n){
    if (m==1) return 0;
        else return (m-Josepus_postive(m,n))%m;
}
