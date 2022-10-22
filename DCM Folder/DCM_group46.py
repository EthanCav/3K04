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
    global modes_screen

    # create a window
    modes_screen = tkinter.Tk()
    modes_screen.title("Pacing Modes")
    modes_screen.geometry('400x350')
    Label(modes_screen, text="Select a pacing mode.", bg="pink").pack()
    
    # Create buttons to select pacing modes
    Button1 = Button(modes_screen, text="AOO", command=AOO_param, height=3, width=20)
    Button2 = Button(modes_screen, text="VOO", command=VOO_param, height=3, width=20)
    Button3 = Button(modes_screen, text="AAI", command=AAI_param, height=3, width=20)
    Button4 = Button(modes_screen, text="VVI", command=VVI_param, height=3, width=20)
      
    # Set the position of buttons
    Button1.pack()
    Button2.pack()
    Button3.pack()
    Button4.pack()

    #Button to connect DCM to pacemaker & visually indicate when connected/disconnected
    #For Assignment 2, we will make adjustments so that when you press the button, it connects or disconnects the pacemaker
    def pacemakerConnect():

        if(Connect['text']=='Connect Device'):
            Connect['text']='Disconnect Device'
            device_connected();
            
        elif(Connect['text']=='Disconnect Device'):
            Connect['text']='Connect Device'
            device_disconnected();

    Connect = Button(modes_screen, text = 'Connect Device', command = pacemakerConnect)
    Connect.pack()

# Implementing Programmable Parameters Screens
def AOO_param():
    global AOO_screen
    AOO_screen = Toplevel(modes_screen)
    AOO_screen.title("AOO Programmable Parameters")
    AOO_screen.geometry("400x450")
    Label(AOO_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()
    
#drop down menus and sliders for value selection for programmable parameters
    def show():
        label.config(text = slider.get())

    LRL_label = Label(AOO_screen, text="Lower Rate Limit  [ppm]: ")
    LRL_label.pack()
    slider = Scale(AOO_screen, from_=30, to=175, orient=HORIZONTAL)
    slider.pack()
    slider.set(60)

    button = Button(AOO_screen, text = "Update Parameter", command = show).pack()
    label = Label(AOO_screen, text = "")
    label.pack()
    
    def show2():
        label.config(text = clicked2.get())
    
    URL_label = Label(AOO_screen, text="Upper Rate Limit [ppm]: ")
    URL_label.pack()
    options2 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked2
    clicked2 = IntVar(AOO_screen)
    clicked2.set(120)
    drop2 = OptionMenu(AOO_screen, clicked2, *options2 )
    drop2.pack()
    button = Button(AOO_screen, text = "Update Parameter", command = show2).pack()
    label = Label(AOO_screen, text = "")
    label.pack()

    def show3():
        label.config(text = clicked3.get())
        
    AA_label = Label(AOO_screen, text="Atrial Amplitude [V]:")
    AA_label.pack()
    options3 = [0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.5,4.0,4.5,5.0,5.5,6.0,6.5,7.0]
    global clicked3
    clicked3 = DoubleVar(AOO_screen)
    clicked3.set(3.5)
    drop3 = OptionMenu(AOO_screen, clicked3, *options3 )
    drop3.pack()
    button = Button(AOO_screen, text = "Update Parameter", command = show3).pack()
    label = Label(AOO_screen, text = "")
    label.pack()

    def show4():
        label.config(text = clicked4.get())
    
    
    APW_label = Label(AOO_screen, text="Atrial Pulse Width [ms]:")
    APW_label.pack()
    options4 = [0.05, 0.1, 0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9]
    global clicked4
    clicked4 = DoubleVar(AOO_screen)
    clicked4.set(0.4)
    drop4 = OptionMenu(AOO_screen, clicked4, *options4 )
    drop4.pack()
    button = Button(AOO_screen, text = "Update Parameter", command = show4).pack()
    label = Label(AOO_screen, text = "")
    label.pack()


def VOO_param():
    global VOO_screen
    VOO_screen = Toplevel(modes_screen)
    VOO_screen.title("VOO Programmable Parameters")
    VOO_screen.geometry("400x450")
    Label(VOO_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()

    #drop down menus and sliders for value selection for programmable parameters
    def show():
        label.config(text = slider.get())

    LRL_label = Label(VOO_screen, text="Lower Rate Limit [ppm]: " )
    LRL_label.pack()
    slider = Scale(VOO_screen, from_=30, to=175, orient=HORIZONTAL)
    slider.pack()
    slider.set(60)
    button = Button(VOO_screen, text = "Update Parameter", command = show).pack()
    label = Label(VOO_screen, text = "")
    label.pack()

    
    def show2():
        label.config(text = clicked2.get())
    
    URL_label = Label(VOO_screen, text="Upper Rate Limit [ppm]: ")
    URL_label.pack()
    options2 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked2
    clicked2 = IntVar(VOO_screen)
    clicked2.set(120)
    drop2 = OptionMenu(VOO_screen, clicked2, *options2 )
    drop2.pack()
    button = Button(VOO_screen, text = "Update Parameter", command = show2).pack()
    label = Label(VOO_screen, text = "")
    label.pack()

    
    def show3():
        label.config(text = clicked3.get())
    
    VA_label = Label(VOO_screen, text="Ventricular Amplitude [V]:")
    VA_label.pack()
    options3 = [0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.5,4.0,4.5,5.0,5.5,6.0,6.5,7.0]
    global clicked3
    clicked3 = DoubleVar(VOO_screen)
    clicked3.set(3.5)
    drop3 = OptionMenu(VOO_screen, clicked3, *options3 )
    drop3.pack()
    button = Button(VOO_screen, text = "Update Parameter", command = show3).pack()
    label = Label(VOO_screen, text = "")
    label.pack()


    def show4():
        label.config(text = clicked4.get())
    
    VPW_label = Label(VOO_screen, text="Ventricular Pulse Width [ms]:")
    VPW_label.pack()
    options4 = [0.05, 0.1, 0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9]
    global clicked4
    clicked4 = DoubleVar(VOO_screen)
    clicked4.set(0.4)
    drop4 = OptionMenu(VOO_screen, clicked4, *options4 )
    drop4.pack()
    button = Button(VOO_screen, text = "Update Parameter", command = show4).pack()
    label = Label(VOO_screen, text = "")
    label.pack()


def AAI_param():
    global AAI_screen
    AAI_screen = Toplevel(modes_screen)
    AAI_screen.title("AAI Programmable Parameters")
    AAI_screen.geometry("400x520")
    Label(AAI_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()
    
    #drop down menus and sliders for value selection for programmable parameters
    def show():
        label.config(text = slider.get())

    LRL_label = Label(AAI_screen, text="Lower Rate Limit [ppm]: " )
    LRL_label.pack()
    slider = Scale(AAI_screen, from_=30, to=175, orient=HORIZONTAL)
    slider.pack()
    slider.set(60)
    button = Button(AAI_screen, text = "Update Parameter", command = show).pack()
    label = Label(AAI_screen, text = "")
    label.pack()

    
    def show2():
        label.config(text = clicked2.get())
    
    URL_label = Label(AAI_screen, text="Upper Rate Limit [ppm]: ")
    URL_label.pack()
    options2 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked2
    clicked2 = IntVar(AAI_screen)
    clicked2.set(120)
    drop2 = OptionMenu(AAI_screen, clicked2, *options2 )
    drop2.pack()
    button = Button(AAI_screen, text = "Update Parameter", command = show2).pack()
    label = Label(AAI_screen, text = "")
    label.pack()

    
    def show3():
        label.config(text = clicked3.get())
        
    AA_label = Label(AAI_screen, text="Atrial Amplitude [V]:")
    AA_label.pack()
    options3 = [0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.5,4.0,4.5,5.0,5.5,6.0,6.5,7.0]
    global clicked3
    clicked3 = DoubleVar(AAI_screen)
    clicked3.set(3.5)
    drop3 = OptionMenu(AAI_screen, clicked3, *options3 )
    drop3.pack()
    button = Button(AAI_screen, text = "Update Parameter", command = show3).pack()
    label = Label(AAI_screen, text = "")
    label.pack()

    def show4():
        label.config(text = clicked4.get())
    
    
    APW_label = Label(AAI_screen, text="Atrial Pulse Width [ms]:")
    APW_label.pack()
    options4 = [0.05, 0.1, 0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9]
    global clicked4
    clicked4 = DoubleVar(AAI_screen)
    clicked4.set(0.4)
    drop4 = OptionMenu(AAI_screen, clicked4, *options4 )
    drop4.pack()
    button = Button(AAI_screen, text = "Update Parameter", command = show4).pack()
    label = Label(AAI_screen, text = "")
    label.pack()


    def show5():
        label.config(text = clicked5.get())
    
    
    ARP_label = Label(AAI_screen, text="Atrial Refractory Period [ms]:")
    ARP_label.pack()
    options5 = [150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500]
    global clicked5
    clicked5 = IntVar(AAI_screen)
    clicked5.set(250)
    drop5 = OptionMenu(AAI_screen, clicked5, *options5 )
    drop5.pack()
    button = Button(AAI_screen, text = "Update Parameter", command = show5).pack()
    label = Label(AAI_screen, text = "")
    label.pack()


def VVI_param():
    global VVI_screen
    VVI_screen = Toplevel(modes_screen)
    VVI_screen.title("VVI Programmable Parameters")
    VVI_screen.geometry("400x520")
    Label(VVI_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()

    #drop down menus and sliders for value selection for programmable parameters
    def show():
        label.config(text = slider.get())

    LRL_label = Label(VVI_screen, text="Lower Rate Limit [ppm]: " )
    LRL_label.pack()
    slider = Scale(VVI_screen, from_=30, to=175, orient=HORIZONTAL)
    slider.pack()
    slider.set(60)
    button = Button(VVI_screen, text = "Update Parameter", command = show).pack()
    label = Label(VVI_screen, text = "")
    label.pack()

    
    def show2():
        label.config(text = clicked2.get())
    
    URL_label = Label(VVI_screen, text="Upper Rate Limit [ppm]: ")
    URL_label.pack()
    options2 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked2
    clicked2 = IntVar(VVI_screen)
    clicked2.set(120)
    drop2 = OptionMenu(VVI_screen, clicked2, *options2 )
    drop2.pack()
    button = Button(VVI_screen, text = "Update Parameter", command = show2).pack()
    label = Label(VVI_screen, text = "")
    label.pack()

    
    def show3():
        label.config(text = clicked3.get())
    
    VA_label = Label(VVI_screen, text="Ventricular Amplitude [V]:")
    VA_label.pack()
    options3 = [0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.5,4.0,4.5,5.0,5.5,6.0,6.5,7.0]
    global clicked3
    clicked3 = DoubleVar(VVI_screen)
    clicked3.set(3.5)
    drop3 = OptionMenu(VVI_screen, clicked3, *options3 )
    drop3.pack()
    button = Button(VVI_screen, text = "Update Parameter", command = show3).pack()
    label = Label(VVI_screen, text = "")
    label.pack()


    def show4():
        label.config(text = clicked4.get())
    
    VPW_label = Label(VVI_screen, text="Ventricular Pulse Width [ms]:")
    VPW_label.pack()
    options4 = [0.05, 0.1, 0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9]
    global clicked4
    clicked4 = DoubleVar(VVI_screen)
    clicked4.set(0.4)
    drop4 = OptionMenu(VVI_screen, clicked4, *options4 )
    drop4.pack()
    button = Button(VVI_screen, text = "Update Parameter", command = show4).pack()
    label = Label(VVI_screen, text = "")
    label.pack()

    def show5():
        label.config(text = clicked5.get())
    
    
    VRP_label = Label(VVI_screen, text="Ventricular Refractory Period [ms]:")
    VRP_label.pack()
    options5 = [150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500]
    global clicked5
    clicked5 = IntVar(VVI_screen)
    clicked5.set(320)
    drop5 = OptionMenu(VVI_screen, clicked5, *options5 )
    drop5.pack()
    button = Button(VVI_screen, text = "Update Parameter", command = show5).pack()
    label = Label(VVI_screen, text = "")
    label.pack()


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
# Designing popup for device connected     
def device_connected():
    global device_connected_screen
    device_connected_screen = Toplevel(modes_screen)
    device_connected_screen.title("Success")
    device_connected_screen.geometry("250x100")
    Label(device_connected_screen, text="Device Connected", fg="green").pack()
    Button(device_connected_screen, text="OK", command=delete_device_connected_screen).pack()
# Designing popup for device disconnected    
def device_disconnected():
    global device_disconnected_screen
    device_disconnected_screen = Toplevel(modes_screen)
    device_disconnected_screen.title("Success")
    device_disconnected_screen.geometry("250x100")
    Label(device_disconnected_screen, text="Device Disconnected", fg="red").pack()
    Button(device_disconnected_screen, text="OK", command=delete_device_disconnected_screen).pack()
    
    
# Deleting popups
def delete_login_success():
    login_success_screen.destroy()
    login_screen.destroy()
    main_screen.destroy()

def delete_password_not_recognised():
    password_not_recog_screen.destroy()

def delete_user_not_found_screen():
    user_not_found_screen.destroy()
    
def delete_max_users_screen():
    max_users_screen.destroy()
    
def delete_username_taken_screen():
    username_taken_screen.destroy()
    
def delete_device_connected_screen():
    device_connected_screen.destroy()
    
def delete_device_disconnected_screen():
    device_disconnected_screen.destroy()

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



