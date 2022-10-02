//created by Ahkar Min Htut
//Library System
#include <iostream>
using namespace std;

class Library
{
public:
  string name[100];
  string phone[100];
  string password[100];
  string bookName[100];
  string author[100];
  string borrowBook[100];
  string borrowName;
  int bookCount[100];
  int bookPrice[100];
  int amount[100];
  int key = 0;
  int id = 0;
  int bookIndex = 0;
  int bookKey = 0;
  int listKey = 0;
  int storeBorrowId[100];
  int borrowDay[100];

    Library ()
  {
    cout << "Welcome to our library." << endl;
  }

  int welcome ();
  int create ();
  int showAll ();
  int login ();
  int myInfo ();
  int addBook ();
  int showBooks ();
  int borrow ();
  int menu ();
  int recharge ();
  int borrowList ();
  int returnBook ();
  int borrowCheck ();
  int allBorrowList ();

};

int
Library::welcome ()
{
  int choice = 0;
  while (true)
    {
      cout << "Press 1 to create member card." << endl;
      cout << "Press 2 to login with member card." << endl;
      cout << "Press 3 to view all data." << endl;
      cout << "Press 4 to add book." << endl;
      cout << "Press 5 to view all books" << endl;
      cout << "Press 6 to view all borrowers list" << endl;
      cout << "Press 7 to quit." << endl;
      cout << "> ";
      cin >> choice;
      if (choice == 1)
	{
	  create ();
	}
      else if (choice == 2)
	{
	  int a = login ();
	  if (a == 1)
	    {
	      cout << "Incorrect Credentials!" << endl;
	      login();
	    }
	}
      else if (choice == 3)
	{
	  if (name[0] == "")
	    {
	      cout << "There is no data yet." << endl;
	    }
	  else
	    {
	      showAll ();
	    }
	}
      else if (choice == 4)
	{
	  addBook ();
	}
      else if (choice == 5)
	{
	  showBooks ();
	}
      else if (choice == 6)
	{
      if(borrowBook[0] == ""){
        cout<<"There is no data."<<endl;
      }else{
	  allBorrowList ();
      }
	}
      else if (choice == 7)
	{
	  cout << "BYE BYE" << endl;
	  return 0;
	}
      else
	{
	  cout << "Invalid input!" << endl;
	}
    }
}

int
Library::create ()
{
  int mini = 0;
  string cname;

  cout << "Please enter your name : ";
  cin >> cname;
  for (int i = 0; i < key; i++)
    {
      if (cname == name[i])
	{
	  cout << "Name already exists.Please use another name." << endl;
	  create ();
	}
    }
  name[key] = cname;
  cout << "Please enter your password : ";
  cin >> password[key];
  cout << "Please enter your phone number : ";
  cin >> phone[key];
  cout << "You have to recharge money in member card." << endl;
  cout << "Minimum recharge is 3000 and maximum is 100000." << endl;
  cout << "Please enter amount to recharge : ";
  cin >> mini;
  if (mini < 3000)
    {
      cout << "Minimum recharge amount is 3000." << endl;
      create ();
    }
  else if (mini > 100000)
    {
      cout << "Maximum recharge amount is 100000." << endl;
      create ();
    }
  else
    {
      amount[key] = mini;
    }
  key++;
  cout << "Successfully created member card." << endl;
  login ();
}

int
Library::login ()
{
  string lname;
  string lpassword;
  cout << "Please enter name to login : ";
  cin >> lname;
  cout << "Please enter password to login : ";
  cin >> lpassword;
  for (int i = 0; i < key; i++)
    {
      if (lname == name[i] && lpassword == password[i])
	{
	  id = i;
	  cout << "Login Success" << endl;
	  myInfo ();
	  menu ();
	}
    }
  return 1;
}

int
Library::showAll ()
{

  cout << "All users are : " << endl;
  for (int i = 0; i < key; i++)
    {
      cout << "User " << i + 1 << endl;
      cout << "  " << "Name : " << name[i] << endl;
      cout << "  " << "Password : " << password[i] << endl;
      cout << "  " << "Phone : " << phone[i] << endl;
      cout << "  " << "Amount : " << amount[i] << endl;
    }

}

int
Library::myInfo ()
{
  cout << "Your Info : " << endl;
  cout << "  " << "Name : " << name[id] << endl;
  cout << "  " << "Password : " << password[id] << endl;
  cout << "  " << "Phone : " << phone[id] << endl;
  cout << "  " << "Amount : " << amount[id] << endl;
}

int
Library::menu ()
{
  int option = 0;
  cout << "Press 1 to borrow book" << endl;
  cout << "Press 2 to recharge" << endl;
  cout << "Press 3 to view your borrow books" << endl;
  cout << "Press 4 to return books" << endl;
  cout << "Press 5 to logout" << endl;
  cin >> option;

  if (option == 1)
    {
      if (bookName[0] == "")
	{
	  cout << "There is no books yet." << endl;
	  menu ();
	}
      else
	{
	  showBooks ();
	  borrow ();
	}
    }
  else if (option == 2)
    {
      recharge ();
      myInfo ();
      menu ();
    }
  else if (option == 3)
    {
      borrowList ();
      menu ();
    }
  else if (option == 4)
    {
      int aChecker = 0;
      for (int y = 0; y < listKey; y++)
	{
	  if (storeBorrowId[y] == id)
	    {
	      aChecker = 1;
	    }
	  else
	    {
	      aChecker = 0;
	    }
	}
      if (aChecker == 0)
	{
	  cout << "You haven't borrowed any book yet." << endl;
	  menu ();
	}
      else
	{
	  returnBook ();
	  aChecker = 0;
	  menu ();
	}
    }
  else if (option == 5)
    {
      welcome ();
    }
  else
    {
      cout << "Invalid Input" << endl;
    }
}

int
Library::borrow ()
{
  int day = 0;
  int check = 0;
  int countCheck = 0;
  cout << "Enter book title you want to borrow : ";
  cin >> borrowName;
  for (int b = 0; b < bookIndex; b++)
    {
      if (borrowName == bookName[b])
	{
	  bookKey = b;
	  cout << "Title : " << bookName[b] << endl;
	  cout << "Author : " << author[b] << endl;
	  cout << "Stock : " << bookCount[b] << endl;
	  cout << "One day rent price : " << bookPrice[b] << endl;
	  check = 1;
	  countCheck = bookCount[b];
	}
    }
  if (check == 0)
    {
      cout << "There is no result." << endl;
      borrow ();
    }
  else
    {
      if (countCheck == 0)
	{
	  cout << "Sorry,not enough stock." << endl;
	  menu ();
	}
      else
	{
	  int bCheck = borrowCheck ();
	  if (bCheck == 1)
	    {
	      cout << "You cannot borrow the same book twice." << endl;
	      menu ();
	    }
	  else
	    {
	      cout << "You cannot borrow books more than one week." << endl;
	      cout << "Enter days you want to borrow : ";
	      cin >> day;
	      if (day > 7)
		{
		  cout << "You cannot borrow books more than one week." <<
		    endl;
		  borrow ();
		}
	      else
		{
		  bookCount[bookKey] = bookCount[bookKey] - 1;
		  if ((day * bookPrice[bookKey]) > amount[id])
		    {
		      cout << "You do not have enough balance." << endl;
		      recharge ();
		    }
		  else
		    {
		      amount[id] = amount[id] - (day * bookPrice[bookKey]);
		      borrowBook[listKey] = bookName[bookKey];
		      storeBorrowId[listKey] = id;
		      borrowDay[listKey] = day;
		      listKey++;
		      cout << day *
			bookPrice[bookKey] << " is reduced from your balance."
			<< endl;
		      myInfo ();
		      borrowList ();
		      menu ();
		    }
		}
	    }
	}
    }
}

int
Library::borrowCheck ()
{
  for (int i = 0; i <= listKey; i++)
    {
      if (borrowName == borrowBook[i] && storeBorrowId[i] == id)
	{
	  return 1;
	}
    }
  return 0;
}

int
Library::borrowList ()
{
  int checker = 0;
  for (int c = 0; c < listKey; c++)
    {
      if (storeBorrowId[c] == id)
	{
	  cout << "You borrowed " << borrowBook[c];
	  cout << " for " << borrowDay[c] << " days." << endl;
	  checker = 1;
	}
      else
	{
	  checker = 0;
	}
    }
  if (checker == 0)
    {
      cout << "You haven't borrowed any book yet." << endl;
      menu ();
    }
}

int
Library::returnBook ()
{
  string rBook;
  borrowList();
  cout << "Enter book title you want to return : ";
  cin >> rBook;
  for (int i = 0; i < bookIndex; i++)
    {
      if (bookName[i] == rBook)
	{
	  bookCount[i] = bookCount[i] + 1;
	}
    }
  for (int x = 0; x < listKey; x++)
    {
      if (borrowBook[x] == rBook && storeBorrowId[x] == id)
	{
	  borrowBook[x] = borrowBook[x + 1];
	  storeBorrowId[x] = storeBorrowId[x + 1];
	  borrowDay[x] = borrowDay[x + 1];
	  listKey--;
	}
    }
    cout<<"You have returned "<<rBook<<endl;

}

int
Library::addBook ()
{
  cout << "Enter book title : ";
  cin >> bookName[bookIndex];
  cout << "Enter author name : ";
  cin >> author[bookIndex];
  cout << "Enter stock : ";
  cin >> bookCount[bookIndex];
  cout << "Enter one day rent price : ";
  cin >> bookPrice[bookIndex];
  bookIndex++;
  showBooks ();
}

int
Library::recharge ()
{
  int rechargeMoney = 0;
  cout << "Enter amount to recharge : ";
  cin >> rechargeMoney;
  if (rechargeMoney > 100000 && amount[id] + rechargeMoney > 100000)
    {
      cout << "Account maximum amount is 100000." << endl;
      recharge ();
    }
  else
    {
      amount[id] = amount[id] + rechargeMoney;
      cout << "Recharge success. " << rechargeMoney <<
	" is added to your account" << endl;
    }
}

int
Library::showBooks ()
{
  for (int a = 0; a < bookIndex; ++a)
    {
      cout << "Book " << a + 1 << endl;
      cout << "  " << "Title : " << bookName[a] << endl;
      cout << "  " << "Author : " << author[a] << endl;
      cout << "  " << "Stock : " << bookCount[a] << endl;
      cout << "  " << "One day rent price : " << bookPrice[a] << endl;
    }
}

int
Library::allBorrowList ()
{
  cout << "All borrowers' list are as follow." << endl;
  for (int i = 0; i < listKey; i++)
    {
      cout << "  " << "Name : " << name[storeBorrowId[i]] << endl;
      cout << "  " << "Book Title : " << borrowBook[i] << endl;
      cout << "  " << "Borrowed days : " << borrowDay[i] << endl;
    }
}

int
main ()
{

  Library obj;
  int acc = obj.welcome ();
  if (acc == 0)
    {
      exit (1);
    }

  return 0;
}

