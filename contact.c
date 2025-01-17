#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"

void listContacts(AddressBook *addressBook) 
{
  //print till contactcount
    for(int i=0;i<addressBook->contactCount;i++){
      printf("CONTACT %d\n",i+1);
        printf("Name:  %s\nPhone: %s\nEmail: %s\n\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}
void initialize(AddressBook *addressBook) {    
    loadContactsFromFile(addressBook); //load contacts from file 
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
}

void createContact(AddressBook *addressBook)
{
	printf("Enter name:");
  int res1;
    do{
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
      res1=nameVal(addressBook,addressBook->contacts[addressBook->contactCount].name);
      if(res1){
        printf("Enter a valid name:");
      }
    }
    while(res1!=0);

    printf("Enter mobile no:");
    int res2;
    do{
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
    res2=mobVal(addressBook,addressBook->contacts[addressBook->contactCount].phone);
    if(res2==2){
      printf("Enter a vaild mobile number:");
     }
     else if(res2==1){
      printf("Same number is present!\n");
      printf("Enter other number:");
     }
    }
    while(res2!=0);

    printf("Enter email:");
    int res3;
    do{
    scanf("%s",addressBook->contacts[addressBook->contactCount].email);
    res3=emailVal(addressBook,addressBook->contacts[addressBook->contactCount].email);
    if(res3==2){
      printf("Enter a vaild email:");
    }
    else if(res3==1){
      printf("Same email is present!\n");
      printf("Enter other email:");
    }
   }
   while(res3!=0);
   printf("Contact created successfully");
   //after creating a new data contactcount in incremented
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook)
{
  int sc,flag=0;
  do{
  printf("Search by:\n1.Name\n2.Phone\n3.Email\n4.Go back\nEnter choice:");
  scanf(" %d",&sc);
  char sname[30],pnum[11],Email[30];
  int resN,resP,resE;
  if(sc==1){
    printf("Enter name:");
  }
  else if(sc==2){
    printf("Enter phone number:");
  }
  else if(sc==3){
    printf("Enter Email:");
  }
  switch(sc){
  
    case 1:
    scanf(" %[^\n]",sname);
    printf("\n");
    int i;
    resN=nameVal(addressBook,sname);
    if(resN==1){
      printf("Enter a valid name\n");
    }
    else{
      for(i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].name,sname)==0){
        printf("CONTACT %d\n",i+1);
        printf("Name:  %s\nPhone: %s\nEmail: %s\n\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        flag=1;
        }
      }
      if(flag==0){
        printf("Name not present!\nEnter name which is present\n");
      }
    }
    break;

    case 2:
    scanf(" %s",pnum);
    printf("\n");
    resP=mobVal(addressBook,pnum);
    if(resP==2){
      printf("Enter a valid phone number\n");
    }
    else if(resP==0){
      printf("Phone number not found!\n");
    }
    else{
      for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].phone,pnum)==0){
        printf("CONTACT %d\n",i+1);
        printf("Name:  %s\nPhone: %s\nEmail: %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        flag=1;
        }
      }
    }
    break;

    case 3:
    scanf(" %[^\n]",Email);
    printf("\n");
    resE=emailVal(addressBook,Email);
    if(resE==2){
      printf("Enter a valid Email\n");
    }
    else if(resE==0){
      printf("Email not found!\n");
    }
    else{
      for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].email,Email)==0){
        printf("CONTACT %d\n",i+1);
        printf("Name:  %s\nPhone: %s\nEmail: %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        flag=1;
        }
      }
    }
    break;

    case 4:
    flag=1;
    break;

    default:
    printf("Invalid choice!\n");
  }
}while(flag!=1);
}
    
void editContact(AddressBook *addressBook)
{
  int sc,count=0,x,indi=0;
     do{
  printf("Search by:\n1.Name\n2.Phone\n3.Email\n4.Go back\nEnter choice:");
  scanf(" %d",&sc);
  int resP,resE;
  if(sc==1){
    printf("Enter name to edit:");
  }
  else if(sc==2){
    printf("Enter phone number to edit:");
  }
  else if(sc==3){
    printf("Enter Email to edit:");
  }
  switch(sc){
  
    case 1:
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name); 
    printf("\n");

     for(int i=0;i<addressBook->contactCount;i++){
    if((strcmp(addressBook->contacts[addressBook->contactCount].name,addressBook->contacts[i].name))==0){
        printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        count++;
        x=i;
    }
  }
   if(count==0){
    printf("Name not found!\n");
  }
  else if(count==1){
   int flag=0;
    do{
      printf("Enter new name:");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
      if(nameVal(addressBook,addressBook->contacts[addressBook->contactCount].name)){
         printf("Enter a valid name\n");
      }
      else{
      strcpy(addressBook->contacts[x].name,addressBook->contacts[addressBook->contactCount].name);
      flag=1;
      }
    }while(flag!=1);

    do{
    printf("Enter new Phone number:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
    resP=mobVal(addressBook,addressBook->contacts[addressBook->contactCount].phone);
      if(resP==2){
      printf("Enter a vaild mobile number\n");
     }
     else if(resP==1){
      printf("Same number is present!\n");
     }
     else{
      strcpy(addressBook->contacts[x].phone,addressBook->contacts[addressBook->contactCount].phone);
      flag=1;
      }
    }while(resP!=0);

    do{
    printf("Enter new Email:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].email);
    resE=emailVal(addressBook,addressBook->contacts[addressBook->contactCount].email);
    if(resE==2){
      printf("Enter a vaild email\n");
    }
     else if(resE==1){
      printf("Same email is present!\n");
    }
    else{
      strcpy(addressBook->contacts[x].email,addressBook->contacts[addressBook->contactCount].email);
      flag=1;
      printf("Contact edited successfully\n\n");
      }
    }while(resE!=0);
  }

  else if(count>1){
    int i,flag=0;
    printf("Multiple names are present!\nEnter phone number to confirm:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
         for(i=0;i<addressBook->contactCount;i++){
         if((strcmp(addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[i].phone))==0){
          break;
    }
  }
  do{
      printf("Enter new name:");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
      if(nameVal(addressBook,addressBook->contacts[addressBook->contactCount].name)){
        printf("Enter a valid name\n");
      }
      else{
      strcpy(addressBook->contacts[x].name,addressBook->contacts[addressBook->contactCount].name);
      flag=1;
      }
    }while(flag!=1);

      do{
    printf("Enter new Phone number:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
    resP=mobVal(addressBook,addressBook->contacts[addressBook->contactCount].phone);
      if(resP==2){
      printf("Enter a vaild mobile number\n");
     }
     else if(resP==1){
      printf("Same number is present!\n");
     }
     else{
      strcpy(addressBook->contacts[x].phone,addressBook->contacts[addressBook->contactCount].phone);
      flag=1;
      }
    }while(resP!=0);

    do{
    printf("Enter new Email:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].email);
    resE=emailVal(addressBook,addressBook->contacts[addressBook->contactCount].email);
    if(resE==2){
      printf("Enter a vaild email\n");
    }
     else if(resE==1){
      printf("Same email is present!\n");
    }
    else{
      strcpy(addressBook->contacts[x].email,addressBook->contacts[addressBook->contactCount].email);
      flag=1;
      indi=1;
      printf("Contact edited successfully\n\n");
      }
    }while(resE!=0);
  }
  else{
    printf("Phone number not found!\n");
  }
  break;

  case 2:
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone); 
    printf("\n");

     for(int i=0;i<addressBook->contactCount;i++){
    if((strcmp(addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[i].phone))==0){
        printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        count++;
        x=i;
        break;
    }
  }
  if(count==0){
    printf("Phone number not found!");
  }
  else{
    int flag=0;
    do{
      printf("Enter new name:");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
      if(nameVal(addressBook,addressBook->contacts[addressBook->contactCount].name)){
         printf("Enter a valid name\n");
      }
      else{
      strcpy(addressBook->contacts[x].name,addressBook->contacts[addressBook->contactCount].name);
      flag=1;
      }
    }while(flag!=1);

    do{
    printf("Enter new Phone number:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
    resP=mobVal(addressBook,addressBook->contacts[addressBook->contactCount].phone);
      if(resP==2){
      printf("Enter a vaild mobile number\n");
     }
     else if(resP==1){
      printf("Same number is present!\n");
     }
     else{
      strcpy(addressBook->contacts[x].phone,addressBook->contacts[addressBook->contactCount].phone);
      flag=1;
      }
    }while(resP!=0);

    do{
    printf("Enter new Email:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].email);
    resE=emailVal(addressBook,addressBook->contacts[addressBook->contactCount].email);
    if(resE==2){
      printf("Enter a vaild email\n");
    }
     else if(resE==1){
      printf("Same email is present!\n");
    }
    else{
      strcpy(addressBook->contacts[x].email,addressBook->contacts[addressBook->contactCount].email);
      flag=1;
      indi=1;
      printf("Contact edited successfully\n\n");
      }
    }while(resE!=0);
  }
    break;

    case 3:
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email); 
    printf("\n");

     for(int i=0;i<addressBook->contactCount;i++){
    if((strcmp(addressBook->contacts[addressBook->contactCount].email,addressBook->contacts[i].email))==0){
        printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        count++;
        x=i;
        break;
    }
  }
  if(count==0){
    printf("Phone number not found!");
  }
  else{
    int flag=0;
    do{
      printf("Enter new name:");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
      if(nameVal(addressBook,addressBook->contacts[addressBook->contactCount].name)){
         printf("Enter a valid name\n");
      }
      else{
      strcpy(addressBook->contacts[x].name,addressBook->contacts[addressBook->contactCount].name);
      flag=1;
      }
    }while(flag!=1);

    do{
    printf("Enter new Phone number:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
    resP=mobVal(addressBook,addressBook->contacts[addressBook->contactCount].phone);
      if(resP==2){
      printf("Enter a vaild mobile number\n");
     }
     else if(resP==1){
      printf("Same number is present!\n");
     }
     else{
      strcpy(addressBook->contacts[x].phone,addressBook->contacts[addressBook->contactCount].phone);
      flag=1;
      }
    }while(resP!=0);

    do{
    printf("Enter new Email:");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].email);
    resE=emailVal(addressBook,addressBook->contacts[addressBook->contactCount].email);
    if(resE==2){
      printf("Enter a vaild email\n");
    }
     else if(resE==1){
      printf("Same email is present!\n");
    }
    else{
      strcpy(addressBook->contacts[x].email,addressBook->contacts[addressBook->contactCount].email);
      flag=1;
      indi=1;
      printf("Contact edited successfully\n\n");
      }
    }while(resE!=0);
  }

  case 4:
  indi=1;
  }
  }while(indi!=1);
}

void deleteContact(AddressBook *addressBook)
{
  int sc,flag=0,count=0;
  do{
  printf("Search by:\n1.Name\n2.Phone\n3.Email\n4.Go back\nEnter choice:");
  scanf(" %d",&sc);
  char sname[30],pnum[11],Email[30];
  int resN,resP,resE;
  if(sc==1){
    printf("Enter name to deleted:");
  }
  else if(sc==2){
    printf("Enter phone number deleted:");
  }
  else if(sc==3){
    printf("Enter Email to be deleted:");
  }
  switch(sc){
  
    case 1:
    scanf(" %[^\n]",sname);
    printf("\n");

       for(int i=0;i<addressBook->contactCount;i++){
         if((strcmp(sname,addressBook->contacts[i].name))==0){
        count++;
    }
  }
  if(count<=1){
    for(int i=0;i<addressBook->contactCount;i++){
         if((strcmp(sname,addressBook->contacts[i].name))==0){
           for(int j=i;j<addressBook->contactCount;j++){
             addressBook->contacts[j]=addressBook->contacts[j+1];
            }
        flag=1;
        printf("Contact delected sucessfully\n");
        break;
    }
  }
  addressBook->contactCount--;
  }

  else if(count>1){
    printf("Multiple names are present!\nEnter phone number to confirm:");
    scanf(" %[^\n]",pnum);
         for(int i=0;i<addressBook->contactCount;i++){
         if((strcmp(pnum,addressBook->contacts[i].phone))==0){
           for(int j=i;j<addressBook->contactCount;j++){
             addressBook->contacts[j]=addressBook->contacts[j+1];
            }
        flag=1;
        printf("Contact delected sucessfully\n");
        break;
    }
  }
  addressBook->contactCount--;
  if(flag==0){
    printf("Phone number not found!\n");
  }
  }
    break;

    case 2:
    scanf(" %s",pnum);
    printf("\n");
    resP=mobVal(addressBook,pnum);
    if(resP==2){
      printf("Enter a valid phone number\n");
    }
    else if(resP==0){
      printf("Phone number not found!\n");
    }
    else{
       for(int i=0;i<addressBook->contactCount;i++){
         if((strcmp(pnum,addressBook->contacts[i].phone))==0){
           for(int j=i;j<addressBook->contactCount;j++){
             addressBook->contacts[j]=addressBook->contacts[j+1];
            }
        flag=1;
        printf("Contact delected sucessfully\n");
        break;
    }
  }
  addressBook->contactCount--;
}
    break;

    case 3:
    scanf(" %[^\n]",Email);
    printf("\n");
    resE=emailVal(addressBook,Email);
    if(resE==2){
      printf("Enter a valid Email\n");
    }
    else if(resE==0){
      printf("Email not found!\n");
    }
       else{
       for(int i=0;i<addressBook->contactCount;i++){
         if((strcmp(Email,addressBook->contacts[i].email))==0){
           for(int j=i;j<addressBook->contactCount;j++){
             addressBook->contacts[j]=addressBook->contacts[j+1];
            }
        flag=1;
        printf("Contact delected sucessfully\n");
        break;
    }
  }
  addressBook->contactCount--;
}
    break;

    case 4:
    flag=1;
    break;

    default:
    printf("Invalid choice!\n");
  }
}while(flag!=1);
}
//name validation
int nameVal(AddressBook *addressBook,char* name){
    for(int i=0;name[i]!=0;i++){
      //input should only have alphabets and space
      if(isalpha(name[i]) || name[i]==' '){
      }
      else{
        //if not a valid name
        return 1;
      }
    }
    //if it only contains alphabets
    return 0;
}

//phone no validation
int mobVal(AddressBook *addressBook,char* phone){
  int invalphone=0,count=0;
  for(int i=0;phone[i]!=0;i++){
      if(!(isdigit(phone[i]))){
        //if any character is not a digit
        invalphone=1;
      }
    }
    //to find length of number
    int len=strlen(phone);
    for(int i=0;i<addressBook->contactCount;i++){
      //to check if same number is present in the file
        if(strcmp(addressBook->contacts[i].phone,phone)==0){
          count++;
        }
      }
      //if it has all digits,length is 10,not repeated
    if(invalphone==0 && len==10 && count==0){
      return 0;
    }
    //if the number is repeated
    else if(count>0){
      return 1;
    }
    else{
      //if number is invalid
      return 2;
    }
}

int emailVal(AddressBook *addressBook,char* email){
  int invalemail=0,count=0;
  //to check @ is present or not
  char* pos=strchr(email,'@');
  //.com should not be next to @
  if(pos != NULL && strstr(email,".com")!=pos+1){
    invalemail=1;
  }
   for(int i=0;i<addressBook->contactCount;i++){
    //to check if same email is present in file
        if(strcmp(addressBook->contacts[i].email,email)==0){
          count++;
        }
      }
      //if same id is not present and a vaild id
      if(count==0 && invalemail==1){
        return 0;
      }
      //same id is present in file
      else if(count>0){
        return 1;
      }
      //invalid id
      else{
        return 2;
      }
}

//to save the contacts is user directly exits after changing the details
void exit1(AddressBook *addressBook){
  printf("The contacts are not saved!\n");
  printf("press y/n to save or not:");
  char ch;
  scanf(" %c",&ch);
  //if y is pressed it saves the file
  if(ch == 'y'){
    printf("Saving and Exiting...\n");
    saveContactsToFile(addressBook);
    exit(0);
  }
  else{
    //directly exits
    exit(0);
  }
}