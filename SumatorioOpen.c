#include <omp.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    int i;

    float sum = 0;

    
    float threadSum[8];
    omp_set_num_threads(8);
    double t1, t2;

    #pragma omp parallel    
    {
        int ID = omp_get_thread_num();
        threadSum[ID] = 0;
        //printf("Thread %d says: Hello World\n", ID);
        t1 = omp_get_wtime();

        #pragma omp for
            for(i = 1; i<=10000;i++){    
                threadSum[ID] += ((float)i/10000);
                //printf("hello");
            }
        
        #pragma omp critical
            //printf("%f\n", threadSum[ID]);
            sum += threadSum[ID];
        t2 = omp_get_wtime();
    }

    printf("%Lf\n Parallel execution time = %f seconds\n", sum, t2 - t1);
    double t3 = omp_get_wtime();

    float secuentialI = 0;
    
    for (float j = 1; j <= 10000; j++)
    {
        secuentialI += (j/10000);
        //printf("hello");
    }
    double t4 = omp_get_wtime();
    printf("%Lf\n Secuential execution time = %f seconds\n", secuentialI,t4-t3);

    return 0;
}
