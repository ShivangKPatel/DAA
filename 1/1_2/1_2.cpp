#include<bits/stdc++.h>
using namespace std;

int c = 0;

//Iterative Fibbo
int itrFibbo(int n){
     int Counter = 0, a = 0, b = 1, c = 0;
     Counter = Counter + 5;
     for(int i = 2; i <= n; i++){
          c = a + b;
          a = b;
          b = c;
          Counter = Counter + 5;
     }
     Counter = Counter - 5;
     cout << "Counter : " << Counter << endl;
     return b;
}


int recFibbo(int n){
     c = c + 1;
     if(n == 0){
          return 0;
     }else if(n == 1) {
          return 1;
     } else {
          return recFibbo(n-1) + recFibbo(n-2);
     }
}

int main(){
     cout << "This program is prepared by 22CE097_Shivang Patel" << endl;
     int n;
     cin >> n;
     int Result = recFibbo(n);
     cout << "Counter : " << c << endl;
     cout << "Result : " << Result << endl;
     return 0;
}