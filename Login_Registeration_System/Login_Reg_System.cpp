#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void NewRegister();
bool validEmail(string);
bool validfirstname(string);
bool validlastname(string);
bool validpassword(string);
void verificationcode();
void Login();
bool saveUserData(string firstname, string lastname, string email, string password); // function to save user data to a file
bool checkUSerCredentials(const string& username, const string& password);

string Filepath = "Login_Registeration_System/user_data.txt";

int main()
{
    // when the user opens the website
    cout << "Welcome to our website!" << endl;
    NewRegister();

    return 0;
}
void NewRegister() // This function asks the user if he is a new user or have already an account
{

    string NewRegister, Username, Password, firstname, lastname, email;

    cout << "New register?  \n(Note: if you are a new user type Yes, otherwise type No) \n";
    
    cin >> NewRegister; // must be "yes" if he is a new user or "no" if he is not a new user
    cin.ignore();

    if (NewRegister == "Yes" || NewRegister == "yes" )
    {
        cout << "First name : "; // enter first name
        cin >> firstname;
        while (validfirstname(firstname) == false)
        {
            cout << "The first name is not valid please try again : " << endl;
            cin >> firstname;
        }
        cout << endl
             << "Valid first name." << endl
             << endl;


        cout << "Last name : "; // enter last name
        cin >>lastname ;
        while (validlastname(lastname) == false)
        {
            cout << "The last name is not valid please try again : " << endl;
            cin >> lastname;
        }
        cout << endl
             << "Valid last name." << endl
             << endl;

        cout << "Email : "; // enter email
        cin >> email;
        while (validEmail(email) == false)
        {
            cout << "The email address is not valid please try again : " << endl;
            cin >> email;
        }
        cout << endl
             << "Valid email address." << endl
             << endl;

        cout << "Password : \n(Note: your password must be at least one digit,one special character, one uppercase letter, and one lowercase letter) \n"; // enter password
        cin >> Password;
        while (validpassword(Password) == false)
        {
            cout << "The password is not valid please try again : " << endl;
            cin >> Password;
        }
        cout << endl
             << "Valid password." << endl
             << endl;

        cout << "Registration completed! \n" << endl;
        verificationcode();
        if(saveUserData(firstname, lastname, email, Password)) // save user data to a file
        {
            cout << "User data saved successfully!" << endl;
            cout << "You can now log in with your username and password." << endl;
            cout << "Username: " << firstname << lastname << endl; // Example username
            cout << "Password: " << Password << endl; // Display password for testing purposes
        }
        else
        {
            cout << "Error saving user data!" << endl;
        }
    }
    else if (NewRegister == "No"  ||NewRegister == "no") // have already an account
    {
        Login();
    }
    else
    {
        cout << "Invalid input. Please type 'Yes' or 'No'." << endl;
        
    }
}

bool saveUserData(string firstname, string lastname, string email, string password) // function to save user data to a file
{
    ofstream file(Filepath, ios::app); // open file in append mode
    if (file.is_open())
    {
        file << "First Name: " << firstname << endl;
        file << "Last Name: " << lastname << endl;
        file << "Email: " << email << endl;
        file << "Password: " << password << endl;
        file << "------------------------" << endl; // separator for each user
        file.close();
        return true;
    }
    else
    {
        cout << "Error opening file!" << endl;
        return false;
    }
}

bool validfirstname(string firstname) // function to check the validity of the first name
{
    if (firstname[0] >= 'A' && firstname[0] <= 'Z')
      return true;
	  else
	  return false;
}
bool validlastname(string lastname) // function to check the validity of the last name
{
    if (lastname[0] >= 'A' && lastname[0] <= 'Z')
      return true;
    
    else 
  	 return false;
       
    
}
bool validEmail(string email) // function to check the validity of the email
{
    int AT = -1, dot = -1;                                                            // variables to store the position of ( @ )and (dot)
    int counterforAT = 0, counterforDot = 0;                                          // check if there is more than one (@) or (dot)
    if ((email[0] >= 'a' && email[0] <= 'z') || (email[0] >= 'A' && email[0] <= 'Z')) // if the email address start with letter(valid )
    {
        for (int i = 0; i < email.length(); i++)
        {
            if (email[i] == '@') // If the character is '@'
            {
                AT = i;
                ++counterforAT;
            }

            else if (email[i] == '.') // If character is '.'
            {
                dot = i;
                ++counterforDot;
            }
        }
        if (AT == -1 || dot == -1) // If (@) or (dot)is not present

            return false;

        if (AT > dot) // If (dot) is present before(@)

            return false;

        if (counterforDot > 1 || counterforAT > 1)
            return false;

        return !(dot >= (email.length() - 1));
    }
    else if (email[0] >= '0' && email[0] <= '9') // if the email address start with number (not valid )
    {
        return false;
    }
    else // if the email address start with other symbols (not valid)
    {
        return false;
    }
}
bool validpassword(string password) // function to check the validity of the password
{
    int digit = 0, uppercase = 0, lowercase = 0, specialchar = 0; // counter to find if password contain at least one digit,one special character, one uppercase letter, and one lowercase letter
    if (password.length() >= 8 && password.length() <= 15)
    {

        if (password.find(" ") ==  std::string::npos) // check if the password contains space
        {
            for (int i = 0; i < password.length(); i++)
            {
                if (password[i] >= '0' && password[i] <= '9')
                {
                    ++digit;
                }
                else if (password[i] >= 'a' && password[i] <= 'z')
                {
                    ++lowercase;
                }
                else if (password[i] >= 'A' && password[i] <= 'Z')
                {
                    ++uppercase;
                } 
                else if (password[i] == '@' || password[i] == '#' || password[i] == '_')
                {
                    ++specialchar;
                }
            }

            if (digit == 0 || uppercase == 0 || lowercase == 0 || specialchar == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else /* Contain Spaces*/
        {

            return false;
        }
    }

    cout << "Note : your password length less than 8 characters or more than 15 characters." << endl;
    return false;
}
void verificationcode() // verifying account
{
    int code ;

    cout << "We have sent a verification code to your email to confirm your account." << endl
         << "Please check your email." << endl;

  
     cout<<"Email message: Your verification code is  ";
    srand(time(0));

	for (int i = 0; i <= 3; i++)
	{
		cout << rand() % 10 ;
	}
    cout<<"\n";

    cout<<"Enter the verification code here : \n";
	cin>>code;

    cout << "Your account has been verified." << endl;
}
void Login()
{
    string Username, Password;

    cin.ignore();
    cout << endl    << "     Log in       " << endl<< endl;
    cout << "Enter your username :" << endl;
    getline(cin, Username);

    cout << "Enter your password :" << endl;
    cin >> Password;

    // Here you would typically check the username and password against stored data
    if(checkUSerCredentials(Username, Password)) // Check user credentials
    {
        cout << endl
             << "Login success!" << endl;
    }
    else
    {
        cout << "Invalid username or password. Please try again." << endl;
        return; // Exit the function if login fails
    }
}

bool checkUSerCredentials(const string& username, const string& password) {
    // This function would typically check the provided credentials against stored data
    ifstream file(Filepath);
    if (file.is_open()) {
        string line;
        cout << "Checking credentials for user: " << username << endl;
        while (getline(file, line)) {
            if (line.find("First Name: " + username) != string::npos) {
                cout << "Found user: " << username << endl;
                getline(file, line); // Read the next line (Last Name)
                getline(file, line); // Read the next line (Email)
                getline(file, line); // Read the next line (Password)
                // Found the user, now check the password
                if (line.find("Password: " + password) != string::npos) {
                    cout << "Password matches for user: " << username << endl;
                    file.close();
                    return true; // Credentials are valid
                }
            }
        }
        file.close();   
    }
    else   
    {
        cout << "Error opening user data file!" << endl;
        return false; // File could not be opened
    }
    return false; // Credentials are invalid
}
