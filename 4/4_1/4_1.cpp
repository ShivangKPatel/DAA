#include<bits/stdc++.h>
using namespace std;

vector<int> Ni;
vector<int> Vi;
vector<int> Wi;
vector<float> Fi;
float selectItem[100];

void sortElebyFrac(int n){
    int last_ele = n, swapp;
    for(int i = 0; i < n; i++){
        swapp = 0;
        for(int j = 0; j < last_ele-1; j++){
            if(Fi[j] < Fi[j+1]){
                swap(Ni[j], Ni[j+1]);
                swap(Vi[j], Vi[j+1]);
                swap(Wi[j], Wi[j+1]);
                swap(Fi[j], Fi[j+1]);
                swapp++;
            }
        }
        if(swapp==0){
            break;
        }
        last_ele--;
    }    
    cout << endl << "Ni : ";
    for(int i = 0; i < n; i++){
        cout << setprecision(4) << Ni[i] << " ";
    }
    cout << endl << "Vi : ";
    for(int i = 0; i < n; i++){
        cout << setprecision(4) << Vi[i] << " ";
    }
    cout << endl << "Wi : ";
    for(int i = 0; i < n; i++){
        cout << setprecision(4) << Wi[i] << " ";
    }
    cout << endl << "Fi : ";
    for(int i = 0; i < n; i++){
        cout << setprecision(4) << Fi[i] << " ";
    }
}

void perform_Task(int n, int w){
    sortElebyFrac(n);
    int i = 0, profit = 0;
    cout << endl;
    while(w!=0){
        if(Wi[i] <= w){
            selectItem[Ni[i]] = 1;
            w = w - Wi[i];
            profit = profit + Vi[i];
        }
        else{  
            selectItem[Ni[i]] = (double) w/Wi[i];
            profit += Vi[i]*((double)w/Wi[i]);
            w = 0;
        }
        i++;
    }
    cout << endl << "Fractional value : ";
    for(int i = 0; i < n; i++){
        cout << selectItem[Ni[i]] << " ";
    }
    cout << endl << "Profit : " << profit << endl; 
}

int main(){
    int n;
    cout << "Enter number of data : ";
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        Ni.push_back(n-i);
        cout << "Enter Vi for " << i+1 << " item : ";
        cin >> x;
        Vi.push_back(x);
        cout << "Enter Wi for " << i+1 << " item : ";
        cin >> x;
        Wi.push_back(x);
        Fi.push_back((float)Vi[i]/Wi[i]);
        cout << endl;
    }
    int w;
    cout << "Enter the knapsack capacity : ";
    cin >> w;
    perform_Task(n, w);
}