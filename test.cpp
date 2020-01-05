#include<iostream>
#include"car.hpp"

#define w_h = 9
#define W_w = 9
int main(){
    int p[2] = {0,0};
    int v[2] = {0, 1};
    int w[4][4] = {{0,0,0,0}, {0,0,0,0},{0,0,0,0},{0,0,0,0}};
    Car c(p, v, w);
    c.updateWorld();
    c.move();
    c.move();
    return 0;
}