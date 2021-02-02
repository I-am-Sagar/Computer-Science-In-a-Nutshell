# How do we compile and run a C program?

Below are the steps we use on an Ubuntu machine with gcc compiler.

We first create a C program using an editor and save the file as filename.c
<pre> $ vi filename.c </pre> </br>

Then compile it using below command.
 <pre> $ gcc –Wall filename.c –o filename </pre> </br>
The option -Wall enables all compiler’s warning messages. This option is recommended to generate better code.
The option -o is used to specify output file name. If we do not use this option, then an output file with name a.out is generated.

After compilation executable is generated and we run the generated executable using below command.
<pre> $ ./filename </pre> </br>

Compiler converts a C program into an executable. There are four phases for a C program to become an executable: Pre-processing, 
Compilation, Assembly and Linking.

By executing below command, We get the all intermediate files in the current directory along with the executable.
<pre> $gcc –Wall –save-temps filename.c –o filename </pre> </br>

This is the first phase through which source code is passed. This phase include: Removal of Comments, Expansion of Macros and Expansion of the included files.
The preprocessed output is stored in the filename.i.

The next step is to compile filename.i and produce an; intermediate compiled output file filename.s. This file is in assembly level instructions.

In the assembly phase the filename.s is taken as input and turned into filename.o by assembler. This file contain machine level instructions.
At this phase, only existing code is converted into machine language, the function calls like printf() are not resolved.

Linking is the final phase in which all the linking of function calls with their definitions are done. 
Linker knows where all these functions are implemented. Linker does some extra work also, it adds some extra code to our program 
which is required when the program starts and ends. For example, there is a code which is required for setting up the environment 
like passing command line arguments. This task can be easily verified by using 

<pre> $size filename.o </pre> 
and 
<pre> $size filename </pre> 
Through these commands, we know that how output file increases from an object file to an executable file. 
This is because of the extra code that linker adds with our program.
