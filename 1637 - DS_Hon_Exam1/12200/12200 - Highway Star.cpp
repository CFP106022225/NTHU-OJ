#include<queue>
#include<cstdio>
using namespace std;


int Can_go_all(int *Loc,int *Gas,int N,int D){
    ///�T�{�O�_�����o�q�]����
    int sum_gas=0;
    for(int i=0;i<N;i++){
        sum_gas+=Gas[i];
    }
    if (sum_gas<D) return 0;
    ///
    ///���]�p�G�������[
    int place=0;
    sum_gas=0;
    for (int i=0;i<N;i++){
        sum_gas-=(Loc[i]-place);//���i�ӥ[�o���A��O�T�o
        if(sum_gas<0) return 0;//���ɪo���t�ơA�Y�줣��o��
        sum_gas+=Gas[i];
        place=Loc[i];
    }
    sum_gas-=(D-place);
    if(sum_gas<0) return 0;//������̫�@��
        else return 1;//���[���ܥi�H����
}

int how_go_all(int *Loc,int *Gas,int N,int D){
    /*if(Can_go_all(Loc,Gas,N,D)==1){

    }
    else return -1;*/
    priority_queue< pair<int,int> > Q;
    int times=0,pos=0,tank=0;//�[�o���ơB�T����m�B�o�c�o�q
    for(int i=0;i<N;i++){//�̦h�[N��
        //printf("times=%d pos=%d tank=%d\n",times,pos,tank);
        //printf("goto [%d]\n",i);
        int Next_distance=Loc[i]-pos;//��U�@�ӥ[�o�����Z��
        //printf("next is length of %d\n",Next_distance);
        while (Next_distance>tank){//�p�G�줣�F�U�@�ӥ[�o���A���e��[�o��
            //printf("back find gas station\n");
            if(Q.empty()) {
                //printf("Q is empty!!\n");
                return -1;//Queue�ŤF�A��ܥ����[�L�F�A���N�٬O�줣�F
            }
            //printf("Q.top=%d\n",Q.top());
            pair<int,int> temp=Q.top();
            Q.pop();
            //printf("tank=%d",tank);
            tank+=temp.first;
            //printf("->%d\n",tank);
            //printf("%d\n",temp.second);
            times++;
            //printf("times=%d\n",times);
        }
        //printf("tank=%d");
        tank-=Next_distance;    //��U�@�Ӳ��I
        //printf("->%d,tank\n");
        pos=Loc[i];
        Q.push(make_pair(Gas[i],i));
    }
    return times;
}


void solve( ){
    int N_stations,D_of_length;
    ///��J
    scanf("%d %d",&N_stations,&D_of_length);//��J����N ����D
    int Loc[N_stations+1],Gas[N_stations+1];//�}���N���ת�array�A�s��m�M�o�q
    for (int i=0;i<N_stations;i++){
        scanf("%d %d",&Loc[i],&Gas[i]);
    }
    Loc[N_stations]=D_of_length;
    Gas[N_stations]=0;
    int ans=how_go_all(Loc,Gas,N_stations+1,D_of_length);
    if(ans>=0) printf("Yes %d\n",ans);
        else printf("No\n");

}

int main(){
    //freopen("12200_sampleIn.txt,","r",stdin);
    //freopen("12200_sampleIn.txt", "r", stdin);
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        solve();
    }
    return 0;



}
