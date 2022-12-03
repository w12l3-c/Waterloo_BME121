/* 
Wallace Lee 
---------------------------------
Program: bubble sort according to user input
Create Date: 2022-10-3
---------------------------------
*/
#include <iostream> // include iostream library
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output

using namespace std; // using std namespace for cin cout cerr

const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
const int ID_LENGTH = 8;

/**
 * @brief This function takes in the user input
 * It will check the user input and also assign a value 
 * to represen the case that it will be going in the switch statement
 *
 * @param none
 * @return the integer value of the case that will be passed to switch
 */
int cases(){
    int choice = 0; // the return variable
    char input[50]; // the user input
    bool firstTime = true;  // a boolean to check if it is the first time the user is inputting a value

    // do while loop to check if the user input is valid
    do{
        // first time asking for input has a different prompt
        if (firstTime){
            cout << "Please enter the sorting category (Age, ID, First, Last, Sex): ";
            cin >> input;
            firstTime = false;
        } 
        // When it iterate more than once, the user has already input somethig wrong so it will send another request
        else {
            cout << "Unexpected input. Please input either Age, ID, First, Last, or Sex: ";
            cin >> input;
        }
        // check if the user's input is valid 
        if (!cin.good()){
            cin.ignore(100, '\n');
            cin.clear();
        } 
        // if the user input a string
        else {
            // convert the input to lower case
            for (int i=0; i<strlen(input); i++){
                input[i] = tolower(input[i]);
            }
            // check if the input is age
            if (strcmp(input, "age") == 0){
                cout << "Case 1, sorting by Age" << endl;
                choice = 1;
            } 
            // check if the input is id
            else if (strcmp(input, "id") == 0){
                cout << "Case 2, sorting by ID" << endl;
                choice = 2;
            } 
            // check if the input is sex
            else if (strcmp(input, "sex") == 0){
                cout << "Case 3, sorting by Sex" << endl;
                choice = 3;
            } 
            // check if the input is last
            else if (strcmp(input, "last") == 0){
                cout << "Case 4, sorting by Last Name" << endl;
                choice = 4;
            } 
            // check if the input is first
            else if (strcmp(input, "first") == 0){
                cout << "Case 5, sorting by First Name" << endl;
                choice = 5;
            } 
            // every other answer will make the while loop continue
            else {
                choice = 0;
            }
        }
    } while (choice == 0);
    // return the choice when it is valid
    return choice;
}

void swapping(unsigned int age[], char id[][ID_LENGTH+1], char firstName[][MAX_NAME_LENGTH], char lastName[][MAX_NAME_LENGTH], char *sex, int j){
    int prevAge = age[j];
    string prevID = id[j];
    string prevFirst = firstName[j];
    string prevLast = lastName[j];
    char prevSex = sex[j];
    age[j] = age[j+1];
    age[j+1] = prevAge;
    strcpy(id[j],id[j+1]);
    strcpy(id[j+1],prevID.c_str());
    strcpy(firstName[j],firstName[j+1]);
    strcpy(firstName[j+1],prevFirst.c_str());
    strcpy(lastName[j],lastName[j+1]);
    strcpy(lastName[j+1],prevLast.c_str());
    sex[j] = sex[j+1];
    sex[j+1] = prevSex;
}

int main()
{
    // Provided arrays and constants
    const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
    const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
    const int ID_LENGTH = 8;
    unsigned int age[NUM_PATIENTS] = {50, 22, 22, 89, 15, 16, 22, 32, 15, 66}; // 1D int array age of each patient
    char id[NUM_PATIENTS][ID_LENGTH + 1] = {"10854893", "10983922", "98333894", "57290888", "14899822", "79278282", "44293822", "62911023", "28399020", "33212322"}; // 2D char array identification #
    char firstName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"allison", "michael", "michael", "johnny", "sabrina", "helen", "ignacio", "melissa", "hassan", "melody"}; // 2D char array: first names for patients
    char lastName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"pratt","xiao", "barkley", "wu", "sappal", "mcdonald", "garza", "tran", "nahas", "baker"}; // 2D char array: last names for patients
    char sex[NUM_PATIENTS] = {'f','m','m','m','f','f','m','f','m','f'}; // 1D char array sex of the patient
    int choice = 0; // the choice of the user
    bool condition = false;     // a boolean to check if the user wants to continue sorting
    int prevAge = 0;    // a variable to store the previous age
    string prevID = ""; // a variable to store the previous ID
    string prevFirst = "";  // a variable to store the previous first name
    string prevLast = "";   // a variable to store the previous last name
    char prevSex = ' ';     // a variable to store the previous sex

    // PART 1: Select a primary sorting category from user input
    choice = cases();   

    // PART 3/4: Sorting patient records
    // comparing the choice and sorting the array accordingly
    switch (choice){
        case 1: // sorting by age
            // bubble sort
            for(int i = 0; i < NUM_PATIENTS; i++){
                for(int j = 0; j < NUM_PATIENTS-1-i; j++){
                    // store the original value
                    if (age[j] > age[j+1]){
                        // swapping the values
                        swapping(age, id, firstName, lastName, sex, j);
                    } 
                    // tiebreaker to compare the first name ascending order 
                    else if (age[j] == age[j+1]) {
                        if (strcmp(firstName[j],firstName[j+1]) > 0){
                            swapping(age, id, firstName, lastName, sex, j);
                        }
                    }
                }
            }
            break;
        case 2: // sorting by ID
            // bubble sort
            for(int i = 0; i < NUM_PATIENTS; i++){
                for(int j = 0; j < NUM_PATIENTS-1-i; j++){
                    if (atoi(id[j]) > atoi(id[j+1])){
                        swapping(age, id, firstName, lastName, sex, j);
                    } 
                    // tiebreaker to compare the first name ascending order 
                    else if (atoi(id[j]) == atoi(id[j+1])) {
                        if (strcmp(firstName[j],firstName[j+1]) > 0){
                            swapping(age, id, firstName, lastName, sex, j);
                        }
                    }
                }
            }
            break;
        case 3: // sorting by sex
            // bubble sort
            for(int i = 0; i < NUM_PATIENTS; i++){
                    for(int j = 0; j < NUM_PATIENTS-1-i; j++){
                        if (int(sex[j])>int(sex[j+1])){
                            swapping(age, id, firstName, lastName, sex, j);
                        } 
                        // tiebreaker to compare the first name ascending order 
                        else if (int(sex[j]) == int(sex[j+1])) {
                            if (strcmp(firstName[j],firstName[j+1]) > 0){
                               swapping(age, id, firstName, lastName, sex, j);
                            }
                        }
                    }
                }
                break;
        case 4: // sorting by last name
            // bubble sort
            for(int i = 0; i < NUM_PATIENTS; i++){
                    for(int j = 0; j < NUM_PATIENTS-1-i; j++){
                        // store the original value
                
                        if (strcmp(lastName[j],lastName[j+1]) > 0){
                            swapping(age, id, firstName, lastName, sex, j);
                        } 
                        // tiebreaker to compare the first name ascending order 
                        else if (strcmp(lastName[j], lastName[j+1]) == 0) {
                            if (strcmp(firstName[j],firstName[j+1]) > 0){
                                swapping(age, id, firstName, lastName, sex, j);
                            }
                        }
                    }
                }
                break;
        case 5: // sorintg by first name
            // bubble sort
            for(int i = 0; i < NUM_PATIENTS; i++){
                    for(int j = 0; j < NUM_PATIENTS-1-i; j++){
                       
                        if (strcmp(firstName[j],firstName[j+1]) > 0){
                            swapping(age, id, firstName, lastName, sex, j);
                        }
                    }
                }
                break;
    }
    
    // PART 2: Outputting patient records to terminal in tabular form
    // each for loop is a row
    cout << setw(10) << "Age:";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw(10) << age[i];
    }
    cout << endl << setw(10) << "ID:";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw(10) << id[i];
    }
    cout << endl << setw(10) << "First:";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw(10) << firstName[i];
    }
    cout << endl << setw(10) << "Last:";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw(10) << lastName[i];
    }
    cout << endl << setw(10) << "Sex:";
    for (int i = 0; i < NUM_PATIENTS; i++){
        cout << setw(10) << sex[i];
    }
    cout << endl;

    return 0;
}