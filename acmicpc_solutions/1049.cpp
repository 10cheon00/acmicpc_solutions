#include <iostream>
using namespace std;
int main(){
    int N,M,B,high=1, low=500, time = 2147483647;
    scanf("%d %d %d", &N, &M, &B);
    int arr[256]{0,}; //높이가 등장한 횟수

    int n;
    for(int i=0; i<N*M; i++){
        scanf("%d", &n);
        arr[n]++;
        if(n<low){
            low=n;
        }
        if(n>high){
            high=n;
        }
    }
    int height=high, res, blocks;
    for(int i=low; i<=high; i++){
        res = 0;
        blocks = 0;
        for(int j=0; j<256; j++){
            if(j<i){ // j높이가 i높이보다 작을 경우
                res+=arr[j]; // 1초 * 블럭갯수
                blocks+=arr[j];
            }
            else{ // j높이가 i높이보다 높을 경우
                res+=arr[j]*2; // 2초 * 블럭개수
                blocks-=arr[j];
            }
        }
        if(blocks <= B && res < time){
            height = i;
            time = res;
        }
    }
    printf("%d %d", height, time);
}