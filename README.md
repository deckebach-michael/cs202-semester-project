# CS202 SEMESTER PROJECT

This is the Basic Challenge on CS 202 Semester project 

**Contributors**

Moreno Moises, Michael Deckebach, Thomas Turngren

**Team Contributions**

Moises Moreno, Processor

Michael Deckebach, File I/O, UI, and some Processing

Thomas Turngren, File I/O and Documentation (UML Diagram, Doxygen)

![diagram](https://user-images.githubusercontent.com/89604178/145154961-c9591cd5-f1df-4907-a598-78251cb7e342.png)

**Functionality**

File I/O and UI are working according to the project description. The required processing is not functional but code has been prototyped. 

**Challenges**

1. File I/O - We encountered some difficulty figuring out how to handle 8-bit vs 16-bit files. Ultimately, the read() and write() functions
use some brute force switch functionality to get the job done, but we recognize there is redundancy in there and this probably is not the best
design. There is probably a way to consider using templates that would be better.

2. Moises got sick the last week before the project was due. This left us scrambling a bit to try and help out with the processing components, 
and is why they are incomplete. Feel better Moises!

3. Currently, the processing functionality for Gain and Normalization are not working properly, and we haven't had enough time to debug. We suspect
it has something to do with scope and that the functions are not modifying the underlying instance of the Wav class, but we would need more time to
figure this out.

4. Figuring out how to set up and output Doxygen to the correct file folder took time, but reading the docs helped and Thomas was able to 
figure this one out for us.

**Instructions**

Run ```Make WavModifier``` to generate the executable.

**Documentation**

[Click here for full documentation](https://deckebach-michael.github.io/cs202-semester-project/)
