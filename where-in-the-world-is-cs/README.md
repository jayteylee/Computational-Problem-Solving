# Where in the World is CS?

I have developed a program that is able to read lines of input from a .txt file that is selected in the file upload on the web page and then displays the appropriate locations on a global map. In order to achieve this, the input had to be validated to ensure only the appropriate input is able to be displayed.

GeoJSON requires coordinates in standard form with the property name variable being optional. Contrary to normal standards, in the GeoJSON format, longitude comes before latitude when passing in the variables.

Some forms of input I have been able to validate and convert into standard form for GeoJSON are:
* Standard form itself
* Standard form when commas for delimiters are missing
* Standard form when the number of decimal points differs from 6
* Standard form with non-negative numbers followed by a direction (N S E W). These variables for longitude and latitude possibly being provided in an incorrect order.
* Standard form when there is only one direction
* Standard form when a direction given is 'S' or 'W' AND the value for that direction has a negative (checks if it is already negative before attempting to convert to negative)
* Degrees, minutes and seconds form (with or without the standard markers and with or without the decimal places)
* Degrees and minutes form.
* DM and DMS format when there is only one direction given
* DM and DMS when a direction given is 'S' or 'W' AND the value for that direction has a negative (checks if it is already negative before attempting to convert to negative)


---
### My Implementation
My way of cleansing and validating the input was to first trim the input line of any leading or trailing white spaces. From here, I then split the input line into an array of strings using the .split() function with regexes that ensure the input is split on spaces, degrees symbol, apostrohes and quotation marks. 

This method is able to split the input into an array for all of the different forms of input stated above.

Once the input has been split into the array, we check whether a direction is present in the filtered coordinates and if the number of directions is 1. If so, we must handle this case. This is done by checking the value of the direction and then converting the value for that direction based on the direction it self. After the conversion, a new array of strings is formed and then passed onto the next step.


Depending on the array size we call different functions that decipher the array and convert it into a feature to be pushed into our feature collection that is then used to display the markers on our Leaflet.js map.

Here are the cases that we cover and call different functions for:
1. when the length of the coordinates array is less than or equal to 3. In this case, the input must be in standard form with no directions specified. The name of the location may or may not be included. Since there is no direction given, we have to assume that the input is in the order of "latitude" and then "longitude".
   
2. When the length of the coordinates array is greater than 3 and less than or equal to 5 and the number of directions in the array is greater than 0. In this case, the input is still in standard form but this time the directions have been provided. Since we need to account for the order of the coordinates being given in different orders (longitude and latitude as opposed to latitude and longitude), we must check the directions value of the array and check whether the first set if coordinates is the latitude or longitude. From here we are able to determine the longitude and latitude and convert it accordingly (negative if S or W) by checking the direction.

3. When the length of the coordinates array is greater than 3 and less than or equal to 7 and there are no directions present in the array. In this case, the input is either in DM or DMS form but there are no direction provided. Since there are no directions, we can assume the input has been given in the order of latitude and longitude. From here we convert the DM or DMS values to decimal and push the feature into our collection.
   
4. When the length of the coordinates array is greater than 3 and less than or equal to 9. This case implies that the input is in either DM or DMS form. Depending on the length, we call upon the appropriate function which is able to convert the input into longitude and latitude which is then passed into the pushFeature function. Another assumption which is pivotal in this implementation is that in the DMS and DM forms, the input will always specify the direction (N S E W). Another assumption is that there is no mixing of DM and DMS.
---
Overall, this program is able to handle a variety of inputs and handle lots of different forms of coordinate information from a .txt file and then display it dynamically on the leaflet.js map via file upload.