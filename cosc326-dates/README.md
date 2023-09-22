## Dates Validator

The dates validator program is used to determine whether a user inputted date is in an accepted format and is a legitimate year according to the Gregorian calendar.

When running normally, the program will read stdin from the keyboard. However, when run with a .txt file 'java DatesValidator.java < "name of .txt file' the program will read through each line of the .txt file and treat each new line as user input.

## Testing
To test my program I developed JUnit tests as you can see in the DatesTest.java file. In here, I created JUnit tests with AssertTrue and AssertFalse to test all functions in the DatesValidator class (we used AssertTrue and AssertFalse since these functions returned a boolean). 

A more informal form of testing that took place was manually inputting valid and invalid dates while developing and comparing the output with what would be expected output.

Beyond that, I also created an invalid.txt file that could be run with the program so that once the program was developed enough, I could test multiple invalid inputs (compared to manually inputting one by one).