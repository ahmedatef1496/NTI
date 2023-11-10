#include <stdio.h>
#include <stdlib.h>

#define ENCRYPT 0
#define DECRYPT 1

void Encrypt_Decrypt();
void Encrypt(char *arr, char key);
void Decrypt(char *arr, char key);
void array_hash();

unsigned char arr[265]=
{ 5,196,13,39,15 , 39 , 70 ,158, 148, 177, 128 ,201 ,243 ,109 ,188 , 16 ,         \
 56, 117 , 32 ,165 ,255 ,143 ,197, 240, 146 ,232 ,103  ,89 ,222 ,105  ,93,207 ,     \
 48,  44 ,231, 108,  94,  25,  83,  11, 21,  22, 150,  25, 130,   8,  21,  26 ,    \
 10, 105 ,199, 110,  64,  20,  41, 243,  18, 160,   0, 123, 148, 115, 199, 229 ,    \
 89,  14 ,29, 119, 20, 233, 138, 171, 207, 165, 107, 221, 204,  72, 134,  43 ,    \
 39,  66 ,172, 145,  86, 196,  4, 170,  13,  97,  41, 161, 179, 221,  2, 163 ,    \
199, 144 ,120, 206, 18,  25, 141,   1,  47, 17,   0,  24, 135, 181,  94,  76 ,    \
 17, 174 ,213, 23, 216, 148, 190, 205, 104, 101,   8,  99, 251, 233, 249,   5 ,    \
 29,  40 ,195, 253, 195,  64, 255,  92,  69,  11, 214,  36, 245,   2, 229, 157 ,    \
 88,  27 , 89, 129, 191,  2,  50,   77,  56, 219, 138, 216,  54, 170,  71,  10 ,    \
118,  19 ,147,  74,  82, 144, 125,  74,  67,  22,  85,  36, 163, 180,  69, 131 ,    \
 55,  78 ,140, 102, 184, 221,  9, 249,  86, 218, 231, 182, 103, 229, 153, 186 ,    \
  2, 145 , 33, 22,  39,  65, 137, 140, 197, 176, 100, 152, 195, 153,  80,  98 ,    \
 16, 122 ,159, 133, 183,  33,  90, 241, 226, 167, 161, 153, 151,  21, 236, 255 ,    \
171, 132 , 88,  30, 165, 181, 217, 188, 160,  96,  15, 127, 200, 214,  22,  28,     \
199,   9 , 32,  18,198 ,125 , 82 , 210, 237 ,20 ,129 ,191 ,162 ,182 , 71 ,146 };

unsigned char arr_1[16];

int main()
{
   // Encrypt_Decrypt();
   array_hash();
    return 0;
}


void Encrypt_Decrypt()
{
    char key = 0;
    char process = 0;
    char Arr[2000];
    while(1)
    {
        printf("Enter the process\nEncrypt -> 0\nDecrypt -> 1\nEnd -> 2\n");
        scanf("%d",&process);
        switch(process)
        {
        case ENCRYPT:
            printf("Enter the Key value :");
            scanf("%d",&key);
            printf("Enter the Message :");
            scanf("%s",Arr);
            Encrypt(Arr,key);
            break;
        case DECRYPT:
            printf("Enter the Key value :");
            scanf("%d",&key);
            printf("Enter the Message :");
            scanf("%s",Arr);
            Decrypt(Arr,key);
            break;
        case 2:
            return 0;
            break;
        default:
            break;
        }
        printf("the Message : %s\n",Arr);
    }

}

void Encrypt(char *arr, char key)
{
    char counter = 0;
    char buffer_F = 0;
    char Flag = 0;
    if(key > 26)
    {
        key %= 26;

    }
    char KEY = key;
    while(arr[counter] != '\0')
    {
        if( Flag )
        {
            key = KEY;
            Flag = 0;
        }
        if(arr[counter] > 'Z')
        {
            arr[counter] -= 32;
            buffer_F = 1;
        }
        if((arr[counter] + key)>'Z')
        {

            if( !Flag )
            {
               key -= (('Z'-arr[counter])+1);
               Flag = 1;
            }
            arr[counter] = 'A';
        }
        arr[counter] += key;
        if(buffer_F)
        {
            arr[counter] += 32;
            buffer_F = 0;
        }
        counter++;
    }
}


void Decrypt(char *arr , char key)
{
    char counter = 0;
    char buffer_F = 0;
    char Flag = 0;
    if(key > 26)
    {
        key %= 26;
    }
    char KEY = key;
    while(arr[counter] != '\0')
    {
        if( Flag )
        {
            key = KEY;
            Flag = 0;
        }
        if(arr[counter] > 'Z')
        {
            arr[counter] -= 32;
            buffer_F = 1;
        }
        if((arr[counter] - key)<'A')
        {
            if( !Flag )
            {
               key -= (arr[counter] - 'A')+1;
               Flag = 1;
            }
            arr[counter] = 'Z';
        }
        arr[counter] -= key;
        if(buffer_F)
        {
            arr[counter] += 32;
            buffer_F = 0;
        }
        counter++;
    }
}

void array_hash()
{

        for(int i =0; i <=15 ; i++)
    {
        for(int j =i*0; j <=i*15 ; j++)
        {
            arr_1[i] += arr[j];
        }
    }
    printf("[");
    printf("%d",arr_1[0]);
    for(int i =1; i <=15 ; i++)
    {
        printf("-%d",arr_1[i]);
    }
    printf("]\n");

}
