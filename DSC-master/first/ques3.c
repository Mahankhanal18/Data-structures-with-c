// 3. Design a C program to store details of COVID patients using structures.
// The details should include: Name, Age, Blood Group, Symptoms(Fever, Cold, Headache,
// cough, Body pain) and address

#include<stdio.h>

struct symptoms{
    char fever[10];
    char cold[10];
    char headache[10];
    char cough[10];
    char bodyPain[10];
};
struct detailsOfPatients{
    char name[20], bloodGroup[5], address[20];
    int age;
    struct symptoms patientDetail;
};

int main(){
    struct detailsOfPatients patient[100];
    int i, numberOfPatients;
    printf("Enter the number of patients: ");
    scanf("%d",&numberOfPatients);
    
    for (i=0; i<numberOfPatients; i++){
    printf("Enter the name of the patient %d: \n", i);
    scanf("%s",patient[i].name);
    printf("Enter the age of the patient %d: \n", i);
    scanf("%d",&patient[i].age);
    printf("Enter the blood group of the patient %d: \n", i);
    scanf("%s",patient[i].bloodGroup);
    
    printf("Does the patient %d have fever? : \n", i );
    scanf("%s",patient[i].patientDetail.fever);
    printf("Does the patient %d have cold? : \n", i );
    scanf("%s",patient[i].patientDetail.cold);
    printf("Does the patient %d have headache? : \n", i );
    scanf("%s",patient[i].patientDetail.headache);
    printf("Does the patient %d have cough? : \n", i );
    scanf("%s",patient[i].patientDetail.cough);
    printf("Does the patient %d have body pain? : \n", i );
    scanf("%s",patient[i].patientDetail.bodyPain);
    
    printf("Enter the address of the patient %d: \n",i);
    scanf("%s",patient[i].address);
    }
    
    for (i=0; i<numberOfPatients; i++){
        printf("The name of the patient %d is: %s \n", i, patient[i].name);
        printf("The age of the patient %d is: %d \n", i, patient[i].age);
        printf("The blood group of the patient %d is: %s \n", i, patient[i].bloodGroup);
        printf("Fever: %s \n",patient[i].patientDetail.fever);
        printf("Cold: %s \n",patient[i].patientDetail.cold);
        printf("Headache: %s \n",patient[i].patientDetail.headache);
        printf("Cough: %s \n",patient[i].patientDetail.cough);
        printf("Body Pain: %s \n",patient[i].patientDetail.bodyPain);
        printf("The address of the patient %d is: %s \n", i, patient[i].address);
    }
    
}