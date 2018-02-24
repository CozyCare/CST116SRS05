# CST116SRS05
Date List


Class ID:  Ekans

SRS ID: CST116SRS05  

Unresolved Issues:  


Notes:  
The program accepts any two dates in any order as long they are in (YYYY-MM-DD) format. 
However I think I might be running into memory issues at times:
	- Sometimes it won't rearrange the dates properly
	- Will cause DateList to not properly execute
The fix for this solution that I found is to clean the solution and do a batch build again before executing the program:
	- Inputted dates are then rearranged accordingly and executes the program successfully. 

---

Purpose:  

Learn to use looping statements.  
Practice using cin and cout formatting.  
Practice using conditionals.  
Learn ISO date formats.  


Instructions:  

Create a project named "DateList" that displays all dates between 2 dates.  

The range of the input year will be between the years 1901 and 2099.  

Read in two dates from the user in ISO format (YYYY-MM-DD) separated by whitespace.  

The dates may come in any order. Print each date between the two. Include the oldest date and exclude the newest date.  

The program should not prompt the user for the two dates. Simply accept the dates seperated by whitespace.  

Don’t forget the Class Policy rules, including using const.  

Zero fill your dates to meet ISO format specification on the output. (see std::setfill manipulator).  
