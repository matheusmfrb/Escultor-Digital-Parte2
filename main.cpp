#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Voxel.h"
#include "Sculptor.h"
#include "figurageometrica.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"


using namespace std;

int main(){
    Sculptor *f;
    vector <FiguraGeometrica*> v;
    ifstream arquivo("escultor.txt");
    string s, aux;
    stringstream ss;
    int nx=1, ny=1, nz=1;
    if(arquivo.is_open()){
        while(!arquivo.eof()){
            getline(arquivo,s);
            ss << s;
            ss >> aux;
            if(aux.compare("dim")==0){
                ss >> nx >> ny >> nz;
                f=new Sculptor(nx,ny,nz);
            }
            else if(aux.compare("putvoxel")==0){
                int x,y,z;
                float r,g,b,a;
                ss >> x >> y >> z;
                ss >> r >> g >> b >> a;
                v.push_back(new PutVoxel(x,y,z,r,g,b,a));
            }
            else if(aux.compare("cutvoxel")==0){
                int x,y,z;
                ss >> x >> y >> z;
                v.push_back(new CutVoxel(x,y,z));
            }
            else if(aux.compare("putbox")==0){
                int x0,x1,y0,y1,z0,z1;
                float r,g,b,a;
                ss >> x0 >> x1 >> y0 >>y1 >> z0 >> z1;
                ss >> r >> g >> b >> a;
                v.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
            }
            else if(aux.compare("cutbox")==0){
                int x0,x1,y0,y1,z0,z1;
                ss >> x0 >> x1 >> y0 >>y1 >> z0 >> z1;
                v.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
            }
            else if(aux.compare("putsphere")==0){
                int xcenter,ycenter,zcenter,radius;
                float r,g,b,a;
                ss >> xcenter >> ycenter >> zcenter >> radius;
                ss >> r >> g >> b >> a;
                v.push_back(new PutSphere(xcenter,ycenter,zcenter,radius,r,g,b,a));
            }
            else if(aux.compare("cutsphere")==0){
                int xcenter,ycenter,zcenter,radius;
                ss >> xcenter >> ycenter >> zcenter >> radius;
                v.push_back(new CutSphere(xcenter,ycenter,zcenter,radius));
            }
            else if(aux.compare("putellipsoid")==0){
                int xcenter,ycenter,zcenter,rx,ry,rz;
                float r,g,b,a;
                ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                ss >> r >> g >> b >> a;
                v.push_back(new PutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz,r,g,b,a));
            }
            else if(aux.compare("cutellipsoid")==0){
                int xcenter,ycenter,zcenter,rx,ry,rz;
                ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                v.push_back(new CutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz));
            }
        }
    }else{
        cout << "Houve um erro ao abrir o arquivo!" << endl;
    }
    Sculptor figura(nx,ny,nz);
    for(int i=0;i<int(v.size());i++){
        v[i]->draw(figura);
    }
    figura.writeOFF("escultor.off");
    return 0;
}
