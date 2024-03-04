#include<bits/stdc++.h>
using namespace std;

int w[1000][1000];
int d[1000];
int v[1000];
int p[1000];
int noOfVertices;

void initialization(){
     for(int i = 0; i < noOfVertices; i++){
          d[i] = INT_MAX;
          v[i] = -1;
          p[i] = -1;
     }
}

void takeGraph(){
     for(int i = 0; i < noOfVertices; i++){
          for(int j = 0; j < noOfVertices; j++){
               cout << "Enter the weight of " << i << " to " << j << " : ";
               cin >> w[i][j];
          }
     }
}

int findSmall(){
     int small = INT_MAX;
     int index = -1;
     for(int i = 0; i < noOfVertices;i++){
          if(v[i]==-1 && d[i] < small){
               small = d[i];
               index = i;
          }
     }
     cout << "Small: " << index << endl;
     return index;
}

void calDistance(){ 
     d[0] = 0;
     v[0] = 1;
     int smallIndex;
     for(int i = 0; i < noOfVertices; i++){
          if(i==0){
               smallIndex = 0;
          }
          else{
               smallIndex = findSmall();
               v[smallIndex] = i+1;
          }
          for(int j = 0; j < noOfVertices; j++){
               if(smallIndex!=j && w[smallIndex][j]!=0 && v[j]==-1){
                    if(d[j] > d[smallIndex] + w[smallIndex][j]){
                         d[j] = d[smallIndex] + w[smallIndex][j];
                         p[j] = smallIndex;
                    }
               }
          }
     }

     cout << "i ";
     for(int j = 0; j < noOfVertices; j++){
          cout << j << " ";
     }

     cout << "D ";
     for(int j = 0; j < noOfVertices; j++){
          cout << d[j] << " ";
     }
     cout << endl;
     cout << "V ";
     for(int j = 0; j < noOfVertices; j++){
          cout << v[j] << " ";
     }
     cout << endl;
     cout << "P ";
     for(int j = 0; j < noOfVertices; j++){
          cout << p[j] << " ";
     }
     cout << endl;
}

int main(){
     cout << "Enter the number of vertices: ";
     cin >> noOfVertices;
     initialization();
     takeGraph();
     calDistance();
     return 0;
}