#include <iostream>
using namespace std;
int main() {
    cout << "This program is developed by 22CE097" << endl;
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int c=0;
    c=c+2;
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        c=c+2;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            c=c+2;
        }
        arr[j + 1] = key;
        c=c+3;
    }
    cout<<"Sorted Array : "<<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Counter: " << c << endl;
    return 0;
}
