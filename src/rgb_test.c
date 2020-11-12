#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
	FILE *rio,*rdir,*rval;
	FILE *gio,*gdir,*gval;
	FILE *bio,*bdir,*bval;

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
    
while(1)
{
	fprintf(gval,"%d",0);
	fflush(gval);
	fprintf(rval,"%d",1);
	fflush(rval);
	printf("Green Light ON: Keep moving\n");
	sleep(5);
	
	fprintf(rval,"%d",0);
	fflush(rval);
	fprintf(bval,"%d",1);
	fflush(bval);
	printf("Blue Light ON: Get Ready!..Wait for green signal\n");
	sleep(5);
	
	fprintf(bval,"%d",0);
	fflush(bval);
	fprintf(gval,"%d",1);
	fflush(gval);
	printf("Red Light ON: Please Stop. Traffic rules violated\n");
	sleep(5);
	
}
return 0;
}
