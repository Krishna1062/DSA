#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = s + (e-s)/2;
    
    int len1 = mid - s+1;
    int len2 = e - mid;
    
    int nums1[len1];
    int nums2[len2];
    
    int mainIndex = s;
    for(int i=0; i<len1; i++){
        nums1[i] = arr[mainIndex++];
    }
    
    mainIndex = mid+1;
    for(int i=0; i<len2; i++){
        nums2[i] = arr[mainIndex++];
    }
    
    //merge two sorted arrays;
    mainIndex = s;
    int i = 0; 
    int j = 0;
    while(i<len1 && j<len2){
        if(nums1[i] < nums2[j]){
            arr[mainIndex++] = nums1[i++];
        }
        else{
            arr[mainIndex++] = nums2[j++];
        }
    }
    
    while(i<len1){
        arr[mainIndex++] = nums1[i++];
    }
    while(j<len2){
        arr[mainIndex++] = nums2[j++];
    }
    
}

void mergeSort(int* arr, int l, int r) {
    if(l >= r) return ;
    int mid = l + (r-l)/2;
    
    // left part;
    mergeSort(arr, l, mid);
    
    //right part;
    mergeSort(arr, mid+1, r);
    
    // merge
    merge(arr, l, r);
}

int main(){
    int arr[] = {8,9,7,6,0,4,5,3};
    mergeSort(arr, 0, 7);
    for(int i=0; i<8; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}