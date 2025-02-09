#include "types.h"
#include "user.h"
#include "stat.h"
int main(int argc, char *argv[])
{printf(1,"Uniq command is getting executed in kernel mode\n");
        char ch='\0';
        if (argc < 1){
                exit();
        }
        else
        {
                switch ((int)argv[1][1])
                {
                        case (int)'i':
                                {
                                        ch = 'i';
                                        break;
                                }
                        case (int)'c':
                                {
                                        ch='c';
                                        break;
                                }
                        case (int)'d':
                                {
                                        ch = 'd';
                                        break;
                                }
                        default:
                                {
                                        exit();
                                }
                                   }
	}
        

        for (int j = 2; j <argc; j++)
        {
                int fdata=open(argv[j],0);
                        printf(1,"%s\n",argv[j]);
                if (fdata < 0)
                {
                        exit();
                }
                        if (argc==2||ch == 'i')
                        {
                                uniqIOperation(fdata);
                        }
                        if (ch == 'd')
                        {
                                uniqDOperation(fdata);
                        }
                        if (ch == 'c')
                        {
                                uniqCOperation(fdata);
                        }
                        close(fdata);
                }

exit();
}
