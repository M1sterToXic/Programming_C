//#1

// #include <stdio.h>  
// #include <stdlib.h>  
  
// void init(int** arr, int n){
//     *arr = malloc(n * sizeof(int)); 
//     if (*arr == NULL){
//         printf('Не удалось выделить память');
//     }
//     for (int i = 0; i < n; ++i) {  
//             (*arr)[i] = i;  
//     }  
// }   

// int main(){      
//     int n = 10;      
//     int* arr = NULL;    
//     init(&arr, n);  
//     for (int i = 0; i < n; ++i) {  
//         printf("%d\n", arr[i]);  
//     }      
//     free(arr);
//     return 0; 
// } 


//#2
// #include <stdio.h>  
  
// #include <stdio.h>  
  
// typedef struct{  
// char str[5];      
// int num;  
// } NumberRepr;  
  
// void format(NumberRepr* number){      
//     sprintf(number->str, "%3d", number->num);   
// }   
// int main(){  
//     NumberRepr number = { .num = 1025 };  
//     format(&number);  
//     printf("str: %s\n", number.str);      
//     printf("num: %d\n", number.num);  
//     return 0;  
// }


//#3
// #include <stdio.h>  
  
// void swap(int* a, int* b){      
//     int tmp = *a;      
//     *a = *b;  
//     *b = tmp;  
// }   

// void bubble_sort(int* array, int size){      
//     for (int i = 0; i < size - 1; ++i) {          
//                 for (int j = 0; j < size - i ; ++j) {              
//             if (array[j] > array[j + 1]) {                  
//                 swap(&array[j], &array[j + 1]);  
//                     }  
//             }  
//         }  
// }  

// int main() {
//     int array[100] = {10, 15, 5, 4, 21, 7};  
//     bubble_sort(array, 6);  
//     int i;   
//     for (i = 0; i < 6 ; ++i) {          
//     printf("%d ", array[i]);  
//         }      
//     printf("\n");  
//     return 0;  
// }  

//#4
// #include <stdio.h>  
// #define SQR(x)x*x  

// int main() {      
// int y = 5;      
// int z = SQR(y+1); //36     
// printf("z = %d\n", z);      
// return 0;
// }  

// #include <stdio.h>
// struct Point
// {
// int x, y, z;
// };
// int main()
// {

// struct Point p1 = {.y = 0, .z = 1, .x = 2};
// printf("%d %d %d", p1.x, p1.y, p1.z); 
// }
