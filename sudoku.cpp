#include<iostream>
#include<math.h>
using namespace std;
void print(int board[][9], int n){
    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool isvalid(int board[0][9],int i, int j,int num, int n){
    for(int x=0; x<n; x++){
        if(board[i][x]==num){
            return false;
        }
    }
    for(int x=0; x<n; x++){
        if(board[x][j]==num){
            return false;
        }
    }
    int rn = sqrt(n);
    int si= i-i%rn;
    int sj= j-j%rn;
    for(int x=si; x<si+rn; x++){
        for(int y =sj; y<sj+rn; y++){
            if(board[x][y]==num){
                return false;
            }
        }
    }
    return true;

}
bool sudokusolver(int board[][9],int i, int j,int n){
    if (i==n){
        print (board,n);
        return true;
    }
    if(j==n){
        return sudokusolver(board,i+1,0,n);
    }
    if(board[i][j]!=0){
        return sudokusolver(board,i,j+1,n);      
    }
    for(int num =1; num<10; num++){
        if(isvalid(board, i, j, num,n)){
        board[i][j]=num;
        bool subans = sudokusolver(board,i,j+1,n);
        if(subans){
            return true;
        }
        board[i][j]=0;
        }
    }
    return false;
}
int main(){
    int n =9;
    int board[9][9]={
        { 9, 7, 8, 4, 1, 0, 0, 0, 5 },
        { 3, 0, 0, 8, 0, 0, 0, 6, 4 },
        { 6, 0, 0, 3, 5, 0, 0, 9, 0 },
        { 2, 6, 9, 0, 3, 0, 0, 0, 7 },
        { 5, 0, 7, 1, 0, 0, 0, 0, 0 },
        { 1, 0, 3, 0, 0, 2, 0, 8, 9 },
        { 7, 1, 0, 2, 0, 5, 0, 0, 3 },
        { 0, 0, 2, 7, 0, 3, 1, 5, 8 },
        { 0, 0, 5, 9, 4, 1, 0, 0, 0 },
    };
    sudokusolver(board,0,0,n);
    return 0;
}