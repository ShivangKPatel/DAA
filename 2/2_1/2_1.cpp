#include<bits/stdc++.h>
using namespace std;

//Using iterative function
int binarySearch(int Arr[], int n, int key){
    int counter = 0;
    int l = 0;
    int h = n-1;
    int mid = 0;
    counter = counter + 3;
    while(l<=h){
        mid = (l+h)/2;
        counter = counter+3;
        if(Arr[mid] == key){
            cout << "Counter : " << counter << endl;
            return mid;
        }
        else if(Arr[mid] < key){
            l = mid+1;
        }
        else if(Arr[mid] > key){
            h = mid-1;
        }
        counter = counter + 1;
    }
    cout << "Counter : " << counter << endl;
    return -1;
}

//Using recursive function
int Counter = 0;
int recbinarySearch(int Arr[], int n, int key, int l, int h){
    Counter++;
    int mid = (l+h)/2;
    if(l>h){
        return -1;
    }
    else if(Arr[mid] == key){
        return mid;
    }
    else if(Arr[mid] < key){
        return recbinarySearch(Arr, n, key, mid+1, h);
    }
    else if(Arr[mid] > key){
        return recbinarySearch(Arr, n, key, l, mid-1);
    }
}

int main(){
    cout << "This program is preared by 22CE097_ShivangPatel" << endl;
    int n;
    int key;
    cout << "Enter number of elements : ";
    cin >> n;
    int Arr[n];
    for(int i=1; i <= n; i++){
        Arr[i-1] = i*10;
        cout << Arr[i-1] << " ";
    }
    cout << endl << "Enter element you want to find : ";
    cin >> key;

    cout << endl << "Iterative function : " << endl; //Using iterative function or recursive function
    int result = binarySearch(Arr, n, key); //Using iterative function or recursive function
    if(result == -1){
        cout << "Element does not found in array." << endl;
    }
    else{
        cout << "Element founded on index number " << result << endl;
    }
    cout << endl << "Recursive function : "<< endl;
    result = recbinarySearch(Arr, n, key, 0, n-1); //Using iterative function or recursive function
    cout << "Counter : " << Counter << endl; //Counter for recursive function
    if(result == -1){
        cout << "Element does not found in array." << endl;
    }
    else{
        cout << "Element founded on index number " << result << endl;
    }
    return 0;
}