#include <stdio.h>

void separate (double num,
               char *signp,
               int *wholep,
               double *fracp);

int main (){
    double num = -25.12;
    char signp;
    int wholep;
    double fracp;
    separate(num, &signp, &wholep, &fracp);


}
{
if (num < 0)
    *signp = '-';
else if (num == 0)
    *signp = ' ';
else
    *signp = '+';
double magnitude = fabs(num);
*wholep = floor(magnitude);
*fracp = magnitude - *wholep;
}
