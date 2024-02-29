#ifndef __SCLASS2_10_CPOINT_H__ 
#define __SCLASS2_10_CPOINT_H__ ?
#include <iostream>
using namespace std;
class CPoint{ 
public:
	 CPoint( ){} 
	~CPoint( ){} 
	CPoint( float x1, float y1 );    
	void Move(float x1, float y1);   	
	float x;  
	float y;
};
#endif

