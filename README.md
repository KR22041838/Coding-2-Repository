# Coding-2-Repository

This provides README explainations for each project. 



1. OpenFW HW2 
- Panopto Video called: Coding2 Week2HW

This project required remaking a homework from Coding 1 in C++ in Visual Studios using OpenFrameworks.

This project creates an animated sequence using the ‘void ofApp::draw’ loop. Inside the draw loop, the colour and movement of circular shapes are dictated by sin, tan and time functions. The colour of the circles oscillates through sine waves and the circular movement follows a tan wave. 





2. OpenFrameworks Arduino Projects
- Panopto Video called: OpenFW Arduino Project

This project connects Arduino Communication with Openframeworks. 

When the Output Display first appears it is green with the text ‘click to change background colour’. When the computer mouse is left clicked the background changes to red. As the mouse is clicked multiple times it alternates between the two colours with the corresponding ‘RED’ of ‘GREEN’ text displayed in the window.

The Arduino Code contains an ‘if statement’ were if the green LED is on, the Red LED is turned off, and if the green LED is turned off the red LED is turned on. 

The Ardunio receives data from OFworks in the form of a char unByte = 1, this tells the Arduino the mouse has been clicked, and tells the the green LED to turn to its opposite state on/off. This then toggles the if statement to determine the state of the red LED. 

There is ‘if else statement’ which writes back to OFworks using a char string. If the state of the green LED = false write ‘RED’, else write ‘GREEN’ to the display screen.





3. JupyterNotebook Python Challenge 

For the PythonChallege style challenge I made a riddle where the user has to work out the new position of ‘m’ within the alphabet using the numerical value of c^2. They then need to create code to map the shift in positional value within  the alphabet and find the new positions of each letter. 

Once they have done this they need to map the new alphabet arrangement to the website address under ‘Cats Know Best’. When put the answer into the search bar it will reward them with a cat meme. 

#To work out c^2, take the numeral position of c in the alphabet and square it:
# c = the 3rd position in alphabet
# 3^2 = 9
# The 9th letter in the alphabet = i 
# There fore m = i





4. JupyterNotebook TensorFlow

In this project I experimented with image processing techniques. 

The colourful dogs were created using Matplotlib colour maps using ‘spring' ‘nipy_spectral’.

Line 8 was an attempt to get to grips with image transforming using Matplotlib mapping, the code worked, however I struggled to apply it to the dog photos so I tried I different approach. 

I successfully transformed the images from line 10 using spicy numpy where the image was rotated, flipped and had a gaussian_filter applied to it.
