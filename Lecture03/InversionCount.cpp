//solution uploaded to:	https://www.spoj.com/problems/INVCNT/

/*
  Use Merge Sort: every time in Merge function we are comparing L[i] with R[j] and we have that 
  L[i]>R[j], add the size of the remaining elements of L to the solution (because we are adding 
  all the pairs (L[x],R[j]) for each L[x] s.t. i<=x<=|L|)
*/


#include <bits/stdc++.h>
using namespace std;


long long Mergesort(int* A, int l, int r);
long long Merge(int* A, int l, int m, int r);




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tests;
    cin >> tests;

    while(tests--){
        int size;
        cin >> size;

        int* A = new int[size];

        for(int i=0; i<size; i++){
            cin >> A[i];
        }

        cout << Mergesort(A,0,size-1);
        if(tests>0){
            cout << "\n";
        }
    }
    return 0;
}




long long Mergesort(int* A, int l, int r){
    long long inversions = 0;
    if(l<r){
        int m = l+(r-l)/2;
        inversions +=Mergesort(A, l, m);
        inversions +=Mergesort(A, m+1, r);
        inversions += Merge(A, l, m, r);
    }
    return inversions;
}




long long Merge(int* A, int l, int m, int r){
    const int L_SIZE = m-l+1;
    const int R_SIZE = r-m;

    //allocate temporary left and right array
    int* L = new int[L_SIZE];
    int* R = new int[R_SIZE];

    //copy data to temporary arrays
    for(int i=0; i<L_SIZE; i++){
        L[i] = A[l+i];
    }
    
    for(int j=0; j<R_SIZE; j++){
        R[j] = A[m+1+j];
    }

    //merge the temp arrays in A and count inversions
    long long inversions=0;
    int index_R=0, index_L=0, index_A=l;

    while (index_L < L_SIZE && index_R < R_SIZE) {
        if(L[index_L]>R[index_R]){
            inversions+=L_SIZE-index_L;
            A[index_A] = R[index_R];
            index_R++;
        }
        else{
             A[index_A] = L[index_L];
            index_L++;
        }
        index_A++;
    }


    // Copy the remaining elements of left[], if there are any
    while (index_L < L_SIZE) {
        A[index_A] = L[index_L];
        index_L++;
        index_A++;
    }
    // Copy the remaining elements of right[], if there are any
    while (index_R < R_SIZE) {
        A[index_A] = R[index_R];
        index_R++;
        index_A++;
    }
    return inversions;
}
