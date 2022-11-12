#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;
 
int search(long long int arr[], int n, int x,long long int&comparisons)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
         
            return i;
        }
        else{
            comparisons++;
        }
    }
    return -1;
}
 
 int binarySearch_recursive(long long int arr[], int l, int r, int x,long long int&comparisons)
{
    if (r >= l) 
    {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
        {
            comparisons++;
            return mid;
        }
 
      
        if (arr[mid] > x)
        {
      
            return binarySearch_recursive(arr, l, mid - 1, x,comparisons);
        }
 
     
        return binarySearch_recursive(arr, mid + 1, r, x,comparisons);
    }
 

    return -1;
}
void insertionSort(long long int arr[], int n,long long int &comparisons,long long int &operations,long long int &assignments)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
  
        j = i - 1;
    
        
 
   
        while (j >= 0 && arr[j] > key)
        {
               assignments++;
            comparisons=comparisons+2;
            arr[j + 1] = arr[j];
            assignments++;
            j = j - 1;
        }
        arr[j + 1] = key;
        assignments++;
    }
    operations=assignments+comparisons;
}



void merge(long long int array[], int const left, int const mid, int const right,long long int &comparisons,long long int &operations,long long int &assignments)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

 
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        {leftArray[i] = array[left + i];
        
            assignments++;
        }
    for (auto j = 0; j < subArrayTwo; j++)
        {rightArray[j] = array[mid + 1 + j];
            assignments++;
        }

    auto indexOfSubArrayOne = 0, 
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        comparisons++;
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            comparisons++;
            assignments++;
            comparisons++;
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
    assignments++;
            comparisons++;
            comparisons++;
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
   
    while (indexOfSubArrayOne < subArrayOne) {
        comparisons++;
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        assignments++;
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
   
    while (indexOfSubArrayTwo < subArrayTwo) {
        comparisons++;
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        assignments++;
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}


void mergeSort(long long int array[], int const begin, int const end,long long int &comparisons,long long int &operations,long long int &assignments)
{
    if (begin >= end)
        return; 

    auto mid = begin + (end - begin) / 2;
    assignments++;
    mergeSort(array, begin, mid,comparisons,operations,assignments);
    mergeSort(array, mid + 1, end,comparisons,operations,assignments);
    merge(array, begin, mid, end,comparisons,operations,assignments);
 operations=comparisons+assignments;   
}
 

void printArray(long long int arr[], int n)
{
    int i;
    if(n>=200)
    {
        for (i = 0; i < 200; i++)
       { cout << arr[i] << " ";}
    }
    else if(n<200){
        for (i = 0; i < n; i++)
       { cout << arr[i] << " ";}
    }
    
    cout << endl;
}
void swap(long long int* a, long long int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
 
void bubbleSort(long long int arr[], int n,long long int &comparisons,long long int &operations,long long int &assignments)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                comparisons++;
                swap(arr[j], arr[j+1]);
                assignments=assignments+1;
            }
        }
    }
    operations=assignments+comparisons;
} 

int partition (long long int arr[], int low, int high,long long int &comparisons,long long int &operations,long long int &assignments) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
       
        if (arr[j] < pivot) 
        { 
            comparisons++;
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
            assignments=assignments+1;
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    assignments=assignments+1;
    return (i + 1); 
} 
  

void quickSort(long long int arr[], int low, int high,long long int &comparisons,long long int &operations,long long int &assignments) 
{ 
    if (low < high) 
    { 
        
        int pi = partition(arr, low, high,comparisons,operations,assignments); 
  
        quickSort(arr, low, pi - 1,comparisons,operations,assignments); 
        quickSort(arr, pi + 1, high,comparisons,operations,assignments); 
    } 
    operations=comparisons+assignments;
}

int main(void)
{
     
    int n=0;
    long long int x;
    long long int*arr;
     int key;
  long long int comparisons;
  long long int operations;
  long long int assignments;
    
     int result;
             
               while(1)
               {     cout<<"press 1 for sequential search"<<endl;
                   cout<<"press 2 for binary search"<<endl;
                   
                   cout<<"press 3 for insertion Sort"<<endl;
                    cout<<"press 4 for quick Sort"<<endl;
                    
                    cout<<"press 5 for merge Sort(nlogn)"<<endl;
                      cout<<"press 6 for bubble Sort(n^2)"<<endl;
                   cout<<"press -1 for exit"<<endl;
                   cin>>key;
                   if(key==-1)
                   {
                       break;
                   }
                       cout << "How many integers should be in the array?:"; //ask the user to enter how many integers they want to be in the vector
                           cin >> n;
                           cout << "\n";
            
                          arr=new long long int[n]; 
                           for (int i = 0; i < n; i++) 
                           {
                               arr[i] = rand()%((n*10)+1);
                           }//for statement close


              x= rand()%((n*10)+1);

               cout << "\nThe number to search for: " <<x<< "\n";
              
              
                   if(key==1)
                   {
                       
                         comparisons=0;
                         auto start = high_resolution_clock::now();
                         // Function call
                       result = search(arr, n, x,comparisons);
                          // Get ending timepoint
                         auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<milliseconds>(stop - start);
                           if(result!=-1)
                           {
                                cout<<"status succesfull"<<endl;
                                cout<<"value found at index="<<result<<endl;
                                cout<<"comparisons per search="<<comparisons<<endl;
                             }
                        else
                        {
                            cout<<"status unsuccesfull"<<endl;
                        }
                         cout << "Time ="
                             << duration.count() << " milliseconds" << endl;
                 
                       
                   }
                   else if(key==2)
                   {
                      comparisons=0;
                         auto start = high_resolution_clock::now();
                         // Function call
                         result = binarySearch_recursive(arr, 0, n-1,x,comparisons);
                          // Get ending timepoint
                         auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<milliseconds>(stop - start);
                           if(result!=-1)
                           {
                                cout<<"status succesfull"<<endl;
                                cout<<"value found at index="<<result<<endl;
                                cout<<"comparisons per search="<<comparisons<<endl;
                                
                             }
                        else
                        {
                            cout<<"status unsuccesfull"<<endl;
                        }
                         cout << "Time = "
                             << duration.count() << " milliseconds" << endl;
                 
                   }
                   else if(key==3)
                   {
                        
                       comparisons=0,operations=0, assignments=0;
                       cout<<"before sort:";
                       printArray(arr,n);
                       cout<<endl;
                         auto start = high_resolution_clock::now();
                         // Function call
                         insertionSort(arr, n,comparisons,operations,assignments);
                          // Get ending timepoint
                         auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<milliseconds>(stop - start);
                         
                       
                               cout<<"after sort:";
                               printArray(arr,n);
                               cout<<endl;
                                cout<<"comparisons ="<<comparisons<<endl;
                                  cout<<"assignments="<<assignments<<endl;
                                  cout<<"operations="<<operations<<endl;
                        
                     
                      
                        
                         cout << "Time= "
                             << duration.count() << " milliseconds" << endl;
                   }
                   else if(key==4)
                   {
                        comparisons=0,operations=0, assignments=0;
                       cout<<"before sort:";
                       printArray(arr,n);
                       cout<<endl;
                         auto start = high_resolution_clock::now();
                         // Function call
                         quickSort(arr, 0,n-1,comparisons,operations,assignments);
                          // Get ending timepoint
                         auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<milliseconds>(stop - start);
                         
                       
                               cout<<"after sort:";
                               printArray(arr,n);
                               cout<<endl;
                                cout<<"comparisons ="<<comparisons<<endl;
                                  cout<<"assignments="<<assignments<<endl;
                                  cout<<"operations="<<operations<<endl;
                        
                     
                      
                        
                         cout << "Time= "
                             << duration.count() << " milliseconds" << endl;
                   }
                   else if(key==5)
                   {
                        comparisons=0,operations=0, assignments=0;
                       cout<<"before sort:";
                       printArray(arr,n);
                       cout<<endl;
                         auto start = high_resolution_clock::now();
                         // Function call
                         mergeSort(arr, 0,n-1,comparisons,operations,assignments);
                          // Get ending timepoint
                         auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<milliseconds>(stop - start);
                         
                       
                               cout<<"after sort:";
                               printArray(arr,n);
                               cout<<endl;
                                cout<<"comparisons ="<<comparisons<<endl;
                                  cout<<"assignments="<<assignments<<endl;
                                  cout<<"operations="<<operations<<endl;
                        
                     
                      
                        
                         cout << "Time= "
                             << duration.count() << " milliseconds" << endl;
                   }
                    else if(key==6)
                    {
                        comparisons=0,operations=0, assignments=0;
                       cout<<"before sort:";
                       printArray(arr,n);
                       cout<<endl;
                         auto start = high_resolution_clock::now();
                         // Function call
                         bubbleSort(arr, n,comparisons,operations,assignments);
                          // Get ending timepoint
                         auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<milliseconds>(stop - start);
                         
                       
                               cout<<"after sort:";
                               printArray(arr,n);
                               cout<<endl;
                                cout<<"comparisons ="<<comparisons<<endl;
                                  cout<<"assignments="<<assignments<<endl;
                                  cout<<"operations="<<operations<<endl;
                        
                     
                      
                        
                         cout << "Time= "
                             << duration.count() << " milliseconds" << endl;
                    }
                   else{
                       cout<<"invalid key"<<endl;
                   }
                   
               }
    
}
