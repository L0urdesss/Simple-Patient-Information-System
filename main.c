// MARIA LOURDES T. VILLARUZ
// SIMPLE PATIENT INFORMATION SYSTEM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    char name[100];
    char address[100];
    char illness[100];
} Patient;

// Function prototypes
void encrypt(char* str);
void decrypt(char* str);
void encrypt_num(int* num);
void decrypt_num(int* num);
void addPatient();
void searchPatient();
void clearScreen();

int main() {
    char choice;
    
    do {
        printf("\nSIMPLE PATIENT INFORMATION SYSTEM\n");
        printf("\n1. Add Patient\n");
        printf("2. Search Patient's Data\n");
        printf("3. Exit\n");
        printf("\nSelect an option: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                addPatient();
                break;
            case '2':
                searchPatient();
                break;
            case '3':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                clearScreen();
                break;
        }
    } while (choice != '3');
    
    return 0;
}

void encrypt(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] += 3;
    }
}

void decrypt(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] -= 3;
    }
}

void encrypt_num(int* num) {
    *num += 3;
}

void decrypt_num(int* num) {
    *num -= 3;
}

void addPatient() {
    clearScreen();
    FILE *fp;
    Patient patient;
    
    printf("Enter Patient Number: ");
    scanf("%d", &patient.num);
    encrypt_num(&patient.num);
    
    char filename[20];
    sprintf(filename, "patient%d.txt", patient.num);
    encrypt(filename); // encrypt the filename
    
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    printf("Enter Name: ");
    getchar(); // consume newline
    fgets(patient.name, sizeof(patient.name), stdin);
    patient.name[strcspn(patient.name, "\n")] = '\0';
    
    printf("Enter Address: ");
    fgets(patient.address, sizeof(patient.address), stdin);
    patient.address[strcspn(patient.address, "\n")] = '\0';
    
    printf("Enter Illness: ");
    fgets(patient.illness, sizeof(patient.illness), stdin);
    patient.illness[strcspn(patient.illness, "\n")] = '\0';
    
    // Encrypt sensitive data
    encrypt(patient.name);
    encrypt(patient.address);
    encrypt(patient.illness);
    
    fprintf(fp, "%d,%s,%s,%s\n", patient.num, patient.name, patient.address, patient.illness);
    fclose(fp);
    
    printf("\nSaved Successfully!\n");
    clearScreen();
}

void searchPatient() {
    clearScreen();
    FILE *fp;
    Patient patient;
    int search_num;
    
    printf("Enter patient number to search: ");
    scanf("%d", &search_num);
    encrypt_num(&search_num);
    
    char filename_search[20];
    sprintf(filename_search, "patient%d.txt", search_num);
    encrypt(filename_search);
    
    fp = fopen(filename_search, "r");
    if (fp != NULL) {
        fscanf(fp, "%d,%[^,],%[^,],%[^\n]\n", &patient.num, patient.name, 
              patient.address, patient.illness);
        
        // Decrypt the data for display
        decrypt_num(&patient.num);
        decrypt(patient.name);
        decrypt(patient.address);
        decrypt(patient.illness);
        
        printf("\nPatient Number: %d\n", patient.num);
        printf("Patient Name: %s\n", patient.name);
        printf("Patient Address: %s\n", patient.address);
        printf("Patient Illness: %s\n\n", patient.illness);
        
        fclose(fp);
    } else {
        printf("Patient not found.\n");
    }
    
    clearScreen();
}

void clearScreen() {
    system("pause");
    system("cls");
}