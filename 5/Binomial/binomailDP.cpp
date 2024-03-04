#include<bits/stdc++.h>
using namespace std;

int n, k;
int Tab[100][100];

void takeInput(){
     cout << "Enter n : ";
     cin >> n;
     cout << "Enter k : ";
     cin >> k; 
}

void makeTable(){
     int x = k;
     if(k > n){
          cout << "Invalid Input" << endl;
          return;
     }
     else if(k == 0 || k == n){
          cout << "The value of C(" << n << ", " << k << ") is : 1" << endl;
          return;
     }
     else if(k == 1 || k == n-1){
          cout << "The value of C(" << n << ", " << k << ") is : " << n << endl;
          return;
     }
     else if(k > n/2){
          k = n-k;
     }
     for(int i = 1; i <= n; i++){
          for(int j = 0; j <= k; j++){
               if(j<=i){
                    if(j==0 || i==j){
                         Tab[i][j] = 1;
                    }
                    else{
                         Tab[i][j] = Tab[i-1][j-1] + Tab[i-1][j];
                    }
               }   
               else{
                    Tab[i][j] = 0;
               }      
          }
     }

     cout << "The value of C(" << n << ", " << x << ") is : " << Tab[n][k] << endl;
}

int main(){
     takeInput();
     makeTable();
}