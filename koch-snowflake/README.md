# Interactive Koch Snowflake

## **Project Objective**
The main objective of this assignment is to create an interactive program with a user interface that draws and displays a Koch's snowflake of a given order. The UI should also implement a responsive design.

---

## **Running the Program**
This program can be run locally via the index.html file which contains the JavaScript script internally and has linked the koch.css file externally.

Once the program is up and running you are able to interact freely with the UI!

Now that the program is running, you will see in front of you a triangle that has been drawn on the canvas element via some JavaScript code. This triangle is Koch's Snowflake at order 1. As you move the slider up and down, you will see that this will increase and decrease the order of the snowflake (respectively) and in turn, the graphical output will also change to match the order on the slider.

**Responsive Design:**
The program has also been implemented to have a responsive design, meaning that you are able to resize the window freely and have the graphical output resize itself in regards to the window size. 

---

## **Algorithm Explanation**

**The X, Y Calculations:**

the `drawKoch` fucntion is called 3 times in the `drawPage` function for each side of the base order triangle

In the `drawKoch` function, we initially calculate the distance between two points (in our case, the two points making up each side of the triangle). With this, we can use a rewritten Pythagoras' theorem to calculate the distance between these two points (reference: [khan academy](https://www.khanacademy.org/math/geometry/hs-geo-analytic-geometry/hs-geo-distance-and-midpoints/v/distance-formula#:~:text=Learn%20how%20to%20find%20the,distance%20between%20any%20two%20points.)).

The calculation for unit (distance / 3) is essentially the calculation of the length for each side of the "new" equilateral triangle that is being drawn.

Math.atan2() function in JavaScript measures the counter clockwise angle in radians between the positive x-axis and the point (x, y). So when we input the values dy and dx (since this function requires the the y coordinate before the x coordinate) this function returns the clockwise angle in radians between the positive x-axis and the point (dx, dy).

From here, we define the new coordinates for the new equilateral triangle. To get the base points (p1 and p3), we add the difference values (dx and dy) divided by 3 onto the original x and y values.

            let p1 = {
                x: a.x + dx / 3,
                y: a.y + dy / 3
            }
            let p3 = {
                x: b.x - dx / 3,
                y: b.y - dy / 3
            }

 However, when it comes to p2 we have to do a few calculations.

    x: p1.x + Math.cos(angle - Math.PI / 3) * unit,
    y: p1.y + Math.sin(angle - Math.PI / 3) * unit

In order to understand this better, we have to break up the calculations for both the x and y coordinates.

In the calculation for the new x coordinate, we need to add the correct number of "units" onto the original x coordinate. To calculate this, we utilise the angle (in radians) which we calculated before. In order to get the correct angle of new point in relation to the existing side of the equilateral triangle, we minus Math.Pi / 3 (which is the equivalent to 60 degrees) off of the previously calculated angle. This is because the original equilateral triangle has an angle of 60 degrees in each corner and this has allowed us to 'align' the new point in relation to the existing side rather than the x axis. Now using SohCahToa, we use the cosine of the new angle that we just calculated multiplied by the "hypotenuse" which is just the previously calculated unit since all sides of the new triangle are equal. This will give us the correct horizontal length to add onto our existing x coordinate to give us x coordinate of the new p2.

To then calculate the y coordinate of the new point, the same calculations as above occurs except with the sine of the new angle multiplied by the unit due to now calculating the vertical length rather than the horizontal (a different side of the new equilateral triangle).




**The Recursion:**

Continuing on from here, the overall function of `drawKoch` is recursive therefore, we require a base case. In this program, the base case is if the order (order) is less than 2 which then calls upon the `drawTriangle()` function to draw a triangle for order 1. However, if the order is greater than 2, we will recursively call the `drawKoch` function on each existing side while decrementing the order upon each recursive call. 

Each call of `drawKoch()` will draw 4 new lines on each side of the previously drawn line. 

---

## **Other Functions**

Within this program, there are also other functions which provide further functionality. The `checkSilder()` function is used to get the input level on the slider and pass the value into the 'level' variable which is used to determine the order of the Koch's Snowflake that is going to be drawn. Each time the level slider changes levels, the canvas is cleared and the `drawPage()` is called.

The `drawPage()` function is responsible for setting the canvas size and translating the context to make sure the drawings are created in the centre of the page. From here, the `drawKoch` function is called 3 times for each side of the base order triangle with.


