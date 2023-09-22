# How to run the program

To compile the program use:

 `gcc -o main main.c -lm 2> /dev/null`

Once compiled, you can either run the program by just using:

`./main`

And then manually inputting the name of the .txt file you'd like to import client data from

or

`./main nameOfFile.txt`

---
I have already created a .txt file containing 32 clients with some users having the same first name or same last name.

Once you have run the program, you will be prompted to try out the different functions of the program.

## Display Clients Function
If you select "5" to display clients, you will then be further prompted to select a sorting order. Valid input for this is:

`firstname`

`lastname`

`email`

`phone`

If you do not input any of these, the clients will just be displayed in their default order (the order in which they were imported).

---
## Filter functions
Please note that the filter functions will return all clients who match the filter criteria. In the data set there are some users with the same first name or the same last name. Therefore, there may be more than one client returned when you filter by a certain first or last name.