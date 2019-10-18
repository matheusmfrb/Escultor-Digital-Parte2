#include "cutvoxel.h"
#include "Sculptor.h"

CutVoxel::CutVoxel(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

CutVoxel::~CutVoxel(){

}

void CutVoxel::draw(Sculptor &v){
    v.cutVoxel(x,y,z);
}
