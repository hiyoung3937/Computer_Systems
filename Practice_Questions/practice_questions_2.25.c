#include<stdio.h>

//当length等于0时应当返回result值为0，但实际上运行会遇到一个内存错误，请问该如何修改代码
float sum_element(float a[] , unsigned length){
    int i;
    float result=0;

    for ( i = 0; i <= length-1; i++)
    {
        result += a[i];
    }
    
    return result;
}

//问题分析，这里的length是unsigned类型，当length=0时，length-1=-1，
//在unsigned中为Umax，代码将访问数组中的非法元素
float sum_element_right(float a[] , int length) //方法1：将unsigned改为int
{
    int i;
    float result=0;

    for ( i = 0; i < length; i++) //方法2：改为i < length
    {
        result += a[i];
    }
    
    return result;
}

int main(void)
{
    float arr[3]={1.1,2.2,3.3};

    printf("%f\n",sum_element(arr,0));//test
    printf("%f\n",sum_element_right(arr,0));//test

    return 0;
}

