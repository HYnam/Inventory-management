#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	int i, recnum, recordid,itemnum, qty, weight;
	char response; 
	bool bcontinue = true;
 	char itemname[150], category[20], recipient[20], destination[20], status[10];
				   

	FILE *inFile;	// inFile = clients.txt file pointer
	inFile = fopen("stock.txt", "r");

	if (inFile == NULL) 	// check data file availability
	{
   		printf("\nThe file was not successfully opened. ");
   		printf("\nPlease check that the file currently exists.\n");
   	//	exit;
	}
	else
	{
		do 
		{	// loop for record number search
			printf("Please enter your record number to search: ");
 			scanf("%d",&recnum);

 			rewind(inFile);		// reset the file pointer to the beginning of the file
	 		
			while (!feof(inFile) )
 			{
 			 	// fscanf(inFile, "%d%117s%d%d%s%d%s%s%s",&recordid,itemname,&itemnum,category,&qty,weight,recipient,destination,status);
			    // fscanf(inFile, "%d%17s",&recordid,itemname);
				fscanf(inFile, "%d",&itemnum);	// Martin's advice on 5/12/2018
 			 	fgets(itemname, 150, inFile); // Martin's advice 			 	
				// recordid = itemname[0]-'0';	// Martin's advice
		   		
			   	if (itemnum == recnum)
			 	{	
		   		    printf("file record num is %d \n", itemnum);	
			  	    printf("%d%150s",itemnum,itemname);
	  		    	break;
			    } 
			}	// InFile
			
			fflush(stdin);
			printf("\nDo you want to continue [Y/N]:");
			scanf("%c",&response);
			
			if (response == 'N')
			{
			   break;  
			}											
		} while (bcontinue == true ); 
	}	// process data file ends
	
	fflush(stdin);	
	fclose(inFile);	// fclose closes the data file
	return 0;
}
