import java.util.Scanner;

/**
 * A class that reads a line of input from stdin and determines whether or not it is a valid date between 
 * the years 1753 and 3000 (including).
 * 
 * Input dates can be presented in different formats and in different orders. For our purposes, 
 * dates in the following order will be considered valid:
 * 
 * day month year
 * 
 * and acceptable input may be in any of the following formats:
 * 
 * day: dd or d or 0d
 * 
 * month: mm or m or 0m or the first three letters of the month name (all in the same case,
 * or with the first letter upper-case) 
 * 
 * year: yy or yyyy
 * 
 * separator: - or / or <space>
 *
 * Notes:
 * 1. 29th of February is only considered a valid date in leap years.
 * 2. If the year is written with only two digits, the date lies between 1950 and 2049, so 65 means 1965 and 42 means 2042.
 * 3. only one separator type to be used in one date
 */
public class DatesValidator {
    public static String[] months = { "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov",
            "dec" };
    public static String[] splitInput;
    public static boolean leapYear;
    public static String year;
    public static String month;
    public static String day;

    /**
     * The main method where user input is checked with the different data validator methods.
     * @param args
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String userInput = sc.nextLine();
            if (checkFormat(userInput) == true) {
                if (checkYear(splitInput[2], userInput) && checkMonth(splitInput[1], userInput)
                        && checkDay(splitInput[0], userInput)) {
                            System.out.println(day + " " + month.substring(0,1).toUpperCase() + month.substring(1) + " " + year);
                }

            }
        }
    }

    /**
     * A method that validates and parses the day component of the given user input, taking into account the 
     * month and year components that have already been validated and parsed. The function determines the number
     * of days in the given month and year, and checks that the day component falls within the valid range. 
     * If the day is valid and successfully parsed, it is stored in the class variable 'day'. If the day 
     * is invalid, an error message is printed and the function returns false.
     * @param dayInput a string representing the day component of the user input to be validated and parsed.
     * @param userInput the original user input, used for error reporting.
     * @return boolean - true if the day component is valid and successfully parsed, false otherwise.
     */
    public static boolean checkDay(String dayInput, String userInput) {
        int daysInMonth;
        if (month.matches("feb")) {
            daysInMonth = leapYear ? 29:28;
        } else if (month.matches(months[3]) || month.matches(months[5]) || month.matches(months[8])
                || month.matches(months[10])) {
            daysInMonth = 30;
        } else {
            daysInMonth = 31;
        }

        if (Integer.parseInt(dayInput) <= daysInMonth && Integer.parseInt(dayInput) > 0) {
            if (dayInput.length() == 1) {
                day = "0" + dayInput;
            } else {
                day = dayInput;
            }
            return true;
        } else {
            printError(userInput, "Day is out of range for the month");
            return false;
        }
    }

    /**
     * A method that validates and parses the month component of the given user input.
     * If the month represented as a two digit number between 01 and 12, it is parsed 
     * into the corresponding month name and stored in the class variable 'month'. 
     * If the month is represented as a three letter abbreviation of a month name (case insensitive),
     * it is validated against a pre-defined list of month abbreviations and parsed into the
     * corresponding month name. If the month is invalid or cannot be parsed, an error message is printed
     * and the function returns false.
     * @param monthInput a string representing the month component of the the user input to be validated and parsed.
     * @param userInput the original user input, used for error reporting.
     * @return boolean - true if the month component is valid and successfully parsed, false otherwise.
     */
    public static boolean checkMonth(String monthInput, String userInput) {
        boolean monthMatch = false;
        if (monthInput.matches("\\d{1,2}") && Integer.parseInt(monthInput) < 13 && Integer.parseInt(monthInput) > 0) {
            month = months[Integer.parseInt(monthInput) - 1];
            return true;
        } else if (monthInput.matches("[a-zA-Z]{3}")) {
            for (int i = 0; i < months.length; i++) {
                if (monthInput.toLowerCase().matches(months[i])) {
                    month = months[i];
                    return true;
                }
            }
        } else {
            System.out.println(userInput + " - INVALID");
            System.err.println("Not a valid month");
            return false;
        }
        if (monthMatch == false) {
            printError(userInput, "Not a valid month.");
            return false;
        }
        return false;
    }

    /**
     * A function that validates and parses the year component of the given user input. If the year is a two-digit number
     * between 50 and 99, it is assumed to represent a year in the 20th century (19xx). If the year is a
     * two-digit number between 00 and 49, it is assumed to represent a year in the 21st century (20xx).
     * If the year is a four-digit number between 1753 and 3000, it is considered valid and passed to the
     * checkLeapYear function to determine if it is a leap year. If the year is out of range or otherwise
     * invalid, an error message is printed and the function returns false. If the year is valid, it is
     * stored in the class variable year and the function returns true.
     * @param yearInput a string representing the year component of the user input to be validated and parsed
     * @param userInput the original user input, used for error reporting
     * @return boolean - true if the year component is valid and successfully parsed, false otherwise
     */
    public static boolean checkYear(String yearInput, String userInput) {
        if (Integer.parseInt(yearInput) > 49 && Integer.parseInt(yearInput) < 100) {
            yearInput = "19" + yearInput;
        } else if (Integer.parseInt(yearInput) < 50) {
            yearInput = "20" + yearInput;
        }
        if (Integer.parseInt(yearInput) > 1752 && Integer.parseInt(yearInput) < 3001) {
            if(checkLeapYear(yearInput)){
                leapYear = true;
            }else{
                leapYear = false;
            }
            year = yearInput;
            return true;
        } else {
            printError(userInput, "Year is out of range.");
            return false;
        }
    }

    /**
     * A method for determining if the given year is a leap year according to the Gregorian calendar. If the year is a leap year,
     * sets the class variable leapYear to true; otherwise, sets leapYear to false.
     * @param yearInput a string representing the year to be checked for leap year status.
     */
    public static boolean checkLeapYear(String yearInput) {
        if (Integer.parseInt(yearInput) % 4 == 0
                && ((Integer.parseInt(yearInput) % 100 != 0 || Integer.parseInt(yearInput) % 400 == 0))) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * A method for checking if the user input is in the correct format with regex.
     * Checks if the given user input matches one of the accepted formats: "dd-MMM-yy", "dd/MMM/yy", or "dd MMM yy".
     * Single or double digits is also an accepted format for month.
     * @param userInput a string containing the user input to be validated
     * @return boolean - true if the input is in one of the accepted formats, false otherwise
     */
    public static boolean checkFormat(String userInput) {
        if (userInput.matches("\\d{1,2}-(\\d{1,2}|[a-zA-Z]{3})-\\d{2,}")
                || userInput.matches("\\d{1,2}/(\\d{1,2}|[a-zA-Z]{3})/\\d{2,}")
                || userInput.matches("\\d{1,2} (\\d{1,2}|[a-zA-Z]{3}) \\d{2,}")) {
            splitInput = userInput.split("[-/ ]");
            if (splitInput[1].matches("[a-zA-Z]{3}")) {
                if (splitInput[1].matches("[a-z]{3}") || (splitInput[1].matches("[A-Z]{3}"))
                        || (splitInput[1].matches("([A-Z][a-z]{2})"))) {
                    return true;
                } else {
                    printError(userInput, "Incorrect input formatting");
                    return false;
                }
            }
            return true;
        } else {
            printError(userInput, "Incorrect input formatting");
            return false;
        }
    }

    /**
     * A method for printing error messages to stdout and stderr
     * @param userInput
     * @param errorMessage
     */
    public static void printError(String userInput, String errorMessage) {
        System.out.println(userInput + " - INVALID");
        System.err.println(errorMessage);
    }
}
