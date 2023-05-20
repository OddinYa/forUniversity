clear;

[x,y,xi] = myInput();

clc;

[yi] = interpolation(x,y,xi);

myOut(x,y,xi,yi);

