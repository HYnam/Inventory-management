// 	Project: AD1_InvMgt_RecSys: Individual part
//	Program: To sort out the most salable quantity of a selected category for decision making
//	Filename: Individual.c (Tentatively)
//  StudentName; Nam, Hiu Yi
//
//	Description:
//		1)	Use of pointer of Struct
//		2)	Apply sorting
//
//	Program Created; 27 Dec, 2018
//	Program last updated on : 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct pdetails
{
    char itemnum[7];
    char itemname[137];
    char recordid[9];
    char cat[25];
    char qtysold[9];
    char weight[6];
};


void truncstr (char str1[]) // char* str1 was used
{
    int length = strlen(str1);
    int maxcnt = 0;
    int i;

    for (i = 0; i < length; i++) {
        if (str1[i] != ' ') {
            maxcnt = i;
        }
    }
    str1[maxcnt+1] = '\0';
}


int i;
void printOut(struct pdetails* pIn, int sizeOfArray)
{
	printf("Qty sold\t item name\n");
//	printf("________\t _________\n");
	for (i = 0; i < sizeOfArray; i++)
	{
		printf("%s\t\t %s\n",(*(pIn + i)).qtysold,(*(pIn + i)).itemname);
	}

	return;
}

void sortFab4(struct pdetails* pNAS, int sizeOfArray)
{
	bool swapAgain = true;
	char var1, var2;
	
	while (swapAgain)
	{
		swapAgain = false;
		for (i = 0; i < (sizeOfArray - 1); i++)
		{
			var1 = atoi((*(pNAS + i)).qtysold);
			var2 = atoi((*(pNAS + i + 1 )).qtysold);
			
			if (var1 < var2)
			{
				swapAgain = true;
				struct pdetails temp = *(pNAS + i);
				*(pNAS + i) = *(pNAS + i   + 1);
				*(pNAS + i + 1) = temp;
			}
		}
	}
//	printOut(pNAS, sizeOfArray);
	return; 
}


int main()
{
	struct pdetails psel[100];
	
 	int category, j, maxcount;
 	// bool bcontinue = true;
 	char tempCat[18];

    FILE *inFile;	
	inFile = fopen("stock.txt", "r");

	if (inFile == NULL) 	// check data file availability
	{
   		printf("\nThe file was not successfully opened. ");
   		printf("\nPlease check that the file currently exists.\n");
   		// exit;
	}
	else
	{
		printf("Inventory Management Record System - Individual part\n");
		printf("To check the most salable products\n\n");
		printf("1 = Food\n");
		printf("2 = Clothing\n");
		printf("3 = Drink\n");
		printf("5 = Product\n\n");
		printf("Please enter your category: ");
		scanf("%d", &category);
		switch (category)
		{
			case 1:
	  			 strcpy(tempCat, "Food");
				 printf("\nThe output for food is...\n");
				 break;
			case 2:
				 strcpy(tempCat, "Clothing");
				 printf("\nThe output for clothing is ...\n ");
				 break;
			case 3:
				 strcpy(tempCat, "Drink");
				 printf("\nThe output for drink is ...\n");
			   	 break;
			case 5:
				 strcpy(tempCat, "Electronic product");
				 printf("\nThe output for electronic product is...\n");
				 break;
			default:
			     printf("\nthere are no such category...");
		}  // close for switch

		int i = 0;
		int a;
		while (!feof(inFile))
		{
            fgets((*(psel + i)).itemnum, 7, inFile);
            char x = (*(psel + i)).itemnum[0] - '0';
            fgets((*(psel + i)).itemname, 137, inFile);
            fgets((*(psel + i)).recordid, 9, inFile);
            fgets((*(psel + i)).cat, 25, inFile);
            fgets((*(psel + i)).qtysold, 9, inFile);
            fgets((*(psel + i)).weight, 6, inFile);

            if(category == x)
            {
            i++;  // Increment a by 1, then use the new value of a in the expression in which a resides.
            }
		}
		//printOut(psel, i);
		sortFab4(psel, i);
	}

       	printf("\n");
       	printf("\nThe output of the products is \n\n");
		for (j=0; j<=i; j++)
		{
		truncstr(psel[j].itemname);
		truncstr(psel[j].recordid);
		truncstr(psel[j].cat);
		truncstr(psel[j].qtysold);
		truncstr(psel[j].weight);
        printf  ("%s\t", psel[j].itemnum);
        printf  ("%s\t", psel[j].itemname);
        printf  ("%s\t", psel[j].recordid);
        printf  ("%s\t", psel[j].cat);
		printf  ("%s\t", psel[j].qtysold);
        printf  ("%s\t", psel[j].weight);
		
        printf("\n");
		}
		printOut(psel, i);
		printf("\nThe most salable quality of product in this category is");
		printf(" '%s' \n\n",psel[0].itemname );
	return 0;
}


