#include "sclass2_10_cpoint.h"
CPoint::CPoint( float x1, float y1 )     {
	x = x1;
	y = y1;
}
void CPoint::Move(float x1, float y1){       
    x=x1;
	y=y1;
}
int main( ) { 
    CPoint *p= new CPoint[5];   // 声明一个对象数组
    for (int i=0;i <5;i++)     { 
        p[i].Move(i,i);   // 将数组下标为i的对象元素的横、
                                     //纵坐标值都设为i 
     } 
for (int i=0;i<5;i++)     {  	    
	cout <<p[i].x <<"," <<p[i].y <<endl;   // 输出数组的下标为i的
                                          //对象元素的横、纵坐标，
                                         // 因为数据成员x和y都是公有的访问权限，
		                  // 所以可以在类外由对象元素直接访问
    } 
    delete []p;                // 释放数组所占用的堆内存
    return 0; 
}

