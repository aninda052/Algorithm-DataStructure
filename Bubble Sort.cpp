#include<bits/stdc++.h>
using namespace std;

int arr[100],element;

void Bubble_sort(){

    for(int i=0;i < element-1;i++){
        for(int j=i+1;j < element;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

}

main(){

    printf("Number Of Elements : ");
    scanf("%d",&element);

    printf("Enter %d Elements...\n",element);
    for(int i = 0;i < element;i++){
        scanf("%d",&arr[i]);
    }

    Bubble_sort();

    printf("Sorted List : \n");

    for(int i = 0;i < element;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

/* Demo input
5
12 42 5 19 1
*/
