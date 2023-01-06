#Brian Jhon
#1131229
#HW.5 PS.1
#This program will calculate the loan amount for a car


class Loan:

    def __init__(self, intRate = 0.0, years = 0, amount = 0.0, name = ""):
    '''Default constructor'''
        self.__intRate = intRate
        self.__years = years
        self.__amount = amount
        self.__name = name


    def getInterestRate(self):
        '''Gets the interest rate'''
        return self.__intRate


    def getYears(self):
        '''Gets the number of years'''
        return self.__years


    def getAmount(self):
        '''Gets the loan amount'''
        return self.__amount


    def getName(self):
        '''Gets the Name of the borrower'''
        return self.__name


    def setInterestRate(self,intRate):
        '''Sets the interest rate'''
        self.__intRate = intRate


    def setYears(self,years):
        '''Sets the number of years'''
        self.__years = years


    def setAmount(self,amount):
        '''Sets the loan amount'''
        self.__amount = amount


    def setName(self,name):
        '''Sets the name of the borrower'''
        self.__name = name


    def getMonthlyPayment(self):
        '''Calculates the monthly payment for the car loan'''
        monthlyIntRate = self.__intRate/1200
        return self.__amount * monthlyIntRate / (1-(1/(1+monthlyIntRate)**(self.__years*12)))


    def getTotalPayment(self):
        '''Calculates the total payment for the car loan'''
        return self.getMonthlyPayment()*self.__years*12


def main():

    #intialize object
    myCarLoan = Loan()

    #Get the Input
    myCarLoan.setInterestRate(float(input("Enter yearly interest rate: ")))
    myCarLoan.setYears(int(input("Enter number of years as an integer: ")))
    myCarLoan.setAmount(float(input("Enter loan amount: ")))
    myCarLoan.setName(input("Enter a borrower's name: "))

    #Display the output
    print("The loan is for ", myCarLoan.getName())
    print("The monthly payment is ", format(myCarLoan.getMonthlyPayment(), ',.2f'))
    print("The total payment is ", format(myCarLoan.getTotalPayment(), ',.2f'))

    #Ask user to change loan amount and diplsy new payment
    KOG = input("\nDo you want to change the loan amount? Y for yes or enter to quit ")
    while KOG == "y" or KOG == "Y":
        myCarLoan.setAmount(float(input("Enter new loan amount: ")))    
        print("The loan is for ", myCarLoan.getName())
        print("The monthly payment is ", format(myCarLoan.getMonthlyPayment(), ',.2f'))
        print("The total payment is ", format(myCarLoan.getTotalPayment(), ',.2f'))  
        KOG = input("\nDo you want to change the loan amount? Y for yes or enter to quit ")

if __name__ == "__main__":
    main()

##Test 1
##Enter yearly interest rate: 2.5
##Enter number of years as an integer: 5
##Enter loan amount: 1000.00
##Enter a borrower's name: John Jones
##The loan is for  John Jones
##The monthly payment is  17.75
##The total payment is  1,064.84
##
##Do you want to change the loan amount? Y for yes or enter to quit y
##Enter new loan amount: 5000
##The loan is for  John Jones
##The monthly payment is  88.74
##The total payment is  5,324.21
##
##Do you want to change the loan amount? Y for yes or enter to quit 

##Test 2
##Enter yearly interest rate: 1.92
##Enter number of years as an integer: 2
##Enter loan amount: 2150.00
##Enter a borrower's name: Hugh Colt
##The loan is for  Hugh Colt
##The monthly payment is  91.39
##The total payment is  2,193.26
##
##Do you want to change the loan amount? Y for yes or enter to quit Y
##Enter new loan amount: 8250
##The loan is for  Hugh Colt
##The monthly payment is  350.67
##The total payment is  8,416.01
##
##Do you want to change the loan amount? Y for yes or enter to quit 

##Test 3
##Enter yearly interest rate: 4.2
##Enter number of years as an integer: 20
##Enter loan amount: 21750
##Enter a borrower's name: Peter Jackson
##The loan is for  Peter Jackson
##The monthly payment is  134.10
##The total payment is  32,184.99
##
##Do you want to change the loan amount? Y for yes or enter to quit 

##Test 4
##Enter yearly interest rate: 3.78
##Enter number of years as an integer: 15
##Enter loan amount: 28600
##Enter a borrower's name: Gary Buss
##The loan is for  Gary Buss
##The monthly payment is  208.41
##The total payment is  37,514.08
##
##Do you want to change the loan amount? Y for yes or enter to quit Y
##Enter new loan amount: 30000
##The loan is for  Gary Buss
##The monthly payment is  218.61
##The total payment is  39,350.43
##
##Do you want to change the loan amount? Y for yes or enter to quit 

##Test 5
##Enter yearly interest rate: 2.8
##Enter number of years as an integer: 20
##Enter loan amount: 26700
##Enter a borrower's name: Brian Jhon
##The loan is for  Brian Jhon
##The monthly payment is  145.42
##The total payment is  34,900.48
##
##Do you want to change the loan amount? Y for yes or enter to quit y
##Enter new loan amount: 24300
##The loan is for  Brian Jhon
##The monthly payment is  132.35
##The total payment is  31,763.36
##
##Do you want to change the loan amount? Y for yes or enter to quit y
##Enter new loan amount: 31478
##The loan is for  Brian Jhon
##The monthly payment is  171.44
##The total payment is  41,145.96
##
##Do you want to change the loan amount? Y for yes or enter to quit 

