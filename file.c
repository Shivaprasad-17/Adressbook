#include <stdio.h>
#include "file.h"

void loadContactsFromFile(AddressBook *addressBook){
  //to open file in ram
  FILE* fptr=fopen("contacts.txt","r");
  //if file is not present
  if(fptr==NULL){
    printf("File not present!");
  }
  //copy details from file to structure
  fscanf(fptr,"%d\n",&addressBook->contactCount);
  for(int i=0;i<addressBook->contactCount;i++){
    fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
  }
  //closing the file 
  fclose(fptr);
}

void saveContactsToFile(AddressBook *addressBook){
  FILE* fptr=fopen("contacts.txt","w");
  //writing to the file
  fprintf(fptr,"%d\n",addressBook->contactCount);
  for(int i=0;i<addressBook->contactCount;i++){
    fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
  }
  //closing the file
  fclose(fptr);
}
