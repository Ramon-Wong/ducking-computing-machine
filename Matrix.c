#include "Matrix.h"
 
 
 

void MLoadIdentity(float * mat){
    float   M[16] = { 1.0, 0.0, 0.0, 0.0,
                      0.0, 1.0, 0.0, 0.0,
                      0.0, 0.0, 1.0, 0.0,
                      0.0, 0.0, 0.0, 1.0 };
 
    memcpy( mat, M, sizeof(float[16]));
}
 
 
void _MFrustum(float * Mat, float Left, float Right, float Bottom, float Top, float Near, float Far){
    float RL    = 1 / (Right - Left);  
    float TB    = 1 / (Top - Bottom);
    float NF    = 1 / (Near - Far);
     
    Mat[0]  = (Near * 2) * RL;
    Mat[1]  = 0.0f;
    Mat[2]  = 0.0f;
    Mat[3]  = 0.0f;
    Mat[4]  = 0.0f;
    Mat[5]  = (Near * 2) * TB;
    Mat[6]  = 0.0f;
    Mat[7]  = 0.0f;
    Mat[8]  = (Right + Left) * RL;
    Mat[9]  = (Top + Bottom) * TB;
    Mat[10] = (Far + Near) * NF;
    Mat[11] = -1.0f;
    Mat[12] = 0.0f;
    Mat[13] = 0.0f;
    Mat[14] = (Far * Near * 2) * NF;
    Mat[15] = 0.0f;
}
 
 
void _MMultiply(float * Mat, float * Mat1, float * Mat2){
     
    int i;
    float Result[16];
     
    for(i = 0; i < 4; i++){
        Result[i * 4]     = (Mat2[i*4] * Mat1[0]) + (Mat2[i*4+1] * Mat1[4]) + (Mat2[i*4+2] * Mat1[8])  + (Mat2[i*4+3] * Mat1[12]);
        Result[i * 4 + 1] = (Mat2[i*4] * Mat1[1]) + (Mat2[i*4+1] * Mat1[5]) + (Mat2[i*4+2] * Mat1[9])  + (Mat2[i*4+3] * Mat1[13]);
        Result[i * 4 + 2] = (Mat2[i*4] * Mat1[2]) + (Mat2[i*4+1] * Mat1[6]) + (Mat2[i*4+2] * Mat1[10]) + (Mat2[i*4+3] * Mat1[14]);
        Result[i * 4 + 3] = (Mat2[i*4] * Mat1[3]) + (Mat2[i*4+1] * Mat1[7]) + (Mat2[i*4+2] * Mat1[11]) + (Mat2[i*4+3] * Mat1[15]);
    }
    memcpy(Mat, Result, sizeof(float[16]));
}
 
 
void _MTranslate(float * Result, float x, float y, float z){
    Result[12] += (Result[0] * x + Result[4] * y + Result[8]  * z);
    Result[13] += (Result[1] * x + Result[5] * y + Result[9]  * z);
    Result[14] += (Result[2] * x + Result[6] * y + Result[10] * z);
    Result[15] += (Result[3] * x + Result[7] * y + Result[11] * z);
}
 
 
void _LookAtM( float * Mat, float * Pose, float * View, float * UpVx){
     
    float X[3], Y[3], Z[3];
                         
    Z[0] = View[0] - Pose[0];
    Z[1] = View[1] - Pose[1];
    Z[2] = View[2] - Pose[2];
     
    _Normalize(Z);
         
    _CrossProduct( X, UpVx, Z); //   Compute cross product of UpVx, Z
    _Normalize(X);
     
    _CrossProduct( Y, Z, X);        // reCompute vector Y
    _Normalize(Y);
 
    Mat[0]  = X[0];	Mat[4]  = X[1];	Mat[8]  = X[2];
    Mat[1]  = Y[0];	Mat[5]  = Y[1];	Mat[9]  = Y[2];
    Mat[2]  = Z[0];	Mat[6]  = Z[1];	Mat[10] = Z[2];
    Mat[3]  = 0.0;	Mat[7]  = 0.0;	Mat[11] = 0.0;
     
    _MTranslate( Mat, -View[0], -View[1], -View[2]);
}


void _CrossProduct(float * Result, float * Vec1, float * Vec2){
     
    Result[0] = Vec1[1] * Vec2[2] - Vec1[2] * Vec2[1];
    Result[1] = Vec1[2] * Vec2[0] - Vec1[0] * Vec2[2];
    Result[2] = Vec1[0] * Vec2[1] - Vec1[1] * Vec2[0];
}
 
 
void _Normalize(float * Vec){
     
    float Magnitude =  sqrt(Vec[0] * Vec[0] + Vec[1] * Vec[1] + Vec[2] * Vec[2]);
    Vec[0] /= Magnitude;
    Vec[1] /= Magnitude;
    Vec[2] /= Magnitude;
}
