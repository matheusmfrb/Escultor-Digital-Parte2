#include <cmath>
#include "putsphere.h"
#include "Sculptor.h"

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}

PutSphere::~PutSphere(){

}

void PutSphere::draw(Sculptor &v){
    for(int i=xcenter-radius;i<=xcenter+radius;i++){
        for(int j=ycenter-radius;j<=ycenter+radius;j++){
            for(int k=zcenter-radius;k<=zcenter+radius;k++){
                if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2)) <= pow(radius,2)){
                    v.setColor(r,g,b,a);
                    v.putVoxel(i,j,k);
                }
            }
        }
    }
}
