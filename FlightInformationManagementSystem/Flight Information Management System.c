#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_FLIGHTS 100 // Maximum number of flights that can be stored

// Define a struct to hold flight information
char destination[30];
char origin[30];
struct Flight {
    int number;
    int type;
    char from[50];
    char to[50];
    char date[20];
    char time[20];
};

struct Flight flights[MAX_FLIGHTS]; // Array of flights
int main() {
    
    int num_flights = 0; // Number of flights currently in the array
    FILE *fp; // Pointer to file
    char filename[] = "flights.txt"; // Name of file containing flight information
    char line[200]; // Buffer for reading each line of the file
    char *token; // Pointer to token within line
    int i,n,a;
    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // Read each line of file, parse flight information, and store in array
    while (fgets(line, 100, fp) != NULL) {
 
        token = strtok(line, ",");
        flights[num_flights].number=atoi(token);        
        token = strtok(NULL, ",");
        flights[num_flights].type=atoi(token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].from, token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].to, token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].date, token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].time, token);
        num_flights++;
        
    }
    // Close file
    fclose(fp);

    
    while(1)
    { 	    	
    	printf("\n Menu:\n");
    	printf("1.Add a flight\n");
    	printf("2.Update a flight \n");
    	printf("3.Search for a flight with departure city\n");
    	printf("4.Search for a flight with arrival city \n");
    	printf("5.List all flights \n");
    	printf("6.Exit \n");
    	printf("Enter your choice 1-6:");
    	scanf("%d",&n);
    
    	switch(n){
    		case 1: 
 	printf("Enter flight number:");
	scanf("%d",&flights[num_flights].number);
	printf("Enter flight type 1 for domestic,0 for international flights:");
	scanf("%d",&flights[num_flights].type);
	printf("Enter the departure city of the flight:");
	scanf("%s",&flights[num_flights].from);
	printf("Enter the arrival city of the flight:");
	scanf("%s",&flights[num_flights].to);
	printf("Enter the flight date:");
	scanf("%s",&flights[num_flights].date);
	printf("Enter the flight time:");
	scanf("%s",&flights[num_flights].time);
	printf("Flight inserted succesfully.");
	num_flights++;
	
    			break;
    		case 2:
    			printf("Please enter flight number to update:");
    			scanf("%d",&n);
    			for(i=0;i<num_flights;i++){
    			if(n==flights[i].number){
    				printf("Flight found.Which field would you like to update?\n");
    				printf("1.Type:\n");
    				printf("2.From:\n");
    				printf("3.To:\n");
    				printf("4.Date:\n");
    				printf("5.Time:\n");
    				printf("Please enter your choice(1-5):");
    				scanf("%d",&n);
    				switch(n){
    					case 1:
    		    			printf("Please enter flight type to update:");
    			            scanf("%d",&n);
    						if(n==1){
    							printf("Enter new type: ");
    							scanf("%d",&flights[i].type);
    							printf("Enter new destination:");
    							scanf("%s",flights[i].to);
    							printf("Flight updated successfully.");
							}
							 if(n==0){
							    printf("Enter new type: ");
                                scanf("%d",&flights[i].type);
							    printf("Enter new destination:");
								scanf("%s",flights[i].to);
								printf("Flight updated successfully.");
							}	
    						break;
    					case 2:
    						printf("Enter new origin: ");
    						scanf("%s",flights[i].from);
    						printf("Flight updated successfully.");
    						break;
    					case 3:
    						printf("Enter new destination: ");
    						scanf("%s",flights[i].to);
    						printf("Flight updated successfully.");
    						break;
    					case 4:
    						printf("Enter new date: ");
    						scanf("%s",flights[i].date);
    						printf("Flight updated successfully.");
    						break;
    					case 5:
    						printf("Enter new time: ");
    						scanf("%s",flights[i].time);
    						printf("Flight updated successfully.");
    					break;
					}
    			}
    		}
    		     if(n!=flights[i].number)
    				printf("Flight has not found.Please try again.");
				
    				break;	
			case 3:
				printf("Enter origin:");
				scanf("%s",&origin);
			    printf("Flights from %s :\n",origin);
				for(i=0;i<num_flights;i++){
				if(strcmp (origin,flights[i].from)==0){
					printf(" %-20d %-10d %-20s %-20s %-20s %-10s \n",flights[i].number,flights[i].type,flights[i].from,flights[i].to,flights[i].date,flights[i].time);
			}
		}
			 if(strcmp (origin,flights[i].from)!=0)
					printf("There is no flight from that city.");				
				break;
				
			case 4:
				printf("Enter destination:");
				scanf("%s",&destination);
				printf("Flights to %s:\n",destination);
				
				for(i=0;i<num_flights;i++){
					if(strcmp(destination,flights[i].to)==0){
					printf(" %-20d %-10d %-20s %-20s %-20s %-10s \n",flights[i].number,flights[i].type,flights[i].from,flights[i].to,flights[i].date,flights[i].time);	
					}
			}
				
			if(strcmp(destination,flights[i].to)!=0)
			printf("There is no flight.");	
				break;
				
			case 5:			
	    printf("%-20s %-10s %-20s %-20s %-20s %-20s \n","Flight num","D/I","from","to","Date","Time");	
	    for(i=0;i<num_flights;i++){
    printf(" %-20d %-10d %-20s %-20s %-20s %-20s \n",flights[i].number,flights[i].type,flights[i].from,flights[i].to,flights[i].date,flights[i].time);
}
				break;
			case 6:
				return 0;
				break;
    	}
	}
    return 0;
}

