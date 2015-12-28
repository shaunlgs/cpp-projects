#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <cmath>
#include <cstdlib>
#define PI 3.1416

using namespace std;

float Theory (float r, float c);
float Error (float Measured,float Theored);
float AbsError(float Measured,float Theored);
float PercentAbsError(float abserror,float actual);

int main()
{
    FILE *fp1;
	fp1 = fopen("sound3.txt","r");
	FILE *fp2;
	fp2 = fopen("result.txt","w");

    char text[10]; 
    int r, c;
    float x[10], y[30], mea[30][10];
    
    // scan data
    char st[2];
	
	float table[25][9];
	float num;
	float Ttheory[25][9];
	float Terror[25][9];
	float Tabspercerror[25][9];
	float Tabserror[25][9];

	
	/*Scan data*/
	for (r=0; r<=24; ++r)
	{
		for (c=0; c<=8; ++c)
		{
			if (r==0 && c==0)
			{
				fscanf(fp1,"%s",&st);
			}
			else
			{
                fscanf(fp1,"%f",&table[r][c]);
            }
		}	
	}
	
	// a) print the reprint of the data from the measurements
	printf("Measurement Values");
	printf("\n");
	fprintf(fp2,"Measurement Values");
	fprintf(fp2,"\n");
	for (r=0; r<=24; ++r)
	{
		for (c=0; c<=8; ++c)
		{
			if (r==0 && c==0)
			{
                     printf("%s", st);     
				fprintf(fp2,"%s", st);
			}
			else
			{
                printf("%6.2f",table[r][c]);
                fprintf(fp2,"%6.2f",table[r][c]);
            }
            printf("\t");
            fprintf(fp2, "\t");
		}
        printf("\n");	
        fprintf(fp2, "\n");	
	}
	printf("\n\n");
	fprintf(fp2, "\n\n");
	
	
	/*Value for Theoretical*/
	for (r=0; r<=24; ++r)
	{
		for (c=0; c<=8; ++c)
		{
			
			if (r==0 && c==0)
			{
			}
			else if (r==0 || c == 0)
			{}
            else     {
                    Ttheory[r][c]=Theory(table[r][0],table[0][c]); 
                 }
			
		}	
	}
	
	// b) print the theoretical values of the sound pressure level at each coordinate
	printf("Theoretical Values");
	printf("\n");
	fprintf(fp2,"Theoretical Values");
	fprintf(fp2,"\n");
    for (r=0; r<=24; ++r)
	{
		for (c=0; c<=8; ++c)
		{
			if (r==0 && c==0)
			{
				printf("%s", st);
				fprintf(fp2,"%s", st);
			}
			else if (r==0 || c == 0)
			{
                 // this is for y and x values
                 printf("%6.2f",table[r][c]);
                 fprintf(fp2,"%6.2f",table[r][c]);
                 }
			else
			{
                // print theoretical values
                printf("%6.2f",Ttheory[r][c]);
                fprintf(fp2,"%6.2f",Ttheory[r][c]);
            }
            printf("\t");
            fprintf(fp2, "\t");
		}
        printf("\n");	
        fprintf(fp2, "\n");	
	}
	printf("\n\n");
	fprintf(fp2, "\n\n");
	
	/*Value of error*/
	for (r=0; r<=24; ++r)
	{
		for (c=0; c<=8; ++c)
		{
			
			if (r==0 && c==0)
			{
			}
			else if (r==0 || c == 0)
			{
                 }
			else
			Terror[r][c]=Error(table[r][c],Ttheory[r][c]);
		}	
	}
	
	// c) print the error of each measurement compared to the theoretical value
	printf("Error Values");
	printf("\n");
	fprintf(fp2,"Error Values");
	fprintf(fp2,"\n");
	for (r=0; r<=24; ++r)
	{
		for (c=0; c<=8; ++c)
		{
			if (r==0 && c==0)
			{
				printf("%s", st);
				fprintf(fp2,"%s", st);
			}
			else if (r==0 || c == 0)
			{
                 // this is for y and x values
                 printf("%6.2f",table[r][c]);
                 fprintf(fp2,"%6.2f",table[r][c]);
                 }
			else
			{
                // print theoretical values
                printf("%6.2f",Terror[r][c]);
                fprintf(fp2,"%6.2f",Terror[r][c]);
            }
            printf("\t");
            fprintf(fp2, "\t");
		}
        printf("\n");
        fprintf(fp2, "\n");	
	}
	printf("\n\n");
	fprintf(fp2, "\n\n");
	
	/*Value of absolute error*/
	for (r=0; r<=24; ++r)
	{
		for (c=0; c<=8; ++c)
		{
			
			if (r==0 && c==0)
			{
			}
			else if (r==0 || c == 0)
			{
                 }
			else
			Tabserror[r][c]=AbsError(table[r][c],Ttheory[r][c]);
		}	
	}
	
	/*Value of absolute percent error*/
	for (r=0; r<=24; ++r)
	{
		for (c=0; c<=8; ++c)
		{
			
			if (r==0 && c==0)
			{
			}
			else if (r==0 || c == 0)
			{
                 }
			else
			Tabspercerror[r][c]=PercentAbsError(Tabserror[r][c],Ttheory[r][c]);
		}	
	}
	
	// d) print the percentage of absolute error of each measurement
	printf("Absolute Percent Error");
	printf("\n");
	fprintf(fp2,"Absolute Percent Error");
	fprintf(fp2,"\n");
	for (r=0; r<=24; ++r)
	{
		for (c=0; c<=8; ++c)
		{
			if (r==0 && c==0)
			{
				printf("%s", st);
				fprintf(fp2,"%s", st);
			}
			else if (r==0 || c == 0)
			{
                 // this is for y and x values
                 printf("%6.2f",table[r][c]);
                 fprintf(fp2,"%6.2f",table[r][c]);
                 }
			else
			{
                // print theoretical values
                printf("%6.2f",Tabspercerror[r][c]);
                fprintf(fp2,"%6.2f",Tabspercerror[r][c]);
            }
            printf("\t");
            fprintf(fp2, "\t");
		}
        printf("\n");
        fprintf(fp2, "\n");	
	}
	printf("\n\n");
	fprintf(fp2, "\n\n");
	
		
	/*Finding Max Error*/
	float max,xmax,ymax;

	for (r=1; r<=24; ++r)
	{
		for (c=1; c<=8; ++c)
		{
			
			if (r==0 && c==0)
			{
			}
			else if (r==0 || c == 0)
			{
                 }
			else if(max<Terror[r][c])
			{
			max=Terror[r][c];
			ymax=table[r][0];
			xmax=table[0][c];
		}
		}	
	}
	
  /*Finding Min Error*/
	float min,xmin,ymin;
	
	for (r=1; r<=24; ++r)
	{
		for (c=1; c<=8; ++c)
		{
			
			if (r==0 && c==0)
			{
			}
			else if (r==0 || c == 0)
			{
                 }
			else if(min>Terror[r][c])
			{
			min=Terror[r][c];
			ymin=table[r][0];
			xmin=table[0][c];
			}
		}	
	}
	
	/*Total Error*/
	float TotalError;
	
	for (r=1; r<=24; ++r)
	{
		for (c=1; c<=8; ++c)
		{
			
			if (r==0 && c==0)
			{
			}
			else if (r==0 || c == 0)
			{
                 }
			else
			TotalError=TotalError+Terror[r][c];
		}	
	}
	
	
	/*Total Absolute Error*/
	float TotalAbsError;
	
	for (r=1; r<=24; ++r)
	{
		for (c=1; c<=8; ++c)
		{
			
			if (r==0 && c==0)
			{
			}
			else if (r==0 || c == 0)
			{
                 }
			else
			TotalAbsError=TotalAbsError+Tabserror[r][c];
		}	
	}
	
	float AverageError;
	AverageError=TotalError/192;
	
	float AverageAbsolute;
	AverageAbsolute=TotalAbsError/192;
	
	// e) print the maximum error, the minimum error, the average error, and the average of the absolute error of the measurements
	printf("The Maximum Error is = %.2f at x=%.1f y=%.1f\nThe Minimum Error is = %.2f at x=%.1f y=%.1f\nThe Average Error is = %.2f\nThe Average of the absolute error is = %.2f\n\n",max,xmax,ymax,min,xmin,ymin,AverageError,AverageAbsolute);
	fprintf(fp2,"The Maximum Error is = %.2f at x=%.1f y=%.1f\nThe Minimum Error is = %.2f at x=%.1f y=%.1f\nThe Average Error is = %.2f\nThe Average of the absolute error is = %.2f\n\n",max,xmax,ymax,min,xmin,ymin,AverageError,AverageAbsolute);
	
    fclose(fp1);
    fclose(fp2);
    system("pause");  
}

/*Sound Intensity function calculation*/
float Theory(float y2, float x2)
{
	float x1,y1,distancex,distancey;
	x1=2.5;y1=-2.5;
	float I,L,r;
	
	distancex=x1-x2;
	distancey=y1-y2;
	
	r=sqrt((pow(distancex,2))+(pow(distancey,2)));
		
		I=20.0/(2*PI*pow(r,2));
	
		L=10.0*log10(I/pow(10.0,-12.0));
	
	return(L);
}

/*Error Function*/
float Error(float Measured,float Theored)
{
	float errordata;
	errordata=Measured-Theored;
	
	return(errordata);
}

/*Absolute Error Function*/
float AbsError(float Measured,float Theored)
{
	float errordataabs;
	errordataabs=fabs(Measured-Theored);
	
	return(errordataabs);
}

/*Absolute Error Percent function*/
float PercentAbsError(float abserror,float actual)
{
	float Percent;;
	Percent=((abserror)/actual)*100;
	
	return(Percent);
}

