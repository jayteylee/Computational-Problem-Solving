#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

#define MAX_LENGTH 100

struct Client
{
    char *firstName;
    char *lastName;
    char *phoneNumber;
    char *emailAddress;
};

static int i, totalClients;

// Find clients by first name
void findByFirstName(struct Client **clients, char *s)
{
    bool found = false;
    printf("---------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-15s | %-35s | %-15s |\n", "First Name", "Last Name", "Email", "Phone Number");
    printf("---------------------------------------------------------------------------------------------\n");
    for (i = 0; i < totalClients; i++)
    {
        if (strcasecmp(clients[i]->firstName, s) == 0)
        {
            found = true;
            printf("| %-15s | %-15s | %-35s | %-15s |\n", clients[i]->firstName, clients[i]->lastName, clients[i]->emailAddress, clients[i]->phoneNumber);
        }
    }
    if (found == false)
    {
        printf("%s not found.\n", s);
    }
    printf("---------------------------------------------------------------------------------------------\n");
}

// Find clients by last name
void findByLastName(struct Client **clients, char *s)
{
    printf("---------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-15s | %-35s | %-15s |\n", "First Name", "Last Name", "Email", "Phone Number");
    printf("---------------------------------------------------------------------------------------------\n");
    bool found = false;
    for (i = 0; i < totalClients; i++)
    {
        if (strcasecmp(clients[i]->lastName, s) == 0)
        {
            found = true;
            printf("| %-15s | %-15s | %-35s | %-15s |\n", clients[i]->firstName, clients[i]->lastName, clients[i]->emailAddress, clients[i]->phoneNumber);
        }
    }
    if (found == false)
    {
        printf("%s not found.\n", s);
    }
    printf("---------------------------------------------------------------------------------------------\n");
}

// Find clients by phone number
void findByPhoneNumber(struct Client **clients, char *s)
{
    printf("---------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-15s | %-35s | %-15s |\n", "First Name", "Last Name", "Email", "Phone Number");
    printf("---------------------------------------------------------------------------------------------\n");
    bool found = false;
    for (i = 0; i < totalClients; i++)
    {
        if (strcasecmp(clients[i]->phoneNumber, s) == 0)
        {
            found = true;
            printf("| %-15s | %-15s | %-35s | %-15s |\n", clients[i]->firstName, clients[i]->lastName, clients[i]->emailAddress, clients[i]->phoneNumber);
        }
    }
    if (found == false)
    {
        printf("%s not found.\n", s);
    }
    printf("---------------------------------------------------------------------------------------------\n");
}

// Find clients by email address
void findByEmailAddress(struct Client **clients, char *s)
{
    printf("---------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-15s | %-35s | %-15s |\n", "First Name", "Last Name", "Email", "Phone Number");
    printf("---------------------------------------------------------------------------------------------\n");
    bool found = false;
    for (i = 0; i < totalClients; i++)
    {
        if (strcasecmp(clients[i]->emailAddress, s) == 0)
        {
            found = true;
            printf("| %-15s | %-15s | %-35s | %-15s |\n", clients[i]->firstName, clients[i]->lastName, clients[i]->emailAddress, clients[i]->phoneNumber);
        }
    }
    if (found == false)
    {
        printf("%s not found.\n", s);
    }
    printf("---------------------------------------------------------------------------------------------\n");
}

// Swap two clients
void swapClients(struct Client **clients, int i, int j)
{
    struct Client *temp = clients[i];
    clients[i] = clients[j];
    clients[j] = temp;
}

// Partition the array for quicksort based on first name
int partitionFirst(struct Client **clients, int low, int high)
{
    char *pivot = clients[high]->firstName;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (strcmp(clients[j]->firstName, pivot) < 0)
        {
            i++;
            swapClients(clients, i, j);
        }
    }

    swapClients(clients, i + 1, high);
    return i + 1;
}

// Partition the array for quicksort based on last name
int partitionLast(struct Client **clients, int low, int high)
{
    char *pivot = clients[high]->lastName;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (strcmp(clients[j]->lastName, pivot) < 0)
        {
            i++;
            swapClients(clients, i, j);
        }
    }

    swapClients(clients, i + 1, high);
    return i + 1;
}

// Partition the array for quicksort based on email address
int partitionEmail(struct Client **clients, int low, int high)
{
    char *pivot = clients[high]->emailAddress;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (strcmp(clients[j]->emailAddress, pivot) < 0)
        {
            i++;
            swapClients(clients, i, j);
        }
    }

    swapClients(clients, i + 1, high);
    return i + 1;
}

// Quicksort the client array based on first name
void quicksortFirst(struct Client **clients, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionFirst(clients, low, high);
        quicksortFirst(clients, low, pivotIndex - 1);
        quicksortFirst(clients, pivotIndex + 1, high);
    }
}

// Quicksort the client array based on last name
void quicksortLast(struct Client **clients, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionLast(clients, low, high);
        quicksortLast(clients, low, pivotIndex - 1);
        quicksortLast(clients, pivotIndex + 1, high);
    }
}

// Quicksort the client array based on email address
void quicksortEmail(struct Client **clients, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionEmail(clients, low, high);
        quicksortEmail(clients, low, pivotIndex - 1);
        quicksortEmail(clients, pivotIndex + 1, high);
    }
}

// Sort first name using quicksort based on first name
void sortFirstName(struct Client **clients, int totalClients)
{
    quicksortFirst(clients, 0, totalClients - 1);
}

// Sort first name using quicksort based on last name
void sortLastName(struct Client **clients, int totalClients)
{
    quicksortLast(clients, 0, totalClients - 1);
}

// Sort email using quicksort based on email address
void sortEmail(struct Client **clients, int totalClients)
{
    quicksortEmail(clients, 0, totalClients - 1);
}

// Compare function for sorting clients by phone number
// Used as a callback function for qsort
int compareByPhoneNumber(const void *a, const void *b)
{
    // Convert void pointers to pointers to Client structures
    struct Client *clientA = *(struct Client **)a;
    struct Client *clientB = *(struct Client **)b;

    // Convert phone numbers to long integers
    long phoneNumberA = atol(clientA->phoneNumber);
    long phoneNumberB = atol(clientB->phoneNumber);

    // Compare phone numbers
    if (phoneNumberA < phoneNumberB)
    {
        return -1; // clientA comes before clientB
    }
    else if (phoneNumberA > phoneNumberB)
    {
        return 1; // clientB comes before clientA
    }
    else
    {
        return 0; // phone numbers are equal
    }
}

// Partition the array for quicksort based on phone number
int partitionPhone(struct Client **clients, int low, int high)
{
    long pivot = atol(clients[high]->phoneNumber);
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        long phoneNumber = atol(clients[j]->phoneNumber);
        if (phoneNumber < pivot)
        {
            i++;
            swapClients(clients, i, j);
        }
    }

    swapClients(clients, i + 1, high);
    return i + 1;
}

// Quicksort the client array by phone number
void quicksortPhone(struct Client **clients, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionPhone(clients, low, high);
        quicksortPhone(clients, low, pivotIndex - 1);
        quicksortPhone(clients, pivotIndex + 1, high);
    }
}

// Sort clients by phone number using quicksort
void sortPhone(struct Client **clients, int totalClients)
{
    quicksortPhone(clients, 0, totalClients - 1);
}

// Display clients information in a formatted table based on the specified sorting order
void displayClients(struct Client **clients, int totalClients, char *s)
{
    // Check the specified sorting order
    if (strcasecmp(s, "firstname") == 0)
    {
        printf("Here are all clients displayed in order of first name:\n");
        sortFirstName(clients, totalClients); // Sort clients by first name
    }
    else if (strcasecmp(s, "lastname") == 0)
    {
        printf("Here are all clients displayed in order of last name:\n");
        sortLastName(clients, totalClients); // Sort clients by last name
    }
    else if (strcasecmp(s, "email") == 0)
    {
        printf("Here are all clients displayed in order of email address:\n");
        sortEmail(clients, totalClients); // Sort clients by email address
    }
    else if (strcasecmp(s, "phone") == 0)
    {
        printf("Here are all clients displayed in order of phone number:\n");
        sortPhone(clients, totalClients); // Sort clients by phone number
    }
    else
    {
        printf("Default sorting order:\n");
    }

    int nameWidth = 20;  // Width for displaying the name column
    int emailWidth = 35; // Width for displaying the email column
    int phoneWidth = 15; // Width for displaying the phone number column

    // Print the table headers
    printf("------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-35s | %-15s |\n", "Name", "Email", "Phone Number");
    printf("------------------------------------------------------------------------------------------------------------------\n");

    // Print the client information
    for (int i = 0; i < totalClients; i++)
    {
        // Combine first name and last name
        char fullName[MAX_LENGTH];
        snprintf(fullName, sizeof(fullName), "%s %s", clients[i]->firstName, clients[i]->lastName);

        // Truncate the name if it exceeds the specified width
        if (strlen(fullName) > nameWidth - 3)
        {
            fullName[nameWidth - 6] = '.';
            fullName[nameWidth - 5] = '.';
            fullName[nameWidth - 4] = '.';
            fullName[nameWidth - 3] = '\0';
        }

        // Print the client's information in the table format
        printf("| %-20s | %-35s | %-15s |\n", fullName, clients[i]->emailAddress, clients[i]->phoneNumber);
    }

    // Print the bottom border
    printf("------------------------------------------------------------------------------------------------------------------\n");
}

int main(int argc, char **argv)
{
    char fileName[MAX_LENGTH];
    FILE *file = NULL;

    // If there are two or more arguments, use the file name from the command-line argument
    if (argc >= 2)
    {
        file = fopen(argv[1], "r");
        if (file == NULL)
        {
            printf("File not found from command line argument\n");
        }
    }

    bool validFile = (file != NULL);

    // Prompt the user for the file name until a valid file is entered
    while (!validFile)
    {
        printf("Enter the file name for the client data: ");
        scanf("%s", fileName);
        file = fopen(fileName, "r");
        if (file == NULL)
        {
            printf("File not found. Please try again.\n");
        }
        else
        {
            printf("File found.\n");
            validFile = true;
        }
    }

    char line[MAX_LENGTH];
    struct Client **clients = malloc(100 * sizeof(struct Client *));
    // totalClients = 0;
    while (fgets(line, sizeof(line), file) != NULL) // Read the file line by line
    {
        // Allocate memory for the client
        clients[totalClients] = malloc(sizeof(struct Client));
        clients[totalClients]->firstName = malloc(80 * sizeof(char));
        clients[totalClients]->lastName = malloc(80 * sizeof(char));
        clients[totalClients]->phoneNumber = malloc(80 * sizeof(char));
        clients[totalClients]->emailAddress = malloc(80 * sizeof(char));

        // Parse the values from the line using sscanf()
        sscanf(line, "%s %s %s %s", clients[totalClients]->firstName, clients[totalClients]->lastName, clients[totalClients]->phoneNumber, clients[totalClients]->emailAddress);

        // Increment the number of clients
        totalClients++;
    }
    // Close the file
    fclose(file);

    // Displays the total number of clients loaded from the file
    printf("%d clients have been loaded into the system.\n", totalClients);

    // Display the menu and prompt the user for a command
    char input;
    char search[MAX_LENGTH];
    char sort[MAX_LENGTH];
    do
    {
        printf("Please select a function:\n 1. Filter by first name\n 2. Filter by last name\n 3. Filter by phone number\n 4. Filter by email\n 5. Display all clients\n e. Exit Program\nSelect task : ");
        scanf(" %c", &input);
        switch (input)
        {
        case '1':
            printf("Enter the first name: ");
            scanf("%s", search);
            findByFirstName(clients, search);
            break;
        case '2':
            printf("Enter the last name: ");
            scanf("%s", search);
            findByLastName(clients, search);
            break;
        case '3':
            printf("Enter the phone number: ");
            scanf("%s", search);
            findByPhoneNumber(clients, search);
            break;
        case '4':
            printf("Enter the email address: ");
            scanf("%s", search);
            findByEmailAddress(clients, search);
            break;
        case '5':
            printf("How would you like to sort the clients? (firstname/lastname/email/phone): ");
            scanf("%99s", sort);
            displayClients(clients, totalClients, sort);
            break;
        case 'e':
            printf("Exiting the program now.\n");
            break;
        default:
            printf("Invalid command. Try again.\n");
            break;
        }
    } while (input != 'e');

    //  Iterate over all clients annd free the malloc-ed memory space.
    for (i = 0; i < totalClients; i++)
    {
        // Free the memory allocated for the client
        free(clients[i]->firstName);
        free(clients[i]->lastName);
        free(clients[i]->emailAddress);
        free(clients[i]->phoneNumber);
        free(clients[i]);
    }
    // Free the memory allocated for the clients array
    free(clients);

    return 0;
}
