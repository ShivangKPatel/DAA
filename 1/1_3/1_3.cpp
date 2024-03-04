#include<bits/stdc++.h>
using namespace std;

//iterative GCD
int GCD(int a, int b){
     int Counter = 0, c;
     Counter = Counter + 2;
     for(int i = a; i >= 1; i--){
          Counter = Counter + 3;
          if(a%i == 0 && b%i == 0){
               c = i;
               Counter = Counter + 1;
               break;
          }
     }
     cout << "Counter : " << Counter << endl;
     return c;
}

//recursive GCD (Euclid's Algorithm)
int Counter = 0;
int recGCD(int a, int b){
     Counter = Counter + 1;
     if(b == 0){
          return a;
     }
     return recGCD(b, a%b);
}

int main(){
     int a, b;
     cin >> a >> b;
     int result = recGCD(a, b); //recursive
     cout << "Counter : " << Counter << endl; 
     cout << "Result : " << result << endl;
}