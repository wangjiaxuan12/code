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
    CPoint *p= new CPoint[5];   // ����һ����������
    for (int i=0;i <5;i++)     { 
        p[i].Move(i,i);   // �������±�Ϊi�Ķ���Ԫ�صĺᡢ
                                     //������ֵ����Ϊi 
     } 
for (int i=0;i<5;i++)     {  	    
	cout <<p[i].x <<"," <<p[i].y <<endl;   // ���������±�Ϊi��
                                          //����Ԫ�صĺᡢ�����꣬
                                         // ��Ϊ���ݳ�Աx��y���ǹ��еķ���Ȩ�ޣ�
		                  // ���Կ����������ɶ���Ԫ��ֱ�ӷ���
    } 
    delete []p;                // �ͷ�������ռ�õĶ��ڴ�
    return 0; 
}

