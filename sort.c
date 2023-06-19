void merge(int *v,int l,int r1,int r2){

    int *v2 = malloc(sizeof(int)*(r2-l+1));

    int k = 0;
    int i = l;
    int j = r1+1;

    while(i<= r1 && j<= r2){
        
        if(v[i]<v[j]){
            v2[k++] = v[i++];
        }else{
            v2[k++] = v[j++];
        }

    }

    while(i<= r1){
        v2[k++] = v[i++];
    }

    
    while(j<= r2){
        v2[k++] = v[j++];
    }

    k = 0;
    
    for(i = l; i<= r2; i++){
        v[i] = v2[k++];
    }

    free(v2);
}

void mergeSort(int *v,int l,int r){
    
    if(l >= r) return;

    int meio = (r+l)/2; 

    mergeSort(v,l,meio);
    mergeSort(v,meio+1,r);
    merge(v,l,meio,r);


}

int* sortArray(int* nums, int numsSize, int* returnSize){
    mergeSort(nums,0,numsSize-1);
    *returnSize = numsSize;
    return nums;
}