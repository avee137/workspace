#include<stdio.h>

#define MAX_INDEX 10
int u_arr[MAX_INDEX] = {12,3,54,31,6,43,9,89,90,5};

void printarr(int *arrbase, int max) {
	int i;
        //printf("in printarr\n");	
	//printf("%u\t",&u_arr[0]);
	//printf("%d\t",*arrbase);
	for (i=0; i<max; i++){
		printf("%d\t",*arrbase);
		arrbase++;
	}
	printf("\n");
	return;
}

void swap( int *arr,int i, int j){
	int tmp;
	tmp = arr[i];
	arr[i]=arr[j];
	arr[j]=tmp;
	//printf ("%d %d\n",i,j);
	//printf ("swap\n");
	return;
}

void qsort(int *arr, int beg_index, int end_index) {
	int pivot_index = (beg_index + end_index)/2 ;
	int b_iter = beg_index, e_iter=end_index-1; //iterator from beginning and end
	int pivot_val = arr[pivot_index];
         
	if (beg_index < end_index){
		//swap pivot value to the highest index in the array to separate it
		swap (arr,pivot_index,end_index);
                while (b_iter < e_iter) {
			//move b_iter to an element greater than pivot
			while( (arr[b_iter] < pivot_val) && (b_iter < end_index)) {
				b_iter++;
			}
			//move e_iter to an element lesss than pivot
			while( (arr[e_iter] > pivot_val) ) {
				e_iter--;
			}
			if(b_iter < e_iter){	
				swap(arr, b_iter, e_iter);
			}
		}
    	        swap (arr,b_iter,end_index);

		qsort(arr,beg_index, e_iter-1);
		qsort(arr,e_iter+1, end_index);
	}

}

int main() {
	printf("the unsorted arr :\n ");
        printarr(u_arr,MAX_INDEX);	
	qsort(u_arr,0,MAX_INDEX-1);
	printf("the sorted arr :\n ");
        printarr(u_arr,MAX_INDEX);	
	return 0;
}
