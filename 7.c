#include <stdio.h>
#include <stdlib.h>



float * s_average(float ptr[][5], int m, int print)  //写float ** ptr，出错，实参 形参 类型不符
{
    int i, j;
    float sum;
    float * s_aver = (float *)malloc(m * sizeof(float));

    if(print == 1)
    {
        printf("average score of student:\n");
    }

    for(i = 0; i < m; i++)
    {
        sum = 0;

        for(j = 0; j < 5; j++)
        {
            sum = sum + ptr[i][j];
        }
 
        if(print == 1)
        {
            printf("student %d: %f\n", i, sum / 5);
        }
        
        s_aver[i] = sum / 5;
    }
    
    return s_aver;
}

    

void c_average(float ptr[][5], int m)
{
    int i, j;
    float sum;

    printf("average score of course:\n");
    
    for(j = 0; j < 5; j++)
    {
        sum = 0.0;

        for(i = 0; i < m; i++)
        {
            sum = sum + ptr[i][j];
        }
        printf("course %d: %f\n", j, sum / m);
    }
}

    
    
void max_score(float ptr[][5], int m)
{
    int i, j;
    int s_max = 0;
    int c_max = 0;
    
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(ptr[s_max][c_max] < ptr[i][j])
            {
                s_max = i;
                c_max = j;
            }
        }
    }

    printf("max score is %f, student is %d, score is %d\n", ptr[s_max][c_max], s_max, c_max );

}

    
    
float sigma(float ptr[][5], int m)
{
    int i;
    float * s_aver = s_average(ptr, m, 0);   
    float sum_1 = 0;
    float sum_2 = 0;
    float sgm;

    for(i = 0; i < m; i++)
    {
        sum_1 = sum_1 + s_aver[i];
        sum_2 = sum_2 + s_aver[i] * s_aver[i];
    }

    sgm = sum_2 / m - (sum_1 / m) * (sum_1 / m);

    printf("mean variance is %f\n", sgm);

    return sgm;
}



void xt_7_14()
{
    float score[10][5] = {{6, 5, 7 ,9, 7}, {8, 6 ,8, 7, 8}, {7, 9 ,6, 8, 7}, {5, 6 ,7, 6, 6}, {7, 9, 8, 7, 9}, {8, 8, 9, 7, 9}, {7, 6, 7, 6, 7}, {7, 8, 9, 7, 7}, {7, 6, 8, 6, 9}, {6, 9, 7, 6, 8}};

    s_average(score, 10, 1);
    c_average(score, 10);
    max_score(score, 10);
    sigma(score, 10);   
}



struct Clerk
{
    int num;
    char name[20];
};


void arr_create(struct Clerk * ptr, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &((ptr + i)->num) );
        scanf("%s", &((ptr + i)->name));
    }
    printf("\n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", (ptr + i)->num);
    }
    printf("\n");
    for(i = 0; i < n; i++)
    {
        printf("%s ", (ptr + i)->name);
    }
    printf("\n");
}



void xt_7_15()
{
    struct Clerk array[10];  
    arr_create(array, 10);
//    arr_sort(array, 10);
//    arr_search(016022);
}


int main()
{
//    xt_7_14();
    xt_7_15();
//    xt_7_16();
//    xt_7_17();
//    xt_7_18();
    
    return 0;
}
