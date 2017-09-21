FILES=main.cpp Accounts.cpp Account.cpp TransactionAccount.cpp LongTermSavingsAccount.cpp SavingsAccount.cpp  Customer.cpp Bank.cpp TestApp.cpp Menu.cpp MenuItem.cpp Functions.cpp
FLAGS=-std=c++14 -Wall -pedantic
OUTFILE=main

all:
	g++ ${FILES} -o ${OUTFILE} ${FLAGS};

run:
	./${OUTFILE};
	
memoryCheck:
	valgrind --track-origins=yes ./${OUTFILE};

clean:
	rm *.knt main;
