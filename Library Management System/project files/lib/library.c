#define MAX_NUM_BOOKS  100

/*-----------------------------------*/
struct library
{
    char BookID ;
    char BookTitle[100];
    char AuthorName[30];
    int PublicationYear;
    int NumberOfCopies;
    float Price;
    char Status[20];
};
struct library NullLib=
{
    .BookID=0
};
struct library lib [MAX_NUM_BOOKS];
int totalnumberofbooks=0,counterofdiffrantbooks=0;

/*----------------------------*/
int countDigit(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

int Stringlen (char*str)
{
    int i;
    for(i=0; str[i]; i++);

    return i;
}
int size_check (struct library*booksDB)
{
    totalnumberofbooks=0;
    counterofdiffrantbooks=0;


    for(int loop=0; loop<100; loop++)
    {
        if (booksDB[loop].NumberOfCopies >0)
        {
            totalnumberofbooks+=booksDB[loop].NumberOfCopies;
            counterofdiffrantbooks++;

        }
    }
}
int BookSearch (char ID, struct library*booksDB,int *book_place)
{
    for(int loop=0; loop<100; loop++)
    {
        if (ID==booksDB[loop].BookID)
        {
            *book_place=loop;

            return 1 ; //bookfound
        }
        else
        {

        }

    }

    return 0; //booknotfound
}

void ExitProject()
{
    system("cls");
    int i;
    char ThankYou[100]     = " ========= Thank You =========\n";
    for(i=0; i<strlen(ThankYou); i++)
    {
        printf("%c",ThankYou[i]);
        Sleep(30);
    }
    exit(1);
}
void GoBackOrExit()
{
    getchar();
    char Option;
    printf("\n Go back(b)? or Exit(0)?: ");
    scanf("%c",&Option);
    if(Option == '0')
    {
        ExitProject();
    }
    else
    {
        system("cls");
    }
}




/*----------------------------------------*/
void menu()
{
    system("COLOR 09");
    printf("\n\n\n\n\n\t\t\t\t\t\t\tMAIN MENU\n");
    printf("\t\t\t\t\t\t=======================\n");
    printf("\t\t\t\t\t\t[1] Add A New Book.\n");
    printf("\t\t\t\t\t\t[2] Display the list of books.\n");
    printf("\t\t\t\t\t\t[3] borrow book.\n");
    printf("\t\t\t\t\t\t[4] buy book.\n");
    printf("\t\t\t\t\t\t[5] delete book.\n");
    printf("\t\t\t\t\t\t[0] Exit the Program.\n");
    printf("\t\t\t\t\t\t=======================\n");
    printf("\t\t\t\t\t\t  Enter The Choice: ");
}
void AddNewBook()
{
    int book_adress=0,flag=0;
    struct library lib_holder ;
    system("COLOR 02");
    printf("\nEnter book ID: ");
    scanf("%d",&lib_holder.BookID);

    if (lib_holder.BookID > 99 )
    {
        printf(" Error: ID can not be more than 99 .\n\n");

    }
    else
    {
        flag= BookSearch(lib_holder.BookID,&lib,&book_adress);

        if (flag==0) //new book
        {

            lib[counterofdiffrantbooks].BookID = lib_holder.BookID;
            lib[counterofdiffrantbooks].NumberOfCopies++;

            printf("\nEnter the book name: ");
            scanf("%s",lib[counterofdiffrantbooks].BookTitle);

            printf("\nEnter the author name: ");
            scanf("%s",lib[counterofdiffrantbooks].AuthorName);

            printf("\nPublication Year: ");
            scanf("%d",&lib[counterofdiffrantbooks].PublicationYear);

            printf("\nEnter the price of the book: ");
            scanf("%f",&lib[counterofdiffrantbooks].Price);

            counterofdiffrantbooks++;
            totalnumberofbooks++;
        }
        else //book is here
        {
            printf("Book added befor , i will increase  the number of copies");
            lib[book_adress].NumberOfCopies++;
            totalnumberofbooks++;
            flag=0;
        }
    }

}

void ShowAllBooks(struct library*Books)
{

    // printf("%s",Books[0].BookTitle);
    int i,j;
    printf("|==========|====================|======================|================|=============|=============|\n");
    printf("|    ID    |     BookName       |      AuthorName      |     P.Year     |    Price    |  N.copies   |\n");
    printf("|==========|====================|======================|================|=============|=============|\n");

    for(i=0; i<100 ; i++)
    {
        if(Books[i].BookID==0)
        {
            continue;
        }
        printf("|");
        printf("%d",Books[i].BookID);
        for(j=0; j < 6+(4-(countDigit(Books[i].BookID))); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s",Books[i].BookTitle);
        for(j=0; j < (20-Stringlen(Books[i].BookTitle)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s",Books[i].AuthorName);
        for(j=0; j < (22-Stringlen(Books[i].AuthorName)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%d",Books[i].PublicationYear);
        for(j=0; j < 12+(4-(countDigit(Books[i].PublicationYear))); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%.2f",Books[i].Price);
        for(j=0; j < 7+(3-(countDigit(Books[i].Price))); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%d",Books[i].NumberOfCopies);
        for(j=0; j < 11+(2-(countDigit(Books[i].NumberOfCopies))); j++)
        {
            printf(" ");
        }
        printf("|\n");
        printf("|----------|--------------------|----------------------|----------------|-------------|-------------|\n");

    }
    printf("\n");
}
int BorrowBook(struct library*Books)
{
    int flag=0,book_adress=0;
    struct library lib_holder ;
    printf("\nEnter book ID: ");
    scanf("%d",&lib_holder.BookID);

    if (lib_holder.BookID > 99 )
    {
        printf(" Error: ID can not be more than 99 .\n\n");

    }
    else
    {

        flag= BookSearch(lib_holder.BookID,Books,&book_adress);


        if (flag==1) //book here
        {
            printf("there are  %d  copy, U can take your copy\n", Books[book_adress].NumberOfCopies);
            Books[book_adress].NumberOfCopies--;
        }

        else
        {
            printf("No Copies Available");
        }
    }

}

int BuyBook(struct library*Books)
{
    int flag=0,book_adress=0;
    struct library lib_holder ;
    printf("\nEnter book ID: ");
    scanf("%d",&lib_holder.BookID);

    if (lib_holder.BookID > 99 )
    {
        printf(" Error: ID can not be more than 99 .\n\n");

    }
    else
    {

        flag= BookSearch(lib_holder.BookID,Books,&book_adress);


        if (flag==1) //book here
        {
            printf("there are  %d  copy of this Book\n and u can add till %d copy  \n", Books[book_adress].NumberOfCopies,(100-totalnumberofbooks));

            printf("\nEnter num of copies you bought: ");
            scanf("%d",&lib_holder.NumberOfCopies);
            if(lib_holder.NumberOfCopies > (100-totalnumberofbooks))
            {
                printf("\n No Place for this num of copies");
            }
            else
            {
                Books[book_adress].NumberOfCopies+=lib_holder.NumberOfCopies;
            }

        }

        else
        {
            printf("Book not on the System , Please Add it first ");
        }
    }

}

int DeleteBook(struct library*Books)
{
    char Sure = 'N';
    int flag=0,book_adress=0;
    struct library lib_holder ;
    printf("\nEnter book ID: ");
    scanf("%d",&lib_holder.BookID);

    if (lib_holder.BookID > 99 )
    {
        printf(" Error: ID can not be more than 99 .\n\n");

    }
    else
    {

        flag= BookSearch(lib_holder.BookID,Books,&book_adress);


        if (flag==1) //book here
        {

            getchar();
            printf("\n\n");
            printf(" Are you sure want to delete this book? (Y/N): ");
            scanf("%c",&Sure);

            if(Sure == 'Y' || Sure == 'y')
            {
                lib[book_adress]=NullLib;
            }
            else
            {
                printf(" We Didn't Delete Your Data Don't Worry.\n\n");
                GoBackOrExit();

            }
        }

        else
        {
            printf("NO Book Has This ID");
        }
    }

}


void LMS ()
{
        char BoolTitle[100],BookID_holder,numofnewbookks;
    int  Option=0,loop=0,flag=0;

    while(1)
    {
        size_check(&lib);
        menu();
        scanf(" %d",&Option);

        switch(Option)
        {
        case 0:
            ExitProject();
            break;
        case 1:

            system("cls");
            system("COLOR 02");
            printf("\n\t\t **** Add A New Book ****\n\n");
            AddNewBook();
            GoBackOrExit();
            break;
        case 2:

            system("cls");
            system("COLOR F0");
            printf("\n\t\t\t\t\t*** Books Data Base ***\n\n");
            ShowAllBooks(&lib);
            GoBackOrExit();
            break;
        case 3:

            system("cls");
            system("COLOR 06");
            printf("\n\t\t **** Borrow a Book ****\n\n");
            BorrowBook(&lib) ;
            GoBackOrExit();
            break;
        case 4:
            system("cls");
            system("COLOR 06");
            printf("\n\t\t **** Buy a Book ****\n\n");
            BuyBook(&lib) ;
            GoBackOrExit();
            break;
        case 5:
            system("cls");
            system("COLOR 04");
            printf("\n\t\t **** Delete a Student ****\n\n");
            DeleteBook(&lib) ;
            GoBackOrExit();
            break;
        default:
            printf("\n\t\t\t\t\t\tInvalid number entered\n");
            GoBackOrExit();
        }
    }
}

void testdata()
{
    for (int loop=0; loop<=100; loop++)
    {
        lib[loop].BookID=0;
    }
    //-- book 0
    lib[0].BookID = 1;
    strcpy(lib[0].BookTitle,"Harry Potter1");
    strcpy(lib[0].AuthorName,"J.K.Rowling");
    lib[0].PublicationYear= 1997;
    lib[0].NumberOfCopies= 20;
    lib[0].Price= 100;
    //-- student 1
    lib[1].BookID = 5;
    strcpy(lib[1].BookTitle,"Harry Potter2");
    strcpy(lib[1].AuthorName,"J.K.Rowling");
    lib[1].PublicationYear= 2000;
    lib[1].NumberOfCopies= 10;
    lib[1].Price= 110;

    lib[2].BookID = 9;
    strcpy(lib[2].BookTitle,"Harry Potter3");
    strcpy(lib[2].AuthorName,"J.K.Rowling");
    lib[2].PublicationYear= 2005;
    lib[2].NumberOfCopies= 20;
    lib[2].Price= 105;


}
