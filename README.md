# Diego G Esquivel and Eric D Smith

# CryptoTradingBot
Project Description:
A bot to help you trade Cryptocurrency. This application applies math to predict wether a Cryptocurrency should be help or traded on a day. This bought implements object oriented principles and multiple inheritance to accomplish this. It was a row-epsilon-from function too. The intended audience for this is for anyone looking to make a lot of money with Cryptocurrency. This is a large audience that spans the continental US. 

Classes :

class frontend - A class of a front-end object that will handle the user interface for the application.

class middleware - Inherits from class Matrix. A class of a middle-ware object that will handle data movement and manipulation for 
    the application.

class backend - A class of a back-end object that will handle data for the application.

class server - A class of a server object that will act as our data movement tool.

class CryptoBotDataObject - A class of a data object that will act as our storage for data(s) that we will work with for the application.

class Matrix - A matrix class used to apply math to predict our most likely outcome.

    variables :
        private double[][] matrix - a 2d array variable we  will use to represent a matrix.

        Constructor - A default constructor for the matrix.
        setMatrix - function to set a single cell in a matrix object.
        setDiagonal - function to set a single diagonal in a matrix object.
        setConstantTerms - function to set constant terms for the matrix to use linear algebra.
        private void rref - function to transform a matrix object to its row-reduced epsilon form.
        String to_Print - function to print the contents of the matrix object

<img align="left" width="600" height="600" alt="Visual Studio Code" src="https://raw.githubusercontent.com/Diego-Esquivel/CryptoTradingBot/main/index.svg" />

## Update Data
This is the update data page. The update data page is operated from the computer CLI.
	<img align="left" width="600" height="600" alt="Visual Studio Code" src="https://raw.githubusercontent.com/Diego-Esquivel/CryptoTradingBot/main/updateFilescli.jpg" />


## Request Screen
This is the page that requests user input. When user input happens the page sends an HTTP request to get coin results.
	<img align="left" width="600" height="600" alt="Visual Studio Code" src="https://raw.githubusercontent.com/Diego-Esquivel/CryptoTradingBot/main/requestscreenhtml.jpg" />


## Bot Response Results
These two pages are results of the program. After a user inputs input to the request screen the program will load two new pages. Page #1 is a results page which looks like the original page but has a message that suggests what a client should do with their coin on a given day.
The second page is the new page a user should input more input for more results. These two pictures are only results pages.
	<img align="left" width="600" height="600" alt="Visual Studio Code" src="https://raw.githubusercontent.com/Diego-Esquivel/CryptoTradingBot/main/botresults1.jpg" />
	<img align="left" width="600" height="600" alt="Visual Studio Code" src="https://raw.githubusercontent.com/Diego-Esquivel/CryptoTradingBot/main/botresults2.jpg" />

## Program idle page
This is what the cli looks like in between client requests.
	<img align="left" width="600" height="600" alt="Visual Studio Code" src="https://raw.githubusercontent.com/Diego-Esquivel/CryptoTradingBot/main/cliupdateswhileidle.jpg" />


### A link to the repository:
https://www.github.com/Diego-Esquivel/CryptoTradingBot