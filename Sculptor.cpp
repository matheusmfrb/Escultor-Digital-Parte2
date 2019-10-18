#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include "Sculptor.h"
#include "Voxel.h"

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx=_nx; ny=_ny; nz=_nz;
    v = new Voxel**[nz];
    for(int i=0;i<nx;i++){
        v[i] = new Voxel*[nx];
        for(int j=0;j<ny;j++){
            v[i][j] = new Voxel[ny];
            for(int k=0;k<nz;k++){
                v[i][j][k].isOn = false;
            }
        }
    }
}

Sculptor::~Sculptor(){
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            delete [] v[i][j];
        }
        delete [] v[i];
    }
    delete [] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    this->r=r;
    this->g=g;
    this->b=b;
    a=alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::writeOFF(string filename){
    int vertices=0, faces=0;
    ofstream arquivo;
    int aux=0;
    arquivo.open(filename);
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn==true){
                    vertices+=8;
                    faces+=6;
                }
            }
        }
    }
    if(arquivo.is_open()){
        cout << "O arquivo foi aberto!" << endl;
        arquivo << fixed << setprecision(1) << endl;
        arquivo << "OFF" << endl;
        arquivo << vertices << " " << faces << " " << 0 << endl;
        for(int i=0;i<nx;i++){
            for(int j=0;j<ny;j++){
                for(int k=0;k<nz;k++){
                    if(v[i][j][k].isOn==true){
                        arquivo << i-0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                        arquivo << i-0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                        arquivo << i+0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                        arquivo << i+0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                        arquivo << i-0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                        arquivo << i-0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                        arquivo << i+0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                        arquivo << i+0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                    }
                }
            }
        }
        for(int i=0;i<nx;i++){
            for(int j=0;j<ny;j++){
                for(int k=0;k<nz;k++){
                    if(v[i][j][k].isOn==true){
                        arquivo << "4 " << 0+(aux*8) << " " << 3+(aux*8) << " " << 2+(aux*8) << " " << 1+(aux*8) << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                        arquivo << "4 " << 4+(aux*8) << " " << 5+(aux*8) << " " << 6+(aux*8) << " " << 7+(aux*8) << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                        arquivo << "4 " << 0+(aux*8) << " " << 1+(aux*8) << " " << 5+(aux*8) << " " << 4+(aux*8) << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                        arquivo << "4 " << 0+(aux*8) << " " << 4+(aux*8) << " " << 7+(aux*8) << " " << 3+(aux*8) << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                        arquivo << "4 " << 3+(aux*8) << " " << 7+(aux*8) << " " << 6+(aux*8) << " " << 2+(aux*8) << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                        arquivo << "4 " << 1+(aux*8) << " " << 2+(aux*8) << " " << 6+(aux*8) << " " << 5+(aux*8) << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                        aux++;
                    }
                }
            }
        }
    }else{
        cout << "Houve um erro ao abrir o arquivo!" << endl;
    }
    arquivo.close();
}
