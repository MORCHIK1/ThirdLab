#include <stdio.h>
#include <math.h>
#include <stdlib.h>

    struct sectors{
    float x, y, R, angle, S;
    };
    typedef struct sectors cir;

float getS(int, cir*);
float create_arr(int*, cir**);
float input_struct(int, cir*);
float sort_arr(int, cir*);
float output_arr(int, cir*);

void main(){
    cir* ci;
    int i,n,j;
    float temp;
    create_arr(&n,&ci);
    if(ci){
        input_struct(n,ci);
        sort_arr(n,ci);
        output_arr(n,ci);
    }
    if(!ci) printf("Memory allocation failed");
}


float create_arr(int* n, cir** ci){
    printf("Input n:");
    scanf("%d",n);
   
    *ci=malloc(*n * sizeof(cir));
}
float input_struct(int n, cir* ci){
    int i;
    for(i=0; i<n; i++){
        scanf("%f %f %f %f",&ci[i].x, &ci[i].y,&ci[i].R,&ci[i].angle);
    }
}

float getS(int k, cir* ci){
    return ci[k].R*ci[k].R*ci[k].angle/M_PI;
}

float sort_arr(int n,cir* ci){
    int i,j;
    float temp;
    for(i=0; i<n; i++)ci[i].S=getS(i,ci);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(ci[i].S<ci[j].S){
                temp=ci[i].S;
                ci[i].S=ci[j].S;
                ci[j].S=temp;
            }
        }
    }
}

float output_arr(int n, cir* ci){
    int j;
    for(j=0; j<n; j++)printf("%f\n",ci[j].S);
}