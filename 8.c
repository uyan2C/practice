#include <stdio.h>
#include <stdlib.h>         //malloc



void arg_num(int num, int n)            //num 为argc，n 为 数组元素个数
{
	if(n != num - 1)                                    //?容错能力，多的取前几位
	{
		printf("请输入%d个数\n", n);
	}
}



void arr_print(int a[], int n)                    //打印数组   通常数组在前，长度在后
{
	int i;

	for(i = 0; i < n; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
}



int eg_8_1()     //通过 指针变量 访问 整型变量
{
	int a = 9, b = 10;
	int * pointer_1, *pointer_2;          //定义  分开写？or连着写？

	pointer_1 = &a;
	pointer_2 = &b;
	
	printf("a = %d, b = %d\n", a, b);
	printf("*pointer_1 = %d, *pointer_2 = %d\n", *pointer_1, *pointer_2);

	return 0;
}



int eg_8_2(int a, int b)          //两整数，先大后小 顺序输出
{
	int * p1 = &a;
	int * p2 = &b;
	int * temp;

	if(a < b)
	{
		temp = p2;
		p2 = p1;
		p1= temp;
	}
	
	printf("%5d %5d\n", *p1, * p2);

	return 0;
}



int str_num(char * str)                   //字符串 转换成 数字
{
	int num = 0;
	int i = 0;

	while(str[i] != 0)
	{
		num = num * 10 + (str[i] - '0' + 0);
		i++;
	}

	return num;
}


void swap(int * p1, int * p2)               //交换两个变量的值
{
	int temp;                     //temp前 加* 段错误
	
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}



void exchange(int * p1, int * p2, int * p3)   //交换3个变量的值    大小顺序 输出             //int * p; *p = 3;  会不会出错？
{
	if(*p1 < *p2)
	{
		swap(p1, p2);
	}

	if(*p1 < * p3)
	{
		swap(p1, p3);
	}

	if(*p2 < *p3)
	{
		swap(p2, p3);
	}
}



void eg_8_5(char * * str)
{
	int a = str_num(str[1]);
	int b = str_num(str[2]);
	int c = str_num(str[3]);	
	
	printf("a = %d b = %d ", a, b);
	printf("c = %d\n", c);

	exchange(&a, &b, &c);
	
	printf("a = %d b = %d ", a, b);
	printf("c = %d\n", c);

}



int * eg_8_6(char * * str, int n)                          //从main函数参数 获取 数组a[] 元素
{
	int i;	
	
/*	if(num < 12)
	{
		printf("Please input 10 numbers.\n");
		return;
	}
*/	
	int * ptr = (int *)malloc(n * sizeof(int));
	
	if(ptr != NULL)
	{
		for(i = 0; i < n; i++)
		{
			ptr[i] = str_num(str[i]);   //本质上时个数组，用下标法访问  如ptr[i]
		}
	}

	return ptr;

/*	int a[10];
	int * p = a;
	
	for(i = 0; i < 10; i++)
	{
		
	
		a[i] = str_num(str[i + 1]);
		printf("a[%2d] = %3d   ", i, a[i]);
		printf("*(p + %d) = %3d\n", i, *(p + i));
	}
*/
	

}



void inv(int * arr, int n)     //实现交换
{
	int i;
	int j = n - 1;

	for(i = 0; i < n; i++)
	{
		if((i == j) || (i > j))
		{
			break;
		}
		else
		{
			swap(arr + i, arr + j);
			j--;
		}
	}


/*	int i;
	int j = n - 1;
	
	if(arr != NULL)	
	{
		for(i = 0; i < n; i++)
		{
			swap(arr + i, arr + j);//(arr[i], arr[j]);		
			
			if((i == (j - 1)) || (i == j))	
			{
				break;
			}
			else
			{
				j--;
			}
		}
	}
*/	
}



void eg_8_8(char * * str, int num)
{
	int * arr = eg_8_6(str, num);    //int * arr = eg_8_6(str + 1， num);                            //数组a[10]  不能写int a[10] = eg_8_6(...);

	arr_print(arr, num);
	inv(arr, num);                                
	arr_print(arr, num);
}



void bubble_sort(int a[], int n)
{
	int i;
	int j;
	
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - 1 - i; j++)
		{
			if(a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}



int arr_max(int arr[], int n)
{
	int i;
	int max = arr[0];

	for(i = 1; i < n; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
	}
	
	return max;						/*	for(i = 0; i < n; i++)
									{
										if(max == arr[i])
										{
											return i;
										}
									}
								*/
}



void sort(int arr[], int n)
{
	int i;
	int j;
	int max;

	for(i = 0; i < n - 1; i++)
	{
		max = arr_max(arr + i, n - i);	
		if(max == arr[i])
		{
			continue;
		}
			
		for(j = i + 1; j < n; j++)	
		{
			if(max == arr[j])
			{
				swap(arr + i, arr + j);
			}
		}
	}
}



void eg_8_10(char ** str, int num)
{
	int * arr = eg_8_6(str, num);
	
	arr_print(arr, num);
//	bubble_sort(arr, num);                                
//	arr_print(arr, num);
	
//	inv(arr, num);
//	arr_print(arr, num);
	sort(arr,num);
	arr_print(arr, num);

}



int main(int argc, char * argv[])                             //argc 的作用？
{ 
	eg_8_10(argv + 1, argc - 1);
		
//	eg_8_8(argv + 1, argc - 1);
	
//	eg_8_6(argc, argv);
	
	//eg_8_5(argv);	

	/*eg_8_1();*/
	
//	eg_8_2(a,b);                      //argv[0] 是 "./a.out"

//	swap(&a, &b);
		
	//printf("%d\n", num);

	return 0;      //main函数中不写 此行 会怎样？  编译未报错
}
