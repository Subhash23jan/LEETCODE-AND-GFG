// Create a class Account that stores customer name, account number and type of account. From this
// derive the classes Cur-acct and Sav-acct to make them more specific to their requirements. Include the
// necessary methods in order to achieve the following tasks.
// a) Accept deposit from customer and update the balance.
// b) Display the balance.
// c) Compute and deposit interest.
// d) Permit withdrawal and update the balance.
// Check for the minimum balance, impose penalty if necessary and update the balance
import java.util.Scanner;
class account{
    Scanner sc=new Scanner(System.in);
    String name;
    int acct_no;
    int balance,deposit;
    // String type;
    
    void deposit()
    {
         System.out.println("Enter amount for deposit\n");
         int amount=sc.nextInt();
         balance+=amount;
         System.out.println("deposite is successfull\n do you want to check your balance");
         System.out.println("1.YES\n2.NO");
         int choice=sc.nextInt();
         check_balance();
          
    }
    void details()
    {
        System.out.println("Name: "+name);
        System.out.println("account_no: "+acct_no);
        System.out.println("balance :"+balance);
    }
    void check_balance()
    {
        System.out.println("Balance is "+balance);
    }
}
class savings extends account
{
    int intrest;
    savings(String n,int a,int d)
    {
        name=n;
        acct_no=a;
        deposit=d;
        balance=deposit;
    }
    void details()
    {
        System.out.println("Account_type: Savings");
        super.details();
    }
    void withdrawal()
    {
        System.out.println("Enter amount for withdrawal\n");
        int amount=sc.nextInt();
        if(balance<amount)
        System.out.println("You can withdraw the amount less than "+balance);
        else
        {
            balance=balance-amount;
            System.out.println("withdrawal is successfull..!!!!!!! \nparty leda "+name);
            System.out.println("\nDo you want check your balance\n");
            System.out.println("1.YES\n2.NO");
            int choice=sc.nextInt();
            if(choice==1)
            check_balance();
            return;
        }
    }
}
class current extends account
{
    int cheque_no;
    current(String n,int a,int d)
    {
        name=n;
        acct_no=a;
        deposit=d;
        balance=deposit;
    }
    void details()
    {
        System.out.println("Account_type: Current");
        super.details();
    }
    void withdrawal()
    {
        System.out.println("Do you have cheque");
        System.out.println("1.YES\n2.NO");
        int choice1=sc.nextInt();
        if(choice1==1)
        {
           System.out.println("enter check number");
           cheque_no=sc.nextInt();
        }
        System.out.println("Enter amount for withdrawal\n");
        int amount=sc.nextInt();
        if(balance<amount)
        System.out.println("You can withdraw the amount less than "+balance);
        else
        {
            balance=balance-amount;
            System.out.println("withdrawal is successfull..!!!!!!! \nparty leda "+name);
            System.out.println("Do you want check your balance\n");
            System.out.println("1.YES\n2.NO");
           int choice=sc.nextInt();
           if(choice==1)
           check_balance();
            return;
        }
    }
}
class Main
{
    public static void  main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
       String name;
       int acct_no;
       int deposit;
       int choice;
       System.out.println("Enter your name\n");
       name=sc.nextLine();
       System.out.println("Type of account\n");
       System.out.println("1.current\n2.Savings");
       choice=sc.nextInt();
       if(choice==2)
       {
           System.out.println("Enter amount for deposition and minimum ampunt 1000 rupees\n");
           deposit=sc.nextInt();
           System.out.println("Create account number \n");
           acct_no=sc.nextInt();
           savings s=new savings(name,acct_no,deposit);
           while(true)
           {
                System.out.println("\nEnter your choice\n1.depost\n2.withdrawal\n3.Details of account\n4.exit\n");
                int ch=sc.nextInt();
                if(ch==1)
                s.deposit();
                else if(ch==2)
                {
                    s.withdrawal();
                }else if(ch==3)
                {
                    s.details();
                }
                else if(ch==4)
                 break;
                else
                {
                    System.out.println("Invalid Choice..!!!!!\n");
                }
           }
       }
       else
       {
            System.out.println("Enter amount for deposition\n");
           deposit=sc.nextInt();
           System.out.println("Create account number \n");
           acct_no=sc.nextInt();
           current c=new current(name,acct_no,deposit);
           while(true)
           {
                System.out.println("Enter your choice\n1.depost\n2.withdrawal\n3.Details of account\n4.exit");
                int ch=sc.nextInt();
                if(ch==1)
                c.deposit();
                else if(ch==2)
                {
                    c.withdrawal();
                }else if(ch==3)
                {
                    c.details();
                }
                else if(ch==4)
                 break;
                else
                {
                    System.out.println("Invalid Choice..!!!!!\n");
                }
           }
       }
    }
}