# Diego G Esquivel and Eric D Smith

# CryptoTradingBot
Project Description:
A bot to help you trade Cryptocurrency. This application applies math to predict wether a Cryptocurrency should be help or traded on a day. This bought implements object oriented principles and multiple inheritance to accomplish this. It was a row-epsilon-from function too. The intended audience for this is for anyone looking to make a lot of money with Cryptocurrency. This is a large audience that spans the continental US. 

Classes :

class Front_End - A class of a front-end object that will handle the user interface for the application.

class Middle_Ware - Inherits from class Matrix. A class of a middle-ware object that will handle data movement and manipulation for 
    the application.
class Matrix - A matrix class used to apply math to predict our most likely outcome.
    variables :
        private double[][] matrix - a 2d array variable we  will use to represent a matrix.

        Constructor - A default constructor for the matrix.
        setMatrix - function to set a single cell in a matrix object.
        setDiagonal - function to set a single diagonal in a matrix object.
        setConstantTerms - function to set constant terms for the matrix to use linear algebra.
        private void rref - function to transform a matrix object to its row-reduced epsilon form.
        String to_Print - function to print the contents of the matrix object


class Back_End - A class of a back-end object that will handle data using CRUD practices.

<img align="left" alt="Visual Studio Code" width="26px" src="https://raw.githubusercontent.com/Diego-Esquivel/CryptoTradingBot/main/indexwebframe.png" />