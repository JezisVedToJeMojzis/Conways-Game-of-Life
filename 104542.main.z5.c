#define LSIZ 128 
#define RSIZ 10 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void next_state(int interakcie,int riadky, int stlpce,char (*pole)[riadky][stlpce])  //interactions, rows, columns, array
{
	int r = riadky; //rows
	int s = stlpce; // columns
	int pocet = 0; 
	int i, j;

    char pole2[r][s];
	
	for (i=r-1;i<r;i++)// left lower corner
	{
		for (j=0;j<1;j++)
		{
			if((*pole)[i][j]=='1')
			{
				if((*pole)[i][s-1]=='1')
				{
					pocet++;
				}
				if((*pole)[0][j]=='1')
				{
					pocet++;
				}
				if((*pole)[i-1][j]=='1')
				{
					pocet++;
				}
				if((*pole)[i-1][j+1]=='1')
				{
					pocet++;
				}
				if((*pole)[i][j+1]=='1')
				{
					pocet++;
				}
				if (pocet==2 || pocet==3) // bunka ostava zit
				{
				pole2[i][j]='j';
				
				}
				if (pocet<2 || pocet>3) //bunka zomrela
				{
				pole2[i][j]='n';
				pocet=0;
				}
				pocet=0;
	
			}
			if((*pole)[i][j]=='0')
			{
				if((*pole)[i][s-1]=='1')
				{
					pocet++;
				}
				if((*pole)[0][j]=='1')
				{
					pocet++;
				}
				if((*pole)[i-1][j]=='1')
				{
					pocet++;
				}
				if((*pole)[i-1][j+1]=='1')
				{
					pocet++;
				}
				if((*pole)[i][j+1]=='1')
				{
					pocet++;
				}
				if (pocet==3) // bunka ozije
				{
				pole2[i][j]='j';
				
				}
				if (pocet!=3) // bunka ostane mrtva
				{
				pole2[i][j]='n';
				
				}
				pocet=0;
			}
		}
	}
	
	for (i=r-1;i<r;i++)// right lower corner
	{
		for (j=s-1;j<s;j++)
		{
			if((*pole)[i][j]=='1')
			{
				if((*pole)[i][j-1]=='1')
				{
					pocet++;
				}
				if((*pole)[i][0]=='1')
				{
					pocet++;
				}
				if((*pole)[0][j]=='1')
				{
					pocet++;
				}
				if((*pole)[i-1][j-1]=='1')
				{
					pocet++;
				}
				if((*pole)[i-1][j]=='1')
				{
					pocet++;
				}
				if (pocet==2 || pocet==3) // stays alive
				{
				pole2[i][j]='j';
				
				}
				if (pocet<2 || pocet>3) // died
				{
				pole2[i][j]='n';
				pocet=0;
				}
				pocet=0;
	
			}
			if((*pole)[i][j]=='0')
			{
				if((*pole)[i][j-1]=='1')
				{
					pocet++;
				}
				if((*pole)[i][0]=='1')
				{
					pocet++;
				}
				if((*pole)[0][j]=='1')
				{
					pocet++;
				}
				if((*pole)[i-1][j-1]=='1')
				{
					pocet++;
				}
				if((*pole)[i-1][j]=='1')
				{
					pocet++;
				}
				if (pocet==3) // came back to life
				{
				pole2[i][j]='j';
				
				}
				if (pocet!=3) // stays dead
				{
				pole2[i][j]='n';
				
				}
				pocet=0;
			}
		}
	}
	
	for (i=0;i<1;i++)// right upper corner
	{
		for (j=s-1;j<s;j++)
		{
			if((*pole)[i][j]=='1')
			{
				if((*pole)[i][j-1]=='1')
				{
					pocet++;
				}
				if((*pole)[i][0]=='1')
				{
					pocet++;
				}
				if((*pole)[i+1][j]=='1')
				{
					pocet++;
				}
				if((*pole)[i+1][j-1]=='1')
				{
					pocet++;
				}
				if((*pole)[r-1][j]=='1')
				{
					pocet++;
				}
				if (pocet==2 || pocet==3) // stays alive
				{
				pole2[i][j]='j';
				
				}
				if (pocet<2 || pocet>3) // died
				{
				pole2[i][j]='n';
				pocet=0;
				}
				pocet=0;
	
			}
			if((*pole)[i][j]=='0')
			{
				if((*pole)[i][j-1]=='1')
				{
					pocet++;
				}
				if((*pole)[i][0]=='1')
				{
					pocet++;
				}
				if((*pole)[i+1][j]=='1')
				{
					pocet++;
				}
				if((*pole)[i+1][j-1]=='1')
				{
					pocet++;
				}
				if((*pole)[r-1][j]=='1')
				{
					pocet++;
				}
				if (pocet==3) // came back to life
				{
				pole2[i][j]='j';
				
				}
				if (pocet!=3) // stays dead
				{
				pole2[i][j]='n';
				
				}
				pocet=0;
			}			
		}	
	}	
	for(i=0;i<1;i++)// left upper corner
	{
		for(j=0;j<1;j++)
		{
			if((*pole)[i][j]=='1')
			{
				if((*pole)[r-1][j]=='1')
				{
					pocet++;
				}
				if((*pole)[i][s-1]=='1')
				{
					pocet++;
				}
				if((*pole)[i+1][j]=='1')
				{
					pocet++;
				}
				if((*pole)[i][j+1]=='1')
				{
					pocet++;
				}
				if((*pole)[i+1][j+1]=='1')
				{
					pocet++;
				}
				if (pocet==2 || pocet==3) // bunka ostava zit
				{
				pole2[i][j]='j';
				
				}
				if (pocet<2 || pocet>3) //bunka zomrela
				{
				pole2[i][j]='n';
				
				}
				pocet=0;
	
			}
			if((*pole)[i][j]=='0')
			{
				if((*pole)[r-1][j]=='1')
				{
					pocet++;
				}
				if((*pole)[i][s-1]=='1')
				{
					pocet++;
				}
				if((*pole)[i+1][j]=='1')
				{
					pocet++;
				}
				if((*pole)[i][j+1]=='1')
				{
					pocet++;
				}
				if((*pole)[i+1][j+1]=='1')
				{
					pocet++;
				}
				if (pocet==2 || pocet==3) // bunka ostava zit
				{
				pole2[i][j]='j';
				
				}
				if (pocet<2 || pocet>3) //bunka zomrela
				{
				pole2[i][j]='n';
				
				}
				pocet=0;
			}
		}
	}
	
	
	for (i=r-1;i<r;i++) //lower row without corners
	{
		for (j=1;j<s-1;j++)
		{
			if ((*pole)[i][j]=='1') //ziva bunka na dolnom okraji
			{
				if ((*pole)[i-1][j]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][j-1]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][j+1]=='1')
				{
					pocet++;
				}
				if ((*pole)[0][j]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i-1][j+1]=='1')
				{
					pocet++;
				}
				if ((*pole)[i-1][j-1]=='1')
				{
					pocet++;
				}	
				if (pocet==2 || pocet==3) // bunka ostava zit
				{
				pole2[i][j]='j';
				
				}
				if (pocet<2 || pocet>3) //bunka zomrela
				{
				pole2[i][j]='n';
				
				}
				pocet=0;	
			}
			if ((*pole)[i][j]=='0') //mrtva bunka na dolnom okraji
			{
				if ((*pole)[i-1][j]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][j-1]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][j+1]=='1')
				{
					pocet++;
				}
				if ((*pole)[0][j]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i-1][j+1]=='1')
				{
					pocet++;
				}
				if ((*pole)[i-1][j-1]=='1')
				{
					pocet++;
				}		
				if (pocet==3) // bunka ozije
				{
				pole2[i][j]='j';
				
				}
				if (pocet!=3) // bunka ostane mrtva
				{
				pole2[i][j]='n';
				}
				pocet=0;
					
			}
		}	
	}
	
	for(i=1;i<r-1;i++) // right column without corners
	{
		for(j=s-1;j<s;j++)
		{
			if ((*pole)[i][j]=='1') //ziva bunka na pravom okraji
			{
				if ((*pole)[i-1][j]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][j-1]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][0]=='1')
				{
					pocet++;
				}
				if ((*pole)[i+1][j]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i+1][j-1]=='1')
				{
					pocet++;
				}
				if ((*pole)[i-1][j-1]=='1')
				{
					pocet++;
				}	
				if (pocet==2 || pocet==3) // bunka ostava zit
				{
				pole2[i][j]='j';
				
				}
				if (pocet<2 || pocet>3) //bunka zomrela
				{
				pole2[i][j]='n';
			
				}
				pocet=0;
					
			}
			if ((*pole)[i][j]=='0') //mrtva bunka na pravom okraji
			{
			    if ((*pole)[i-1][j]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][j-1]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][0]=='1')
				{
					pocet++;
				}
				if ((*pole)[i+1][j]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i+1][j-1]=='1')
				{
					pocet++;
				}
				if ((*pole)[i-1][j-1]=='1')
				{
					pocet++;
				}		
				if (pocet==3) // bunka ozije
				{
				pole2[i][j]='j';
				
				}
				if (pocet!=3) // bunka ostane mrtva
				{
				pole2[i][j]='n';
				
				}
				pocet=0;	
			}
		}
	}
	
		
	for(i=1;i<r-1;i++) // left column without corners
	{
		for(j=0;j<1;j++)
		{
			if ((*pole)[i][j]=='1') //ziva bunka na lavom okraji
			{
				if ((*pole)[i-1][j]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][s-1]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][j+1]=='1')
				{
					pocet++;
				}
				if ((*pole)[i+1][j+1]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i+1][j]=='1')
				{
					pocet++;
				}
				if ((*pole)[i-1][j+1]=='1')
				{
					pocet++;
				}	
				if (pocet==2 || pocet==3) // bunka ostava zit
				{
				pole2[i][j]='j';
				
				}
				if (pocet<2 || pocet>3) //bunka zomrela
				{
				pole2[i][j]='n';
			
				}
				pocet=0;
					
			}
			if ((*pole)[i][j]=='0') //mrtva bunka na lavom okraji
			{
			    if ((*pole)[i-1][j]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][s-1]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][j+1]=='1')
				{
					pocet++;
				}
				if ((*pole)[i+1][j+1]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i+1][j]=='1')
				{
					pocet++;
				}
				if ((*pole)[i-1][j+1]=='1')
				{
					pocet++;
				}	
				if (pocet==3) // bunka ostane mrtva
				{
				pole2[i][j]='j';
				}
				if (pocet!=3) // bunka ostane mrtva
				{
				pole2[i][j]='n';
				
				}
				pocet=0;	
			}
		}
	}
	
	 for (i=0;i<1;i++) //upper row without corners
	{
		for (j=1;j<s-1;j++)
		{
			if ((*pole)[i][j]=='1') //ziva bunka na hornom okraji
			{
				if ((*pole)[r-1][j]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][j-1]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][j+1]=='1')
				{
					pocet++;
				}
				if ((*pole)[i+1][j+1]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i+1][j]=='1')
				{
					pocet++;
				}
				if ((*pole)[i+1][j-1]=='1')
				{
					pocet++;
				}	
				if (pocet==2 || pocet==3) // bunka ostava zit
				{
				pole2[i][j]='j';
				}
				if (pocet<2 || pocet>3) //bunka zomrela
				{
				pole2[i][j]='n';
				}
				pocet=0;
					
			}
			if ((*pole)[i][j]=='0') //mrtva bunka na hornom okraji
			{
				if ((*pole)[r-1][j]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][j-1]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i][j+1]=='1')
				{
					pocet++;
				}
				if ((*pole)[i+1][j+1]=='1')
				{
					pocet++;
				}	
				if ((*pole)[i+1][j]=='1')
				{
					pocet++;
				}
				if ((*pole)[i+1][j-1]=='1')
				{
					pocet++;
				}	
				if (pocet==3) // bunka ozije
				{
				pole2[i][j]='j';
				
				}
				if (pocet!=3) // bunka ostane mrtva
				{
				pole2[i][j]='n';
				
				}
				pocet=0;	
			}
		}
	}
	
	
	
	for (i = 1; i < r-1; i++) // vnutro pola
	 {
		for (j = 1; j < s-1; j++)
		 {
		    if ((*pole)[i][j]=='0'){
				if ((*pole)[i - 1][j] == '1')
				{
					pocet++;
				}
				if ((*pole)[i][j - 1] == '1')
				{
					pocet++;
				}
				if ((*pole)[i + 1][j] == '1')
				{
					pocet++;
				}
				if ((*pole)[i][j + 1] == '1')
				{
					pocet++;
				}
				if ((*pole)[i + 1][j + 1] == '1')
				{
					pocet++;
				}
				if ((*pole)[i - 1][j + 1] == '1')
				{
					pocet++;
				}
				if ((*pole)[i - 1][j - 1] == '1')
				{
					pocet++;
				}
			    if ((*pole)[i + 1][j - 1] == '1')
				{
					pocet++;
				}
				if (pocet == 3) // bunka ozije
				{
					pole2[i][j] = 'j';
					
				}
				if (pocet < 3 || pocet>3) // bunka ostane mrtva
				{
					pole2[i][j] = 'n';
					
				}
				
				pocet=0;
			
			}
			if ((*pole)[i][j]=='1'){
				if ((*pole)[i - 1][j] == '1')
				{
					pocet++;
				}
				if ((*pole)[i][j - 1] == '1')
				{
					pocet++;
				}
				if ((*pole)[i + 1][j] == '1')
				{
					pocet++;
				}
				if ((*pole)[i][j + 1] == '1')
				{
					pocet++;
				}
				if ((*pole)[i + 1][j + 1] == '1')
				{
					pocet++;
				}
				if ((*pole)[i - 1][j + 1] == '1')
				{
					pocet++;
				}
				if ((*pole)[i - 1][j - 1] == '1')
				{
					pocet++;
				}
			    if ((*pole)[i + 1][j - 1] == '1')
				{
					pocet++;
				}
				if (pocet == 2 || pocet == 3) // bunka ostava zit
				{
					pole2[i][j] = 'j';	
				}
			    if (pocet < 2 || pocet > 3) //bunka zomrela
				{
					pole2[i][j] = 'n';
				
				}
				pocet=0;
		    }		
		}	
	}
	for (i=0;i<r;i++)
	{
	    for(j=0;j<s;j++)
	    {
	       if(pole2[i][j]=='j')
	       {
	           (*pole)[i][j]='1';
	       }
	        if(pole2[i][j]=='n')
	       {
	           (*pole)[i][j]='0';
	       }
	    }
	}
}

void read_text_file(int r,int s,char *nazov_suboru,char (*pole)[r][s]) //reading from file
{
	FILE *myFile;
    myFile = fopen(nazov_suboru, "r");

    static int state[1000];
    char ppole[r*s];
   
    int i=0,j=0;
    char pismeno;
	while ((pismeno=fgetc(myFile))!=EOF)
	{
		if (pismeno=='1')
		{
			state[i]=1;
		}
		if (pismeno=='0')
		{
			state[i]=0;
		}
		if (pismeno=='\n')
		{
			pismeno=fgetc(myFile);
		}
		i++;
	}
	
	for (i=0;i<r*s;i++)
	{
		if (state[i]==1)
		{
			ppole[i]='1';
		}
		if (state[i]==0)
		{
			ppole[i]='0';
		}
	}	
	int k=0;
	for (i=0;i<r;i++)
	{
		for (j=0;j<s;j++)
		{
			if (ppole[k]=='1')
			{
				(*pole)[i][j]='1';
			}
			if (ppole[k]=='0')
			{
				(*pole)[i][j]='0';
			}
			k++;
		}	
	}
	fclose(myFile);  
}

void write_text_file(int r,int s,char *nazov_suboru,char (*pole)[r][s]) //writing into file
{
	int i,j;
	FILE* fp2; 
	fp2 = fopen(nazov_suboru, "w"); //w - write
	for (i=0;i<r;i++)
	{
		for (j=0;j<s;j++)
		{
			fprintf(fp2, "%c",(*pole)[i][j]);
		}
			fprintf(fp2, "%c",'\n');
	}
	fclose(fp2);
}

void print_state(int r,int s,char (*pole)[r][s]) //print state
{
	int i,j;
	
	for (i=0;i<r;i++)
	{
	    for(j=0;j<s;j++)
	    {
	    	if((*pole)[i][j]=='1')
	    	{
	    		(*pole)[i][j]='*';
			}
			if((*pole)[i][j]=='0')
	    	{
	    		(*pole)[i][j]=' ';
			}
	    }
	}
	for (i=0;i<r;i++)
	{
	    for(j=0;j<s;j++)
	    {
	    	fprintf(stdout,"%c",(*pole)[i][j]);
	    }
	    fprintf(stdout,"\n");    
	}
	
	for (i=0;i<r;i++)
	{
	    for(j=0;j<s;j++)
	    {
	    	if((*pole)[i][j]=='*')
	    	{
	    		(*pole)[i][j]='1';
			}
			if((*pole)[i][j]==' ')
	    	{
	    		(*pole)[i][j]='0';
			}
	    }
	}
}

void game_of_life(int argc, char* argv[])
{
	int i,j,r,s,t;

 	r = atoi(argv[argc-5]);
    s = atoi(argv[argc-4]);
    t= atoi(argv[argc-3]);
 	char *input=argv[argc-2];
 	char *output=argv[argc-1];
	
	int v=0; 
	
	char ppole[r][s];
	
	read_text_file(r,s,input,&ppole);
	
	
	int x;
	while ((x = getopt(argc, argv, "v")) != -1) // ak je zadane -v
        {
            switch (x)
            {
            case 'v':
            	v=1;
            	print_state(r,s,&ppole);
            	for(i=0;i<t;i++)
            	{
            		next_state(t,r,s,&ppole);
					print_state(r,s,&ppole);
            	}
                break;
            
            default:
               abort();
            } 

        }
    if (v==0)// ak nieje zadane -v
    {
    	for(i=0;i<t;i++) 
        {
            next_state(t,r,s,&ppole);
        }
	}


	write_text_file(r,s,output,&ppole); // print last interaction from file
}

int main(int argc, char* argv[])
{
	game_of_life(argc, argv);
	return 0;  
}
