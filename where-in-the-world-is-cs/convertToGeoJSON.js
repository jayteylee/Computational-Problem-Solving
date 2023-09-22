//Author Jay Lee

// Initialize an empty GeoJSON feature collection
const featureCollection = {
  type: 'FeatureCollection',
  features: []
};

// Initialize Leaflet map
const map = L.map('map').setView([0, 0], 2); // Set the initial map view

// Add a tile layer to the map
L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
  attribution: 'Map data &copy; <a href="https://www.openstreetmap.org/">OpenStreetMap</a> contributors',
  maxZoom: 18
}).addTo(map);

let geoJsonLayer; // Define a global variable to hold the GeoJSON layer

function displayFeatureCollection() {
  // Remove the existing GeoJSON layer if it exists
  if (geoJsonLayer) {
    map.removeLayer(geoJsonLayer);
  }

  // Create a new GeoJSON layer
  geoJsonLayer = L.geoJSON(featureCollection, {
    onEachFeature: function (feature, layer) {
      const name = feature.properties.name;
      layer.bindTooltip(name);
    }
  });

  // Add the new GeoJSON layer to the map
  geoJsonLayer.addTo(map);
}


// Attach event listener to the file input change event
const fileInput = document.getElementById('file-input');
fileInput.addEventListener('change', handleFileInputChange);

/**
 * Event handler for the file input change event.
 * Triggered when a file is selected.
 * Calls the processSelectedFile function to process the selected file.
 */
function handleFileInputChange() {
  processSelectedFile();
}

/**
 * Process the selected file from the file input.
 * Read the file content and pass it to processFileContent function.
 */
function processSelectedFile() {
  const fileInput = document.getElementById('file-input');
  const file = fileInput.files[0];
  const reader = new FileReader();
  reader.onload = (event) => {
    const fileContent = event.target.result;
    processFileContent(fileContent);
  };
  reader.readAsText(file);
}

/**
 * Process the content of a file.
 * Clears the previous feature collection, splits the file content into lines,
 * and processes each input line.
 * Finally, displays the feature collection on the map.
 * @param {string} fileContent - The content of the file to process.
 */
function processFileContent(fileContent) {
  // Clear the previous feature collection
  featureCollection.features = [];

  const lines = fileContent.split('\n');
  lines.forEach(processInputLine);

  // Display the feature collection on the map
  displayFeatureCollection();
}

/**
 * Process a line of input from a .txt file.
 * @param {string} line - The input line to process.
 */
const processInputLine = (line) => {
  try {
    // Trim whitespace from the input line
    const inputLine = line.trim();
    // Split the line into an array of coordinates, removing empty elements (splitting on commas, degrees symbol, quotation marks and single quote)
    let coordinates = inputLine.split(/[ ,"\u00B0']/).filter(Boolean);
    // Filter out elements that are not 'd', 'm', or 's'
    let filteredCoordinates = coordinates.filter((element) => {
      return !['d', 'm', 's'].includes(element);
    });

    let newCoordinates;

    // Check if there is only one direction element ('W', 'S', 'N, 'E') and update the corresponding coordinate
    if (countDirections(filteredCoordinates) === 1) {
      const index = findDirectionIndex(filteredCoordinates);
      if (filteredCoordinates[index].toLowerCase() === 'w' || filteredCoordinates[index].toLowerCase() === 's') {
        if (filteredCoordinates.length <= 4) {
          let value = parseFloat(filteredCoordinates[index - 1]);
          if (value >= 0) {
            value *= -1;
          }
          let stringValue = value.toFixed(4); // Convert the numeric value to a string with 4 decimal places
          newCoordinates = [
            ...filteredCoordinates.slice(0, index - 1),  // Elements before the updated element
            stringValue,
            ...filteredCoordinates.slice(index)  // Elements after the updated element
          ];
        } else if (filteredCoordinates.length <= 6) {
          let value = parseFloat(filteredCoordinates[index - 2]);
          if (value >= 0) {
            value *= -1;
          }
          let stringValue = value.toFixed(4); // Convert the numeric value to a string with 4 decimal places
          newCoordinates = [
            ...filteredCoordinates.slice(0, index - 2),  // Elements before the updated element
            stringValue,
            ...filteredCoordinates.slice(index - 1)  // Elements after the updated element
          ];
        } else if (filteredCoordinates.length <= 8) {
          let value = parseFloat(filteredCoordinates[index - 3]);
          if (value >= 0) {
            value *= -1;
          }
          let stringValue = value.toFixed(4); // Convert the numeric value to a string with 4 decimal places
          newCoordinates = [
            ...filteredCoordinates.slice(0, index - 3),  // Elements before the updated element
            stringValue,
            ...filteredCoordinates.slice(index - 2)  // Elements after the updated element
          ];
        }
      }

      let coordinatesToFilter = newCoordinates || filteredCoordinates;

      // Filter out direction elements ('N', 'S', 'W', 'E')
      filteredCoordinates = coordinatesToFilter.filter((element) => {
        return !['N', 'S', 'W', 'E', 'n', 's', 'w', 'e'].map(dir => dir.toLowerCase()).includes(element.toLowerCase());
      });
    }

    if (filteredCoordinates.length <= 3) {
      // Process coordinates in standard form without any directions (e.g., N, S, W, E)
      standardFormNoDirections(filteredCoordinates);
    } else if (filteredCoordinates.length > 3 && filteredCoordinates.length <= 5 && countDirections(filteredCoordinates) > 0) {
      // Process coordinates in standard form with included directions
      standardFormWithDirections(filteredCoordinates);
    } else if (filteredCoordinates.length > 3 && filteredCoordinates.length <= 7 && countDirections(filteredCoordinates) === 0) {
      // Process coordinates in decimal form without any directions
      decimalFormNoDirections(filteredCoordinates);
    } else if (filteredCoordinates.length > 5 && filteredCoordinates.length <= 9) {
      // Process coordinates in decimal form (handles both DM and DMS formats)
      decimalForm(filteredCoordinates);
    } else {
      console.log("Input too long");
    }
  } catch (error) {
    console.error(`Unable to process: ${line}`);
  }


  /**
 * Counts the number of direction elements ('N', 'S', 'W', 'E') in an array of coordinates.
 * @param {string[]} coordinates - The array of coordinates.
 * @returns {number} - The count of direction elements.
 */
  function countDirections(coordinates) {
    const regexPattern = /^(?:S|s|N|n|E|e|W|w)$/; // Regular expression pattern for 'S', 'N', 'E', 'W' (both upper and lower case)
    const count = coordinates.filter((element) => regexPattern.test(element)).length;
    return count;
  }

  /**
   * A function for searching through the coordinates array and returning the index of where N, S, W, E are.
   * @param {string[]} coordinates - The array of coordinates.
   * @returns {number} - The index of the direction in the array.
   */
  function findDirectionIndex(coordinates) {
    const directions = ["N", "S", "W", "E"];

    for (let i = 0; i < coordinates.length; i++) {
      const currentElement = coordinates[i].toUpperCase();
      if (directions.includes(currentElement)) {
        return i;
      }
    }

    return -1; // Return -1 if no matching element is found
  }

  /**
   * Function for handling a line of input that has no directions. Array length will either be 2 or 3.
   * Since there are no directions, we can assume the input is in the order of latitude and then longitude.
   * This function will check if they are within the valid range and then process them by calling the pushFeature() function.
   * @param {string[]} coordinates - The array of coordinates.
   */
  function standardFormNoDirections(coordinates) {
    const [lat, lon] = [coordinates[0], coordinates[1]];
    if ((lat <= 90 && lat >= -90) && (lon <= 180 && lon >= -180)) {
      const latitude = parseFloat(lat);
      const longitude = parseFloat(lon);
      const locationName = getLocationName(coordinates);
      pushFeature(latitude, longitude, locationName);
    } else {
      console.log("Latitude or longitude is not in the valid range.");
    }
  }

  /**
   * A function that handles a line of input that includes directions (e.g., N, S, E, W).
   * Since the longitude and latitude can be provided in a mixed order, we check to see whether the first set of coordinates (value and direction)
   * is for the latitude or longitude by checking the direction value. Based on this, we can assign the values and directions of the longitude and latitude.
   * @param {string[]} coordinates - The array of coordinates.
   */
  function standardFormWithDirections(coordinates) {
    // Check which index in coordinates is the direction and value. Then set them accordingly.
    if (coordinates[1].toLowerCase() === "w" || coordinates[1].toLowerCase() === "e") {
      [lon, lonDir] = [coordinates[0], coordinates[1]];
      [lat, latDir] = [coordinates[2], coordinates[3]];
    } else {
      [lat, latDir] = [coordinates[0], coordinates[1]];
      [lon, lonDir] = [coordinates[2], coordinates[3]];
    }

    // Check the value of the direction and convert the value (multiply by -1 or not) depending on the direction.
    const latitude = (parseFloat(lat) < 0) ? parseFloat(lat) : parseFloat(lat) * (latDir.toUpperCase() === 'S' ? -1 : 1);
    const longitude = (parseFloat(lon) < 0) ? parseFloat(lon) : parseFloat(lon) * (lonDir.toUpperCase() === 'W' ? -1 : 1);
    const locationName = getLocationName(coordinates);
    pushFeature(latitude, longitude, locationName);
  }
  /**
   * Function for handling a line of input in decimal form without directions. The array length will be either 4 or 5.
   * This function converts the coordinates from degrees and minutes to decimal form, checks if they are within the valid range,
   * and then calls the pushFeature() function to process them.
   * @param {string[]} coordinates - The array of coordinates.
   */
  function decimalFormNoDirections(coordinates) {
    const locationName = getLocationName(coordinates);
    let latitude, longitude;

    if (coordinates.length === 4 || coordinates.length === 5) {
      latitude = convertDMToDecimal(coordinates[0], coordinates[1]);
      longitude = convertDMToDecimal(coordinates[2], coordinates[3]);
    } else {
      latitude = convertDMSToDecimal(coordinates[0], coordinates[1], coordinates[2]);
      longitude = convertDMSToDecimal(coordinates[3], coordinates[4], coordinates[5]);
    }

    pushFeature(latitude, longitude, locationName);
  }

  /**
   * Function for handling a line of input that is in decimal form (both DM and DMS). Depending on the length of the coordinates array,
   * we can determine whether it is in DM or DMS format. We then check the direction to determine whether it represents the latitude or
   * longitude coordinate set. Based on the format and direction, the corresponding conversion function (convertDMToDecimal or convertDMSToDecimal)
   * is called. The results of these function calls are assigned to the longitude and latitude variables, which are then pushed as a feature.
   * @param {string[]} coordinates - The array of coordinates.
   */
  function decimalForm(coordinates) {
    const locationName = getLocationName(coordinates);
    let latitude, longitude;

    if (coordinates.length === 6 || coordinates.length === 7) {
      if (coordinates[2].toLowerCase() === 'w' || coordinates[2].toLowerCase() === 'e') {
        const [lonDir, latDir] = [coordinates[2], coordinates[5]];
        const lonDecimal = convertDMToDecimal(coordinates[0], coordinates[1]);
        const latDecimal = convertDMToDecimal(coordinates[3], coordinates[4]);

        longitude = (lonDecimal < 0) ? lonDecimal : lonDecimal * (lonDir.toUpperCase() === 'W' ? -1 : 1);
        latitude = (latDecimal < 0) ? latDecimal : latDecimal * (latDir.toUpperCase() === 'S' ? -1 : 1);
      } else {
        const [latDir, lonDir] = [coordinates[2], coordinates[5]];
        const latDecimal = convertDMToDecimal(coordinates[0], coordinates[1]);
        const lonDecimal = convertDMToDecimal(coordinates[3], coordinates[4]);

        latitude = (latDecimal < 0) ? latDecimal : latDecimal * (latDir.toUpperCase() === 'S' ? -1 : 1);
        longitude = (lonDecimal < 0) ? lonDecimal : lonDecimal * (lonDir.toUpperCase() === 'W' ? -1 : 1);
      }
    } else {
      if (coordinates[3].toLowerCase() === 'w' || coordinates[3].toLowerCase() === 'e') {
        const [lonDir, latDir] = [coordinates[3], coordinates[7]];
        const lonDecimal = convertDMSToDecimal(coordinates[0], coordinates[1], coordinates[2]);
        const latDecimal = convertDMSToDecimal(coordinates[4], coordinates[5], coordinates[6]);

        longitude = (lonDecimal < 0) ? lonDecimal : lonDecimal * (lonDir.toUpperCase() === 'W' ? -1 : 1);
        latitude = (latDecimal < 0) ? latDecimal : latDecimal * (latDir.toUpperCase() === 'S' ? -1 : 1);
      } else {
        const [latDir, lonDir] = [coordinates[3], coordinates[7]];
        const latDecimal = convertDMSToDecimal(coordinates[0], coordinates[1], coordinates[2]);
        const lonDecimal = convertDMSToDecimal(coordinates[4], coordinates[5], coordinates[6]);

        latitude = (latDecimal < 0) ? latDecimal : latDecimal * (latDir.toUpperCase() === 'S' ? -1 : 1);
        longitude = (lonDecimal < 0) ? lonDecimal : lonDecimal * (lonDir.toUpperCase() === 'W' ? -1 : 1);
      }
    }

    pushFeature(latitude, longitude, locationName);
  }

  /**
   * This function converts coordinates in DM format to decimal format. It divides the minutes variable by 60 and then adds it
   * to the value of the degrees input. The result is the decimal degrees.
   * @param {number|string} degrees - The degrees part of the coordinates.
   * @param {number|string} minutes - The minutes part of the coordinates.
   * @returns {number} The converted decimal degrees.
   */
  function convertDMToDecimal(degrees, minutes) {
    const parsedDegrees = parseFloat(degrees);
    const parsedMinutes = parseFloat(minutes);

    let decimalDegrees;
    if (parsedDegrees < 0) {
      decimalDegrees = parsedDegrees - (parsedMinutes / 60);
    } else {
      decimalDegrees = parsedDegrees + (parsedMinutes / 60);
    }

    return decimalDegrees;
  }

  /**
   * This function converts coordinates in DMS format to decimal format. It divides the seconds variable by 3600, the minutes
   * variable by 60, and adds both to the degrees variable. The result is the decimal degrees.
   * @param {number|string} degrees - The degrees part of the coordinates.
   * @param {number|string} minutes - The minutes part of the coordinates.
   * @param {number|string} seconds - The seconds part of the coordinates.
   * @returns {number} The converted decimal degrees.
   */
  function convertDMSToDecimal(degrees, minutes, seconds) {
    const parsedDegrees = parseFloat(degrees);
    const parsedMinutes = parseFloat(minutes);
    const parsedSeconds = parseFloat(seconds);

    let decimalDegrees;
    if (parsedDegrees < 0) {
      decimalDegrees = parsedDegrees - (parsedMinutes / 60) - (parsedSeconds / 3600);
    } else {
      decimalDegrees = parsedDegrees + (parsedMinutes / 60) + (parsedSeconds / 3600);
    }

    return decimalDegrees;
  }

  /**
   * This function sets the name variable based on the length of the coordinates array. It extracts the name from the array
   * if it exists at the specific index.
   * @param {string[]} coordinates - The array of coordinates.
   * @returns {string} The extracted location name.
   */
  function getLocationName(coordinates) {
    let name = "";
    if (coordinates.length === 3) {
      name = coordinates[2];
    } else if (coordinates.length === 5) {
      name = coordinates[4];
    } else if (coordinates.length === 7) {
      name = coordinates[6];
    } else if (coordinates.length === 9) {
      name = coordinates[8];
    }
    return name;
  }

  /**
   * This function is used to push a feature to the feature collection. It creates a GeoJSON Point feature with the latitude,
   * longitude, and location name. If the location name is empty, it sets the property name of the feature to "default". The
   * coordinates are passed in the order of longitude and then latitude, conforming to the GeoJSON standard.
   * @param {number} latitude - The latitude coordinate.
   * @param {number} longitude - The longitude coordinate.
   * @param {string} locationName - The name of the location.
   */
  function pushFeature(latitude, longitude, locationName) {
    // Create GeoJSON Point feature
    const feature = {
      type: 'Feature',
      properties: {
        name: locationName !== "" ? locationName : "default" // Set a name for the feature if needed
      },
      geometry: {
        type: 'Point',
        coordinates: [longitude, latitude] // Note the order: [longitude, latitude]
      }
    };
        // Add the feature to the feature collection
    featureCollection.features.push(feature);
    console.error(`Successfully processed: ${line} \n`);
  }
}