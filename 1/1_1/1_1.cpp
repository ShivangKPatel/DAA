#include<bits/stdc++.h>
using namespace std;

int c = 0;

//iterative factorial
int factorial(int n){
     int f = 1;
     c = c+3;
     for(int i=1; i<=n; i++){
          f = f*i;
          c = c+3;
     }
     // cout << "C : " << c << endl;
     return f;
}

//recursive factorial
int recfactorial(int n){
     c = c + 1;
     if(n==0){
          return 1;
     }
     return n*recfactorial(n-1);
}

int main(){
     int n;
     cout << "This program is prepared by 22CE097_ShivangPatel" << endl;
     cout << "Enter the number : ";
     cin >> n;
     int res = factorial(n);
     cout << "C : " << c << endl;
     cout << "Result : " << res << endl;
}