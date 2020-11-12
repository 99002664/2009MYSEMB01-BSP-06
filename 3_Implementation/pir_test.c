#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
    FILE *pio,*pdir,*pval;

    pio=fopen("/sys/class/gpio/export", "w");
    fseek(pio,0,SEEK_SET);
    fprintf(pio,"%d",115);
    fflush(pio);
    fclose(pio);

    pdir=fopen("/sys/class/gpio/gpio115/direction","w");
    fseek(pdir,0,SEEK_SET);
    fprintf(pdir,"in");
    fflush(pdir);
    fclose(pdir);

volatile int pir_val;
while(1)
{
    pval=fopen("/sys/class/gpio/gpio115/value","r");
    fseek(pval,0,SEEK_SET);

    fscanf(pval,"%d",&pir_val);
    if(pir_val)
    {
      printf("pir val = %d\n",pir_val);
      sleep(2);
    }
    else 
    {
      printf("pir val = %d\n",pir_val);
      sleep(2);
    }
    fflush(pval);
}
return 0;
}
	
