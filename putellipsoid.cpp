#include <cmath>
#include "putellipsoid.h"
#include "Sculptor.h"

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->rx=rx;
    this->ry=ry;
    this->rz=rz;
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}

PutEllipsoid::~PutEllipsoid(){

}

void PutEllipsoid::draw(Sculptor &v){
    for(int i=xcenter;i<=rx;i++){
        for(int j=ycenter;j<=ry;j++){
            for(int k=zcenter;k<=rz;k++){
                if(1.0*(double((pow(((i-xcenter)/(rx*1.0)),2)+pow(((j-ycenter)/(ry*1.0)),2)+pow(((k-zcenter)/(rz*1.0)),2)))) <= 1.0){
                    v.setColor(r,g,b,a);
                    v.putVoxel(i,j,k);
                }
            }
        }
    }
}
