/***************************************************************************
 *
 * SYNOPSIS:
 * Simple C shell (Simple Sea Shell - sss)
 *
 * DESIGN NOTE:
 * The aim of the exercise is to develop a simple OS shell in C for a unix
 * -type system. So, you must work on a Linux environment for this exercise.
 *
 * BUS:
 * See Revision History ;)
 *
 * FILE:
 * sss.c
 *
 * AUTHORS:
 * Yordan Y Stoykov    Reg No: 201334079
 * Fraser Graham       Reg No: 201348442
 * Kieran Scott        Reg No: 201312912
 * Ramsay Meiklem      Reg No: 201343272
 * Omer Shah           Reg No: 201348997
 *
 * GROUP:
 * Tuesday, 10-12
 *
 * PROMISE::
 * We confirm that this submission is all our own work.
 *
 * (Signed) Yordan Y Stoykov:______________________________________________
 *
 *          Fraser Graham:_________________________________________________
 *
 *          Kieran Scott:__________________________________________________
 *
 *          Ramsay Meiklem:________________________________________________
 *
 *          Omer Shah:_____________________________________________________
 *
 * VERSION:
 * See VERSION below
 *
 **************************************************************************/


/********************* R E V I S I O N   H I S T O R Y ********************
 * 	v0.0  02/24/2015: Day one. Came into lab, got GitHub set up and the
 *                    intial file name as well as the Synopsis and Revision
 *                    History. Started brainstorming ideas.
 *  v0.1 02/24/2015:  As a group, we all read the exercise description and
 *                    tried to get an understanding of the exercise. Thinking
 *                    about how each part of the program would connect to what
 *  v1.2 03/03/2015:  Start of STAGE 1. We read the description again
 *                    for stage 1 to get a better idea
 *  v1.3 03/03/2015:  We made functions, that the user would see and what function
 *                    they can do in the main function. We will add to them
 *                    as we go along.
 *  v1.2 03/03/2015:  We created the file (sss.c). We then started the user
 *                    input.
 *  v1.3 03/03/2015:  We made a count for fgets, which would take in the users
 *                    input.
 *  v1.4 03/03/2015:  We then made a basic loop for fgets, which would take in
 *  v1.5 03/03/2015:  Once we fixed any problems with the fgets loop, we then
 *                    then made a token variable that would tokenise the users
 *                    input and we also added a print.
 *  v1.6 03/10/2015:  We then made a while loop which would tokenise the input
 *                    and then would add each token to an array.
 *  v1.7 03/10/2015:  Once we had done that, we started out loop for token_list
 *                    which would display the list of tokens one at a time, we made
 *                    an if loop for this and used the same while loop within it as
 *                    as we did for then original tokenise.
 *  v2.0 03/10/2015:  Start of STAGE 2. As before, we read the description for this
 *                    stage and tried to think of ideas on how we would process it
 *  v2.1 03/10/2015:  We made a new method called forkSplit which made a new child
 *                    process, we did this by making an if loop, with an else if
 *                    which would let the child be made unless there is an error
 *                    with the users input, it would display and error message.
 *                    The original process, the parent would then wait, this was
 *                    done by making a wait(NULL).
 *  v2.2 03/10/2015:  Once we had programmed the fork, we then checked if this had
 *                    had any effect on any previous work.
 *  v2.3 03/10/2015:  We had to ensure that the sss.c program could execute any
 *                    external commands from the PATH enivorment. We did this by
 *                    using the function execvp(). This was added in the loop for
 *                    forking.
 *  v2.4 03/10/2015:  We added an else forkSplit in the main method.
 *  v3.0 03/10/2015:  Start of STAGE 3. As before, we read the description for this
 *                    stage and tried to think of ideas on how we would process it
 *  v3.1 03/10/2015:  We made a new method called set_enviorment, which would make
 *                    a new setting for HOME and to create a new getter and setter
 *                    for PATH.
 *  v3.2 03/10/2015:  For setting the directory for HOME, we use the function getenv
 *                    ("HOME") and the another function called chdir(home).This sets
 *                    the current directory for HOME.
 *  v3.3 03/11/2015:  We then made a new method called setPath, which would set a
 *                    new path, which also updates the token list.
 *
 *  v3.4 03/11/2015:  We then made a new function called getPath. This uses the function
 *                    getenv("PATH") which will get the new PATH from the token list which
 *                    was set from the setPath method.
 *  v3.4 03/11/2015:  To restore the the original path, we made a new variable in our
 *                    main method called orig_path = getenv("PATH"), which was used in
 *                    the setPath which stores the original path, before it changes.
 *  v3.5 03/11/2015:  We then add getpath, setpath to the main function
 *  v4.0 03/11/2015:  Start of STAGE 4. As before, we read the description for this
 *                    stage and tried to think of ideas on how we would process it.
 *  v4.1 03/12/2015:  For this, we made a new method called changeDirectory. This would
 *                    change the HOME directory by using an if loop, with the function
 *                    chdir, making sure that there is not too many arguements that are
 *                    entered by the user.
 *  v4.2 03/12/2015:  We also used perror, to utilise the error value.
 *  v4.3 03/12/2015:  We then added the cd, which will go to the changeDirectory when
 *                    the user types cd.
 *  v5.0 03/17/2015:  Start of STAGE 5. As before, we read the description for this
 *                    stage and tried to think of ideas on how we would process it
 *  v5.1 03/17/2015:  We made a loop which would check if the input was ! then put into
 *                    token variable the command from history and if not then add to the
 *                    history array.
 *  v5.2 03/17/2015:  We added a view_history, to print history to the user, we used this
 *                    by making a while loop, which will add to the counter and show the
 *                    element last added in the index
 *  v5.3 03/17/2015:  We then added the history, which will go to the view_history method
 *                    when the user types history.
 *  v5.4 03/17/2015:  We then make a new method called call_history, which invokes the
 *                    command from history using if statements, depeding on the number
 *  v6.0 03/17/2015:  Start of STAGE 6. As before, we read the description for this
 *                    stage and tried to think of ideas on how we would process it.
 *  v6.1 03/17/2015:  We made a method called saveHistory, which saves the conents of the
 *                    history to a file, and we added a while loop which makes sure that if the
 *                    history list is empty, then it will not display it.
 *  v6.2 03/24/2015:  We made a method called loadHistory, which will check if the file exists
 *                    and then it if it does, then it will add to history
 *  v6.3 03/24/2015:  If the file does not exist, then it will create a file and skip.
 *  v6.4 03/24/2015:  We then added an if statement to do see if the file exist or not.
 *                    We also had to make sure that the file was in the users home
 *                    directory.
 *  v7.0 03/24/2015:  Start of STAGE 7. As before, we read the description for this
 *                    stage and tried to think of ideas on how we would process it.
 *  v7.1 03/24/2015:  We first had to initialise the aliases.
 *  v7.2 03/24/2015:  We then made a new method called add_alias. This is where we add a new
 *                    alias. We first trimmed the inputs by whiles. We also used the function
 *                    strpy in our if statements when were adding the alias when we write
 *                    the original command and once the the command has been aliased.
 *  v7.3 03/24/2015:  We then added a new method called remove_alias, which removes alias from
 *                    list of aliases that have been changed. It searches the token_list to see
 *                    if the alias that the user has entered is an alias or not, if it is then
 *                    we use an if statments that does this, it will be removed from the list
 *  v7.4 03/25/2015:  We then added a new method called view_alias. This prints out all the
 *                    aliases, it displays the name of the alias and then also displays the
 *                    aliase command.
 *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define token_delim " ,|<>&;\t\n"
#define VERSION "\nSimple Shell in C v0.8. Last Updated 19th April 2015\n"
#define AUTHORS "\nAuthors:\n\n> Yordan Y Stoykov\n> Fraser Graham\n> Kieran Scott\n> Ramsay Meiklem\n> Omer Shah\n"
#define COPYRIGHT "\nCopyright 2015.\n"


typedef struct
{
    char alias_name[512];
    char alias_command[512];
}
alias;

alias aliases[10];
int alias_counter;
char history[20][512] = { "" };
int counter;

/**************************************************************************
 *
 * Call History
 *
 * Checks the command asks for an history element between 0 and 19. If not, 
 * no history will be invoked.
 *
 **************************************************************************/

long call_history(char *buffer)
{
    long num;
    char * error;
    
    buffer++;
    num = strtol(buffer, &error, 10);
    
    if (num < 0 && num >= -20)
    {
        if (*error)
        {
            return -21;
        }
        num = (counter + (21 + num))%20 - 1;
    }
    else if (num > 0 && num <= 20)
    {
        if (*error)
        {
            return -21;
        }
        num = ((counter + num)%20) -1;
    }
    else {
        printf("No previous command found");
        return -21;
    }
    return num;
}

/**************************************************************************
 *
 * View History
 *
 * Prints out the history for 20 elements.
 *
 **************************************************************************/

void view_history()
{
    int i = 0;
    int c = 0;
    c = counter;
    
    while (i < 20)
    {
        if (strcmp(history[c], ""))
        {
            printf("[%i] %i. %s", c, i+1, history[c]);
        }
        c = (c+1)%20;
        i++;
    }
    printf("Counter = %i\n", counter);
    printf("Last element at index [%i]\n", counter-1);
}

/**************************************************************************
 *
 * Save History
 *
 * Adds in the latest command to the history array. Ensures empty history 
 * is not printed.
 *
 **************************************************************************/

void saveHistory()
{
    FILE *fp;
    FILE *fp2;
    int i;
    
    fp = fopen(".hist_list", "w+");
    
    i = 0;
    
    while (strcmp(history[i], "") != 0)
    {
        fprintf(fp, "%s", history[i]);
        i++;
    }
    fclose(fp);
    fp2 = fopen(".hist_list2", "w+");
    fprintf(fp2, "%d", counter);
    fclose(fp2);
}

/**************************************************************************
 *
 * Load History
 *
 * If .hist_list exists, read it and add it into the history. If it does 
 * not exist then create it and skip.
 *
 **************************************************************************/

void loadHistory()
{
    FILE *fp;
    FILE *fp2;
    int i;
    char c[513];
    
    if ((fp = fopen(".hist_list", "r")) == NULL) /*Find or create file*/
    {
        fprintf(stderr, "No history file present. - creating a new one\n");
        
    }
    else /*File exist, read it*/
    {
        while (1)
        {
            if ((fgets(c, 513, fp)) == NULL) /*End of file check*/
            {
                break;
            }
            strcpy(history[counter], c);
            counter = (counter+1) % 20;
        }
        fclose(fp);
    }
    if ((fp2 = fopen(".hist_list2", "r")) == NULL)
    {
        fprintf(stderr, "No counter file present. - creating a new one\n");
    }
    else
    {
        fscanf(fp2, "%d", &i);
        counter = i;
    }
}

/**************************************************************************
 * Check Alias
 *
 * Checks if an alias has already been created.
 *
 **************************************************************************/

char * check_alias(char **token_list)
{
    int i;
    char *output;
    i = 0;
    
    while (i < alias_counter)
    {
        if (!strcmp(token_list[0], aliases[i].alias_name))
        {
            output = aliases[i].alias_command;
            return output;
        }
        i++;
    }
    return "failed";
}

/**************************************************************************
 *
 * View Alias
 *
 * Loops through the array of aliases and prints them.
 *
 **************************************************************************/

void view_alias()
{
    int i;
    printf("LIST OF ALIASES:\n");
    
    while (i < alias_counter)
    {
        printf("Alias name : %s - Alias command : %s", aliases[i].alias_name, aliases[i].alias_command);
        i++;
    }
    printf("Alias counter = %i\n", alias_counter);
}

/**************************************************************************
 *
 * Add Alias
 *
 * Takes input and checks if alias can be created. If so, creates alias.
 *
 **************************************************************************/

void add_alias(char **token_list, char *buffer)
{
    int i;
    bool check;
    check = false;
    i = 0;
    
    buffer = buffer + 5;
    
    /*Trims input*/
    while (isspace(*buffer))
    {
        buffer++;
    }
    
    while (!isspace(*buffer))
    {
        buffer++;
    }
    
    while (isspace(*buffer))
    {
        buffer++;
    }
    
    if (token_list[1] == NULL)
    {
        view_alias();
    }
    else if (token_list[2] != NULL)
    {
        while(i < alias_counter)
        {
            if (!strcmp(token_list[1], aliases[i].alias_name))
            {
                strcpy(aliases[i].alias_command, buffer);
                check = true;
                printf("CHANGED\n");
            }
            i++;
        }

        if (alias_counter < 10)
        {
            if (check == false)
            {
                strcpy(aliases[alias_counter].alias_name, token_list[1]);
                strcpy(aliases[alias_counter].alias_command, buffer);
                alias_counter++;
                printf("ALIASED\n");
            }
        }
        if(alias_counter == 10 && check == false)
        {
            printf("List of aliased commands is full. \n");
        }
    }
    else
    {
        printf("Can't alias that command.\n");
    }
}

/**************************************************************************
 *
 * Remove Alias
 *
 * Checks input has something to unalias. If so, removes that alias.
 *
 **************************************************************************/
           
void remove_alias(char **token_list)
{
    int i;
    int j;
    i = 0;
    j = 0;
    
    if(token_list[1] == NULL)
    {
        printf("There is nothing to unalias\n");
    }
    else
    {
        while (i < alias_counter)
        {
            if (!strcmp(token_list[1], aliases[i].alias_name))
            {
                j = i;
                while (j < alias_counter)
                {
                    strcpy(aliases[j].alias_name, aliases[j+1].alias_name);
                    strcpy(aliases[j].alias_command, aliases[j+1].alias_command);
                    j++;
                }
                alias_counter--;
                printf("Unaliased the command: %s\n", token_list[1]);
            }
            i++;
        }
    }
}

/**************************************************************************
 *
 * Set Environment
 *
 * Gathers environment information and prints it at start of program 
 * execution. Fills the history with empty strings.
 *
 **************************************************************************/

void set_environment ()
{
    char * home;
    int i = 0;
    
    printf("PATH : %s\n", getenv("PATH"));
    printf("HOME : %s\n", getenv("HOME"));
    printf("ROOT : %s\n", getenv("ROOT"));
    
    printf("\n*************************************************************************\n");
    
    
    home = getenv("HOME");
    chdir(home);
    
    while (i < 20)
    {
        strcpy(history[i], "");
        i++;
    }
}

/**************************************************************************
 *
 * Set Path
 *
 * Sets path according to users input
 *
 **************************************************************************/

void setPath(char **token_list)
{
    if (token_list[1] == NULL || token_list[2] != NULL)
    {
        printf("Can't set path.");
    }
    else
    {
        setenv("PATH", token_list[1], 1);
        printf("Path set!");
    }
}

/**************************************************************************
 *
 * Get Path
 *
 * Sets path according to the system the program is being ran on.
 *
 **************************************************************************/

void getPath(char **token_list)
{
    if (token_list[1] != NULL)
    {
        printf("Can't get path.");
    }
    else
    {
        printf("Your path is: %s\n", getenv("PATH"));
    }
}

/**************************************************************************
 *
 * Change Directory
 *
 * If cd command entered has no further arguments, home directory selected.
 * If input includes an argument, the directory is changed to the argument.
 *
 **************************************************************************/

void changeDirectory(char **token_list)
    {
    
    if (token_list[1] == NULL )
    {
        chdir(getenv("HOME"));
    }
    else if (token_list[2] != NULL)
    {
        printf("Too many arguments.\n");
    }
    else {
        if (chdir(token_list[1]) != 0)
        {
            perror("cd");
        }
    }
}

/**************************************************************************
 *
 * Fork Split
 *
 * Forks processes. Parent process will wait for child processes to finish
 * before continuing.
 *
 **************************************************************************/

void forkSplit(char **token_list)
{
    pid_t pid;
    
    /*Process forkings*/
    pid = fork();
    
    if (pid == 0)
    {
        /*Child process*/
        if (execvp(token_list[0], token_list) == -1)
        {
            perror("Error while forking");
        }
        exit(0);
    }
    else if (pid < 0)
    {
        /*Error forking*/
        perror("Error while forking");
        exit(-1);
    }
    else
    {
        /*Parent process*/
        wait(NULL); /*Wait for child to exit*/
    }
}

/**************************************************************************
 *
 * Main
 *
 * Starts the simple shell. Loads the history.
 *
 **************************************************************************/

int main(int args, char *argv[])
{
    char buff[512];
    char * cwd;
    char buffer[512];
    char buffer2[512];
    char hist_buff[512];
    char * token_list[50];
    char * token;
    char * orig_path;
    int count;
    long hist_location;
    
    count = 0;
    counter = 0;
    alias_counter = 0;
    
    orig_path = getenv("PATH");
    
    printf("\n************************************************************************\n");
    printf(VERSION);
    printf(AUTHORS);
    printf(COPYRIGHT);
    printf("\n*************************************************************************\n\n");
    
    set_environment();
    cwd = getcwd(buff, 512);
    
    printf("\n%s$:", cwd);
    
    loadHistory();
    
    while (fgets(buffer, 512, stdin) != NULL && (strcmp(buffer, "exit\n") != 0))
    {
        if (strcmp(buffer, "\n") != 0)
        {
            /*Split put into token variable*/
            strcpy(buffer2, buffer);
            strcpy(hist_buff, buffer2);
            
            token = strtok(buffer, token_delim);
            
            /*If the input was ! then put into token variable the command from history and if not then add it to he history array*/
            if (strcspn(buffer2,  "!") == 0)
            {
                hist_location = call_history(buffer);
                if (hist_location != -21)
                {
                    strcpy(buffer, history[hist_location]);
                    strcpy(buffer2, buffer);
                    token = strtok(buffer, token_delim);
                }
                else
                {
                    printf("\nHistory - invalid input\n");
                }
            }
            else if (token_list[0] != NULL)
            {
                strcpy(history[counter], hist_buff);
                counter = (counter+1) % 20;
            }
            /*Tokanise*/
            while (token != NULL)
            {
                token_list[count] = token;
                count++;
                /*printf( " %s\n", token );*/
                token = strtok(NULL, token_delim);
            }
            /*Add each of the tokens to an array*/
            token_list[count] = NULL;
            count = 0;
            /*Check if aliased commnad*/
            if (token_list[0] != NULL)
            {
                if (strcmp(check_alias(token_list), "failed"))
                {
                    strcpy(buffer, check_alias(token_list));
                    token = strtok(buffer, token_delim);
                    /*Tokanise*/
                    while (token != NULL)
                    {
                        token_list[count] = token;
                        count++;
                        /*printf( " %s\n", token );*/
                        token = strtok(NULL, token_delim);
                    }
                    /*Add each of the tokens to an array*/
                    token_list[count] = NULL;
                    count = 0;
                }
            }
            /*For our commands*/
            if (token_list[0] != NULL && hist_location != -21)
            {
                if (!strcmp(token_list[0], "alias"))
                {
                    add_alias(token_list, buffer2);
                }
                else if (!strcmp(token_list[0], "unalias"))
                {
                    remove_alias(token_list);
                }
                else if (!strcmp(token_list[0], "getpath"))
                {
                    getPath(token_list);
                }
                
                else if (!strcmp(token_list[0], "setpath"))
                {
                    setPath(token_list);
                }
                
                else if (!strcmp(token_list[0], "cd"))
                {
                    changeDirectory(token_list);
                }
                else if (!strcmp(token_list[0], "history"))
                {
                    view_history();
                }
                else /*Fork*/
                {
                    forkSplit(token_list);
                }
            }
            hist_location = 0;
        }
        /*Asks for next command*/
        printf("%s$:", getcwd(buff, 512));
        /*Exits procedures*/
        saveHistory();
        setenv("PATH", orig_path, 1);
    }
    printf("Original path = %s \n", orig_path);
    return 0;
}
