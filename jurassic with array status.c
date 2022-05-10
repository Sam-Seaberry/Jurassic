/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUMROWS	    9 //none of these are necessary
#define NUMCOLS     9
#define NUMWALKS    1000

void RandomStep(int *Number);
int Status(int number[]);

void printResults(double mean[], double standard[], double precision[]);

double Mean(double steps[]);
double Standard(double steps[]);
double Precision(double steps[]);
//function to calculate mean value of walks
double Mean(double steps[]){
	double a=0;
	double b=0;

		for(int i=0; i < 1000; i++){
			if(steps[i]<=0){
				continue;
			}
			else {
				a = a + steps[i];
				b++;
			}

		}
		return a/b;


}

//function to calculate standard deviation from mean value for each walk
double Standard(double steps[]){
	double c = Mean(steps);
	double sd=0;

		for(int i=0; i < 1000; i++){
			if(steps[i]<=0){

				continue;
			}
			else {
				sd = sd + (steps[i]-c)*(steps[i]-c);

			}
		}
		return (double)sqrt((sd)/1000);
}

//function to calculate Percentage of successful walks for each cell
double Precision(double steps[]){
	double b = 0;

	for(int i=0; i < 1000; i++){ //finds each successful walk
		if(steps[i]<=.001){
			continue; //if walk was not successful go to next number in array
		}
		else {
			b++;
		}

	}
	return (b/1000)*100; //returns percentage out of 100
}

//function to generate random numbers between 0-7 to be used as steps
void RandomStep(int *Number)
{
	*Number = (rand()%8); // %8 is used the limit the numbers that rand() can output from 0-7

}

//function to give status of walks
int Status(int number[])
{

    int a=0,b=0,c=0;
	for(int i =0; i<1000; i++){
	    //printf("%d", number[i]);
	    switch(number[i]){
	        case 0:
	            a++;
	        case 1:
	            b++;
	        case 2:
	            c++;
	        }
	}
printf("\n%d,%d,%d\n", a,b,c);
printf("\n%f\n", (double)a/1000);
}

//uses three input arrays so that it can print in tables
void printResults(double mean[], double standard[], double precision[]){
	printf("Mean path lenght when escaping");
	for (int i=0; i<81; i++){ //prints each part of array
		if ((i%9)==0){ //adds a new line after 9 numbers have been printed
			printf("\n");
		}
		printf("  %5.2f ",mean[i]); //prints to 2 decimal places
	}
	printf("\n");
	printf("\nStandard Deviation of path length when escaping");
	for (int i=0; i<81; i++){
			if ((i%9)==0){
				printf("\n");
			}
			printf("  %5.2f ",standard[i]);
		}
	printf("\n");
	printf("\nPercentage/Probability of making it off Jurassic Island");
	for (int i=0; i<81; i++){
			if ((i%9)==0){
				printf("\n");
			}
			printf("  %-5.2f ",precision[i]); //Formats output so that it will come out in a aligned table
		}



}



int main(void)
{



	time_t t; //initalizes time
	srand((unsigned) time(&t)); //sets rand() function



	char map [NUMROWS][NUMCOLS] ={
			{'B', 'W', 'W', 'B', 'B', 'W', 'B', 'W','W'},  //creating the 9 by 9 board using a array
			{'B', 'L', 'L', 'V', 'L', 'L', 'L', 'L', 'B'},
			{'W', 'L', 'L', 'L', 'L', 'D', 'L', 'L', 'B'},
			{'B', 'L', 'L', 'D', 'L', 'L', 'L', 'L', 'W'},
			{'B', 'L', 'D', 'L', 'L', 'L', 'L', 'L', 'W'},
			{'W', 'L', 'L', 'L', 'L', 'L', 'V', 'L', 'B'},
			{'W', 'V', 'L', 'L', 'L', 'L', 'L', 'L', 'W'},
			{'W', 'L', 'L', 'L', 'D', 'L', 'L', 'L', 'W'},
			{'B', 'B', 'W', 'B', 'W', 'B', 'B', 'W', 'B'}
	};

	double Mean_Total[81]={0}; //arrays for the mean standard diviation and precision

	double Standard_Total[81]={0};

	double Precison_Total[81]={0};

	int cell_number=0; //tells what cell of the map we are currently in


	for (int Start_Row = 0; Start_Row <9 ;Start_Row++){
		for (int Start_Col = 0; Start_Col < 9 ; Start_Col++){
			int i =0;

			double steps[1000]= {0}; //array for our 1000 random walks

            int status[10000]={0};
            int status_current=0;
			while ( i < 1000){

                    
					int Step; //random walk defined by the value of step

					int a=Start_Row;
					int b=Start_Col;

					int step=0; //how many steps have been taken in the current walk

					




					//if we start on a cell "D", "W", or "V" it counts as a failed walk
					if ((map[Start_Row][Start_Col] == 'D') || (map[Start_Row][Start_Col] == 'W' )|| (map[Start_Row][Start_Col] == 'V') ){
						steps[1]= .0000001; //this is used so that mean, standard deviation and precision give real numbers
						status[status_current]=1; //status for failed walk
						status_current++;
						break;
					}

					else
					{
						//walks countine unless the current map cell is a  "D", "W", or "V"
						while((map[a][b] != 'D') || (map[a][b] != 'W') ||  (map[a][b] != 'V'))
						{

							RandomStep(&Step); //using our random function to give a value to Step

							switch (Step){ //this switch statement defines the direction of each step

								case 0: //north
									    a++;

										break;


								case 1: //north-east
										a++;
										b++;

										break;


								case 2: //east
										b++;

										break;


								case 3: //south-east
										a--;
										b++;

										break;


								case 4: //south
										a--;

										break;


								case 5: //south-west
										a--;
										b--;

										break;


								case 6: //west
									    b--;

										break;



								case 7: //north-west
										a++;
										b--;


										break;
							}

						if ((a>8) || (a<0) || (b<0) || (b>8)){ //if we have exited the cell then walk is terminated


							step++; //counts a step for making it out
							status[status_current]=0;
							steps[i]=step; // the number of steps is put into a array at location i
							status_current++;
							break;
						}


						//checks whether the current cell is a  "D", "W", or "V"
						else if ((map[a][b] == 'D') || (map[a][b] == 'W' )|| (map[a][b] == 'V') ){
							steps[i]=0; //it current cell is a  "D", "W", or "V" set step array location i to 0 as it has failed the walk
							status[status_current]=1; //status is put to 1, it has failed
							status_current++;
							break;
						}
						else{
							status[status_current]=2; //walk is continued
							status_current++;
							step++; //step is increased by 1
							
							continue;

						}

						}




                        
						i++;
					
					}




				



			}

			//the mean/standard deviation/precision value of all steps for a cell is put into a array at the location of the current cell
			Mean_Total[cell_number]= Mean(steps);

			Standard_Total[cell_number]=Standard(steps);

		    Precison_Total[cell_number]=Precision(steps);

            Status(status);

		    cell_number++;
		}





	}

	//printResults(Mean_Total, Standard_Total,Precison_Total );//printing everything


return 0;




}



/* other maps
 * char map [NUMROWS][NUMCOLS] ={
			{'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B','B'},  //creating the 9 by 9 board using a array
			{'B', 'L', 'L', 'V', 'L', 'L', 'L', 'L', 'B'},
			{'B', 'L', 'L', 'L', 'L', 'D', 'L', 'L', 'B'},
			{'B', 'L', 'L', 'D', 'L', 'L', 'L', 'L', 'B'},
			{'B', 'L', 'D', 'L', 'L', 'L', 'L', 'L', 'B'},
			{'B', 'L', 'L', 'L', 'L', 'L', 'V', 'L', 'B'},
			{'B', 'V', 'L', 'L', 'L', 'L', 'L', 'L', 'B'},
			{'B', 'L', 'L', 'L', 'D', 'L', 'L', 'L', 'B'},
			{'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'}
	};
char map [NUMROWS][NUMCOLS] ={
			{'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W','W'},  //creating the 9 by 9 board using a array
			{'W', 'L', 'L', 'V', 'L', 'L', 'L', 'L', 'W'},
			{'W', 'L', 'L', 'L', 'L', 'D', 'L', 'L', 'W'},
			{'B', 'L', 'L', 'D', 'L', 'L', 'L', 'L', 'B'},
			{'B', 'L', 'D', 'L', 'L', 'L', 'L', 'L', 'B'},
			{'B', 'L', 'L', 'L', 'L', 'L', 'V', 'L', 'B'},
			{'B', 'V', 'L', 'L', 'L', 'L', 'L', 'L', 'B'},
			{'B', 'L', 'L', 'L', 'D', 'L', 'L', 'L', 'B'},
			{'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'}
	};
 */
