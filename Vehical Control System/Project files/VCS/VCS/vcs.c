#include "vcs.h"

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


void menu()
{
    system("cls");
    system("COLOR 09");
    printf("\n\n\n\n\n\t\t\t\t\t\t     Vehicle Control System\n");
    printf("\t\t\t\t\t\t===============================\n");
    printf("\t\t\t\t\t\t[1] Turn ON the vehicle engine.\n");
    printf("\t\t\t\t\t\t[2] Turn OFF the vehicle engine.\n");
    printf("\t\t\t\t\t\t[0] Quit the program.\n");
    printf("\t\t\t\t\t\t===============================\n");
    printf("\t\t\t\t\t\t    Enter The Choice: ");
}

void SensorsSetMenu()
{

    system("COLOR 09");
    printf("\n\n\n\n\n\t\t\t\t\t\t    Sensors set menu\n");
    printf("\t\t\t\t\t\t===============================\n");
    printf("\t\t\t\t\t\t[1] Turn OFF the vehicle engine.\n");
    printf("\t\t\t\t\t\t[2] Set the traffic light color.\n");
    printf("\t\t\t\t\t\t[3] Set the Room Temperature.\n");
    printf("\t\t\t\t\t\t[4] Set the Engine Temperature.\n");

    printf("\t\t\t\t\t\t===============================\n");
    printf("\t\t\t\t\t\t    Enter The Choice: ");

    //scanf("%d",Choice);
}

void SetEngineSpeed(struct Sensors *s,struct vcs *v)
{
    printf("Enter traffic light color : ");
    scanf(" %c",&s->TLC);
    switch(s->TLC)
    {
    case 'G':
        v->speed = 100;
       // printf("\n%d\n",v->speed);
        break;
    case 'O':
        v->speed = 30;
        //printf("\n%d\n",v->speed);
        break;
    case 'R':
        v->speed = 0;
        //  printf("\n%d\n",v->speed);
        break;
    default :
        printf("\n wrong enter \n");
        break;
    }


}

void SetACState(struct Sensors *s,struct vcs *v)
{
    printf("Enter Room Temp : ");
    scanf("%d",&s->RT);
    if(s->RT< 10)
    {
        v->ACState = ON;
        s->RT = 20;
        //  printf("\n%d\n",s->RT);
    }
    else if(s->RT > 30)
    {
        v->ACState = ON;
        s->RT = 20;
        //  printf("\n%d\n",s->RT);
    }
    else
    {
        v->ACState=OFF;
    }

}

void SetEnginTemp(struct Sensors *s,struct vcs *v)
{
    printf("Please Enter Engine Temp : ");
    scanf("%d",&s->ET);
    if(s->ET < 100)
    {
        v->EnginTempC = ON;
        s->ET= 125;
        // printf("\n%d\n",s->ET);
    }
    else if(s->ET > 150)
    {
        v->EnginTempC = ON;
        s->ET= 125;
        // printf("\n%d\n",s->ET);
    }
    else
    {
        v->EnginTempC = OFF;
    }

}

void UpdateState (struct Sensors *s,struct vcs *v)
{
    if(v->speed==3&&v->ACState==OFF)
    {
        v->ACState = ON;
        s->RT *= ((5/4)+1);

        v->EnginTempC= ON;
        s->ET *= ((5/4)+1);
    }
}


void PrinrSS(struct Sensors *s,struct vcs *v)
{
    system("cls");
    printf("Vehicle State:\n");
    printf("Engine state: %s\n", v->VehicleState ? "ON" : "OFF");
    printf("AC: %s\n", v->ACState ? "ON" : "OFF");
    printf("Vehicle Speed: %d km/hr\n", v->speed);
    printf("Room Temperature: %d\n", s->RT);
    printf("Engine Temperature Controller State: %s\n", v->EnginTempC ? "ON" : "OFF");
    printf("Engine Temperature: %d\n", s->ET);
}

int SSM(struct Sensors *s,struct vcs *v)
{

    int  R5Option=0,flag=1;
    while(flag==1)
    {
        SensorsSetMenu();
        scanf(" %d",&R5Option);

        switch(R5Option)
        {
        case 1:

            v->VehicleState=OFF;
            break;
        case 2:

            system("cls");
            system("COLOR 02");
            printf("\n\t\t **** SetEngineSpeed ****\n\n");
            SetEngineSpeed(&s,&v);
            flag=0;
            break;
        case 3:

            system("cls");
            system("COLOR 02");
            printf("\n\t\t\t\t\t*** SetACState***\n\n");
            SetACState(&s,&v);
            flag=0;
            break;
        case 4:

            system("cls");
            system("COLOR 02");
            printf("\n\t\t\t\t\t*** SetEnginTemp***\n\n");
            SetEnginTemp(&s,&v);
            flag=0;
            break;
        default:
            printf("\n\t\t\t\t\t\tInvalid number entered\n");
        }
    }
}

void VCS (struct Sensors *s,struct vcs *v)
{

    int  R1Option=0,flag=1,firstrunflag=0;;
    v->VehicleState=OFF;
    while(1)
    {
        menu();
        scanf(" %d",&R1Option);
        switch(R1Option)
        {
        case 0:
            ExitProject();
            break;
        case 1:
   while(1)
    {
                system("cls");
            system("COLOR 02");
            printf("\n\t\t **** ON ****\n\n");
            if(firstrunflag==0)
            {
                SetEngineSpeed(&s,&v);
                SetACState(&s,&v);
                SetEnginTemp(&s,&v);
                UpdateState(&s,&v);
                firstrunflag++;
            }
          //  printf("\n\t\t **** ON2 ****\n\n");
          //  system("cls");
            UpdateState(&s,&v);
            PrinrSS(&s,&v);
            SSM(&s,&v);
            UpdateState(&s,&v);
            PrinrSS(&s,&v);
   }

            //GoBackOrExit();
            break;
        case 2:

            // system("cls");
            //  system("COLOR F0");
            //  printf("\n\t\t\t\t\t*** 2***\n\n");
            //  GoBackOrExit();
            break;

        default:
            printf("\n\t\t\t\t\t\tInvalid number entered\n");
            GoBackOrExit();
        }
    }
}
