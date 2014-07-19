#ifndef _MATRIX_H
#define _MATRIX_H
 
#include <assert.h>
#include <string.h>
#include <math.h>
 
 
#define		PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
 
 
void         MLoadIdentity(float*);
 
void        _MFrustum(float *, float, float, float, float, float, float);
void        _MMultiply(float *, float *, float *);
void        _LookAtM( float *, float *, float *, float *);
 
void        _MTranslate(float * Result, float x, float y, float z);
 
void        _CrossProduct(float *, float *, float *);
void        _Normalize(float *);
 
 
 

 //~ http://stackoverflow.com/questions/21980947/replacement-for-gl-position-gl-modelviewprojectionmatrix-gl-vertex
 
#endif
