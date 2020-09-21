#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 256

//struct definition
struct record
{
    int RecordNumber;
    char ItemName[40];
    int ItemNumber;
    char Category[20];
    int Quantity;
    double Weight;
    char Recipient[40];
    char FinalDestination[40];
    char DeliveryStatus[40];
};

//main program
int main ()
{
    //function Declaations
    
    void function1(void);
    void function2(void);
    void function3(void);
    void function4(void);
    void function5(void);
    void functionA1(void); //Ho Man Tik, 2008 6351
    void functionA2(void);
    void functionA3(void);//Wong Yuk Tung , 20087904
    void functionA4(void);
    void functionA5(void);
    
    int choice; //varible choice is inputted by user with range 1-5
    int i = 0;
    
    printf("\n\t*** Welcome to HKUSPACE Inventory Management and Record System ***");
    
    printf("\n\n\t\t\t\t***  1819S1  ***");
    
    printf("\n\n\t*** This system is developed by CCIT4020 Class No. CL-04 Group No.1***");
    
    printf("\n\n--<Basic functions>--\n");
    
    
    while (i == 0){
        
        printf("\n1. Add New Item(s):");
        
        printf("\n\n2. Display Item Record(s)");
        
        printf("\n\n3. Search New information:");
        
        printf("\n\n4. Modify Item records(s):");
        
        printf("\n\n5. Delete Item Record(s):\n\n");
        
        printf("What is your option <1-5>? ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                function1();
                break;
                
            case 2:
                function2();
                break;
                
            case 3:
                function3();
                break;
                
            case 4:
                function4();
                break;
                
            case 5:
                function5();
                break;
                
            case 6:
                functionA1();
                break;
                
            case 7:
                functionA2();
                break;
                
            case 8:
                functionA3();
                break;
                
            case 9:
                functionA4();
                break;
                
            case 10:
                functionA5();
                break;
                
            default:
                printf("error"); //change it later, for testing purpose
        }
    }
    return 0;
}

void function1(void){
    FILE * Newfile;
    
    Newfile = fopen("stock.txt","a+");
    
    char AddNewItem;
    struct record item;
    AddNewItem = 'y';
    int count = 0;
    
    fseek(Newfile,0,SEEK_END);
    
    while(AddNewItem == 'y'){
        
        /*int c;
         while ((c = getchar()) != '\n' && c != EOF);*/
        fseek(Newfile,0,SEEK_END);
        
        while (count == 0){
            printf("\nEnter Record number: ");
            scanf("%d",&item.RecordNumber) ;
            
            if (item.RecordNumber < 1000 || item.RecordNumber > 10000){
                printf("The range is not between 1000 and 10000, input again");
                continue;
            }
            
            fprintf(Newfile,"%d\n",item.RecordNumber) ;
            count = count + 1;
        }
        count = 0;
        
        printf("\nEnter Item Name: ");
        scanf("%s",item.ItemName);
        fprintf(Newfile,"%s\n",item.ItemName) ;
        
        while (count == 0){
            printf("\nEnter Item Number:  ");
            scanf("%d", &item.ItemNumber);
            
            if (item.ItemNumber < 0 || item.ItemNumber > 1000){
                printf("The range is not between 0 and 1000, input again");
                continue;
            }
            
            fprintf(Newfile,"%d\n",item.ItemNumber) ;
            count = count + 1;
        }
        count = 0;
        
        printf("\nEnter Category:  ");
        scanf("%s",item.Category);
        fprintf(Newfile,"%s\n",item.Category) ;
        
        printf("\nEnter Quantity:  ");
        scanf("%d", &item.Quantity);
        fprintf(Newfile,"%d\n",item.Quantity);
        
        printf("\nEnter Weight:  ");
        scanf("%lf", &item.Weight);
        fprintf(Newfile,"%lf\n",item.Weight);
        
        printf("\nEnter Recipient: ");
        scanf("%s",item.Recipient);
        fprintf(Newfile,"%s\n",item.Recipient);
        
        printf("\nEnter Final destination: ");
        scanf("%s",item.FinalDestination);
        fprintf(Newfile,"%s\n",item.FinalDestination) ;
        
        printf("\nEnter Delivery status  :  ");
        scanf("%s",item.DeliveryStatus);
        fprintf(Newfile,"%s\n\n",item.DeliveryStatus) ;
        
        printf("\nType any character or n to get back mainpage, Add another record type y ");
        fflush(stdin);
        scanf("\n%c", &AddNewItem);
        
        if (AddNewItem == 'n')
        {
            break;
        }
        
        fclose(Newfile);
    }
}

void function2(void){
    
    int check;
    FILE * Newfile;
    Newfile = fopen("stock.txt", "r");
    
    if (Newfile)
    {
        while ((check = getc(Newfile)) != EOF)
            putchar(check);
        fclose(Newfile);
    }
    getchar();
    fclose(Newfile);
    return;
    
}

void function3(void){
    
    struct record item;
    
    int RecordNumberSearch; //user input and use the varible to search
    char response;
    bool bcontinue = true;
    char ItemName[40];
    
    FILE * Newfile;
    Newfile = fopen("stock.txt", "r");
    
    if (Newfile == NULL)     // check data file availability
    {
        printf("\nThe file was not successfully opened. ");
        printf("\nPlease check that the file currently exists.\n");
        //    exit;
    }
    else
    {
        do{    // loop for record number search
            printf("Please enter the record number to search: ");
            scanf("%d",&RecordNumberSearch);
            
            rewind(Newfile); //reset the file pointer at the beginning
            int success = 0;
            while (!feof(Newfile) ){
                //int success = 0;
                fscanf(Newfile, "%d", &item.ItemNumber);
                fgets(ItemName, 40, Newfile);
                if (item.ItemNumber == RecordNumberSearch)
                {
                    success = 1;
                    printf("Record detail:\n%d\n", item.ItemNumber);
                    while (success != 9) {
                        fgets(ItemName, 40, Newfile);
                        printf("%s", ItemName);
                        success++;
                    }
                    if (success == 9)
                        break;
                }
            }
            if (success == 9) {
                printf("\nsucceed to search record through keyword.");
            } else {
                printf("\nseaerch record unsuccessfully!");
            }
            fflush(stdin);
            printf("\nDo you want to continue [Y/N]:");
            scanf("%c",&response);
            
            if (response == 'N')
            {
                break;
            }
            
        } while (bcontinue == true );
    }    // process data file ends
    
    fflush(stdin);
    fclose(Newfile);    // fclose closes the data file
}


void function4(void){
    FILE *fp = fopen("stock.txt", "r");
    printf("Please enter record number to choose record and modify it:");
    int num, lineCounter = 0;
    scanf("%d", &num);
    char trash[100];
    int find = 0;
    char AddNewItem;
    //printf("%d", num);
    do {
        while (!feof(fp)) {
            lineCounter++;
            int fileNum;
            if (lineCounter % 9 != 1) {
                fscanf(fp, "%s", trash);
            } else {
                fscanf(fp, "%d", &fileNum);
                //printf("\nnumber search:%d", fileNum);
                if (num == fileNum) {
                    find = 1;
                    rewind(fp);
                    int r = 0;
                    remove("t.txt");
                    FILE *temporary = fopen("t.txt", "a");
                    while(r < lineCounter - 1) {
                        char text[50];
                        fgets(text, 50, fp);
                        fprintf(temporary, "%s", text);
                        r++;
                    }
                    struct record item;
                    printf("\nEnter NEW Record number: ", r);
                    scanf("%d%c",&item.RecordNumber, &AddNewItem) ;
                    if (fprintf(temporary,"%d\n",item.RecordNumber) < 0)
                        printf("error");
                    
                    printf("\nEnter NEW Item Name: ");
                    gets(item.ItemName);
                    fprintf(temporary,"%s\n",item.ItemName) ;
                    
                    printf("\nEnter NEW Item Number:  ");
                    scanf("%d%c", &item.ItemNumber, &AddNewItem);
                    fprintf(temporary,"%d\n",item.ItemNumber) ;
                    
                    printf("\nEnter NEW Category:  ");
                    gets(item.Category);
                    fprintf(temporary,"%s\n",item.Category) ;
                    
                    printf("\nEnter NEWQuantity:  ");
                    scanf("%d%c", &item.Quantity, &AddNewItem);
                    fprintf(temporary,"%d\n",item.Quantity);
                    
                    printf("\nEnter NEW Weight:  ");
                    scanf("%lf%c", &item.Weight, &AddNewItem);
                    fprintf(temporary,"%lf\n",item.Weight);
                    
                    printf("\nEnter NEW Recipient: ");
                    gets(item.Recipient);
                    fprintf(temporary,"%s\n",item.Recipient);
                    
                    printf("\nEnter NEW Final destination: ");
                    gets(item.FinalDestination);
                    fprintf(temporary,"%s\n",item.FinalDestination) ;
                    
                    printf("\nEnter NEW Delivery status  :  ");
                    gets(item.DeliveryStatus);
                    fprintf(temporary,"%s\n",item.DeliveryStatus) ;
                    
                    while (r + 1 < lineCounter + 9) {
                        //printf("skip line:%d\n", r);
                        char text[50];
                        fgets(text, 50, fp);
                        r++;
                    }
                    while(!feof(fp)) {
                        //printf("fill content\n");
                        char text[50];
                        fgets(text, 50, fp);
                        fprintf(temporary, "%s", text);
                    }
                    fclose(fp);
                    fclose(temporary);
                    remove("stock.txt");
                    rename("t.txt", "stock.txt");
                    remove("t.txt");
                }
            }
            if (find == 1)
                break;
            
        }
        if (find == 0)
            printf("\nNo record found.");
        printf("\nDo you want to continue [Y/N]:");
        scanf("\n%c", &AddNewItem);
        while (AddNewItem != 'n' && AddNewItem != 'y') {
            printf("unexpected key is input, please input again:");
            scanf("\n%c", &AddNewItem);
        }
        if (AddNewItem == 'n')
            break;
    } while (1);
    
}

void function5(void){
    FILE *fp = fopen("stock.txt", "r");
    printf("Please enter record number to choose record and delete it:");
    int num, lineCounter = 0;
    scanf("%d", &num);
    char trash[100];
    int find = 0;
    char AddNewItem;
    //printf("%d", num);
    do {
        while (!feof(fp)) {
            lineCounter++;
            int fileNum;
            if (lineCounter % 9 != 1) {
                fscanf(fp, "%s", trash);
            } else {
                fscanf(fp, "%d", &fileNum);
                //printf("\nnumber search:%d", fileNum);
                if (num == fileNum) {
                    find = 1;
                    rewind(fp);
                    int r = 0;
                    remove("t.txt");
                    FILE *temporary = fopen("t.txt", "a");
                    while(r < lineCounter - 1) {
                        char text[50];
                        fgets(text, 50, fp);
                        fprintf(temporary, "%s", text);
                        r++;
                    }
                    
                    struct record item;
                    printf("\nr:%d Enter Record number: ", r);
                    scanf("%d%c",&item.RecordNumber, &AddNewItem) ;
                    if (fprintf(temporary,"%d\n",item.RecordNumber) < 0)
                        printf("error");
                    
                    while (r + 1 < lineCounter + 9) {
                        //printf("skip line:%d\n", r);
                        char text[50];
                        fgets(text, 50, fp);
                        r++;
                    }
                    while(!feof(fp)) {
                        //printf("fill content\n");
                        char text[50];
                        fgets(text, 50, fp);
                        fprintf(temporary, "%s", text);
                    }
                    fclose(fp);
                    fclose(temporary);
                    remove("stock.txt");
                    rename("t.txt", "stock.txt");
                    remove("t.txt");
                }
            }
            if (find == 1)
                break;
            
        }
        if (find == 0)
            printf("\nNo record found.");
        printf("\nDo you want to continue [Y/N]:");
        scanf("\n%c", &AddNewItem);
        while (AddNewItem != 'n' && AddNewItem != 'y') {
            printf("unexpected key is input, please input again:");
            scanf("\n%c", &AddNewItem);
        }
        if (AddNewItem == 'n')
            break;
    } while (1);
    
}

//Ho Man Tik 2008 6351 The Summary of the Stock
void functionA1(){
    
    int i = 0;
char count;

FILE * Newfile;
Newfile = fopen ("stock.txt", "r");

if (Newfile == NULL)
{
    printf("Could not open file - Newfile");
}

rewind(Newfile);

for (count = getc(Newfile); count != EOF; count = getc(Newfile)){
    if (count == '\n')
        i = i + 1;
        }

time_t BasicTime;
struct tm * TimeNow;

time ( &BasicTime );
TimeNow = localtime ( &BasicTime );

fclose(Newfile);

printf("The total items of the stock is %d at %s ", 50,asctime(TimeNow));
}

// Cheng Wai Yan
void functionA2(){
    char buffer[SIZE];
    time_t curtime;
    struct tm *loctime;
    
    
    FILE *log = fopen("timelog.txt","a+");
    
    /* Get the current time. */
    curtime = time (NULL);
    
    /* Convert it to local time representation. */
    loctime = localtime (&curtime);
    
    /* Print out the date and time in the standard format. */
    fputs (asctime (loctime), stdout);
    
    /* Print it out in a nice format. */
    strftime (buffer, SIZE, "Today is %A, %B %d.\n", loctime);
    fputs (buffer, stdout);
    strftime (buffer, SIZE, "U are now checking the file on %I:%M %p.\n", loctime);
    fputs (buffer, stdout);
    
    fclose(log);
}

void functionA3()   /*Wong Yuk Tung , 20087904 */
{
    char ch, source_file[20], target_file[20];
    FILE *source, *target;
    printf("Enter name of file to copy\n");
    gets(source_file);
    source = fopen(source_file, "r");
    printf("Enter name of target file\n");
    gets(target_file);
    target = fopen(target_file, "w");
    while ((ch = fgetc(source)) != EOF)
        fputc(ch, target);
    printf("File copied successfully.\n");
    fclose(source);
    fclose(target);
    
}

void functionA4()
{
    char choice;

    printf("You are going to leave the program....\n");

    printf("Are you sure you want to leave?....\n");
    printf("Y / N :%c",&choice);
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        exit(0);

        printf("End of the program....\n");
    }
    else
    {
        printf("Return to main program");
    }
    return;
}

void functionA5()
{
    #define col_catsize 5
#define col_itemsize 5
#define col_namesize 133
#define col_soldsize 164
#define col_soldsize_p 163


struct pdetails
{
    char itemnum[7];
    char itemname[137];
    char recordid[9];
    char cat[25];
    char qtysold[9];
    char weight[6];
    //char line[50];
};

// struct pdetails bubbleSort(struct pdetails list[], int maxcount); // function prototype

void truncstr (char* str1) {
    int length = strlen(str1);
    int ptr = 0;
    //char str2[length];
    int i;

    for (i = 0; i < length; i++) {
        if (str1[i] != ' ') {
            ptr = i;
        }
    }
    str1[ptr+1] = '\0';
}

int main()
{
	struct pdetails prd[100];

 	int category, j, col_item, col_sold, col_sold_p;// variable declaration
 	bool bcontinue = true;
 	char tempCat[18], tempCat2[18];
 	char itemname1, itemname2, col_name, col_name_p;

    FILE *inFile;	// inFile = clients.txt file pointer
	inFile = fopen("stock_individual.txt", "r");

	if (inFile == NULL) 	// check data file availability
	{
   		printf("\nThe file was not successfully opened. ");
   		printf("\nPlease check that the file currently exists.\n");
   	//	exit;
	}
	else
	{
		printf("Please enter your category [1(Food)/2(Clothing)/3(Drink)/4(Electronic product)]: ");
		scanf("%d", &category);
		switch (category)
		{
			case 1:
	  			 //tempCat = "Food";
	  			 strcpy(tempCat, "Food");
				 printf("\nsearching for food ...");
				 break;
			case 2:
				 //tempCat = "Clothing";
				 strcpy(tempCat, "Clothing");
				 printf("\nsearching for clothing ... ");
				 break;
			case 3:
				 //tempCat = "Drink";
				 strcpy(tempCat, "Drink");
				 printf("\nsearching for drink ...");
			   	 break;
			case 4:
				 //tempCat = "Electronic product";
				 strcpy(tempCat, "Electronic product");
				 printf("\nsearching for electronic product...");
				 break;
			default:
			     printf("\nthere are no such category...");
		}  // close for switch

		int i = 0;
		while (!feof(inFile))
		{
            //if(strcmp(tempCat,fgets(tempCat2,5, inFile)))

            //fscanf(inFile, "%s", prd[i].itemnum);
            fgets(prd[i].itemnum, 7, inFile);
            //printf("%s", prd[i].itemnum);

            //fgets(prd[i].first, 153, inFile);
            //char x = prd[i].first[0] - '0';
            char x = prd[i].itemnum[0] - '0';
            fgets(prd[i].itemname, 137, inFile);
            fgets(prd[i].recordid, 9, inFile);
            fgets(prd[i].cat, 25, inFile);
            fgets(prd[i].qtysold, 9, inFile);
            fgets(prd[i].weight, 6, inFile);

            if(category == x)
            {

            /*
            fscanf(inFile, "%s", prd[i].recordid);
            fscanf(inFile, "%s", prd[i].cat);
            fscanf(inFile, "%s", prd[i].qtysold);
            fscanf(inFile, "%s", prd[i].weight);
*/
/*
            fscanf(inFile, "%s", prd[i].itemname);
            fscanf(inFile, "%s", prd[i].cat);
            fscanf(inFile, "%d", prd[i].qtysold);
            fgets(prd[i].first, 1, inFile);
*/
            i++;  // Increment a by 1, then use the new value of a in the expression in which a resides.

                //prd = new pdetails[i];
                /*
            fgets(prd[i].line, 50, inFile);
*/

                //prd[i].itemnum = fgets(col_item, col_itemsize, inFile) ;
                //prd[i].itemname = fgets(col_name, col_namesize, inFile) - fgets(col_name_p, col_itemsize, inFile);
                //prd[i].qtysold = fgets(col_sold, col_soldsize, inFile) - fgets(col_sold_p, col_soldsize_p, inFile);
            }
		}
        printf("\n");
		for (j=0; j<i; j++)
		{
truncstr(prd[j].itemname);
truncstr(prd[j].recordid);
truncstr(prd[j].cat);
truncstr(prd[j].qtysold);
truncstr(prd[j].weight);
            printf  ("%s\t", prd[j].itemnum);
            printf  ("%s\t", prd[j].itemname);
            printf  ("%s\t", prd[j].recordid);
            printf  ("%s\t", prd[j].cat);
			printf  ("%s\t", prd[j].qtysold);
            printf  ("%s\t", prd[j].weight);

            printf("\n");
		}
		/* bubbleSort(a[] , i); */

	/* 	printf("Show the sales volume of the products in descending order of quantity brought...\n");
		printf("This function help firms for decision making\n");

		printf("The maximum quantity sold and item name: %d%s", &a[i].qtysold, a[i].itemname);		*/

	} // end of data file
	return 0;
}


/* bubbleSort(pdetails list[], int maxcount)
{
    pdetails temp;
    int iteration;
    int index;
    for (iteration = 1; iteration < maxcount; iteration++)
    {
        for (index = 0; index < maxcount - iteration; index++)
             if (list[index].itemnum > list[index + 1].itemnum)
            {
                temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
    }
    return (list);
} */
}

