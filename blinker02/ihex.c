
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fpin;
FILE *fpout;

unsigned char newline[2048];
unsigned char xstring[1024];

int main ( int argc, char *argv[] )
{
    unsigned int ra;
    unsigned int line;

    if(argc<2) return(1);
    fpin=fopen(argv[1],"rt");
    if(fpin==NULL)
    {
        printf("Error opening file [%s]\n",argv[1]);
        return(1);
    }

    sprintf(xstring,"%s.hex",argv[1]);
    fpout=fopen(xstring,"wt");
    if(fpout==NULL)
    {
        printf("Error opening file [%s]\n",xstring);
        return(1);
    }

    line=0;
    while(fgets(newline,sizeof(newline)-1,fpin))
    {
        line++;
        if(newline[0]==':')
        {
            ra=strlen(newline);
            if(ra>=9)
            {
                if(newline[7]==0x30)
                {
                    if(newline[8]==0x35)
                    {
                        printf("type 0x05, skipping line %u\n",line);
                        continue;
                    }
                }
            }
        }
        fprintf(fpout,"%s",newline);
    }
    fclose(fpout);
    fclose(fpin);
    return(0);
}


