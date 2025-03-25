1. Start the Program:
Compile and run the program. Upon launching, the program displays the "Norco Bank" menu.

2. Menu Options:
The menu provides four choices:

- 1. Deposit: Add funds to the account.

- 2. Withdraw: Remove funds from the account.

- 3. Check Balance: View the current account balance.

- 4. Close Account and Exit: Close the account and terminate the program.

3. Making a Choice:
Enter the number corresponding to your desired operation. If you enter invalid input (non-numeric or an unrecognized number), the program prompts you to try again.

4. Deposit Operation:

If you choose 1 (Deposit), you will be asked to enter the deposit amount.

Enter the amount.

Note: If you enter a negative amount, a NegativeDepositException will be thrown, and an error message will be displayed.

5. Withdrawal Operation:

If you choose 2 (Withdraw), you will be prompted to enter the withdrawal amount.

Enter the amount.

Note: If you attempt to withdraw more than the available balance, an OverdrawException will be thrown, and an error message will be displayed.

6. Checking the Balance:

If you choose 3 (Check Balance), the program will display the current account balance.

7. Closing the Account and Exiting:

Choosing 4 (Close Account and Exit) will close the account.

Once the account is closed, any further deposit or withdrawal attempts will result in an InvalidAccountOperationException.

The program then exits after displaying a confirmation message.

8. Error Handling:

The program uses exception handling to catch errors for negative deposits, overdraw attempts, and operations on a closed account.

Any caught errors are displayed as messages to help you correct the input or understand the issue.