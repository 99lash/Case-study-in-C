#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
/* 
--------------GUIDELINE AND OUTLINE OF PROGRAM-------------
--DASHBOARD{
    [1] LOGIN PAGE
    [2] SIGN UP PAGE
    [3] EXIT 
}

--MENU{
    [G] START MATH WHIZ
    [L] LEADERBOARDS
    [A] ABOUT MATH WHIZ
    [X] EXIT OPTION
}

--ABOUT MATH WHIZ{
    [B] BACK TO MENU OPTION
}

--LEADERBOARDS{
    [B] BACK TO MENU OPTION
    [X] EXIT OPTION
}

--MATH WHIZ{

    [X] EXIT OPTION
}
-----------------------------------------------------------
*/

struct user
{
    char username[20];
    char password[12];
    struct progress{
        int stage, level;
    }mode[2];
};

//SIGNUP FUNCTION//
int signup(int isRegistered)
{   
    char option, username_checker[20], confirm_password[12], file_name[20];
    struct user account;
    FILE *details_handler;
    isRegistered = 0;

    tryagain:
    system("cls");
    printf("CREATE YOUR ACCOUNT");
    printf("\n\n\n");
    printf("Enter your username:\t");
    scanf("%s", &username_checker);
    printf("Enter your password:\t");
    scanf("%s", &account.password);
    printf("Confirm your passsword:\t");
    scanf("%s", &confirm_password);
    strcpy(file_name, username_checker);
    details_handler = fopen(strcat(file_name,".txt"),"w");
    if(details_handler == NULL) printf("ERROR_FILE_NOT_FOUND_3");
    if(!strcmp(account.username, username_checker)){
        printf("\nUSERNAME HAVE ALREADY EXIST!\n");
        fclose(details_handler);
        getch();
        return isRegistered;
        
    }
    else{
        if(!strcmp(account.password, confirm_password)){
            fwrite(&account, sizeof(struct user),1,details_handler);
            fclose(details_handler);
            printf("\nAccount has been created successfully\nPress any key to continue");
            getch();
            return isRegistered=1;
        }
        else{
            A:
            printf("\nPASSWORD DOES NOT MATCH\n\n\nPRESS [Y] TO TRY AGAIN \nPRESS [N] TO GO BACK TO DASHBOARD");
            option = getch();
            option = toupper(option);
            if(option == 89){ // ASCII CODE OF [Y] == 89
                system("cls");
                goto tryagain;
            }
            else if(option == 78){ // ASCII CODE OF [N] == 66
                return isRegistered-1;
            }
            else{
                system("cls");
                goto A;
            }
        }
    }
}//END OF SIGNUP FUNCTION//

//LOGIN FUNCTION//
int login(int isLogin)
{
    
    isLogin=0;
    char username_checker[20], password_checker[12], file_name[FILENAME_MAX];
    struct user account;
    FILE *details_handler;

    printf("LOGIN INTO YOUR ACCOUNT");
    printf("\n\n\n");
    printf("Username:\t");
    scanf("%s", username_checker);
    printf("Password:\t");
    scanf("%s", password_checker);
    strcpy(file_name,username_checker);
    details_handler = fopen(strcat(file_name,".txt"), "r");
    if(details_handler == NULL) { //find the account name using file_name
        printf("\nACCOUNT DOES NOT EXIST\n");
        fclose(details_handler);
        getch();
        system("cls");
        return isLogin = 0;
    } 
    else{
        while(fread(&account, sizeof(struct user),1, details_handler)!=EOF){
            if(!strcmp(account.password, password_checker)){
            isLogin = 1;
            break;
            }
            else{
            printf("\nINCORRECT PASSWORD");
            isLogin=0;
            getch();
            system("cls");
            break;
            }
        }
        fclose(details_handler);
    }
return isLogin;
}
//END OF LOGIN FUNCTION//

//MENU FUNCTION//

    
//END OF MENU FUNCTION
/*
//ABOUT FUNCTION
char about(char about_option){
    if(about_option != 66){ //ASCII CODE OF [B] == 66
        system("cls");
        printf("THIS IS ABOUT MATH WHIZ\n\n\n");
        printf("PRESS [B] TO GO BACK TO MENU\n");
        about_option = getch();
        about_option = toupper(about_option);
    }
    else return about_option;
}//END OF ABOUT FUNCTION//
*/

int main()
{   
    int isRegistered = 0, auth = 0;
    char dashboard_option, confirm_passsword[12], menu_option, about_option;
    struct user account;

    //FILE *details_handler;
    //DASHBOARD PAGE//
    dashboard:
    printf("MATH WHIZ\n\n\n");
    printf("[1] LOG IN\n[2] SIGN UP\n[3] EXIT\n\n\n");
    printf("PRESS THE CORRESPONDING KEY TO SELECT");
    dashboard_option = getch();
    //END OF DASHBOARD PAGE//
    if(dashboard_option == 49){//LOG IN PAGE FUNCTION // ASCII CODE OF [1] == 49
        system("cls");
        auth = login(auth);
        if(auth==0){
            goto dashboard;
        }
        else if(auth == 1){ 
            system("cls"); //MENU PAGE//
            while(menu_option != 71 && menu_option != 76 && menu_option != 65 && menu_option != 88){ // di ko maexplain and imagine kung bakit gumagana && instead of ||. BAKA PAGOD NA UTAK
                system("cls"); 
                printf("MATH WHIZ");
                printf("\n\n\n");
                printf("[G] START\n[L] LEADERBOARDS\n[A] ABOUT PAGE\n[X] EXIT");
                menu_option = getch();
                menu_option = toupper(menu_option);
                //END OF MENU PAGE //

                switch(menu_option){
                    case 71 : //MATH WHIZ GAME//
                        do{ //ASCII CODE OF [B] == 66
                            system("cls");
                            printf("MATH WHIZ GAME\n\n\n");
                            printf("PRESS [B] TO GO BACK TO MENU\n");
                            about_option = getch();
                            about_option = toupper(about_option);
                            if(about_option == 66) break;
                        }while(about_option != 66);
                        menu_option = 00; break;
                        //MATH WHIZ PAGE//
                    
                    case 76 : //LEADERBOARDS PAGE//
                        do{ //ASCII CODE OF [B] == 66
                            system("cls");
                            printf("LEADERBOARDS\n\n\n");
                            printf("PRESS [B] TO GO BACK TO MENU\n");
                            about_option = getch();
                            about_option = toupper(about_option);
                            if(about_option == 66) break;
                        }while(about_option != 66);
                        menu_option = 00; break;
                        //END OF LEADERBOARDS PAGE//

                    case 65 : //ABOUT PAGE//
                        do{ //ASCII CODE OF [B] == 66
                            system("cls");
                            printf("THIS IS ABOUT MATH WHIZ\n\n\n");
                            printf("PRESS [B] TO GO BACK TO MENU\n");
                            about_option = getch();
                            about_option = toupper(about_option);
                            if(about_option == 66) break;
                        }while(about_option != 66);
                        menu_option = 00; break;
                        //END OF ABOUT PAGE//

                    case 88 : exit(0);
                }
            }   
        }
    }//END LOG IN PAGE FUNCTION//
    else if(dashboard_option == 50){ // // ASCII CODE OF [2] == 50
        //SIGN UP PAGE FUNCTION//
        system("cls");
        isRegistered = signup(auth);
        if(isRegistered==1){
            system("cls");
            goto dashboard;
        }
        else if(isRegistered==-1){
            system("cls");
            goto dashboard;
        }//END OF SIGN UP PAGE FUNCTION//
    }
    else if(dashboard_option == 51){ // ASCII CODE OF [3] == 51
        //EXIT CODE
        return 1;
    }
    else{
        printf("\nINVALID KEY SELECTION\n");
        getch();
        system("cls");
        goto dashboard;
    }
return 0;
}