/* Implentation of userspace code on Angstronm using BBB */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
	FILE *pio,*pdir,*pval;
	FILE *rio,*rdir,*rval;
	FILE *gio,*gdir,*gval;
	FILE *bio,*bdir,*bval;

	pio=fopen("/sys/class/gpio/export", "w");
	fseek(pio,0,SEEK_SET);
	fprintf(pio,"%d",115);
	fflush(pio);
	fclose(pio);

	rio=fopen("/sys/class/gpio/export", "w");
	fseek(rio,0,SEEK_SET);
	fprintf(rio,"%d",60);
	fflush(rio);
	fclose(rio);

	gio=fopen("/sys/class/gpio/export", "w");
	fseek(gio,0,SEEK_SET);
	fprintf(gio,"%d",48);
	fflush(gio);
	fclose(gio);

	bio=fopen("/sys/class/gpio/export", "w");
	fseek(bio,0,SEEK_SET);
	fprintf(bio,"%d",49);
	fflush(bio);
	fclose(bio);
	
	
	

	pdir=fopen("/sys/class/gpio/gpio115/direction","w");
	fseek(pdir,0,SEEK_SET);
	fprintf(pdir,"in");
	fflush(pdir);
	fclose(pdir);

	rdir=fopen("/sys/class/gpio/gpio60/direction","w");
	fseek(rdir,0,SEEK_SET);
	fprintf(rdir,"out");
	fflush(rdir);
    
        gdir=fopen("/sys/class/gpio/gpio48/direction","w");
        fseek(gdir,0,SEEK_SET);
        fprintf(gdir,"out");
        fflush(gdir);
    
        bdir=fopen("/sys/class/gpio/gpio49/direction","w");
        fseek(bdir,0,SEEK_SET);
    	fprintf(bdir,"out");
    	fflush(bdir);

    	rval=fopen("/sys/class/gpio/gpio60/value","w");
    	fseek(rval,0,SEEK_SET);
    	gval=fopen("/sys/class/gpio/gpio48/value","w");
    	fseek(gval,0,SEEK_SET);
    	bval=fopen("/sys/class/gpio/gpio49/value","w");
    	fseek(bval,0,SEEK_SET);

volatile int pir_val;
while(1)
{
	
	fprintf(gval,"%d",0);
	fflush(gval);
	fprintf(rval,"%d",1);
	fflush(rval);
	if(rval)             //Checking if red light is glowing 
	{
	pval=fopen("/sys/class/gpio/gpio115/value","r");
	fseek(pval,0,SEEK_SET);
	fscanf(pval,"%d",&pir_val);
		if(pir_val)   //checking vehicle motion detected
		{
	          printf("PIR_sensor_value = %d\n",pir_val);
	          printf("Vehicle detected = %d\n",pir_val);
	          printf("Red Light ON: Stop Traffic rules violated\n");
	        }
	        else
	        {
	        printf("PIR_sensor_value=%d\n",pir_val);
	        printf("No vehicle detected\n");
	        }        
	sleep(5);
	}
	
	fprintf(rval,"%d",0);
	fflush(rval);
	fprintf(bval,"%d",1);
	fflush(bval);
	if(bval)        //Checking if blue light is glowing 
	{
	pval=fopen("/sys/class/gpio/gpio115/value","r");
	fseek(pval,0,SEEK_SET);
	fscanf(pval,"%d",&pir_val);
		if(pir_val)  //checking vehicle motion detected
		{
		printf("PIR_sensor_value=%d\n",pir_val);
		printf("Blue Light ON: Please stop!..Get ready\n");
	        }
	        else
	        {
	        printf("PIR_sensor_value=%d\n",pir_val);
	        printf("Blue light ON:slow down\n");
	        }
	sleep(5);
	}
	
	fprintf(bval,"%d",0);
	fflush(bval);
	fprintf(gval,"%d",1);
	fflush(gval);
	if(gval)  //Checking if green light is glowing 
	{
	pval=fopen("/sys/class/gpio/gpio115/value","r");
	fseek(pval,0,SEEK_SET);
	fscanf(pval,"%d",&pir_val);
	printf("PIR_sensor_value=%d\n",pir_val);
	printf("Green Light ON: Keep moving\n"); 
	sleep(5);
	}
fflush(pval);
}
return 0;
}
	

