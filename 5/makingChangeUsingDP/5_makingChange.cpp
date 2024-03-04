#include<bits/stdc++.h>
using namespace std;

int den[1000];
int n;
int amount;
int Tab[1000][1000];

void takeInput(){
     cout << "Enter number of denominations: ";
     cin >> n;
     for(int i = 0; i < n; i++){
          cout << "Enter the denominations " << i+1 << " : ";
          cin >> den[i];
     }
     cout << "Enter the amount : ";
     cin >> amount;
     Tab[0][0] = 0;
     for(int j = 1; j <= amount; j++){
          Tab[0][j] = INT_MAX;
     }
}

void makeTable(){
     for(int i = 0; i < n;i++){
          for(int j = 0; j <= amount; j++){
               if(j < den[i]){
                    Tab[i+1][j] = Tab[i][j];
               }
               else{
                    Tab[i+1][j] = min(Tab[i+1][j-den[i]]+1, Tab[i][j]);
               }
          }
     }
     for(int i = 0; i < n; i++){
          for(int j = 0; j <= amount; j++){
               cout << Tab[i+1][j] << " ";
          }
          cout << endl;
     }
}

int main(){
     takeInput();
     makeTable();
}