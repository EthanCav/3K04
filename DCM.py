#import modules
from tkinter import *
import tkinter.messagebox
import os

# Designing window for registration
def register():
    global register_screen
    register_screen = Toplevel(main_screen)
    register_screen.title("Register")
    register_screen.geometry("300x250")

    global username
    global password
    global username_entry
    global password_entry
    username = StringVar()
    password = StringVar()

    Label(register_screen, text="Please enter details below", bg="pink").pack()
    Label(register_screen, text="").pack()
    username_lable = Label(register_screen, text="Username * ")
    username_lable.pack()
    username_entry = Entry(register_screen, textvariable=username)
    username_entry.pack()
    password_lable = Label(register_screen, text="Password * ")
    password_lable.pack()
    password_entry = Entry(register_screen, textvariable=password, show='*')
    password_entry.pack()
    Label(register_screen, text="").pack()
    Button(register_screen, text="Register", width=10, height=1, bg="blue", command = register_user).pack()

# Designing window for login
def login():
    global login_screen
    login_screen = Toplevel(main_screen)
    login_screen.title("Login")
    login_screen.geometry("300x250")
    Label(login_screen, text="Please enter details below to login", bg="pink").pack()
    Label(login_screen, text="").pack()

    global username_verify
    global password_verify

    username_verify = StringVar()
    password_verify = StringVar()

    global username_login_entry
    global password_login_entry

    Label(login_screen, text="Username * ").pack()
    username_login_entry = Entry(login_screen, textvariable=username_verify)
    username_login_entry.pack()
    Label(login_screen, text="").pack()
    Label(login_screen, text="Password * ").pack()
    password_login_entry = Entry(login_screen, textvariable=password_verify, show= '*')
    password_login_entry.pack()
    Label(login_screen, text="").pack()
    Button(login_screen, text="Login", width=10, height=1, command = login_verify).pack()

# Designing window for pacing modes
def modes():
      
    # create a window
    root = tkinter.Tk()
    root.title("Pacing Modes")
    root.geometry('400x250')
    Label(root, text="Select a pacing mode.", bg="pink").pack()
      
    # Create buttons to select pacing modes
    Button1 = Button(root, text="AOO", command=AOO_param, height=3, width=20)
    Button2 = Button(root, text="VOO", command=VOO_param, height=3, width=20)
    Button3 = Button(root, text="AAI", command=AAI_param, height=3, width=20)
    Button4 = Button(root, text="VVI", command=VVI_param, height=3, width=20)
      
    # Set the position of buttons
    Button1.pack()
    Button2.pack()
    Button3.pack()
    Button4.pack()
      
    root.mainloop()

# Implementing Programmable Parameters Screens
def AOO_param():
    global AOO_screen
    AOO_screen = Toplevel(main_screen)
    AOO_screen.title("AOO Programmable Parameters")
    AOO_screen.geometry("400x450")
    Label(AOO_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()

    # define inital values
    LRL_value = 60
    URL_value = 120

## make initial values the "Nominal" values from PACEMAKER appendix A and make them editable by the user
    LRL_label = Label(AOO_screen, text=("Lower Rate Limit: ", LRL_value))
    LRL_label.pack()
    LRL_entry = Entry(AOO_screen, textvariable=LRL_value) #CHANGE "number" should be a variable storing the input 
    LRL_entry.pack()
    Button(AOO_screen, text="Update Parameter", width=15, height=2, command = update_param).pack()

    URL_label = Label(AOO_screen, text="Upper Rate Limit: ")
    URL_label.pack()
    URL_entry = Entry(AOO_screen, textvariable="number")
    URL_entry.pack()

    AA_label = Label(AOO_screen, text="Atrial Amplitude: ")
    AA_label.pack()
    AA_entry = Entry(AOO_screen, textvariable="number") 
    AA_entry.pack()

    APW_label = Label(AOO_screen, text="Atrial Pulse Width: ")
    APW_label.pack()
    APW_entry = Entry(AOO_screen, textvariable="number") 
    APW_entry.pack()

def update_param(): #fix - should update the value displayed for the parameter
    LRL_value = 10
    LRL_label = Label(AOO_screen, text=("Lower Rate Limit: ", LRL_value))


def VOO_param():
    global VOO_screen
    VOO_screen = Toplevel(main_screen)
    VOO_screen.title("VOO Programmable Parameters")
    VOO_screen.geometry("400x450")
    Label(VOO_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()


    LRL_label = Label(VOO_screen, text="Lower Rate Limit: ")
    LRL_label.pack()
    LRL_entry = Entry(VOO_screen, textvariable="number") 
    LRL_entry.pack()

    URL_label = Label(VOO_screen, text="Upper Rate Limit:")
    URL_label.pack()
    URL_entry = Entry(VOO_screen, textvariable="number") 
    URL_entry.pack()

    VA_label = Label(VOO_screen, text="Ventricular Amplitude:")
    VA_label.pack()
    VA_entry = Entry(VOO_screen, textvariable="number") 
    VA_entry.pack()

    VPW_label = Label(VOO_screen, text="Ventricular Pulse Width:")
    VPW_label.pack()
    VPW_entry = Entry(VOO_screen, textvariable="number") 
    VPW_entry.pack()


def AAI_param():
    global AAI_screen
    AAI_screen = Toplevel(main_screen)
    AAI_screen.title("AAI Programmable Parameters")
    AAI_screen.geometry("400x450")
    Label(AAI_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()


    LRL_label = Label(AAI_screen, text="Lower Rate Limit: ")
    LRL_label.pack()
    LRL_entry = Entry(AAI_screen, textvariable="number") 
    LRL_entry.pack()

    URL_label = Label(AAI_screen, text="Upper Rate Limit:")
    URL_label.pack()
    URL_entry = Entry(AAI_screen, textvariable="number")
    URL_entry.pack()

    AA_label = Label(AAI_screen, text="Atrial Amplitude:")
    AA_label.pack()
    AA_entry = Entry(AAI_screen, textvariable="number") 
    AA_entry.pack()

    APW_label = Label(AAI_screen, text="Atrial Pulse Width:")
    APW_label.pack()
    APW_entry = Entry(AAI_screen, textvariable="number") 
    APW_entry.pack()

    ARP_label = Label(AAI_screen, text="ARP:")
    ARP_label.pack()
    ARP_entry = Entry(AAI_screen, textvariable="number") 
    ARP_entry.pack()


def VVI_param():
    global VVI_screen
    VVI_screen = Toplevel(main_screen)
    VVI_screen.title("VVI Programmable Parameters")
    VVI_screen.geometry("400x450")
    Label(VVI_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()


    LRL_label = Label(VVI_screen, text="Lower Rate Limit: ")
    LRL_label.pack()
    LRL_entry = Entry(VVI_screen, textvariable="number") 
    LRL_entry.pack()

    URL_label = Label(VVI_screen, text="Upper Rate Limit:")
    URL_label.pack()
    URL_entry = Entry(VVI_screen, textvariable="number") 
    URL_entry.pack()

    VA_label = Label(VVI_screen, text="Ventricular Amplitude:")
    VA_label.pack()
    VA_entry = Entry(VVI_screen, textvariable="number") 
    VA_entry.pack()

    VPW_label = Label(VVI_screen, text="Ventricular Pulse Width:")
    VPW_label.pack()
    VPW_entry = Entry(VVI_screen, textvariable="number") 
    VPW_entry.pack()

    VRP_label = Label(VVI_screen, text="VRP:")
    VRP_label.pack()
    VRP_entry = Entry(VVI_screen, textvariable="number") 
    VRP_entry.pack()


# Implementing event on register button
def register_user():

    username_info = username.get()
    password_info = password.get()
    
    file3 = open('user_registration.txt',"a")
    file3.close()
    
    file2 = open('user_registration.txt', "r")
    x = len(file2.readlines())/2
    
    if x < 10:
        
        file3 = open('user_registration.txt', "r")
        verify = file3.read().splitlines()
        if username_info in verify:
            username_taken()
        else:
            file = open('user_registration.txt', "a")
            file.write(username_info + "\n")
            file.write(password_info + "\n")
            file.close()

            username_entry.delete(0, END)
            password_entry.delete(0, END)

            Label(register_screen, text="Registration Confirmed, Please Log In", fg="green", font=("calibri", 11)).pack()
        
    else:
        max_users()

# Implementing event on login button
def login_verify():
    username1 = username_verify.get()
    password1 = password_verify.get()
    username_login_entry.delete(0, END)
    password_login_entry.delete(0, END)

    import os.path
    file_exists = os.path.exists('user_registration.txt')

    if file_exists == False:
        Label(login_screen, text="Please register first, then log in.").pack()
    
    file1 = open('user_registration.txt', "r")
    verify = file1.read().splitlines()
    if username1 in verify:
        if password1 in verify:
            login_sucess()
            modes()

        else:
            password_not_recognised()

    else:
        user_not_found()
        
  
# Designing popup for login success
def login_sucess():
    global login_success_screen
    login_success_screen = Toplevel(login_screen)
    login_success_screen.title("Success")
    login_success_screen.geometry("150x100")
    Label(login_success_screen, text="Login Success").pack()
    Button(login_success_screen, text="OK", command=delete_login_success).pack()

# Designing popup for login invalid password
def password_not_recognised():
    global password_not_recog_screen
    password_not_recog_screen = Toplevel(login_screen)
    password_not_recog_screen.title("Success")
    password_not_recog_screen.geometry("150x100")
    Label(password_not_recog_screen, text="Invalid Password ").pack()
    Button(password_not_recog_screen, text="OK", command=delete_password_not_recognised).pack()

# Designing popup for user not found
def user_not_found():
    global user_not_found_screen
    user_not_found_screen = Toplevel(login_screen)
    user_not_found_screen.title("Success")
    user_not_found_screen.geometry("150x100")
    Label(user_not_found_screen, text="User Not Found").pack()
    Button(user_not_found_screen, text="OK", command=delete_user_not_found_screen).pack()
    
# Designing popup for max users 
def max_users():
    global max_users_screen
    max_users_screen = Toplevel(register_screen)
    max_users_screen.title("Success")
    max_users_screen.geometry("250x100")
    Label(max_users_screen, text="Max. Number of Users Reached").pack()
    Button(max_users_screen, text="OK", command=delete_max_users_screen).pack()
# Designing popup for username taken
def username_taken():
    global username_taken_screen
    username_taken_screen = Toplevel(register_screen)
    username_taken_screen.title("Success")
    username_taken_screen.geometry("250x100")
    Label(username_taken_screen, text="Username Taken").pack()
    Button(username_taken_screen, text="OK", command=delete_username_taken_screen).pack()

# Deleting popups
def delete_login_success():
    login_success_screen.destroy()

def delete_password_not_recognised():
    password_not_recog_screen.destroy()

def delete_user_not_found_screen():
    user_not_found_screen.destroy()
    
def delete_max_users_screen():
    max_users_screen.destroy()
    
def delete_username_taken_screen():
    username_taken_screen.destroy()

# Designing Main(first) window
def main_account_screen():
    global main_screen
    main_screen = Tk()
    main_screen.geometry("300x250")
    main_screen.title("Welcome to Pacemaker Pros!")
    Label(text="Please Login or Register as a New User.", bg="pink", width="300", height="2", font=("Calibri", 13)).pack()
    Label(text="").pack()
    Button(text="Login", height="2", width="30", command = login).pack()
    Label(text="").pack()
    Button(text="Register", height="2", width="30", command=register).pack()
    
    main_screen.mainloop()

main_account_screen()
