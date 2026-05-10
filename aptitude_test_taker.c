#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // for clear screen buffer
#include <time.h>   // for time functions
#include <string.h> // for string functions
#include <ctype.h>  // for upper/lower case versions
#include <unistd.h> // for sleep function
#include <Windows.h>

struct information_of_students
{
    char name[100];
    char roll_num[100];
    char institute[100];
    char degree[100];
    char select;
    char answer;
    int marks;
    float percentage;
};
// passing the struct information as a pointer to update side by side the marks value
void python(struct information_of_students *st);
void reactJS(struct information_of_students *st);
void C(struct information_of_students *st);
void Cpp(struct information_of_students *st);
void displayResults(struct information_of_students *st);

int main()
{
    char username[50];
    char password[20];
    char correctUsername[30] = "Operator";
    char correctPassword[20] = "Dshk147";

    system("cls");

    while (1)
    {

        // Get user input to open portal
        char ch;
        puts("\n");
        puts("\t\t\t\t\033[1;4m******ADMIN LOGIN PORTAL!!******\033[0m\n");
        printf("\t\t\t\tEnter Username : ");
        gets(username);
        printf("\t\t\t\tEnter Password : ");

        // MASKING OF PASSWORD PART

        int i = 0;
        ch = getch();
        while (ch != 13 && i < sizeof(password) - 1)
        {
            password[i++] = ch;
            printf("*");
            ch = getch();
        }
        password[i] = '\0'; // Null-terminate the password

        // Check credentials
        if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0)
        {
            system("cls");
            printf("\e[4;32m"); // Set text color to green
            printf("\t\t\t\tLogin successful!\n");
            sleep(2);
            printf("\033[0m"); // Reset text color and style
            // Add your code to open the quiz app or perform other actions here
            system("cls");
            /* The line `struct information st;` is declaring a variable `st` of type `struct information`.
            This structure is used to store information about a person, including their name, roll number,
            institute, degree, and a selection. */
            int press;
            do
            {
                struct information_of_students st;

            registration:
                printf("\n");
                printf("\t\t\t\t*****************************************\n");
                printf("\t\t\t\t*      Welcome to the INTELLIQUEST      *\n");
                printf("\t\t\t\t*                 Signup                *\n");
                printf("\t\t\t\t*****************************************\n\n");

                printf("\t\t\t\tEnter name: ");
                fgets(st.name, sizeof(st.name), stdin);
                st.name[strcspn(st.name, "\n")] = '\0';
                printf("\t\t\t\tEnter Roll Number : ");
                fgets(st.roll_num, sizeof(st.roll_num), stdin);
                printf("\t\t\t\tEnter Institution: ");
                fgets(st.institute, sizeof(st.institute), stdin);
                printf("\t\t\t\tEnter Degree: ");
                fgets(st.degree, sizeof(st.degree), stdin);

                printf("\n\t\t\t\tThank you for registering!\n");
                sleep(2); // Wait for 2 seconds

                // RULES OF THE APTITUDE TEST
                system("cls");
                printf("\033[1;31m"); // Set text color to bright red
                printf("\n -------------  A WARM WELCOME %s TO INTELLIQUEST APPTITUDE TAKER  --------------", st.name);
                printf("\033[0m"); // Reset text color and style
                printf("\n\n \t Before getting started, you might want to be aware of the following advice:");
                printf("\n -----------------------------------------------------------------------------------------------");
                printf("\n 1. There are 4 primary categories in our aptitude test. ");
                printf("\n 2. You can choose to test in any of the following categories if you'd like:");
                printf("\n 3. It is a multiple choice exam with 5 questions and 4 options in each academic category.");
                printf("\n 4. For the correct selection, press A, B, C, or D.");
                printf("\n 5. Each question has a time limit of 10 secs, if you didn't give the answer in 10 sec it will");
                printf("\n    be visible whenever you gave the answer that Time is up and that question is not considered");
                printf("\n    at INCORRECT ");
                printf("\n 6. No points deducted for incorrect responses!");
                printf("\n 7. Your final score will be shown after the test.");
                printf("\n -----------------------------------------------------------------------------------------------");
                printf("\033[1m"); // BOLD WHITE TEXT
                printf("\n\n\t\t********** WISHING YOU ALL THE BEST!**********\n");
                printf("\033[0m"); // Reset text color and style

                printf("\033[2;36m"); // Set text color to bright cyan
                printf("\n\t\tMarks less than 50%% will be considered as fail\n\n");
                printf("\033[0m"); // Reset text color and style

                printf("\033[1;32m"); // Set text color to bright green and make it bold
                printf("* Select the subject for the quiz:\n\n");
                printf("\033[0m"); // Reset text color and style

                printf("\033[2;33m"); // Set text color to bright yellow and make it bold
                printf("1) C\n");
                printf("2) Python\n");
                printf("3) React JS\n");
                printf("4) C++\n");
                printf("\033[0m"); // Reset text color and style
                printf("\n Press 1 2 3 or 4 for respective quiz.\n");

                st.select = getche(); // To take choice of Test from user
                st.select = toupper(st.select);

                system("cls");
                switch (st.select)
                {
                case '1':
                    printf("Welcome to C Language Exam\n\n ");
                    C(&st);
                    // RESULT DISPLAYING
                    displayResults(&st);
                    break;
                case '2':
                    printf("Welcome to PYTHON Language Exam\n\n ");
                    python(&st);
                    // RESULT DISPLAYING
                    displayResults(&st);
                    break;
                case '3':
                    printf("Welcome to REACT JS Language Exam\n\n ");
                    reactJS(&st);
                    // RESULT DISPLAYING
                    displayResults(&st);
                    break;
                case '4':
                    printf("Welcome to C++ Language Exam\n\n ");
                    Cpp(&st);
                    // RESULT DISPLAYING
                    displayResults(&st);
                    break;
                default:
                    printf("INVALID INPUT\n");
                    break;
                }

                printf("Press S if you want to continue");

                press = getche();
                press = toupper(press);
                system("CLS");

            } while (press == 'S');

            if (press == 'S')
            {
                goto registration;
            }
            break;
        }
        else
        {
            system("cls");
            printf("\e[4;31m"); // Set text color to red
            printf("\t\t\t\tInvalid username or password. Please try again.\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    return 0;
}
void python(struct information_of_students *st)
{
    // struct information_of_students st;
    st->marks = 0;

    /* The code `double time_limit = 10.0;` is declaring a variable `time_limit` of type `double` and
    initializing it with the value `10.0`. This variable is used to set the time limit for answering
    the questions. */
    double time_limit = 10.0;
    clock_t start_time, end_time;

    printf("\033[1;31m"); // Set text color to bright red
    printf("DIFFICULTY LEVEL : Medium\t\t PASSING RATIO: 85%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 1 : What is the output of the following Python code?\n\n");
    printf("\033[0m"); // Reset text color and style
    printf(" def my_function(x)\n return x * 2 \n result = my_function(3) \n print(result)\n\n");
    printf("A) 3 \t B) 6 \t C) 9 \t D) 12 \t\n\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'B')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is B) 6\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");

    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Hard\t\t\t PASSING RATIO: 40%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 2 : What will be the output of the following code?\n\n");
    printf("\033[0m"); // Reset text color and style
    printf(" x = 5\n y = 2 \n result = x // y \n print(result)\n\n");
    printf("A) 2 \t B) 2.5 \t C) 2.0 \t D) 2.2 \t\n\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) 2\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");

    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Medium\t\t PASSING RATIO: 70%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 3 : Which of the following is a correct way to open a file named example.txt in Python for writing?\n\n");
    printf("\033[0m"); // Reset text color and style

    printf("A) file = fopen(\"example.txt\", \"r\");\n");
    printf("B) file = fopen(\"example.txt\", \"w\");\n");
    printf("C) file = fopen(\"example.txt\", \"a\");\n");
    printf("D) file = fopen(\"example.txt\", \"x\");\n\n");

    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'B')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is B) file = fopen(\"example.txt\", \"w\")\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");

    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Medium\t\t PASSING RATIO: 60%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 4 : Which data structure in Python is typically implemented as a dynamic array?\n\n");
    printf("\033[0m"); // Reset text color and style

    printf("A) List \t B) Set \t C) Dictionary     \t D) Tuple \t\n\n");

    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) List\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");

    start_time = clock();

    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Hard\t\t\t PASSING RATIO: 45%%\n\n");
    printf("\033[0m"); // Reset text color and style

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 5 : What is the output of the following Python code?\n\n");
    printf("\033[0m"); // Reset text color and style
    printf(" def func(x):\n   if x > 0: \n     return \"Positive\" \n   elseif x < 0: \n     return \"Negative\" \n   else: \n     return \"Zero\" \n result = func(0) \n print(result) \n\n");
    printf("A) Positive \t B) Negative \t C) Zero \t D) Error \t\n\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'C')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is C) Zero\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("MARKS: %d\n", st->marks);
    st->marks = st->marks;
}

void reactJS(struct information_of_students *st)
{

    st->marks = 0;

    /* The code `double time_limit = 10.0;` is declaring a variable `time_limit` of type `double` and
  initializing it with the value `10.0`. This variable is used to set the time limit for answering
  the questions. */
    double time_limit = 10.0;
    clock_t start_time, end_time;

    printf("\033[1;31m"); // Set text color to bright red
    printf("DIFFICULTY LEVEL : Medium\t\t PASSING RATIO: 70%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 1 : In React, what is the purpose of setState?\n\n");
    printf("\033[0m"); // Reset text color and style

    printf("A) To update the component's state\n");
    printf("B) To set the initial state of a component\n");
    printf("C) To create a new component \n");
    printf("D) To access props\n\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) To update the component's state\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Hard\t\t\t PASSING RATIO: 45%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 2 : Which lifecycle method in React is called after a component has been rendered to the screen?\n\n");
    printf("\033[0m"); // Reset text color and style

    printf("A) componentWillUnmount\n");
    printf("B) componentDidMount\n");
    printf("C) componentWillMount \n");
    printf("D) componentDidUpdate\n\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'B')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is B) componentDidMount\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Medium\t\t PASSING RATIO: 65%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 3 : In React, what is the purpose of props?\n\n");
    printf("\033[0m"); // Reset text color and style

    printf("A) To pass data from a parent component to a child component\n");
    printf("B) To update the component's state\n");
    printf("C) To handle events\n");
    printf("D) To define the component's structure\n\n");

    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) To pass data from a parent component to a child component\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Medium\t\t PASSING RATIO: 75%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 4 : In React, what is the purpose of a key in a list?\n\n");
    printf("\033[0m"); // Reset text color and style

    printf("A) It is used to uniquely identify elements in a list\n");
    printf("B) It determines the order of elements in a list\n");
    printf("C) It sets the style for each element in a list \n");
    printf("D) It controls the visibility of elements in a list\n\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) It is used to uniquely identify elements in a list\n");
            printf("\033[0m"); // Reset text color and style
        }
    }
    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Hard\t\t\t PASSING RATIO: 50%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 5 : In React, what is the correct way to handle forms?\n\n");
    printf("\033[0m"); // Reset text color and style

    printf("A) Using the form tag with a custom event handler\n");
    printf("B) Using the onFormSubmit event\n");
    printf("C) Using the handleSubmit function with event.preventDefault()\n");
    printf("D) Using the form tag with inline JavaScript\n\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'C')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is C) Using the handleSubmit function with event.preventDefault()\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    st->marks = st->marks;
}

void C(struct information_of_students *st)
{

    st->marks = 0;

    /* The code `double time_limit = 10.0;` is declaring a variable `time_limit` of type `double` and
      initializing it with the value `10.0`. This variable is used to set the time limit for answering
      the questions. */
    double time_limit = 10.0;
    clock_t start_time, end_time;

    printf("\033[1;31m"); // Set text color to bright red
    printf("DIFFICULTY LEVEL : Medium\t\t PASSING RATIO: 90%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 1 : In C, what is the result of the following expression?\n\n");
    printf("\033[0m"); // Reset text color and style

    printf("A) 2\n");
    printf("B) 2.2\n");
    printf("C) 2.0 \n");
    printf("D) 2.5\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) 2\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Hard\t\t\t PASSING RATIO: 50%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 2 : What will be the output of the following C code?\n\n");
    printf("\033[0m"); // Reset text color and style
    printf(" #include <stdio.h>\n int main() { \n int x = 5; \n   int *ptr = &x; \n printf(\"%%d\", *ptr); \n  return 0; \n }\n");
    printf("A) Error\n");
    printf("B) Garbadge Value\n");
    printf("C) 5 \n");
    printf("D) 0\n\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'C')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is C) 5\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Medium\t\t PASSING RATIO: 65%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 3 : Which of the following is a correct way to declare a pointer to an integer in C?\n\n");
    printf("\033[0m"); // Reset text color and style

    printf("A) int *x;\n");
    printf("B) int x;\n");
    printf("C) int &x;\n");
    printf("D) int x[];\n\n");

    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) int *x;\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Medium\t\t PASSING RATIO: 75%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 4 : What will be the output of the following C code?\n\n");
    printf("\033[0m"); // Reset text color and style
    printf("#include <stdio.h>\nint main() {\n  int x = 5;\n  printf(\"%%d\", x++);\n  return 0;\n}\n");

    printf("A) 5\n");
    printf("B) 6\n");
    printf("C) 4 \n");
    printf("D) 7\n\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) 5\n");
            printf("\033[0m"); // Reset text color and style
        }
    }
    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Hard\t\t\t PASSING RATIO: 35%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 5 : In C, what is the output of the following code?\n\n");
    printf("\033[0m"); // Reset text color and style
    printf(" #include <stdio.h> \n int main() { \n int i = 0; \n  while (i < 5) { \n  printf(\"%%d\", i); \n i = i + 2; \n } \n  return 0; \n } \n");

    printf("A) 0 2 4\n");
    printf("B) 0 1 2\n");
    printf("C) 0 2 3\n");
    printf("D) 0 1 3\n\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) 0 2 4\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    st->marks = st->marks;
}

void Cpp(struct information_of_students *st)
{

    st->marks = 0;

    /* The code `double time_limit = 10.0;` is declaring a variable `time_limit` of type `double` and
  initializing it with the value `10.0`. This variable is used to set the time limit for answering
  the questions. */
    double time_limit = 10.0;
    clock_t start_time, end_time;

    printf("\033[1;31m"); // Set text color to bright red
    printf("DIFFICULTY LEVEL : Easy  \t\t PASSING RATIO: 90%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 1 : What is the output of the following C++ code??\n\n");
    printf("\033[0m"); // Reset text color and style
    printf("#include <iostream> \n using namespace std; \n int main() { \n  int x = 10; \n  int *ptr = &x; \n  cout << *ptr << endl; \n  return 0; \n }\n");

    printf("A) 10\n");
    printf("B) Error\n");
    printf("C) Garbadge  \n");
    printf("D) 0\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) 10\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Hard\t\t\t PASSING RATIO: 40%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 2 :In C++, what is the output of the following code?\n\n");
    printf("\033[0m"); // Reset text color and style
    printf(" #include <iostream> \n using namespace std; \n   int main() { \n for (int i = 0; i < 5; i++) { \n    cout << i << "
           "; \n    i++; \n } \n return 0; \n } \n");
    printf("A) 0 1 2 3 4\n");
    printf("B) 0 2 4\n");
    printf("C) 0 2 9 \n");
    printf("D) 0 2 3\n\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) 0 1 2 3 4\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Medium\t\t PASSING RATIO: 60%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 3 : Which of the following is a correct way to create a class in C++?\n\n");
    printf("\033[0m"); // Reset text color and style

    printf("A) class MyClass { };\n");
    printf("B) def MyClass: pass\n");
    printf("C) function MyClass() { }\n");
    printf("D) class = MyClass() { }\n\n");

    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) class MyClass { };\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Medium\t\t PASSING RATIO: 75%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 4 : What will be the output of the following  code?\n\n");
    printf("\033[0m"); // Reset text color and style
    printf(" #include <iostream> \n using namespace std; { \n int main() { \n   int arr[5] = {1, 2, 3, 4, 5}; \n  int *ptr = arr; \n  cout << \"The value at index 2 is: \" << *(ptr + 2) << endl; \n   return 0; \n }\n");

    printf("A) The value at index 2 is: 2\n");
    printf("B) The value at index 2 is: 3\n");
    printf("C) The value at index 2 is: 4 \n");
    printf("D) The value at index 2 is: 5\n\n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'B')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is B) The value at index 2 is: 3\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    printf("\033[1;31m"); // Set text color to bright red
    printf("\nDIFFICULTY LEVEL : Hard\t\t\t PASSING RATIO: 35%%\n\n");
    printf("\033[0m"); // Reset text color and style

    start_time = clock();

    printf("\033[1;37m"); // Set text color to bold white
    printf("Question 5 : What is the output of the following C++ code?\n\n");
    printf("\033[0m"); // Reset text color and style
    printf(" #include <iostream> \n using namespace std; \n   int main() { \n   int x = 5; { \n    int &ref = x; \n    cout << ref << endl;; \n } \n return 0; \n } \n");

    printf("A) 5\n");
    printf("B) Error\n");
    printf("C) Implicit Declaration\n");
    printf("D) 0 \n");
    st->answer = getche();
    st->answer = toupper(st->answer);

    end_time = clock();

    if ((clock() - start_time) / CLOCKS_PER_SEC < time_limit)
    {

        if (st->answer == 'A')
        {
            printf("\e[1;3;32m"); // Set text color to bright green
            printf("\nCORRECT!!\n");
            printf("\033[0m"); // Reset text color and style
            st->marks++;       // Score increment
        }
        else
        {
            printf("\033[3;2;31m"); // Set text color to thin red
            printf("\nSorry the answer you provided is not correct\n");
            printf("The correct option is A) 5\n");
            printf("\033[0m"); // Reset text color and style
        }
    }

    if ((clock() - start_time) / CLOCKS_PER_SEC >= time_limit)
    {
        printf("\nTime is up! This question is considered as WRONG.\n");
    }

    sleep(2); // Wait for 2 seconds
    system("cls");
    st->marks = st->marks;
}

void displayResults(struct information_of_students *st)
{
    system("cls");
    printf("\n\n\t\t\t\t\t************ QUIZ RESULTS ************\n\n");
    printf("\e[0;33m"); // Set text color to bright yellow and make it bold
    printf("\t\t\t\t\t        Name: %s\n", st->name);
    printf("\t\t\t\t\t        Institute: %s", st->institute);
    printf("\t\t\t\t\t        Roll Number: %s", st->roll_num);
    printf("\t\t\t\t\t        Degree: %s\n", st->degree);
    printf("\033[0m"); // Reset text color and style
    // Calculate percentage

    st->percentage = (st->marks * 100) / 5;
    char grade[10];
    // Assign PASS or FAIL based on the percentage
    if (st->percentage > 50)
    {
        strcpy(grade, "PASS");
    }
    else
    {
        strcpy(grade, "FAIL");
    }

    // Print quiz details
    printf("\033[1;34;3m"); // Reset text color and style
    printf("\n\t\t\t\t\t        Quiz Summary\n\n");
    printf("\033[0m"); // Reset text color and style
    printf(" \e[0;36m");
    printf("\t\t\t\t\t        Total Questions: 5\n");
    printf("\t\t\t\t\t        Correct Questions: %d\n", st->marks);
    printf("\t\t\t\t\t        Percentage: %.2f%%\n", st->percentage);
    printf("\t\t\t\t\t        Grade: %s\n", grade);
    printf("\033[0m"); // Reset text color and style

    // Display remarks based on percentage
    if (st->percentage >= 80)
    {
        printf("\e[4;32m"); // Set text color to green
        printf("\n\t\t\t\t\t\tREMARKS: Excellent!!\n\n");
        printf("\033[0m"); // Reset text color and style
    }
    else if (st->percentage >= 60)
    {
        printf("\e[4;32m"); // Set text color to green
        printf("\n\t\t\t\t\t\tREMARKS: Good Job!\n\n");
        printf("\033[0m"); // Reset text color and style
    }
    else if (st->percentage >= 40)
    {
        printf("\e[4;31m"); // Set text color to red
        printf("\n\t\t\t\t\t\tREMARKS: Average.\n\n");
        printf("\033[0m"); // Reset text color and style
    }
    else
    {
        printf("\e[4;31m"); // Set text color to red
        printf("\t\t\t\t\t\tREMARKS: Keep practicing!\n\n");
        printf("\033[0m"); // Reset text color and style
    }

    printf("\t\t\t\t\t+------------+------------+-----------+\n");
}