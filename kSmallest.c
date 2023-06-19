#define less(A,B) ((A) < (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }

int separa(int *v,int l,int r){

    int p = v[r];
    int k = l;

    for(int i = l;i<=r;i++){
        if(less(v[i],p)){
            exch(v[i],v[k]);
            k++;
        }
    }

    exch(v[k],v[r]);

    return k;

}

void quickSelect(int *v,int l,int r,int p){ 

    
    int j = separa(v,l,r);

    if(j == p) return;

    if(j<p){
        quickSelect(v,j+1,r,p);
    }else{
        quickSelect(v,l,j-1,p);
    }
}

int findKthLargest(int* nums, int numsSize, int k){

    quickSelect(nums,0,numsSize-1,numsSize-k);
    return nums[numsSize-k];
}
