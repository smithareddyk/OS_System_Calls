#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"
#define MAX 80
void standard()
{
    char a[MAX][MAX];
    int printedLines = 0;

    while (printedLines < 15) {
        char c;
        int bytesRead = 0;

        while (read(0, &c, 1) == 1) {
            if (c == '\n' || bytesRead >= MAX- 1) {
                a[printedLines][bytesRead] = '\0'; 
                break;
            }

            a[printedLines][bytesRead] = c;
            bytesRead++;
        }

        if (bytesRead > 0) {
            printedLines++;
	}
        	  
	else {
            break;
        }
    }
	for(int i=0;i<printedLines;i++)
        {
          printf(1,"%s\n",a[i]);
        }

    exit();
}

int main(int argc, char *argv[])
{
   printf(1,"Head command is getting executed in kernel mode\n");    	
                if(argc==1)
		{
                  standard();
                }
		else if(argc==2)
		{
			 int f=open(argv[1],0);
			headOperation(f,14);
		}
		else
		{   
                    
                     if(argv[1][0]=='-')
                     {
                        for (int j = 3; j <argc; j++)
                     {
                        int f=open(argv[j],0);
			printf(1,"%s\n",argv[j]);
                        char *a=argv[2];

                        int num=atoi(a);
                        headOperation(f,num);
                     }
                     }
                     else
                     {
                             for (int j = 1; j <argc; j++)
                             {
                                      int f=open(argv[j],0);
				     printf(1,"%s\n",argv[j]);
                        headOperation(f,14);
                     }
                     }

                }
		     
		
		
                exit();
        }

