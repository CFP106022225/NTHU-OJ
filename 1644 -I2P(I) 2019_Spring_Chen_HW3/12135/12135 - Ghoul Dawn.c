#include <stdio.h>
#include <limits.h>
#include <math.h>

void tm(char C,int i){
    printf("[%c]=%d\n",C,i);
}


long long int max_average(long long int* S,int least,int length){
    long long int MAX_AVERAGE=0,m=0;
    long long int sum=0,tmp=0;
    for(int i=least;i<=length;i++){
        //�q�̤p�϶��W�ɶ}�l
        ///tm('i',i);
        //�q�W�ɩ��^���A���̤j����
        for(int j=i-least;j>=0;j--){
            sum=S[i]-S[j];//�q j+1 j+2 ... i ����(i-j)�Ӽƪ��M
            tmp=sum*10000/(i-j);// ��i-j������ �]��3��G*1000
            ///printf("\tj=%d sum=%lld tmp=%lld \n",j,sum,tmp);
            //if(tmp<m) break;// �p�G�ܤp�F�A���N���n�A���U�h�F
            if(tmp>m) m=tmp;
            ///printf("\t\tm=%lld\n",m);
        }
        ///printf("%lld?%lld %d\n",m,MAX_AVERAGE,(m-MAX_AVERAGE)>0);
        if((m-MAX_AVERAGE)>0){
            //�p�G���@�Ӥ���j���A������
            ///printf("MAX=%lld->%lld\n",MAX_AVERAGE,m);
            MAX_AVERAGE=m;
            m=0;
        }
        else{
            //�_�h�M�s�N�n
            ///printf("MAX=%lld\n",MAX_AVERAGE);
            m=0;
        }
    }
    return MAX_AVERAGE;
}

int main(){
    freopen("12135_sampleIn.txt","r",stdin);
    int n,k;
    scanf("%d %d",&n,&k);
    long long int S[n+1];
    S[0]=0LL;
    int scan;
    for (int i=0;i<n;i++){
        scanf("%d",&scan);
        //printf("%d\n",scan);
        S[i+1]=S[i]+scan;
        //printf("% lld\n",S[i+1]);
    }
//    for (int i=0;i<=n;i++){
//        printf("%lld\n",S[i]);
//    }
    long long int result=max_average(S,k,n);
    printf("%lld.%03lld\n",result/10000,((result%10000)+5)/10);
///����1~5�����٥h�L�t�A������6�ݥ|�ˤ��J�i��]SID1884721 1884727�^
    return 0;
}
