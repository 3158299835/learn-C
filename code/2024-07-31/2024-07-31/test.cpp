#define _CRT_SECURE_NO_WARNINGS

//宏的探索


//#
//#include <stdio.h>
//
//#define PRINTF(N) printf("我是"#N"\n")
//
//int main()
//{
//	PRINTF(小明);
//	PRINTF(小红);
//	PRINTF(小刘);
//
//	return 0;
//}


//##
//#include <stdio.h>
//
//#define ABC(A,B) A##B
//
//int main()
//{
//	int abc = 1000;
//	printf("%d\n", ABC(a, bc));
//	//这里的传入的a和bc被##合并成一个符号了
//	//等同于printf("%d\n",abc));
//	return 0;
//}



//条件编译

//#include <stdio.h>
//
//#define DEBUG1
////#define DEBUG2
//
//int main()
//{
//#ifdef DEBUG1 
//	printf("你好\n");
//#endif // DEBUG
//
//#ifdef DEBUG2
//	printf("世界\n");
//#endif // DEBUG
//
//	return 0;
//}


////单片机中经常实用的
//#ifndef __NAME__//如果NAME没有被定义，那么就执行中间的 定义然后一些函数
////如果被定义了。那么#ifndef __NAME__为假。 就可以不被重复定义！！！
//#define __NAME__
//
////这里函数的声明
//int xxxx(int x, int y);
//
//
//#endif // 

