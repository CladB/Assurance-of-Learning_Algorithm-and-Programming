#include <stdio.h>
#include <string.h>

struct data{
	char location[101];
	char city[101];
	int price;
	int room;
	int bathroom;
	int carpark;
	char type[101];
	char furnish[101];
}mhs[10001];

//Display function
void display(struct data mhs[], int n, int total){
	printf("\n%-30s %-15s %-10s %-8s %-10s %-10s %-10s %-10s\n", 
	"Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish"); // This line is for the header
	for(int i = 0; i < n+1 && i < total; i++){
		printf("%-30s %-15s %-10d %-8d %-10d %-10d %-10s %-10s\n", mhs[i].location, mhs[i].city, mhs[i].price, mhs[i].room, mhs[i].bathroom, mhs[i].carpark, mhs[i].type, mhs[i].furnish);
	} // This loop use for display until integer n (from input). It is from the Struct data mhs[]
}

//Searching function
void search(struct data mhs[], int total, char column[101], char what[101]){
	int found = 0;
	int header = 0;
	for(int i = 0; i < total; i++){
	// Searching STRING
		if (strcmp(column, "Location") == 0  || strcmp(column, "City") == 0 || strcmp(column, "Type") == 0 || strcmp(column, "Furnish") == 0){
			char value[101]; // I use strcmp for comparing (linear search) the column and what into the data.
			sscanf(what, "%s", value);
			if(strcmp(column, "Location") == 0 && strcmp(mhs[i].location, value) == 0 ||
				strcmp(column, "City") == 0 && strcmp(mhs[i].city, value) == 0||
				strcmp(column, "Type") == 0 && strcmp(mhs[i].type, value) == 0 ||
				strcmp(column, "Furnish") == 0 && strcmp(mhs[i].furnish, value) == 0){
				found = 1;
				if (!header) {
					printf("Data found. Detail of data:\n%-30s %-15s %-10s %-8s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
					header = 1;
				} 
				printf("%-30s %-15s %-10d %-8d %-10d %-10d %-10s %-10s\n", mhs[i].location, mhs[i].city, mhs[i].price, mhs[i].room, mhs[i].bathroom, mhs[i].carpark, mhs[i].type, mhs[i].furnish);
			}
		} 
	
	// Searching INTEGER
		else if (strcmp(column, "Price") == 0 || strcmp(column, "Rooms") == 0 || strcmp(column, "Bathroom") == 0 || strcmp(column, "Carpark") == 0){
			int value; // I use strcmp for comparing (linear search) the column and just compare what into the data.
			sscanf(what, "%d", &value);
			if(	strcmp(column, "Price") == 0 && mhs[i].price == value ||
				strcmp(column, "Rooms") == 0 && mhs[i].room == value ||
				strcmp(column, "Bathroom") == 0 && mhs[i].bathroom == value ||
				strcmp(column, "Car Park") == 0 && mhs[i].carpark == value){
				found = 1;	
				if (!header) {
					printf("Data found. Detail of data:\n%-30s %-15s %-10s %-8s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
					header = 1;
				} 
			printf("%-30s %-15s %-10d %-8d %-10d %-10d %-10s %-10s\n", mhs[i].location, mhs[i].city, mhs[i].price, mhs[i].room, mhs[i].bathroom, mhs[i].carpark, mhs[i].type, mhs[i].furnish);
			}		
		}			
	}
	if (!found) printf("Data not found!\n");
}

//Sorting Main (Bubble sort -> because it is easier to edit the code and less code)
void bsort(struct data mhs[], int n, char column[101], char what[101]){
	struct data temp;
// STRING SORTING
// Location
	if (strcmp(column, "Location") == 0){
			if(strcmp(what, "asc") == 0) {
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(strcmp(mhs[j].location, mhs[j+1].location) > 0){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
		} else if (strcmp(what, "dsc") == 0){
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(strcmp(mhs[j].location, mhs[j+1].location) < 0){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
			}
	}
// City
	else if (strcmp(column, "City") == 0){
			if(strcmp(what, "asc") == 0) {
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(strcmp(mhs[j].city, mhs[j+1].city) > 0){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
		} else if (strcmp(what, "dsc") == 0){
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(strcmp(mhs[j].city, mhs[j+1].city) < 0){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
			}
	}
// Type
	else if (strcmp(column, "Type") == 0){
			if(strcmp(what, "asc") == 0) {
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(strcmp(mhs[j].type, mhs[j+1].type) > 0){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
		} else if (strcmp(what, "dsc") == 0){
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(strcmp(mhs[j].type, mhs[j+1].type) < 0){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
			}
	}
// Furnish
	else if (strcmp(column, "Furnish") == 0){
		if(strcmp(what, "asc") == 0) {
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(strcmp(mhs[j].furnish, mhs[j+1].furnish) > 0){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
		} else if (strcmp(what, "dsc") == 0){
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(strcmp(mhs[j].furnish, mhs[j+1].furnish) < 0){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
			}
	}
// INTEGER SORTING
// Price	
	else if (strcmp(column, "Price") == 0){
		if(strcmp(what, "asc") == 0) {
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(mhs[j].price > mhs[j+1].price){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
		} else if (strcmp(what, "dsc") == 0){
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(mhs[j].price < mhs[j+1].price){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
			}
	}
// Rooms
	else if (strcmp(column, "Rooms") == 0){
		if(strcmp(what, "asc") == 0) {
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(mhs[j].room > mhs[j+1].room){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
		} else if (strcmp(what, "dsc") == 0){
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(mhs[j].room < mhs[j+1].room){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
			}
	}
// Bathroom
	else if (strcmp(column, "Bathroom") == 0){
		if(strcmp(what, "asc") == 0) {
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(mhs[j].bathroom > mhs[j+1].bathroom){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
		} else if (strcmp(what, "dsc") == 0){
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(mhs[j].bathroom < mhs[j+1].bathroom){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
			}
	}
// Carpark
	else if (strcmp(column, "Carpark") == 0){
		if(strcmp(what, "asc") == 0) {
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(mhs[j].carpark > mhs[j+1].carpark){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
		} else if (strcmp(what, "dsc") == 0){
				for(int i = 0; i < n -1; i++){
					for(int j = 0; j < n - i - 1; j++){
						if(mhs[j].carpark < mhs[j+1].carpark){
							temp = mhs[j];
							mhs[j] = mhs[j+1];
							mhs[j+1] = temp;
						}
					}
				}
			}
	}
// End
}

//Export
void exportfile(struct data mhs[], int total, char filename[101]){
	FILE *fp;
	char hasil_akhir[1001];
	
	strcpy(hasil_akhir, filename);
	hasil_akhir[strcspn(hasil_akhir, "\n")] = '\0'; // To replace the "\n" into "\0".
	strcat(hasil_akhir, ".csv"); 
	
	fp = fopen(hasil_akhir, "w"); 	// Because I do not know how to make the new file name as the char filename. So I use the strcpy and strcat
									// to combine the sentence.
				
	fprintf(fp, "Location 1,Location 2,Price,Rooms,Bathrooms,Car Parks,Type,Furnish\n");
	for (int i = 0; i < total; i++) {	
     	fprintf(fp, "%s,%s,%d,%d,%d,%d,%s,%s\n", mhs[i].location, mhs[i].city, mhs[i].price, mhs[i].room, mhs[i].bathroom, mhs[i].carpark, mhs[i].type, mhs[i].furnish);
	}
	fclose(fp);
	printf("Data successfully written to file %s!\n", hasil_akhir);
}

// Main
int main(){
	int total = 0;
	FILE *fp;
	fp = fopen("file.csv", "r"); // This is the read function.
	if(!fp)
		printf("File not Found\n");
	else {
		while(!feof(fp)){
			fscanf(fp, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", mhs[total].location, mhs[total].city, &mhs[total].price, &mhs[total].room, &mhs[total].bathroom, &mhs[total].carpark, mhs[total].type, mhs[total].furnish); 
			total++;
		}
	}
	fclose(fp);
	int menu;
	do {
		printf("What do you want to do?\n");
		printf("1. Display Data\n");
		printf("2. Search Data\n");
		printf("3. Sort Data\n");
		printf("4. Export Data\n");
		printf("5. Exit\n");
		printf("Your choice: ");
		scanf("%d", &menu);	getchar();
		switch (menu) {
			case 1:
				int n;
					do{
						printf("Number of rows: ");
						scanf("%d", &n); getchar(); // Many rows that want to be displayed.
					} while (n <= 0); // Validation if the input zero or less than zero will go to input the rows again.
					display(mhs, n, total); // Print the data as much as integer "n".
				break;
				
			case 2:
				char column[101];
				char what[101];
				printf("Choose column: "); 
				scanf("%s", column); getchar(); // Choosing which column to search.
				printf("What do you want to find? "); 
				scanf("%s", what); getchar(); 
				search(mhs, total, column, what); // Function Searching.
				break;
				
			case 3:
				printf("Choose column: "); 
				scanf("%s", column); getchar(); // Choosing which column want to search.
				printf("Sort ascending or decending? ");
				scanf("%s", what); // It can be asc for ascending and dsc for decending.
				bsort(mhs, total, column, what); // Function Sorting.
				display(mhs, 9, total); // Display only arr[0] until arr[9] which mean only 10 data will displayed.
				break;
				
			case 4:
				char new_file[101];
				printf("File name: ");
				scanf("%[^\n]", new_file);  // Input the new file name.
				exportfile(mhs, total, new_file); // Funtion Export.
				break;
		}
	} while (menu !=5); // The program will end if switch case is integer 5.
	return 0;
}

