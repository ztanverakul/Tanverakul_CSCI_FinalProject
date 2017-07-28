# Tanverakul_CSCI_FinalProject
Project Summary:
My final project will be a program that takes all the starting nfl quarterbacks and lists them by quarterback rating, number of touchdown passes and number of interceptions.
I will use a linked list data structure to organize all my data.
It will then create three different classes of qb: dumpster-fire, mediocre, and elite. 
Im going to use a graph to make connections between them based off of those three criteria listed above.
Then the program will then post a random profile of a quarterback and the user has to guess.
The program will then ask the user for a quarterback that can be beaten by the best quarterback in each respective class. If the path between them is long enough, it will output that that quarterback can be beaten.


How to run:
Open up your virtual machine. Then open up codeblocks. Download the folder called "Final_Project_Data_Structures_Zach_Tanverakul" and open up the file "Final_Project_Data_Structures_Zach_Tanverakul.cbp". To run the program build and compile the project. When you run it a menu will pop up with several choices. Press 1 first and it will prompt you for a class of quarterback. When you do that it will post a graph that was created using a linked list of the specific class of quarterback. You can then choose to display the linked list, play the game, or find the shortest path to either victory or a loss. When you press 3 and play the game, it will show you the touchdowns and interceptions thrown of that quarterback for 2016. If you guess right, "You're Elite!" otherwise it will say that you are garbage and post the name of the correct quarterback. You can keep playing by pressing 3 as you wish. Also you have to post the quarterbacks name with capital first lettes. For number 4 it will ask you for a quarterback in that specific class that the best qb in that class can beat. It will then calculate the shortest path and depending on how short it is then it will output whether or not that quarterback was beaten. Finally when you press 5, the program will delete the linked list and the graph and exit out. 

Dependencies:
My program did not rely on a third party library that you need to download. Just download the project to your virtual machine and run the cbp file in codeblocks.

System Requirements:
This program requires a Linux virtual machine that has codeblocks installed on it. 

Zachary Tanverakul

Open Issues/Bugs:
I could not figure out how to delete the graph every single time that I built a new one. I also had problems with capitalization. If you could figure out how to reset the graph every time I build a new one without breaking my program that would be great.
