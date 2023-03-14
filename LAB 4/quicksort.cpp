#include<iostream>

using namespace std;

void quicksort(int a[], int low, int high){
    
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        int tmp;
        cin>>tmp;
        a[i] = tmp;
    }   

    quicksort(a, 0, n-1);
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";

    return 0;
}
