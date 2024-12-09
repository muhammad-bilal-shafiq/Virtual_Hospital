#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>

struct patient{
	char name[50];
	char weight[10];
	char phoneno[12];
	char MedID[7];
	char age[10];
	char height[10];
	char bloodtype[5];
	int S[13];
	int done;
	int diseases[5];
};
struct patient p[50];

struct time{

char table[6][6];

}time[11];

void home(int end);
void generateReceipt(struct patient *p, int booked);
void booking();



int main(){

//Creating Seating Layout

int i,j,k;
char cont,a='A';

for(i=0;i<11;i++){

for(j=0;j<6;j++){

for(k=0;k<6;k++){

time[i].table[j][k]=a;
}
}
}

home(0);



}

void home(int end){

int i,j,t,cont;
char choice;
home:

if(end==1) goto end;
do{

//HOME SCREEN

system("cls");
printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t");
for(i=0;i<41;i++)printf("=");
printf("\n\t\t\t\t\t\t\t\t\t\t\t\tWELCOME TO THE PAKISTAN DIGITAL HOSPITAL\t\t\n\t\t\t\t\t\t\t\t\t\t\t\t");
for(i=0;i<41;i++)printf("=");

printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t    Book Your Physical Appointment (1)\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Virtual Check-up (2)\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t   Exit(3)\n\n");
scanf(" %c",&choice);

switch(choice){

case '1':
booking();
break;

case '2':
generateReceipt(p, 0);
break;

case '3':
system("cls");
printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tExited Successfully");
sleep(1);
goto end;
break;
 
default:
printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tInvalid Input, Try again");
sleep(1);
break;
}

}while(choice!=3);

end:
end=0;
printf("\n\n\n\t\t\t\t\t\t\t\t\t\tEnter any key to continue: ");
scanf(" %c",&cont);
goto home;




}


void booking(){

int i,j,k;
char t1[10];
int t;


system("cls");
printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  OUR");
sleep(1);
system("cls");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t BOOKING");
sleep(1);
system("cls");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  LAYOUT");
sleep(1);
system("cls");

for(i=0;i<11;i++){

printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tFor %d:00 PM\n\n",i+1);

for(j=0;j<6;j++){

printf("\n\n\t\t\t\t\t\t\t\t\t\t ");
for(k=0;k<6;k++){

printf("\t%c",time[i].table[j][k]);
}

}
usleep(99999);
}


//CHECKING AVAILABILITY
//Flag2 for all day
//Flag1 for given time


int flag1=0,flag2=0;

for(k=0;k<11;k++){ //Checking for all day

for(i=0;i<6;i++){

for(j=0;j<6;j++){

if(time[k].table[i][j]=='A'){  
flag2=1;
goto flag2break;
}
}
}
}
flag2break: //GOTO LABEL
if(flag2==1){

choosetime: //CHOSE TIME LABEL (FOR GOTO STATMENT)

printf("\n\n\n\t\t\t\t\tEnter your time of arrival: ");
scanf(" %s",&t1);
t=atoi(t1);
if(t<1||t>11){
printf("\n\n\n\t\t\t\t\t\t\t\t\tPlease Select from given slots");
goto choosetime;
}

system("cls");
printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tFor %d:00 PM\n\n",t);
for(i=0;i<6;i++){

printf("\n\n\t\t\t\t\t\t\t\tRow %d)\t\t ",i+1);
for(j=0;j<6;j++){

printf("\t%d(%c)",j+1,time[t-1].table[i][j]);
}
}





//Checking for provided time
for(i=0;i<6;i++){

for(j=0;j<6;j++){

if(time[t-1].table[i][j]=='A'){
flag1=1;    
goto flag1break;
}
}
}
flag1break: //GOTO LABEL

if(flag1==1){

int r,c;
char row[2],col[2],s;

//CHOOSING THE TABLE
choosetable:

printf("\n\n\n\n\nEnter the row number you wish to dine in:\n");
scanf(" %s",&row);
printf("\nEnter the table number of Row: \n");
scanf(" %s",&col);
r=atoi(row);
c=atoi(col);
if(r<1||c<1||r>6||c>6){
printf("\n\n\n\n\n\t\t\t\t\t\t\t\tInvalid Input, Choose from following layout");
goto choosetable;
}
printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\tAre you sure you want to book this table ( Y/y | N/n ): ");
scanf(" %c",&s);

if(s=='Y'||s=='y'){


if(time[t-1].table[r-1][c-1]=='A'){
time[t-1].table[r-1][c-1]='B';


usleep(99999);

printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tBOOKED FOR %dPM\n",t);
for(i=0;i<6;i++){

printf("\n\n\t\t\t\t\t\t\t\t\t\t    ");
for(j=0;j<6;j++){

printf("\t%c",time[t-1].table[i][j]);
}
}

home(1);


}
else{
printf("\n\nCHOOSE ANOTHER TABLE:");
goto flag1break;
}
}
else if(s=='n'||s=='N'){
system("cls");
printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tFor %d:00 PM\n\n",t);
for(i=0;i<6;i++){

printf("\n\n\t\t\t\t\t\t\t\tRow %d)\t\t ",i+1);
for(j=0;j<6;j++){

printf("\t%d(%c)",j+1,time[t-1].table[i][j]);
}
}
sleep(1);
goto choosetable;
}
else{
printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input");
goto choosetable;
}
}
else{
printf("ALL BOOKED CHOOSE ANOTHER TIME");
goto choosetime;
}
}
else
printf("\n\nALL BOOKED COME BACK LATER :)");
sleep(2);

}

	
	void generateReceipt(struct patient *p, int booked){
	system("cls");
	char cont;
	int count=0;
	char inp='y';
	char inps='y';
	int i=0;
		
	printf("Enter your name: ");
	scanf("%s",&p[i].name);
	printf("Enter your weight: ");
	scanf("%f",&p[i].weight);
	printf("Enter your Phone Number: ");
	scanf("%d",&p[i].phoneno);
	printf("Enter your Medical ID (Seven Digits):");
	scanf("%s",&p[i].MedID);
	printf("Enter your age:");
	scanf("%d",&p[i].age);
	printf("Enter your height(in cm):");
	scanf("%f",&p[i].height);
	printf("Enter your blood type:");
	scanf("%s",&p[i].bloodtype);
	printf("\n//////Check Up Started//////");
		printf("\n0-Fever\n1-Cough\n2-Short of Breath\n3-Aches\n4-Fatigue\n5-Runny Nose\n6-Sneezing\n7-Sore Throat\n8-Abdominal Pain\n9-Bowel Movement\n10-WateryStools\n11-Chest Pain\n12-Wheezing while coughing");
		while(inps=='y'){
			int i=0;
			int check;
			//GOTOLABEL
			chooseSymptom:
			printf("\nEnter the ID no of the symptoms shown on the list: \n");
			scanf("%d",&check);
			switch(check){
				case 0:
					p[i].S[0]=1;
					p[i].diseases[0]++;
					p[i].diseases[1]++;
					p[i].diseases[3]++;
					count++;
					break;
				case 1:
					p[i].S[1]=1;
					p[i].diseases[0]++;
					p[i].diseases[1]++;
					p[i].diseases[2]++;
					count++;
					break;
				case 2:
					p[i].S[2]=1;
					p[i].diseases[0]++;
					p[i].diseases[4]++;
					count++;
					break;
				case 3:
					p[i].S[3]=1;
					p[i].diseases[0]++;
					p[i].diseases[1]++;
					count++;
					break;
				case 4:
					p[i].S[4]=1;
					p[i].diseases[1]++;
					count++;
					break;
				case 5:
					p[i].S[5]=1;
					p[i].diseases[2]++;
					count++;
					break;
				case 6:
					p[i].S[6]=1;
					p[i].diseases[2]++;
					count++;
					break;
				case 7:
					p[i].S[7]=1;
					p[i].diseases[2]++;
					count++;
					break;
				case 8:
					p[i].S[8]=1;
					p[i].diseases[3]++;
					count++;
					break;
				case 9:
					p[i].S[9]=1;
					p[i].diseases[3]++;
					count++;
					break;
				case 10:
					p[i].S[10]=1;
					p[i].diseases[3]++;
					count++;
					break;
				case 11:
					p[i].S[11]=1;
					p[i].diseases[4]++;
					count++;
					break;			
				case 12:
					p[i].S[12]=1;
					p[i].diseases[4]++;
					count++;
					break;
				default:
				    printf("Please Enter Valid Option");
					break;		
			}
                if(count>=3){
				printf("Do you want to enter more symptoms?(y/n):");
				scanf(" %c",&inps);
			    }
			    else if(count<=3){
			    	goto chooseSymptom;
				}
		
			}
			int greatest=-9999, index, j, n=0;
			for(j=0;j<5;j++){
				if(p[i].diseases[j]>greatest){
					greatest=p[i].diseases[j];
					index=j;
				}
				else
				continue;
			}
			
			printf("////////PRESCRIPTION RECEIPT////////");
			printf("\n\tName: %s",p[i].name);
			printf("\n\tMedID: %s",p[i].MedID);
			printf("\n\tBlood Group: %s\n",p[i].bloodtype);
			
			for(j=0;j<5;j++){
				n++;
				if(j == index){
					continue;
				}
				else if(p[i].diseases[j] == greatest){
					printf("book a physical check-up to get a proper diagnosis of your condition");
					break;
				}
			}
			
			if(n==5){
					switch(index){
						case 0 :
							printf("\n\tyou have covid\n");
							printf("List of Medicines\n\t1)Azithromycin 250mg\n\t2)Paracetemol 500mg\n\t3)Coferb Cough Syrup 125ml\n\t4)Ipatropium Bromide 500mcg\n");
							break;
						case 1 :
							printf("\n\tyou have influenza\n");
							printf("List of Medicines\n\t1)Paracetemol 500mg\n\t2)Zanamivir 250mg\n\t3)Coferb Cough Syrup 125ml\n");
							break;
						case 2 :
							printf("\n\tyou have cold\n");
							printf("List of Medicines\n\t1)Coferb Cough Syrup 125ml\n\t2)Naproxen 150mg\n\t3)Echinacea Suppplement 200mg\n\t4)Paracetemol 500mg\n");
							break;
						case 3 :
							printf("\n\tyou have diarrhea\n");
							printf("List of Medicines\n\t1)Imodium 200ml\n\t2)Pepto Bismol 170mg\n\t3)Azithromycin 200mg\n\t4)Paracetemol 500mg\n");
							break;
						case 4 :
							printf("\n\tyou have asthma\n");
							printf("List of Medicines\n\t1)Corticosteroid 300ml\n\t2)Anticholinergeics 100ml 170mg\n\t3)Albutorol 200mg\n\t4)Paracetemol 500mg\n");
							break;		
					}
				}
			else if(p[i].diseases[0] != 0 && p[i].diseases[1] != 0 ){	
					if(p[i].diseases[0]==p[i].diseases[1]){
					printf("And Please get Covid Test done from our Laboratory\n");
					}
			}
		contorhome:
		printf("\n\n\n\t**Enter zero for home: ");
		scanf(" %c",&cont);
		if(cont=='0'){
		
			switch(booked){
			case 1:
			home(0);
			break;
			
			case 0:
			home(0);
			break;
			}
		}
		else{
		printf("\n\n\t\t\t\t\t\t\tInvalid Input");
		sleep(1);
		goto contorhome;
		}   		
           
    }