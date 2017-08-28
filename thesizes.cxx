#include <stdio.h>

int main(void)
{
	printf ("char %d, short %d, int %d, long %d, float %d, double %d, void* %llu",sizeof(char),sizeof(short),sizeof(int),sizeof(float),sizeof(double),sizeof(void *));
	return 0;
}
/* 在windows764bit 上，分别用gcc和clang编译，
 * gcc编译的结果是char 1, short 2, int 4, long 4, float 8, double 4, void* 2130567168
 * clang编译的结果是char 1, short 2, int 4, long 4, float 8, double 8, void* 5361642412
 * 两个问题：
 * 1. gcc double 比 float 所用的空间更小，精度也应该更低
 * 2. 两个编译器得到的 指针类型的大小到底是几个字节
*/
