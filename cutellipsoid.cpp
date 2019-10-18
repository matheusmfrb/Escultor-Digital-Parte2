#include <cmath>
#include "cutellipsoid.h"
#include "Sculptor.h"

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->rx=rx;
    this->ry=ry;
    this->rz=rz;
}

CutEllipsoid::~CutEllipsoid(){

}

void CutEllipsoid::draw(Sculptor &v){
    for(int i=xcenter;i<=rx;i++){
        for(int j=ycenter;j<=ry;j++){
            for(int k=zcenter;k<=rz;k++){
                if(1.0*(double((pow(((i-xcenter)/(rx*1.0)),2)+pow(((j-ycenter)/(ry*1.0)),2)+pow(((k-zcenter)/(rz*1.0)),2)))) <= 1.0){
                    v.cutVoxel(i,j,k);
                }
            }
        }
    }
}
