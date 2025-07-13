#include <iostream>
#include <pthread.h>

#define product_M 4
#define product_N 6
#define P 2
//multiplying MxP and PxN matrices

#include <sys/time.h>

#define numberOfThreads (product_M*product_N)

using namespace std;

struct threadData{
    int row;
    int col;
};

int product[product_M][product_N];

int p_matrix1[product_M][P];
int p_matrix2[P][product_N];

int timeTaken[product_M][product_N];

void*productMatrixValues(void* args){
    threadData* data=(threadData*)args;
    int p_row=data->row;
    int p_col=data->col;
    
    delete data;

    int value=0;

    for (int i=0; i<P; i++){
        value+=p_matrix1[p_row][i]*p_matrix2[i][p_col];
    }
    product[p_row][p_col]=value;

    return nullptr;
  
}

int main(){
    cout<<"Enter values for first matrix of size "<<product_M<<" x "<<P<<endl;
    for (int i=0; i<product_M;i++){
        for (int j=0; j<P; j++){
            cin>>p_matrix1[i][j];
        }
    }

    cout<<"Enter values for second matrix of size "<<P<<" x "<<product_N<<endl;
    for (int i=0; i<P; i++){
        for (int j=0; j<product_N; j++){
            cin>>p_matrix2[i][j];
        }
    }
    
    pthread_t threads[numberOfThreads];

    int threadIndex = 0;
    for (int i = 0; i < product_M; i++) {
        for (int j = 0; j < product_N; j++) {
            threadData* thisThread = new threadData;
            thisThread->row = i;
            thisThread->col = j;
            pthread_create(&threads[threadIndex++], nullptr, productMatrixValues, thisThread);
        }
    }

    struct timeval start, end;
    gettimeofday(&start, nullptr);

    for (int i=0; i<numberOfThreads; i++){
        pthread_join(threads[i], nullptr);
    }

    gettimeofday(&end, nullptr);
    long long time_taken=end.tv_sec-start.tv_sec;

    cout << "Product Matrix:\n";
    for (int i = 0; i < product_M; i++) {
        for (int j = 0; j < product_N; j++) {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }


    cout<<"Total time taken by parallel processing is: "<<time_taken<<endl;
    return 0;

}



