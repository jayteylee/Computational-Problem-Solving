import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class DatesTest {
    @Test
    public void checkFormatTest() throws Exception {
        // checking that correct format is returning true
        assertTrue(DatesValidator.checkFormat("01-Jan-2000"));
        assertTrue(DatesValidator.checkFormat("01-JAN-2000"));
        assertTrue(DatesValidator.checkFormat("01-jan-2000"));
        assertTrue(DatesValidator.checkFormat("01-01-2000"));
        assertTrue(DatesValidator.checkFormat("1-1-2000"));
        assertTrue(DatesValidator.checkFormat("1-01-00"));
        assertTrue(DatesValidator.checkFormat("1-1-00"));
        assertTrue(DatesValidator.checkFormat("01-1-00"));
        assertTrue(DatesValidator.checkFormat("01-01-00"));
        assertTrue(DatesValidator.checkFormat("01/Jan/2000"));
        assertTrue(DatesValidator.checkFormat("01/JAN/2000"));
        assertTrue(DatesValidator.checkFormat("01/jan/2000"));
        assertTrue(DatesValidator.checkFormat("01/01/2000"));
        assertTrue(DatesValidator.checkFormat("1/1/2000"));
        assertTrue(DatesValidator.checkFormat("1/01/00"));
        assertTrue(DatesValidator.checkFormat("1/1/00"));
        assertTrue(DatesValidator.checkFormat("01/1/00"));
        assertTrue(DatesValidator.checkFormat("01/01/00"));
        assertTrue(DatesValidator.checkFormat("01 Jan 2000"));
        assertTrue(DatesValidator.checkFormat("01 JAN 2000"));
        assertTrue(DatesValidator.checkFormat("01 jan 2000"));
        assertTrue(DatesValidator.checkFormat("01 01 2000"));
        assertTrue(DatesValidator.checkFormat("1 1 2000"));
        assertTrue(DatesValidator.checkFormat("1 01 00"));
        assertTrue(DatesValidator.checkFormat("1 1 00"));
        assertTrue(DatesValidator.checkFormat("01 1 00"));
        assertTrue(DatesValidator.checkFormat("01 01 00"));
        assertTrue(DatesValidator.checkFormat("01 01 000"));
        // checking incorrect format is returning false
        assertFalse(DatesValidator.checkFormat(" 01 02 1999"));
        assertFalse(DatesValidator.checkFormat("01 02-1999"));
        assertFalse(DatesValidator.checkFormat("01-02 1999"));
        assertFalse(DatesValidator.checkFormat("01/02 1999"));
        assertFalse(DatesValidator.checkFormat("01 02/1999"));
        assertFalse(DatesValidator.checkFormat(" 01/02-1999"));
        assertFalse(DatesValidator.checkFormat(" 01-02-1999"));
        assertFalse(DatesValidator.checkFormat(" 01 02-1999"));
        assertFalse(DatesValidator.checkFormat(" 01)02-1999"));
        assertFalse(DatesValidator.checkFormat(" 01*02*1999"));
        assertFalse(DatesValidator.checkFormat(" 01 02- 1999"));
        assertFalse(DatesValidator.checkFormat(" 01/ 02/ 1999"));
        assertFalse(DatesValidator.checkFormat(" 01021999"));
        assertFalse(DatesValidator.checkFormat("01/023/1999"));
        assertFalse(DatesValidator.checkFormat("-1/02/1999"));
        assertFalse(DatesValidator.checkFormat("/1/02 1999"));
        assertFalse(DatesValidator.checkFormat("/1 02 1999"));
        assertFalse(DatesValidator.checkFormat("/- 202 1999"));
        assertFalse(DatesValidator.checkFormat("1/02 1999"));
        assertFalse(DatesValidator.checkFormat("one/feb/nineteennineteen"));
    }

    @Test
    public void checkYearTest() throws Exception {
        // checking that years within bounds are returning true
        assertTrue(DatesValidator.checkYear("2000", "1 1 2000"));
        assertTrue(DatesValidator.checkYear("1753", "1 1 1753"));
        assertTrue(DatesValidator.checkYear("3000", "1 1 3000"));
        assertTrue(DatesValidator.checkYear("00", "1 1 00"));
        assertTrue(DatesValidator.checkYear("56", "1 1 1956"));
        assertTrue(DatesValidator.checkYear("29", "1 1 2029"));
        // checking that years out of bounds are returning false
        assertFalse(DatesValidator.checkYear("1752", "1 1 1752"));
        assertFalse(DatesValidator.checkYear("3001", "1 1 3001"));
        assertFalse(DatesValidator.checkYear("1", "1 1 1"));
        assertFalse(DatesValidator.checkYear("101", "1 1 101"));
        assertFalse(DatesValidator.checkYear("50000", "1 1 50000"));
    }

    @Test
    public void checkLeapYearTest() throws Exception {
        // Checking that leap years are returning true
        assertTrue(DatesValidator.checkLeapYear("2000"));
        assertTrue(DatesValidator.checkLeapYear("2004"));
        assertTrue(DatesValidator.checkLeapYear("1600"));
        assertTrue(DatesValidator.checkLeapYear("1200"));
        assertTrue(DatesValidator.checkLeapYear("800"));
        assertTrue(DatesValidator.checkLeapYear("2400"));
        assertTrue(DatesValidator.checkLeapYear("1912"));
        assertTrue(DatesValidator.checkLeapYear("1716"));
        assertTrue(DatesValidator.checkLeapYear("1320"));
        assertTrue(DatesValidator.checkLeapYear("2080"));
        assertTrue(DatesValidator.checkLeapYear("1808"));
        // checking that common years are returning false
        assertFalse(DatesValidator.checkLeapYear("1900"));
        assertFalse(DatesValidator.checkLeapYear("2100"));
        assertFalse(DatesValidator.checkLeapYear("2200"));
        assertFalse(DatesValidator.checkLeapYear("2300"));
        assertFalse(DatesValidator.checkLeapYear("1700"));
        assertFalse(DatesValidator.checkLeapYear("1500"));
        assertFalse(DatesValidator.checkLeapYear("1400"));
        assertFalse(DatesValidator.checkLeapYear("1905"));
        assertFalse(DatesValidator.checkLeapYear("1807"));
        assertFalse(DatesValidator.checkLeapYear("1617"));
        assertFalse(DatesValidator.checkLeapYear("1319"));
        assertFalse(DatesValidator.checkLeapYear("2123"));
        assertFalse(DatesValidator.checkLeapYear("2733"));
        assertFalse(DatesValidator.checkLeapYear("1837"));
        assertFalse(DatesValidator.checkLeapYear("2483"));
        assertFalse(DatesValidator.checkLeapYear("1939"));
    }

    @Test
    public void checkDayTest() throws Exception {
        if (DatesValidator.month == "apr" || DatesValidator.month == "jun" || DatesValidator.month == "sep" || DatesValidator.month == "nov") {
            assertTrue(DatesValidator.checkDay("30", ""));
            assertTrue(DatesValidator.checkDay("1", ""));
            assertTrue(DatesValidator.checkDay("01", ""));
            assertTrue(DatesValidator.checkDay("15", ""));
            assertFalse(DatesValidator.checkDay("32", ""));
            assertFalse(DatesValidator.checkDay("0", ""));
            assertFalse(DatesValidator.checkDay("-1", ""));
            assertFalse(DatesValidator.checkDay("0", ""));
        }else if(DatesValidator.month == "feb" && DatesValidator.leapYear == true){
            assertTrue(DatesValidator.checkDay("29", ""));
            assertTrue(DatesValidator.checkDay("28", ""));
            assertTrue(DatesValidator.checkDay("1", ""));
            assertFalse(DatesValidator.checkDay("30", ""));
            assertFalse(DatesValidator.checkDay("31", ""));
            assertFalse(DatesValidator.checkDay("0", ""));
        }else if(DatesValidator.month == "feb" && DatesValidator.leapYear == false){
            assertTrue(DatesValidator.checkDay("28", ""));
            assertFalse(DatesValidator.checkDay("29", ""));
            assertFalse(DatesValidator.checkDay("30", ""));
            assertFalse(DatesValidator.checkDay("31", ""));
            assertFalse(DatesValidator.checkDay("0", ""));
        }else if (DatesValidator.month == "jan" || DatesValidator.month == "mar"
         || DatesValidator.month == "may" || DatesValidator.month == "jul" || DatesValidator.month == "aug" 
         || DatesValidator.month == "oct" || DatesValidator.month == "dec") {
            assertTrue(DatesValidator.checkDay("31", ""));
            assertTrue(DatesValidator.checkDay("30", ""));
            assertTrue(DatesValidator.checkDay("29", ""));
            assertTrue(DatesValidator.checkDay("28", ""));
            assertTrue(DatesValidator.checkDay("1", ""));
            assertFalse(DatesValidator.checkDay("32", ""));
            assertFalse(DatesValidator.checkDay("0", ""));
        }
    }

    @Test
    public void checkMonthTest() throws Exception {
        // checking digit month input
        assertTrue(DatesValidator.checkMonth("1", ""));
        assertTrue(DatesValidator.checkMonth("2", ""));
        assertTrue(DatesValidator.checkMonth("3", ""));
        assertTrue(DatesValidator.checkMonth("4", ""));
        assertTrue(DatesValidator.checkMonth("5", ""));
        assertTrue(DatesValidator.checkMonth("6", ""));
        assertTrue(DatesValidator.checkMonth("7", ""));
        assertTrue(DatesValidator.checkMonth("8", ""));
        assertTrue(DatesValidator.checkMonth("9", ""));
        assertTrue(DatesValidator.checkMonth("01", ""));
        assertTrue(DatesValidator.checkMonth("02", ""));
        assertTrue(DatesValidator.checkMonth("03", ""));
        assertTrue(DatesValidator.checkMonth("04", ""));
        assertTrue(DatesValidator.checkMonth("05", ""));
        assertTrue(DatesValidator.checkMonth("06", ""));
        assertTrue(DatesValidator.checkMonth("07", ""));
        assertTrue(DatesValidator.checkMonth("08", ""));
        assertTrue(DatesValidator.checkMonth("09", ""));
        assertTrue(DatesValidator.checkMonth("10", ""));
        assertTrue(DatesValidator.checkMonth("11", ""));
        assertTrue(DatesValidator.checkMonth("12", ""));
        assertFalse(DatesValidator.checkMonth("13", ""));
        assertFalse(DatesValidator.checkMonth("0", ""));
        assertFalse(DatesValidator.checkMonth("-1", ""));
        assertFalse(DatesValidator.checkMonth("14", ""));
        // checking 3 letter month input
        assertTrue(DatesValidator.checkMonth("jan", ""));
        assertTrue(DatesValidator.checkMonth("feb", ""));
        assertTrue(DatesValidator.checkMonth("mar", ""));
        assertTrue(DatesValidator.checkMonth("apr", ""));
        assertTrue(DatesValidator.checkMonth("may", ""));
        assertTrue(DatesValidator.checkMonth("jun", ""));
        assertTrue(DatesValidator.checkMonth("jul", ""));
        assertTrue(DatesValidator.checkMonth("aug", ""));
        assertTrue(DatesValidator.checkMonth("sep", ""));
        assertTrue(DatesValidator.checkMonth("oct", ""));
        assertTrue(DatesValidator.checkMonth("nov", ""));
        assertTrue(DatesValidator.checkMonth("dec", ""));
        assertTrue(DatesValidator.checkMonth("JAN", ""));
        assertTrue(DatesValidator.checkMonth("FEB", ""));
        assertTrue(DatesValidator.checkMonth("MAR", ""));
        assertTrue(DatesValidator.checkMonth("APR", ""));
        assertTrue(DatesValidator.checkMonth("MAY", ""));
        assertTrue(DatesValidator.checkMonth("JUN", ""));
        assertTrue(DatesValidator.checkMonth("JUL", ""));
        assertTrue(DatesValidator.checkMonth("AUG", ""));
        assertTrue(DatesValidator.checkMonth("SEP", ""));
        assertTrue(DatesValidator.checkMonth("OCT", ""));
        assertTrue(DatesValidator.checkMonth("NOV", ""));
        assertTrue(DatesValidator.checkMonth("DEC", ""));
        assertTrue(DatesValidator.checkMonth("Jan", ""));
        assertTrue(DatesValidator.checkMonth("Feb", ""));
        assertTrue(DatesValidator.checkMonth("Mar", ""));
        assertTrue(DatesValidator.checkMonth("Apr", ""));
        assertTrue(DatesValidator.checkMonth("May", ""));
        assertTrue(DatesValidator.checkMonth("Jun", ""));
        assertTrue(DatesValidator.checkMonth("Jul", ""));
        assertTrue(DatesValidator.checkMonth("Aug", ""));
        assertTrue(DatesValidator.checkMonth("Sep", ""));
        assertTrue(DatesValidator.checkMonth("Oct", ""));
        assertTrue(DatesValidator.checkMonth("Nov", ""));
        assertTrue(DatesValidator.checkMonth("Dec", ""));
        assertFalse(DatesValidator.checkMonth("january", ""));
        assertFalse(DatesValidator.checkMonth("february", ""));
        assertFalse(DatesValidator.checkMonth("march", ""));
        assertFalse(DatesValidator.checkMonth("april", ""));
        assertFalse(DatesValidator.checkMonth("june", ""));
        assertFalse(DatesValidator.checkMonth("july", ""));
        assertFalse(DatesValidator.checkMonth("august", ""));
        assertFalse(DatesValidator.checkMonth("september", ""));
        assertFalse(DatesValidator.checkMonth("october", ""));
        assertFalse(DatesValidator.checkMonth("november", ""));
        assertFalse(DatesValidator.checkMonth("december", ""));
        assertFalse(DatesValidator.checkMonth("sept", ""));
        assertFalse(DatesValidator.checkMonth("hello", ""));
    }
    
}
