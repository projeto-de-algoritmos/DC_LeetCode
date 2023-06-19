#define greater(A,B) ((A) > (B))

int merge(int *v,int l,int r1,int r2){

    int *v2 = malloc(sizeof(int)*(r2-l+1));
    int k = 0;
    int i = l;
    int j = r1+1;
    int r = r1 - l + 1;
    int count = 0;

    
    while(i<= r1 && j<= r2){

        if(greater(v[i],v[j]*2ll)) {
            count += r;
            j++;
        }else{
            i++;
            r--;
        }

    }

    i = l;
    j = r1+1;

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

    return count;
}

int mergeSort(int *v,int l,int r){
    
    if(l >= r) return 0;

    int meio = (r+l)/2; 

    int r1 = mergeSort(v,l,meio);
    int r2 = mergeSort(v,meio+1,r);
    return r1 + r2 + merge(v,l,meio,r);

}

int reversePairs(int* nums, int numsSize){
    return mergeSort(nums,0,numsSize-1);
}