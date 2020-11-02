#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    system("sudo python /home/pi/gpstranslate.py > /home/pi/output.txt");
    FILE *input=fopen("/home/pi/output.txt", "r");
    float x, y, z;
    fscanf(input,"%f %f %f", &x, &y, &z);
    double final_x, final_y;
    final_x=floor(x/100);
    final_y=floor(y/100);
    if(x==0.0&&y==0&&z==0)
    {
        return 0;
    }
    x-=final_x*100;
    y-=final_y*100;
    if(x==0.0&&y==0&&z==0)
    {
        return 0;
    }
    x-=final_x*100;
    y-=final_y*100;
    final_x+=x/60.0;
    final_y+=y/60.0;
    FILE *output=fopen("/home/pi/location.txt", "w");
    fprintf(output,"%f;\n%f;\n%f", final_y, final_x, z);
    fclose(output);
    fclose(input);
}

