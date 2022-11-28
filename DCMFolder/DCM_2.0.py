#import modules
from tkinter import *
import tkinter.messagebox
from tkinter import messagebox
import os
import serial
from serial.tools import list_ports
import struct
import tkinter as tk
import time

global modes_value 
global VRP_value 
global VPW_value
global LRL_value 
global URL_value
global ARP_value 
global VA_value 
global AA_value
global RCT_value 
global RF_value 
global RT_value 
global AT_value
global at_value
global APW_value 
global MSR_value
global VS_value
global AS_value

#Set parameters to nominal values
mode_value = 0
VRP_value = 320
VPW_value = 1
LRL_value = 60
URL_value = 120
ARP_value = 250
VA_value = 4.0
AA_value = 4.0
RCT_value = 300
RF_value = 8
RT_value = 30
AT_value = "Med"
at_value = 28
APW_value = 1
MSR_value = 120
VS_value = 3.5
AS_value = 3.5

def AT_Converter():
    global at_value
    if AT_value == "V-Low":
        at_value = 7
    elif AT_value == "Low":
        at_value = 14
    elif AT_value == "Med-Low":
        at_value = 21
    elif AT_value == "Med":
        at_value = 28
    elif AT_value == "Med-High":
        at_value = 35
    elif AT_value == "High":
        at_value = 42
    elif AT_value == "V-High":
        at_value = 49
    return at_value

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
    modes_screen.geometry('500x600')
    Label(modes_screen, text="Select a pacing mode.", bg="pink").pack()
    
    # Create buttons to select pacing modes
    Button1 = Button(modes_screen, text="AOO", command=AOO_param, height=3, width=20)
    Button2 = Button(modes_screen, text="VOO", command=VOO_param, height=3, width=20)
    Button3 = Button(modes_screen, text="AAI", command=AAI_param, height=3, width=20)
    Button4 = Button(modes_screen, text="VVI", command=VVI_param, height=3, width=20)
    Button5 = Button(modes_screen, text="VOOR", command=VOOR_param, height=3, width=20)
    Button6 = Button(modes_screen, text="AOOR", command=AOOR_param, height=3, width=20)
    Button7 = Button(modes_screen, text="VVIR", command=VVIR_param, height=3, width=20)
    Button8 = Button(modes_screen, text="AAIR", command=AAIR_param, height=3, width=20)
      
    # Set the position of buttons
    Button1.pack()
    Button2.pack()
    Button3.pack()
    Button4.pack()
    Button5.pack()
    Button6.pack()
    Button7.pack()
    Button8.pack()
    
    '''
    #Set parameters to nominal values
    VRP_value = 320
    VPW_value = 1
    LRL_value = 60
    URL_value = 120
    ARP_value = 250
    VA_value = 4.0
    AA_value = 4.0
    RCT_value = 300
    RF_value = 8
    RT_value = 30
    AT_value = "Med"
    at_value = 28
    APW_value = 1
    MSR_value = 120
    VS_value = 3.5
    AS_value = 3.5
    '''
    
    # Store parameters in a text file 
    file = open('programmable_parameters.txt',"a")
    file.write("Ventricular Refractory Period = "+ str(VRP_value) + " " + "ms" + "\n")
    file.write("Ventricular Pulse Width = "+ str(VPW_value) + " " + "ms" + "\n")
    file.write("LRL = "+ str(LRL_value) + " " + "ppm" + "\n")
    file.write("URL = "+ str(URL_value) + " " + "ppm" + "\n")
    file.write("Atrial Refractory Period = "+ str(ARP_value) + " " + "ms" + "\n")
    file.write("Ventricular Amlitude = "+ str(VA_value) + " " "V" + "\n")
    file.write("Atrial Amlitude = "+ str(AA_value) + " " "V" + "\n")
    file.write("Recovery Time = "+ str(RCT_value) + " " + "sec"+ "\n")
    file.write("Response Factor = "+ str(RF_value) + "\n")
    file.write("Reaction Time = "+ str(RT_value) + " " + "sec"+ "\n")
    file.write("Activity Threshold = "+ str(at_value)  + "\n")
    file.write("Atrial Pulse Width = "+ str(APW_value) + " " + "ms" + "\n")
    file.write("MSR = "+ str(MSR_value) + " " + "ppm" + "\n")
    file.write("Ventricular Sensitivity = "+ str(VS_value) + " " + "V" + "\n")
    file.write("Atrial Sensitivity = "+ str(AS_value) + " " + "V" + "\n")    
    file.close()
    
    
    def logout():
        logout_success()
        
    Logout = Button(modes_screen, text = 'Logout', command = logout)
    Logout.pack()
    Logout.place(x=400, y = 5)

############################################################################################

    #Connect pacemaker and DCM with serial communication
    def serialConnect():
        global ser #for setting up serial communication
        global ports #for setting up the port that is connected to the device

        #check to get the right port every time
        ports = list(serial.tools.list_ports.comports())
        K64F_HWID = "1366:1015"
        for i in ports:
            if K64F_HWID in i.hwid:
                    port = i.device
        print("port: ", port)
    
        ser = serial.Serial(port, baudrate = 115200, timeout=None) 

    ##    ser.open()

        if ser.is_open:
            root = tk.Tk()
            root.withdraw() #to get rid of empty pop-up window 
            messagebox.showinfo("System Message", "Device connected!")
            print("connected")
            check_device()

        else:
            messagebox.showerror("System Message","Device not connected.") #this doesn't seem to work
            
    #disconnect pacemaker and DCM
    def serialDisconnect():
        global ser 
        ser.close()
        print("disconnected")
        messagebox.showerror("System Message","Device disconnected.")

    #Button to visually indicate when DCM and pacemaker are connected/disconnected 
    def pacemakerConnect():
        if(Connect['text']=='Connect Device'):
            Connect['text']='Disconnect Device'
            serialConnect()
            
        elif(Connect['text']=='Disconnect Device'):
            Connect['text']='Connect Device'
            serialDisconnect()
                    
    Connect = Button(modes_screen, text = 'Connect Device', command = pacemakerConnect)
    Connect.pack()

    #Visually indicate when a different pacemaker device is approached than when previously interrogated
    def diff_device():
        global diff_device_screen
        diff_device_screen = Toplevel(modes_screen)
        diff_device_screen.title("System Message")
        diff_device_screen.geometry ("400x100")
        Label(diff_device_screen, text="Device Connected!\n\nWarning: New pacemaker device detected.", fg="green").pack()
        Button(diff_device_screen, text="OK", command=delete_diff_device_screen).pack()

    #Check for a different device
    def check_device():
            condition = serialCommunication()

            if condition != True:
                diff_device()

############################################################################################       

# Implementing Programmable Parameters Screens
def AOO_param():
    global AOO_screen
    AOO_screen = Toplevel(modes_screen)
    AOO_screen.title("AOO Programmable Parameters")
    AOO_screen.geometry("400x450")
    Label(AOO_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()

    global mode_value

    mode_value = 3
    
#drop down menus and sliders for value selection for programmable parameters
    def show():
        global LRL_value
        if slider.get() < clicked2.get():
            label.config(text = slider.get())
            LRL_value = slider.get()
            file = open('programmable_parameters.txt',"a")
            file.write("LRL = "+ str(LRL_value) + " " + "ppm" + "\n")
            file.close()
            

    LRL_label = Label(AOO_screen, text="Lower Rate Limit  [ppm]: ")
    LRL_label.pack()
    slider = Scale(AOO_screen, from_=30, to=175, orient=HORIZONTAL)
    slider.pack()
    slider.set(60)
    button = Button(AOO_screen, text = "Update Parameter", command = show).pack()
    label = Label(AOO_screen, text = "")
    label.pack()
    
    def show2():
        global URL_value
        if clicked2.get() > slider.get():
            label2.config(text = clicked2.get())
            URL_value = clicked2.get()
            file = open('programmable_parameters.txt',"a")
            file.write("URL = "+ str(URL_value) + " " + "ppm" + "\n")
            file.close()
        
    URL_label = Label(AOO_screen, text="Upper Rate Limit [ppm]: ")
    URL_label.pack()
    options2 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked2
    clicked2 = IntVar(AOO_screen)
    clicked2.set(120)
    drop2 = OptionMenu(AOO_screen, clicked2, *options2 )
    drop2.pack()
    button = Button(AOO_screen, text = "Update Parameter", command = show2).pack()
    label2 = Label(AOO_screen, text = "")
    label2.pack()

    def show3():
        global AA_value
        label3.config(text = clicked3.get())
        AA_value = clicked3.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Atrial Amlitude = "+ str(AA_value) + " " "V" + "\n")
        file.close()
        
    AA_label = Label(AOO_screen, text="Atrial Amplitude [V]:")
    AA_label.pack()
    options3 = [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0]
    global clicked3
    clicked3 = DoubleVar(AOO_screen)
    clicked3.set(4.0)
    drop3 = OptionMenu(AOO_screen, clicked3, *options3 )
    drop3.pack()
    button = Button(AOO_screen, text = "Update Parameter", command = show3).pack()
    label3 = Label(AOO_screen, text = "")
    label3.pack()

    def show4():
        global APW_value
        label4.config(text = clicked4.get())
        APW_value = clicked4.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Atrial Pulse Width = "+ str(APW_value) + " " + "ms" + "\n")
        file.close()
    
    
    APW_label = Label(AOO_screen, text="Atrial Pulse Width [ms]:")
    APW_label.pack()
    options4 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
    global clicked4
    clicked4 = IntVar(AOO_screen)
    clicked4.set(1)
    drop4 = OptionMenu(AOO_screen, clicked4, *options4 )
    drop4.pack()
    button = Button(AOO_screen, text = "Update Parameter", command = show4).pack()
    label4 = Label(AOO_screen, text = "")
    label4.pack()
    
    Push = Button(AOO_screen, text = "Push to Pacemaker", command = serialCommunication) #command =  serial() call serial communcation code
    Push.pack()
    
############################################################################################

def VOO_param():
    global VOO_screen
    VOO_screen = Toplevel(modes_screen)
    VOO_screen.title("VOO Programmable Parameters")
    VOO_screen.geometry("400x450")
    Label(VOO_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()

    global mode_value
    
    mode_value = 1

    #drop down menus and sliders for value selection for programmable parameters
    def show():
        global LRL_value
        if slider.get() < clicked2.get():
            label.config(text = slider.get())
            LRL_value = slider.get()
            file = open('programmable_parameters.txt',"a")
            file.write("LRL = "+ str(LRL_value) + " " + "ppm" + "\n")
            file.close()

    LRL_label = Label(VOO_screen, text="Lower Rate Limit  [ppm]: ")
    LRL_label.pack()
    slider = Scale(VOO_screen, from_=30, to=175, orient=HORIZONTAL)
    slider.pack()
    slider.set(60)
    button = Button(VOO_screen, text = "Update Parameter", command = show).pack()
    label = Label(VOO_screen, text = "")
    label.pack()
    
    def show2():
        global URL_value
        if clicked2.get() > slider.get():
            label2.config(text = clicked2.get())
            URL_value = clicked2.get()
            file = open('programmable_parameters.txt',"a")
            file.write("URL = "+ str(URL_value) + " " + "ppm" + "\n")
            file.close()
        
    URL_label = Label(VOO_screen, text="Upper Rate Limit [ppm]: ")
    URL_label.pack()
    options2 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked2
    clicked2 = IntVar(VOO_screen)
    clicked2.set(120)
    drop2 = OptionMenu(VOO_screen, clicked2, *options2 )
    drop2.pack()
    button = Button(VOO_screen, text = "Update Parameter", command = show2).pack()
    label2 = Label(VOO_screen, text = "")
    label2.pack()

    
    def show3():
        global VA_value
        label3.config(text = clicked3.get())
        VA_value = clicked3.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Ventricular Amlitude = "+ str(VA_value) + " " "V" + "\n")
        file.close()
    
    VA_label = Label(VOO_screen, text="Ventricular Amplitude [V]:")
    VA_label.pack()
    options3 = [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0]
    global clicked3
    clicked3 = DoubleVar(VOO_screen)
    clicked3.set(4.0)
    drop3 = OptionMenu(VOO_screen, clicked3, *options3 )
    drop3.pack()
    button = Button(VOO_screen, text = "Update Parameter", command = show3).pack()
    label3 = Label(VOO_screen, text = "")
    label3.pack()


    def show4():
        global VPW_value
        label4.config(text = clicked4.get())
        VPW_value = clicked4.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Ventricular Pulse Width = "+ str(VPW_value) + " " + "ms" + "\n")
        file.close()
    
    VPW_label = Label(VOO_screen, text="Ventricular Pulse Width [ms]:")
    VPW_label.pack()
    options4 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
    global clicked4
    clicked4 = IntVar(VOO_screen)
    clicked4.set(1)
    drop4 = OptionMenu(VOO_screen, clicked4, *options4 )
    drop4.pack()
    button = Button(VOO_screen, text = "Update Parameter", command = show4).pack()
    label4 = Label(VOO_screen, text = "")
    label4.pack()

    Push = Button(VOO_screen, text = "Push to Pacemaker", command = serialCommunication) #command =  serial() call serial communcation code
    Push.pack()
    
############################################################################################
    
def AAI_param():
    global AAI_screen
    AAI_screen = Toplevel(modes_screen)
    AAI_screen.title("AAI Programmable Parameters")
    AAI_screen.geometry("400x520")
    Label(AAI_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()

    global mode_value

    mode_value = 4
    
    #drop down menus and sliders for value selection for programmable parameters
    def show():
        global LRL_value
        if slider.get() < clicked2.get():
            label.config(text = slider.get())
            LRL_value = slider.get()
            file = open('programmable_parameters.txt',"a")
            file.write("LRL = "+ str(LRL_value) + " " + "ppm" + "\n")
            file.close()

    LRL_label = Label(AAI_screen, text="Lower Rate Limit  [ppm]: ")
    LRL_label.pack()
    slider = Scale(AAI_screen, from_=30, to=175, orient=HORIZONTAL)
    slider.pack()
    slider.set(60)
    button = Button(AAI_screen, text = "Update Parameter", command = show).pack()
    label = Label(AAI_screen, text = "")
    label.pack()

    
    def show2():
        global URL_value
        if clicked2.get() > slider.get():
            label2.config(text = clicked2.get())
            URL_value = clicked2.get()
            file = open('programmable_parameters.txt',"a")
            file.write("URL = "+ str(URL_value) + " " + "ppm" + "\n")
            file.close()
        
    URL_label = Label(AAI_screen, text="Upper Rate Limit [ppm]: ")
    URL_label.pack()
    options2 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked2
    clicked2 = IntVar(AAI_screen)
    clicked2.set(120)
    drop2 = OptionMenu(AAI_screen, clicked2, *options2 )
    drop2.pack()
    button = Button(AAI_screen, text = "Update Parameter", command = show2).pack()
    label2 = Label(AAI_screen, text = "")
    label2.pack()

    
    def show3():
        global AA_value
        label3.config(text = clicked3.get())
        AA_value = clicked3.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Atrial Amlitude = "+ str(AA_value) + " " "V" + "\n")
        file.close()
        
    AA_label = Label(AAI_screen, text="Atrial Amplitude [V]:")
    AA_label.pack()
    options3 = [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0]
    global clicked3
    clicked3 = DoubleVar(AAI_screen)
    clicked3.set(4.0)
    drop3 = OptionMenu(AAI_screen, clicked3, *options3 )
    drop3.pack()
    button = Button(AAI_screen, text = "Update Parameter", command = show3).pack()
    label3 = Label(AAI_screen, text = "")
    label3.pack()

    def show4():
        global APW_value
        label4.config(text = clicked4.get())
        APW_value = clicked4.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Atrial Pulse Width = "+ str(APW_value) + " " + "ms" + "\n")
        file.close()
    
    
    APW_label = Label(AAI_screen, text="Atrial Pulse Width [ms]:")
    APW_label.pack()
    options4 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
    global clicked4
    clicked4 = IntVar(AAI_screen)
    clicked4.set(1)
    drop4 = OptionMenu(AAI_screen, clicked4, *options4 )
    drop4.pack()
    button = Button(AAI_screen, text = "Update Parameter", command = show4).pack()
    label4 = Label(AAI_screen, text = "")
    label4.pack()


    def show5():
        global ARP_value
        if clicked5.get() <= (60000/slider.get()):
            label5.config(text = clicked5.get())
            ARP_value = clicked5.get()
            file = open('programmable_parameters.txt',"a")
            file.write("Atrial Refractory Period = "+ str(ARP_value) + " " + "ms" + "\n")
            file.close()
    
    
    ARP_label = Label(AAI_screen, text="Atrial Refractory Period [ms]:")
    ARP_label.pack()
    options5 = [150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500]
    global clicked5
    clicked5 = IntVar(AAI_screen)
    clicked5.set(250)
    drop5 = OptionMenu(AAI_screen, clicked5, *options5 )
    drop5.pack()
    button = Button(AAI_screen, text = "Update Parameter", command = show5).pack()
    label5 = Label(AAI_screen, text = "")
    label5.pack()
    
    def show6():
            global AS_value
            label6.config(text = clicked6.get())
            AS_value = clicked6.get()
            file = open('programmable_parameters.txt',"a")
            file.write("Atrial Sensitivity = "+ str(AS_value) + " " + "V" + "\n")
            file.close()
    

    AS_label = Label(AAI_screen, text="Atrial Sensitivity  [V]:")
    AS_label.pack()
    options6 = [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0]
    global clicked6
    clicked6 = DoubleVar(AAI_screen)
    clicked6.set(3.5)
    drop6 = OptionMenu(AAI_screen, clicked6, *options6 )
    drop6.pack()    
    button = Button(AAI_screen, text = "Update Parameter", command = show6).pack()
    label6 = Label(AAI_screen, text = "")
    label6.pack() 
    
    Push = Button(AAI_screen, text = "Push to Pacemaker", command = serialCommunication) #command =  serial() call serial communication code
    Push.pack()
    
############################################################################################    

def VVI_param():
    global VVI_screen
    VVI_screen = Toplevel(modes_screen)
    VVI_screen.title("VVI Programmable Parameters")
    VVI_screen.geometry("400x520")
    Label(VVI_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()

    global mode_value

    mode_value = 2

    #drop down menus and sliders for value selection for programmable parameters
    def show():
        global LRL_value
        if slider.get() < clicked2.get():
            label.config(text = slider.get())
            LRL_value = slider.get()
            file = open('programmable_parameters.txt',"a")
            file.write("LRL = "+ str(LRL_value) + " " + "ppm" + "\n")
            file.close()

    LRL_label = Label(VVI_screen, text="Lower Rate Limit  [ppm]: ")
    LRL_label.pack()
    slider = Scale(VVI_screen, from_=30, to=175, orient=HORIZONTAL)
    slider.pack()
    slider.set(60)
    button = Button(VVI_screen, text = "Update Parameter", command = show).pack()
    label = Label(VVI_screen, text = "")
    label.pack()

    
    def show2():
        global URL_value
        if clicked2.get() > slider.get():
            label2.config(text = clicked2.get())
            URL_value = clicked2.get()
            file = open('programmable_parameters.txt',"a")
            file.write("URL = "+ str(URL_value) + " " + "ppm" + "\n")
            file.close()
        
    URL_label = Label(VVI_screen, text="Upper Rate Limit [ppm]: ")
    URL_label.pack()
    options2 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked2
    clicked2 = IntVar(VVI_screen)
    clicked2.set(120)
    drop2 = OptionMenu(VVI_screen, clicked2, *options2 )
    drop2.pack()
    button = Button(VVI_screen, text = "Update Parameter", command = show2).pack()
    label2 = Label(VVI_screen, text = "")
    label2.pack()

    
    def show3():
        global VA_value
        label3.config(text = clicked3.get())
        VA_value = clicked3.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Ventricular Amlitude = "+ str(VA_value) + " " "V" + "\n")
        file.close()
    
    VA_label = Label(VVI_screen, text="Ventricular Amplitude [V]:")
    VA_label.pack()
    options3 = [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0]
    global clicked3
    clicked3 = DoubleVar(VVI_screen)
    clicked3.set(4.0)
    drop3 = OptionMenu(VVI_screen, clicked3, *options3 )
    drop3.pack()
    button = Button(VVI_screen, text = "Update Parameter", command = show3).pack()
    label3 = Label(VVI_screen, text = "")
    label3.pack()


    def show4():
        global VPW_value
        label4.config(text = clicked4.get())
        VPW_value = clicked4.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Ventricular Pulse Width = "+ str(VPW_value) + " " + "ms" + "\n")
        file.close()
    
    VPW_label = Label(VVI_screen, text="Ventricular Pulse Width [ms]:")
    VPW_label.pack()
    options4 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
    global clicked4
    clicked4 = IntVar(VVI_screen)
    clicked4.set(1)
    drop4 = OptionMenu(VVI_screen, clicked4, *options4 )
    drop4.pack()
    button = Button(VVI_screen, text = "Update Parameter", command = show4).pack()
    label4 = Label(VVI_screen, text = "")
    label4.pack()

        
    def show5():
        global VRP_value
        if clicked5.get() <= (60000/slider.get()):
            label5.config(text = clicked5.get())
            VRP_value = clicked5.get()
            file = open('programmable_parameters.txt',"a")
            file.write("Ventricular Refractory Period = "+ str(VRP_value) + " " + "ms" + "\n")
            file.close()
    
    
    VRP_label = Label(VVI_screen, text="Ventricular Refractory Period [ms]:")
    VRP_label.pack()
    options5 = [150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500]
    global clicked5
    clicked5 = IntVar(VVI_screen)
    clicked5.set(320)
    drop5 = OptionMenu(VVI_screen, clicked5, *options5 )
    drop5.pack()
    button = Button(VVI_screen, text = "Update Parameter", command = show5).pack()
    label5 = Label(VVI_screen, text = "")
    label5.pack()
    
    
    def show6():
        global VS_value
        label6.config(text = clicked6.get())
        VS_value = clicked6.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Ventricular Sensitivity = "+ str(VS_value) + " " + "V" + "\n")
        file.close()
    

    VS_label = Label(VVI_screen, text="Ventricular Sensitivity  [V]:")
    VS_label.pack()
    options6 = [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0]
    global clicked6
    clicked6 = DoubleVar(VVI_screen)
    clicked6.set(3.5)
    drop6 = OptionMenu(VVI_screen, clicked6, *options6 )
    drop6.pack()    
    button = Button(VVI_screen, text = "Update Parameter", command = show6).pack()
    label6 = Label(VVI_screen, text = "")
    label6.pack()   
       
    Push = Button(VVI_screen, text = "Push to Pacemaker", command = serialCommunication) #command =  serial() call serial communcation code
    Push.pack()

############################################################################################

def VOOR_param():
    global VOOR_screen
    VOOR_screen = Toplevel(modes_screen)
    VOOR_screen.title("VOOR Programmable Parameters")
    VOOR_screen.geometry("400x450")
    Label(VOOR_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()

    global mode_value

    mode_value = 5

    #drop down menus and sliders for value selection for programmable parameters
    def show():
        global LRL_value
        if slider.get() < clicked2.get():
            label.config(text = slider.get())
            LRL_value = slider.get()
            file = open('programmable_parameters.txt',"a")
            file.write("LRL = "+ str(LRL_value) + " " + "ppm" + "\n")
            file.close()

    LRL_label = Label(VOOR_screen, text="Lower Rate Limit  [ppm]: ")
    LRL_label.pack()
    slider = Scale(VOOR_screen, from_=30, to=175, orient=HORIZONTAL)
    slider.pack()
    slider.set(60)
    button = Button(VOOR_screen, text = "Update Parameter", command = show).pack()
    label = Label(VOOR_screen, text = "")
    label.pack()

    
    def show2():
        global URL_value
        if clicked2.get() > slider.get():
            label2.config(text = clicked2.get())
            URL_value = clicked2.get()
            file = open('programmable_parameters.txt',"a")
            file.write("URL = "+ str(URL_value) + " " + "ppm" + "\n")
            file.close()
        
    URL_label = Label(VOOR_screen, text="Upper Rate Limit [ppm]: ")
    URL_label.pack()
    options2 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked2
    clicked2 = IntVar(VOOR_screen)
    clicked2.set(120)
    drop2 = OptionMenu(VOOR_screen, clicked2, *options2 )
    drop2.pack()
    button = Button(VOOR_screen, text = "Update Parameter", command = show2).pack()
    label2 = Label(VOOR_screen, text = "")
    label2.pack()
    
    
    def show3():
        global MSR_value
        label3.config(text = clicked3.get())
        MSR_value = clicked3.get()
        file = open('programmable_parameters.txt',"a")
        file.write("MSR = "+ str(MSR_value) + " " + "ppm" + "\n")
        file.close()
            
    MSR_label = Label(VOOR_screen, text="Maximum Sensor Rate [ppm]: ")
    MSR_label.pack()
    options3 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked3
    clicked3 = IntVar(VOOR_screen)
    clicked3.set(120)
    drop3 = OptionMenu(VOOR_screen, clicked3, *options3 )
    drop3.pack()
    button = Button(VOOR_screen, text = "Update Parameter", command = show3).pack()
    label3 = Label(VOOR_screen, text = "")
    label3.pack()
    
    def show4():
        global VA_value
        label4.config(text = clicked4.get())
        VA_value = clicked4.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Ventricular Amplitude = "+ str(VA_value) + " " "V" + "\n")
        file.close()
    
    VA_label = Label(VOOR_screen, text="Ventricular Amplitude [V]:")
    VA_label.pack()
    options4 = [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0]
    global clicked4
    clicked4 = DoubleVar(VOOR_screen)
    clicked4.set(4.0)
    drop4 = OptionMenu(VOOR_screen, clicked4, *options4 )
    drop4.pack()
    button = Button(VOOR_screen, text = "Update Parameter", command = show4).pack()
    label4 = Label(VOOR_screen, text = "")
    label4.pack()
    
    def show5():
        global VPW_value
        label5.config(text = clicked5.get())
        VPW_value = clicked5.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Ventricular Pulse Width = "+ str(VPW_value) + " " + "ms" + "\n")
        file.close()
    
    VPW_label = Label(VOOR_screen, text="Ventricular Pulse Width [ms]:")
    VPW_label.pack()
    options5 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
    global clicked5
    clicked5 = IntVar(VOOR_screen)
    clicked5.set(1)
    drop5 = OptionMenu(VOOR_screen, clicked5, *options5 )
    drop5.pack()
    button = Button(VOOR_screen, text = "Update Parameter", command = show5).pack()
    label5 = Label(VOOR_screen, text = "")
    label5.pack()
    
    def show6():
        global AT_value
        label6.config(text = clicked6.get())
        AT_value = clicked6.get()
        AT_Converter()
        at_value = AT_Converter()
        file = open('programmable_parameters.txt',"a")
        file.write("Activity Threshold = "+ str(at_value)  + "\n")
        file.close()
    
    AT_label = Label(VOOR_screen, text="Activity Threshold:")
    AT_label.pack()
    options6 = ["V-Low","Low","Med-Low", "Med", "Med-High","High","V-High"]
    global clicked6
    clicked6 = StringVar(VOOR_screen)
    clicked6.set("Med")
    drop6 = OptionMenu(VOOR_screen, clicked6, *options6 )
    drop6.pack()
    button = Button(VOOR_screen, text = "Update Parameter", command = show6).pack()
    label6 = Label(VOOR_screen, text = "")
    label6.pack()
     
    def show7():
        global RT_value
        label7.config(text = clicked7.get())
        RT_value = clicked7.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Reaction Time = "+ str(RT_value) + " " + "sec"+ "\n")
        file.close()
    
    RT_label = Label(VOOR_screen, text="Reaction Time [sec]:")
    RT_label.pack()
    options7 = [10,20,30,40,50]
    global clicked7
    clicked7 = IntVar(VOOR_screen)
    clicked7.set(30)
    drop7 = OptionMenu(VOOR_screen, clicked7, *options7 )
    drop7.pack()
    button = Button(VOOR_screen, text = "Update Parameter", command = show7).pack()
    label7 = Label(VOOR_screen, text = "")
    label7.pack()
    
    def show8():
        global RF_value
        label8.config(text = clicked8.get())
        RF_value = clicked8.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Response Factor = "+ str(RF_value) + "\n")
        file.close()
    
    RF_label = Label(VOOR_screen, text="Reaction Factor:")
    RF_label.pack()
    options8 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
    global clicked8
    clicked8 = IntVar(VOOR_screen)
    clicked8.set(8)
    drop8 = OptionMenu(VOOR_screen, clicked8, *options8 )
    drop8.pack()
    button = Button(VOOR_screen, text = "Update Parameter", command = show8).pack()
    label8 = Label(VOOR_screen, text = "")
    label8.pack()
    
    def show9():
        global RCT_value
        label9.config(text = clicked9.get())
        RCT_value = clicked9.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Recovery Time = "+ str(RCT_value) + " " + "sec"+ "\n")
        file.close()
    
    RCT_label = Label(VOOR_screen, text="Recovery Time [sec]:")
    RCT_label.pack()
    options9 = [120,180,240,300,360,420,480,540,600,660,720,780,840,900,960]
    global clicked9
    clicked9 = IntVar(VOOR_screen)
    clicked9.set(300)
    drop9 = OptionMenu(VOOR_screen, clicked9, *options9 )
    drop9.pack()
    button = Button(VOOR_screen, text = "Update Parameter", command = show9).pack()
    label9 = Label(VOOR_screen, text = "")
    label9.pack()
    
    Push = Button(VOOR_screen, text = "Push to Pacemaker", command = serialCommunication) #command =  serial() call serial communcation code
    Push.pack()
    Push.place(x = 400, y =5)
    
############################################################################################

def AOOR_param():
    global AOOR_screen
    AOOR_screen = Toplevel(modes_screen)
    AOOR_screen.title("AOOR Programmable Parameters")
    AOOR_screen.geometry("400x450")
    Label(AOOR_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()

    global mode_value

    mode_value = 7

    #drop down menus and sliders for value selection for programmable parameters
    def show():
        global LRL_value
        if slider.get() < clicked2.get():
            label.config(text = slider.get())
            LRL_value = slider.get()
            file = open('programmable_parameters.txt',"a")
            file.write("LRL = "+ str(LRL_value) + " " + "ppm" + "\n")
            file.close()

    LRL_label = Label(AOOR_screen, text="Lower Rate Limit  [ppm]: ")
    LRL_label.pack()
    slider = Scale(AOOR_screen, from_=30, to=175, orient=HORIZONTAL)
    slider.pack()
    slider.set(60)
    LRL_value = int
    LRL_value = 60
    button = Button(AOOR_screen, text = "Update Parameter", command = show).pack()
    label = Label(AOOR_screen, text = "")
    label.pack()

    
    def show2():
        global URL_value
        if clicked2.get() > slider.get():
            label2.config(text = clicked2.get())
            URL_value = clicked2.get()
            file = open('programmable_parameters.txt',"a")
            file.write("URL = "+ str(URL_value) + " " + "ppm" + "\n")
            file.close()
        
    URL_label = Label(AOOR_screen, text="Upper Rate Limit [ppm]: ")
    URL_label.pack()
    options2 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked2
    clicked2 = IntVar(AOOR_screen)
    clicked2.set(120)
    drop2 = OptionMenu(AOOR_screen, clicked2, *options2 )
    drop2.pack()
    button = Button(AOOR_screen, text = "Update Parameter", command = show2).pack()
    label2 = Label(AOOR_screen, text = "")
    label2.pack()

    def show3():
        global MSR_value
        label3.config(text = clicked3.get())
        MSR_value = clicked3.get()
        file = open('programmable_parameters.txt',"a")
        file.write("MSR = "+ str(MSR_value) + " " + "ppm" + "\n")
        file.close()
            
    MSR_label = Label(AOOR_screen, text="Maximum Sensor Rate [ppm]: ")
    MSR_label.pack()
    options3 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked3
    clicked3 = IntVar(AOOR_screen)
    clicked3.set(120)
    drop3 = OptionMenu(AOOR_screen, clicked3, *options3 )
    drop3.pack()
    button = Button(AOOR_screen, text = "Update Parameter", command = show3).pack()
    label3 = Label(AOOR_screen, text = "")
    label3.pack()
    
    def show4():
        global AA_value
        label4.config(text = clicked4.get())
        AA_value = clicked4.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Atrial Amlitude = "+ str(AA_value) + " " "V" + "\n")
        file.close()
    
    AA_label = Label(AOOR_screen, text="Atrial Amplitude [V]:")
    AA_label.pack()
    options4 = [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0]
    global clicked4
    clicked4 = DoubleVar(AOOR_screen)
    clicked4.set(4.0)
    drop4 = OptionMenu(AOOR_screen, clicked4, *options4 )
    drop4.pack()
    button = Button(AOOR_screen, text = "Update Parameter", command = show4).pack()
    label4 = Label(AOOR_screen, text = "")
    label4.pack()
    
    def show5():
        global APW_value
        label5.config(text = clicked5.get())
        APW_value = clicked5.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Atrial Pulse Width = "+ str(APW_value) + " " + "ms" + "\n")
        file.close()
    
    APW_label = Label(AOOR_screen, text="Atrial Pulse Width [ms]:")
    APW_label.pack()
    options5 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
    global clicked5
    clicked5 = IntVar(AOOR_screen)
    clicked5.set(1)
    drop5 = OptionMenu(AOOR_screen, clicked5, *options5 )
    drop5.pack()
    button = Button(AOOR_screen, text = "Update Parameter", command = show5).pack()
    label5 = Label(AOOR_screen, text = "")
    label5.pack()

    def show6():
        global AT_value
        label6.config(text = clicked6.get())
        AT_value = clicked6.get()
        AT_Converter()
        at_value = AT_Converter()
        file = open('programmable_parameters.txt',"a")
        file.write("Activity Threshold = "+ str(at_value)  + "\n")
        file.close()
    
    AT_label = Label(AOOR_screen, text="Activity Threshold:")
    AT_label.pack()
    options6 = ["V-Low","Low","Med-Low", "Med", "Med-High","High","V-High"]
    global clicked6
    clicked6 = StringVar(AOOR_screen)
    clicked6.set("Med")
    drop6 = OptionMenu(AOOR_screen, clicked6, *options6 )
    drop6.pack()
    button = Button(AOOR_screen, text = "Update Parameter", command = show6).pack()
    label6 = Label(AOOR_screen, text = "")
    label6.pack()
     
    def show7():
        global RT_value
        label7.config(text = clicked7.get())
        RT_value = clicked7.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Reaction Time = "+ str(RT_value) + " " + "sec"+ "\n")
        file.close()
    
    RT_label = Label(AOOR_screen, text="Reaction Time [sec]:")
    RT_label.pack()
    options7 = [10,20,30,40,50]
    global clicked7
    clicked7 = IntVar(AOOR_screen)
    clicked7.set(30)
    drop7 = OptionMenu(AOOR_screen, clicked7, *options7 )
    drop7.pack()
    button = Button(AOOR_screen, text = "Update Parameter", command = show7).pack()
    label7 = Label(AOOR_screen, text = "")
    label7.pack()
    
    def show8():
        global RF_value
        label8.config(text = clicked8.get())
        RF_value = clicked8.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Response Factor = "+ str(RF_value) + "\n")
        file.close()
    
    RF_label = Label(AOOR_screen, text="Reaction Factor:")
    RF_label.pack()
    options8 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
    global clicked8
    clicked8 = IntVar(AOOR_screen)
    clicked8.set(8)
    drop8 = OptionMenu(AOOR_screen, clicked8, *options8 )
    drop8.pack()
    button = Button(AOOR_screen, text = "Update Parameter", command = show8).pack()
    label8 = Label(AOOR_screen, text = "")
    label8.pack()
    
    def show9():
        global RCT_value
        label9.config(text = clicked9.get())
        RCT_value = clicked9.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Recovery Time = "+ str(RCT_value) + " " + "sec"+ "\n")
        file.close()
    
    RCT_label = Label(AOOR_screen, text="Recovery Time [sec]:")
    RCT_label.pack()
    options9 = [120,180,240,300,360,420,480,540,600,660,720,780,840,900,960]
    global clicked9
    clicked9 = IntVar(AOOR_screen)
    clicked9.set(300)
    drop9 = OptionMenu(AOOR_screen, clicked9, *options9 )
    drop9.pack()
    button = Button(AOOR_screen, text = "Update Parameter", command = show9).pack()
    label9 = Label(AOOR_screen, text = "")
    label9.pack()   
    
    Push = Button(AOOR_screen, text = "Push to Pacemaker", command = serialCommunication) #command =  serial() call serial communcation code
    Push.pack()
    Push.place(x = 400, y =5)

############################################################################################

def VVIR_param():
    global VVIR_screen
    VVIR_screen = Toplevel(modes_screen)
    VVIR_screen.title("VVIR Programmable Parameters")
    VVIR_screen.geometry("400x450")
    Label(VVIR_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()

    global mode_value

    mode_value = 6

    #drop down menus and sliders for value selection for programmable parameters
    def show():
        global LRL_value
        if slider.get() < clicked2.get():
            label.config(text = slider.get())
            LRL_value = slider.get()
            file = open('programmable_parameters.txt',"a")
            file.write("LRL = "+ str(LRL_value) + " " + "ppm" + "\n")
            file.close()

    LRL_label = Label(VVIR_screen, text="Lower Rate Limit  [ppm]: ")
    LRL_label.pack()
    slider = Scale(VVIR_screen, from_=30, to=175, orient=HORIZONTAL)
    slider.pack()
    slider.set(60)
    button = Button(VVIR_screen, text = "Update Parameter", command = show).pack()
    label = Label(VVIR_screen, text = "")
    label.pack()

    
    def show2():
        global URL_value
        if clicked2.get() > slider.get():
            label2.config(text = clicked2.get())
            URL_value = clicked2.get()
            file = open('programmable_parameters.txt',"a")
            file.write("URL = "+ str(URL_value) + " " + "ppm" + "\n")
            file.close()
            
            
    URL_label = Label(VVIR_screen, text="Upper Rate Limit [ppm]: ")
    URL_label.pack()
    options2 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked2
    clicked2 = IntVar(VVIR_screen)
    clicked2.set(120)
    drop2 = OptionMenu(VVIR_screen, clicked2, *options2 )
    drop2.pack()
    button = Button(VVIR_screen, text = "Update Parameter", command = show2).pack()
    label2 = Label(VVIR_screen, text = "")
    label2.pack()
    
    def show3():
        global MSR_value
        label3.config(text = clicked3.get())
        MSR_value = clicked3.get()
        file = open('programmable_parameters.txt',"a")
        file.write("MSR = "+ str(MSR_value) + " " + "ppm" + "\n")
        file.close()
            
    MSR_label = Label(VVIR_screen, text="Maximum Sensor Rate [ppm]: ")
    MSR_label.pack()
    options3 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked3
    clicked3 = IntVar(VVIR_screen)
    clicked3.set(120)
    drop3 = OptionMenu(VVIR_screen, clicked3, *options3 )
    drop3.pack()
    button = Button(VVIR_screen, text = "Update Parameter", command = show3).pack()
    label3 = Label(VVIR_screen, text = "")
    label3.pack()
    
    def show4():
        global VA_value
        label4.config(text = clicked4.get())
        VA_value = clicked4.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Ventricular Amplitude = "+ str(VA_value) + " " "V" + "\n")
        file.close()
    
    VA_label = Label(VVIR_screen, text="Ventricular Amplitude [V]:")
    VA_label.pack()
    options4 = [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0]
    global clicked4
    clicked4 = DoubleVar(VVIR_screen)
    clicked4.set(4.0)
    drop4 = OptionMenu(VVIR_screen, clicked4, *options4 )
    drop4.pack()
    button = Button(VVIR_screen, text = "Update Parameter", command = show4).pack()
    label4 = Label(VVIR_screen, text = "")
    label4.pack()
    
    def show5():
        global VPW_value
        label5.config(text = clicked5.get())
        VPW_value = clicked5.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Ventricular Pulse Width = "+ str(VPW_value) + " " + "ms" + "\n")
        file.close()
    
    VPW_label = Label(VVIR_screen, text="Ventricular Pulse Width [ms]:")
    VPW_label.pack()
    options5 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
    global clicked5
    clicked5 = IntVar(VVIR_screen)
    clicked5.set(1)
    drop5 = OptionMenu(VVIR_screen, clicked5, *options5 )
    drop5.pack()
    button = Button(VVIR_screen, text = "Update Parameter", command = show5).pack()
    label5 = Label(VVIR_screen, text = "")
    label5.pack()
    
    def show6():
        global VS_value
        label6.config(text = clicked6.get())
        VS_value = clicked6.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Ventricular Sensitivity = "+ str(VS_value) + " " + "V" + "\n")
        file.close()
    

    VS_label = Label(VVIR_screen, text="Ventricular Sensitivity  [V]:")
    VS_label.pack()
    options6 = [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0]
    global clicked6
    clicked6 = DoubleVar(VVIR_screen)
    clicked6.set(3.5)
    drop6 = OptionMenu(VVIR_screen, clicked6, *options6 )
    drop6.pack()    
    button = Button(VVIR_screen, text = "Update Parameter", command = show6).pack()
    label6 = Label(VVIR_screen, text = "")
    label6.pack()
    
    def show7():
        global VRP_value
        if clicked7.get() <= (60000/slider.get()):
            label7.config(text = clicked7.get())
            VRP_value = clicked7.get()
            file = open('programmable_parameters.txt',"a")
            file.write("Ventricular Refractory Period = "+ str(VRP_value) + " " + "ms" + "\n")
            file.close()  
    
    
    VRP_label = Label(VVIR_screen, text="Ventricular Refractory Period [ms]:")
    VRP_label.pack()
    options7 = [150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500]
    global clicked7
    clicked7 = IntVar(VVIR_screen)
    clicked7.set(320)
    drop5 = OptionMenu(VVIR_screen, clicked7, *options7 )
    drop5.pack()
    button = Button(VVIR_screen, text = "Update Parameter", command = show7).pack()
    label7 = Label(VVIR_screen, text = "")
    label7.pack()
     
    
    def show10():
        global AT_value
        label10.config(text = clicked10.get())
        AT_value = clicked10.get()
        AT_Converter()
        at_value = AT_Converter()
        file = open('programmable_parameters.txt',"a")
        file.write("Activity Threshold = "+ str(at_value)  + "\n")
        file.close()
    
    AT_label = Label(VVIR_screen, text="Activity Threshold:")
    AT_label.pack()
    options10 = ["V-Low","Low","Med-Low", "Med", "Med-High","High","V-High"]
    global clicked10
    clicked10 = StringVar(VVIR_screen)
    clicked10.set("Med")
    drop10 = OptionMenu(VVIR_screen, clicked10, *options10 )
    drop10.pack()
    button = Button(VVIR_screen, text = "Update Parameter", command = show10).pack()
    label10 = Label(VVIR_screen, text = "")
    label10.pack()
     
    def show11():
        global RT_value
        label11.config(text = clicked11.get())
        RT_value = clicked11.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Reaction Time = "+ str(RT_value) + " " + "sec"+ "\n")
        file.close()
    
    RT_label = Label(VVIR_screen, text="Reaction Time [sec]:")
    RT_label.pack()
    options11 = [10,20,30,40,50]
    global clicked11
    clicked11 = IntVar(VVIR_screen)
    clicked11.set(30)
    drop11 = OptionMenu(VVIR_screen, clicked11, *options11 )
    drop11.pack()
    button = Button(VVIR_screen, text = "Update Parameter", command = show11).pack()
    label11 = Label(VVIR_screen, text = "")
    label11.pack()
    
    def show12():
        global RF_value
        label12.config(text = clicked12.get())
        RF_value = clicked12.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Response Factor = "+ str(RF_value) + "\n")
        file.close()
    
    RF_label = Label(VVIR_screen, text="Response Factor:")
    RF_label.pack()
    RF_label.place(x=400, y = 25)
    options12 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
    global clicked12
    clicked12 = IntVar(VVIR_screen)
    clicked12.set(8)
    drop12 = OptionMenu(VVIR_screen, clicked12, *options12 )
    drop12.pack()
    drop12.place(x=400, y = 45 )
    Update = Button(VVIR_screen, text = "Update Parameter", command = show12)
    Update.pack()
    Update.place(x = 400,y = 65)    
    label12 = Label(VVIR_screen, text = "")
    label12.pack()
    label12.place(x=400, y= 95)
    
    def show13():
        global RCT_value
        label13.config(text = clicked13.get())
        RCT_value = clicked13.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Recovery Time = "+ str(RCT_value) + " " + "sec"+ "\n")
        file.close()
    
    RCT_label = Label(VVIR_screen, text="Recovery Time [sec]:")
    RCT_label.pack()
    RCT_label.place(x=400, y = 115)
    options13 = [120,180,240,300,360,420,480,540,600,660,720,780,840,900,960]
    global clicked13
    clicked13 = IntVar(VVIR_screen)
    clicked13.set(300)
    drop13 = OptionMenu(VVIR_screen, clicked13, *options13 )
    drop13.pack()
    drop13.place(x=400, y = 135 )
    Update2 = Button(VVIR_screen, text = "Update Parameter", command = show13)
    Update2.pack()
    Update2.place(x = 400,y = 155)     
    label13 = Label(VVIR_screen, text = "")
    label13.pack()
    label13.place(x =400,y=185)
    
    Push = Button(VVIR_screen, text = "Push to Pacemaker", command = serialCommunication(False)) #command =  serial() call serial communcation code
    Push.pack()
    Push.place(x = 400, y =210)

############################################################################################

def AAIR_param():
    global AAIR_screen
    AAIR_screen = Toplevel(modes_screen)
    AAIR_screen.title("AAIR Programmable Parameters")
    AAIR_screen.geometry("400x450")
    Label(AAIR_screen, text="Review/modify pacing mode paramaters.", bg="pink").pack()

    global mode_value
    

    
    

    global RF_value
    global RT_value 

    mode_value = 8

    #drop down menus and sliders for value selection for programmable parameters
    def show():
        global LRL_value
        if slider.get() < clicked2.get():
            label.config(text = slider.get())
            LRL_value = slider.get()
            file = open('programmable_parameters.txt',"a")
            file.write("LRL = "+ str(LRL_value) + " " + "ppm" + "\n")
            file.close()

    LRL_label = Label(AAIR_screen, text="Lower Rate Limit  [ppm]: ")
    LRL_label.pack()
    slider = Scale(AAIR_screen, from_=30, to=175, orient=HORIZONTAL)
    slider.pack()
    slider.set(60)
    button = Button(AAIR_screen, text = "Update Parameter", command = show).pack()
    label = Label(AAIR_screen, text = "")
    label.pack()

    
    def show2():
        global URL_value
        if clicked2.get() > slider.get():
            label2.config(text = clicked2.get())
            URL_value = clicked2.get()
            file = open('programmable_parameters.txt',"a")
            file.write("URL = "+ str(URL_value) + " " + "ppm" + "\n")
            file.close()
        
    URL_label = Label(AAIR_screen, text="Upper Rate Limit [ppm]: ")
    URL_label.pack()
    options2 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked2
    clicked2 = IntVar(AAIR_screen)
    clicked2.set(120)
    drop2 = OptionMenu(AAIR_screen, clicked2, *options2 )
    drop2.pack()
    button = Button(AAIR_screen, text = "Update Parameter", command = show2).pack()
    label2 = Label(AAIR_screen, text = "")
    label2.pack()
    
    def show3():
        global MSR_value
        label3.config(text = clicked3.get())
        MSR_value = clicked3.get()
        file = open('programmable_parameters.txt',"a")
        file.write("MSR = "+ str(MSR_value) + " " + "ppm" + "\n")
        file.close()
            
    MSR_label = Label(AAIR_screen, text="Maximum Sensor Rate [ppm]: ")
    MSR_label.pack()
    options3 = [50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175]
    global clicked3
    clicked3 = IntVar(AAIR_screen)
    clicked3.set(120)
    drop3 = OptionMenu(AAIR_screen, clicked3, *options3 )
    drop3.pack()
    button = Button(AAIR_screen, text = "Update Parameter", command = show3).pack()
    label3 = Label(AAIR_screen, text = "")
    label3.pack()
    
    def show4():
        global AA_value
        label4.config(text = clicked4.get())
        AA_value = clicked4.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Atrial Amplitude = "+ str(AA_value) + " " "V" + "\n")
        file.close()
    
    AA_label = Label(AAIR_screen, text="Atrial Amplitude [V]:")
    AA_label.pack()
    options4 = [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0]
    global clicked4
    clicked4 = DoubleVar(AAIR_screen)
    clicked4.set(4.0)
    drop4 = OptionMenu(AAIR_screen, clicked4, *options4 )
    drop4.pack()
    button = Button(AAIR_screen, text = "Update Parameter", command = show4).pack()
    label4 = Label(AAIR_screen, text = "")
    label4.pack()
    
    def show5():
        global APW_value
        label5.config(text = clicked5.get())
        APW_value = clicked5.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Atrial Pulse Width = "+ str(APW_value) + " " + "ms" + "\n")
        file.close()
    
    APW_label = Label(AAIR_screen, text="Atrial Pulse Width [ms]:")
    APW_label.pack()
    options5 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
    global clicked5
    clicked5 = IntVar(AAIR_screen)
    clicked5.set(1)
    drop5 = OptionMenu(AAIR_screen, clicked5, *options5 )
    drop5.pack()
    button = Button(AAIR_screen, text = "Update Parameter", command = show5).pack()
    label5 = Label(AAIR_screen, text = "")
    label5.pack()
    
    def show6():
        global AS_value
        label6.config(text = clicked6.get())
        AS_value = clicked6.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Atrial Sensitivity = "+ str(AS_value) + " " + "V" + "\n")
        file.close()
    

    AS_label = Label(AAIR_screen, text="Atrial Sensitivity  [V]:")
    AS_label.pack()
    options6 = [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0]
    global clicked6
    clicked6 = DoubleVar(AAIR_screen)
    clicked6.set(3.5)
    drop6 = OptionMenu(AAIR_screen, clicked6, *options6 )
    drop6.pack()    
    button = Button(AAIR_screen, text = "Update Parameter", command = show6).pack()
    label6 = Label(AAIR_screen, text = "")
    label6.pack()
    
    def show7():
        global ARP_value
        if clicked7.get() <= (60000/slider.get()):
            label7.config(text = clicked7.get())
            ARP_value = clicked7.get()
            file = open('programmable_parameters.txt',"a")
            file.write("Atrial Refractory Period = "+ str(ARP_value) + " " + "ms" + "\n")
            file.close()
    
    
    ARP_label = Label(AAIR_screen, text="Atrial Refractory Period [ms]:")
    ARP_label.pack()
    options7 = [150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500]
    global clicked7
    clicked7 = IntVar(AAIR_screen)
    clicked7.set(250)
    drop5 = OptionMenu(AAIR_screen, clicked7, *options7 )
    drop5.pack()
    button = Button(AAIR_screen, text = "Update Parameter", command = show7).pack()
    label7 = Label(AAIR_screen, text = "")
    label7.pack()
    

    def show11():
        global AT_value
        label11.config(text = clicked11.get())
        AT_value = clicked11.get()
        AT_Converter()
        at_value = AT_Converter()
        file = open('programmable_parameters.txt',"a")
        file.write("Activity Threshold = "+ str(at_value)  + "\n")
        file.close()
    
    AT_label = Label(AAIR_screen, text="Activity Threshold:")
    AT_label.pack()
    options11 = ["V-Low","Low","Med-Low", "Med", "Med-High","High","V-High"]
    global clicked11
    clicked11 = StringVar(AAIR_screen)
    clicked11.set("Med")
    drop11 = OptionMenu(AAIR_screen, clicked11, *options11 )
    drop11.pack()
    button = Button(AAIR_screen, text = "Update Parameter", command = show11).pack()
    label11 = Label(AAIR_screen, text = "")
    label11.pack()
     
    def show12():
        global RT_value
        label12.config(text = clicked12.get())
        RT_value = clicked12.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Reaction Time = "+ str(RT_value) + " " + "sec"+ "\n")
        file.close()
    
    RT_label = Label(AAIR_screen, text="Reaction Time [sec]:")
    RT_label.pack()
    options12 = [10,20,30,40,50]
    global clicked12
    clicked12 = IntVar(AAIR_screen)
    clicked12.set(30)
    drop12 = OptionMenu(AAIR_screen, clicked12, *options12 )
    drop12.pack()
    button = Button(AAIR_screen, text = "Update Parameter", command = show12).pack()
    label12 = Label(AAIR_screen, text = "")
    label12.pack()
    
    def show13():
        global RF_value
        label13.config(text = clicked13.get())
        RF_value = clicked13.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Response Factor = "+ str(RF_value) + "\n")
        file.close()
        
    RF_label = Label(AAIR_screen, text="Reaction Factor:")
    RF_label.pack()
    RF_label.place(x=400, y = 25)
    options13 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
    global clicked13
    clicked13 = IntVar(AAIR_screen)
    clicked13.set(8)
    drop13 = OptionMenu(AAIR_screen, clicked13, *options13 )
    drop13.pack()
    drop13.place(x=400, y = 45 )
    Update = Button(AAIR_screen, text = "Update Parameter", command = show13)
    Update.pack()
    Update.place(x = 400,y = 65)
    label13 = Label(AAIR_screen, text = "")
    label13.pack()
    label13.place(x = 400,y = 95)
    
    def show14():
        global RCT_value
        label14.config(text = clicked14.get())
        RCT_value = clicked14.get()
        file = open('programmable_parameters.txt',"a")
        file.write("Recovery Time = "+ str(RCT_value) + " " + "sec"+ "\n")
        file.close()
    
    RCT_label = Label(AAIR_screen, text="Recovery Time [sec]:")
    RCT_label.pack()
    RCT_label.place(x=400, y = 115)
    options14 = [120,180,240,300,360,420,480,540,600,660,720,780,840,900,960]
    global clicked14
    clicked14 = IntVar(AAIR_screen)
    clicked14.set(300)
    drop14 = OptionMenu(AAIR_screen, clicked14, *options14 )
    drop14.pack()
    drop14.place(x=400, y = 135 )
    Update2 = Button(AAIR_screen, text = "Update Parameter", command = show14)
    Update2.pack()
    Update2.place(x = 400,y = 155)    
    label14 = Label(AAIR_screen, text = "")
    label14.pack()
    label14.place(x =400,y=185)
    
    Push = Button(AAIR_screen, text = "Push to Pacemaker", command =  serialCommunication) #command =  serial() call serial communcation code
    Push.pack()
    Push.place(x = 400, y =210)

############################################################################################
    #Transmit and receive information to/from Pacemaker
    #Set, store, transmit, and verify programmable parameter data is stored correctly on Pacemaker
    
def serialCommunication(echo_only):

    ports = list(serial.tools.list_ports.comports())
    K64F_HWID = "1366:1015"
    for i in ports:
        if K64F_HWID in i.hwid:
                port = i.device
    print("port: ", port)

    if echo_only == True:
        Start = b'\x16'
        SYNC = b'\x33' 
        Param_set = b'\x22'
        ECG = b'\x44'

        mode_reset = struct.pack("h", 0)

        VRP_en = struct.pack("d", VRP_value)
        VentWidth_en = struct.pack("h", VPW_value) 
        URL_en = struct.pack("d", URL_value)
        LRL_en = struct.pack("d", LRL_value)
        ARP_en = struct.pack("d", ARP_value)
        mode_en = struct.pack("h", mode_value) 
        VAmplitude_en = struct.pack("d", VA_value)
        AAmplitude_en = struct.pack("d", AA_value)
        RecoveryTime_en = struct.pack("d", RCT_value)
        ResponseFactor_en = struct.pack("d", RF_value)
        ReactionTime_en = struct.pack("d", RT_value)
        ActivityThreshold_en = struct.pack("d", at_value)
        AtrWidth_en = struct.pack("h", APW_value)
        MSR_en = struct.pack("d", MSR_value)
        VentSensitivity_en = struct.pack("d", VS_value)
        AtrSensitivity_en = struct.pack("d", AS_value)

        Signal_reset = Start + Param_set + VRP_en + VentWidth_en + URL_en + LRL_en + ARP_en + mode_reset + VAmplitude_en + AAmplitude_en + RecoveryTime_en + ResponseFactor_en + ReactionTime_en + ActivityThreshold_en + AtrWidth_en  + MSR_en + VentSensitivity_en + AtrSensitivity_en
        Signal_echo_reset = Start + SYNC + VRP_en + VentWidth_en + URL_en + LRL_en + ARP_en + mode_reset + VAmplitude_en + AAmplitude_en + RecoveryTime_en + ResponseFactor_en + ReactionTime_en + ActivityThreshold_en + AtrWidth_en  + MSR_en + VentSensitivity_en + AtrSensitivity_en

        with serial.Serial(port, 115200) as pacemaker:
            pacemaker.write(Signal_reset)

        with serial.Serial(port, 115200) as pacemaker:
            pacemaker.write(Signal_echo_reset)
            data = pacemaker.read(110)

            VRP_rev = struct.unpack("d", data[0:8])[0]
            VentWidth_rev = struct.unpack("h", data[8:10])[0]
            URL_rev = struct.unpack("d", data[10:18])[0]
            LRL_rev = struct.unpack("d", data[18:26])[0]
            ARP_rev = struct.unpack("d", data[26:34])[0]
            mode_rev = struct.unpack("h", data[34:36])[0]
            VAmplitude_rev = struct.unpack("d", data[36:44])[0]
            AAmplitude_rev = struct.unpack("d", data[44:52])[0]
            RecoveryTime_rev = struct.unpack("d", data[52:60])[0]
            ResponseFactor_rev = struct.unpack("d", data[60:68])[0]
            ReactionTime_rev = struct.unpack("d", data[68:76])[0]
            ActivityThreshold_rev = struct.unpack("d", data[76:84])[0]
            AtrWidth_rev = struct.unpack("h", data[84:86])[0]
            MSR_rev = struct.unpack("d", data[86:94])[0]
            VentSensitivity_rev = struct.unpack("d", data[94:102])[0]
            AtrSensitivity_rev = struct.unpack("d", data[102:110])[0]

            time.sleep(1)


        Signal_set = Start + Param_set + VRP_en + VentWidth_en + URL_en + LRL_en + ARP_en + mode_en + VAmplitude_en + AAmplitude_en + RecoveryTime_en + ResponseFactor_en + ReactionTime_en + ActivityThreshold_en + AtrWidth_en  + MSR_en + VentSensitivity_en + AtrSensitivity_en
        Signal_echo = Start + SYNC + VRP_en + VentWidth_en + URL_en + LRL_en + ARP_en + mode_en + VAmplitude_en + AAmplitude_en + RecoveryTime_en + ResponseFactor_en + ReactionTime_en + ActivityThreshold_en + AtrWidth_en  + MSR_en + VentSensitivity_en + AtrSensitivity_en
        ECG_set = Start + ECG + VRP_en + VentWidth_en + URL_en + LRL_en + ARP_en + mode_en + VAmplitude_en + AAmplitude_en + RecoveryTime_en + ResponseFactor_en + ReactionTime_en + ActivityThreshold_en + AtrWidth_en  + MSR_en + VentSensitivity_en + AtrSensitivity_en

        with serial.Serial(port, 115200) as pacemaker:
            pacemaker.write(Signal_set)

        with serial.Serial(port, 115200) as pacemaker:
            pacemaker.write(Signal_echo)
            data = pacemaker.read(110)

            VRP_rev = struct.unpack("d", data[0:8])[0]
            VentWidth_rev = struct.unpack("h", data[8:10])[0]
            URL_rev = struct.unpack("d", data[10:18])[0]
            LRL_rev = struct.unpack("d", data[18:26])[0]
            ARP_rev = struct.unpack("d", data[26:34])[0]
            mode_rev = struct.unpack("h", data[34:36])[0]
            VAmplitude_rev = struct.unpack("d", data[36:44])[0]
            AAmplitude_rev = struct.unpack("d", data[44:52])[0]
            RecoveryTime_rev = struct.unpack("d", data[52:60])[0]
            ResponseFactor_rev = struct.unpack("d", data[60:68])[0]
            ReactionTime_rev = struct.unpack("d", data[68:76])[0]
            ActivityThreshold_rev = struct.unpack("d", data[76:84])[0]
            AtrWidth_rev = struct.unpack("h", data[84:86])[0]
            MSR_rev = struct.unpack("d", data[86:94])[0]
            VentSensitivity_rev = struct.unpack("d", data[94:102])[0]
            AtrSensitivity_rev = struct.unpack("d", data[102:110])[0]


        print("\nFrom the board:")
        print("VRP_rev = ",VRP_rev)
        print("VentWidth_rev = ", VentWidth_rev)
        print("URL_rev = ", URL_rev)
        print("LRL_rev = ",  LRL_rev)
        print("ARP_rev = ",  ARP_rev)
        print("mode_rev = ", mode_rev)
        print("VAmplitude_rev = ", VAmplitude_rev)
        print("AAmplitude_rev = ", AAmplitude_rev)
        print("RecoveryTime_rev = ", RecoveryTime_rev)
        print("ResponseFactor_rev = ", ResponseFactor_rev)
        print("ReactionTime_rev = ", ReactionTime_rev)
        print("ActivityThreshold_rev = ", ActivityThreshold_rev)
        print("AtrWidth_rev = ", AtrWidth_rev)
        print("MSR_rev = ", MSR_rev)
        print("VentSensitivity_rev = ", VentSensitivity_rev)
        print("AtrSensitivity_rev = ", AtrSensitivity_rev)
        
    elif echo_only == False:
        Start = b'\x16'
            SYNC = b'\x33' 
            Param_set = b'\x22'
            ECG = b'\x44'

            VRP_en = struct.pack("d", VRP_value)
            VentWidth_en = struct.pack("h", VPW_value) 
            URL_en = struct.pack("d", URL_value)
            LRL_en = struct.pack("d", LRL_value)
            ARP_en = struct.pack("d", ARP_value)
            mode_en = struct.pack("h", mode_value) 
            VAmplitude_en = struct.pack("d", VA_value)
            AAmplitude_en = struct.pack("d", AA_value)
            RecoveryTime_en = struct.pack("d", RCT_value)
            ResponseFactor_en = struct.pack("d", RF_value)
            ReactionTime_en = struct.pack("d", RT_value)
            ActivityThreshold_en = struct.pack("d", at_value)
            AtrWidth_en = struct.pack("h", APW_value)
            MSR_en = struct.pack("d", MSR_value)
            VentSensitivity_en = struct.pack("d", VS_value)
            AtrSensitivity_en = struct.pack("d", AS_value)

            Signal_echo = Start + SYNC + VRP_en + VentWidth_en + URL_en + LRL_en + ARP_en + mode_en + VAmplitude_en + AAmplitude_en + RecoveryTime_en + ResponseFactor_en + ReactionTime_en + ActivityThreshold_en + AtrWidth_en  + MSR_en + VentSensitivity_en + AtrSensitivity_en


            with serial.Serial(port, 115200) as pacemaker:
                pacemaker.write(Signal_echo)
                data = pacemaker.read(110)

                VRP_rev = struct.unpack("d", data[0:8])[0]
                VentWidth_rev = struct.unpack("h", data[8:10])[0]
                URL_rev = struct.unpack("d", data[10:18])[0]
                LRL_rev = struct.unpack("d", data[18:26])[0]
                ARP_rev = struct.unpack("d", data[26:34])[0]
                mode_rev = struct.unpack("h", data[34:36])[0]
                VAmplitude_rev = struct.unpack("d", data[36:44])[0]
                AAmplitude_rev = struct.unpack("d", data[44:52])[0]
                RecoveryTime_rev = struct.unpack("d", data[52:60])[0]
                ResponseFactor_rev = struct.unpack("d", data[60:68])[0]
                ReactionTime_rev = struct.unpack("d", data[68:76])[0]
                ActivityThreshold_rev = struct.unpack("d", data[76:84])[0]
                AtrWidth_rev = struct.unpack("h", data[84:86])[0]
                MSR_rev = struct.unpack("d", data[86:94])[0]
                VentSensitivity_rev = struct.unpack("d", data[94:102])[0]
                AtrSensitivity_rev = struct.unpack("d", data[102:110])[0]

                condition = VRP_rev == VRP_en and VentWidth_rev == VentWidth_en and URL_rev == URL_en and LRL_rev == LRL_en and ARP_rev == ARP_en and mode_rev == mode_en and Vamplitude_rev == Vamplitude_en and AAmplitude_rev == AAmplitude_en and RecoveryTime_rev == RecoveryTime_en and ResponseFactor_rev == ResponseFactor_en and ReactionTime_rev == ReactionTime_en and ActivityThreshold_rev == ActivityThreshold_en and AtrWidth_rev == AtrWidth_en and MSR_rev == MSR_en and VentSensitivity_rev == VentSensitivity_en and AtrSensitivity_rev == AtrSensitivity_en


############################################################################################

# Implementing event on register button
def register_user():

    username_info = username.get()
    password_info = password.get()
    
    if username_info == "" or password_info == "":
        empty_field()
        
    else:
    
        file3 = open('user_registration.txt',"a")
        file3.close()
        
        file1 = open('usernames.txt',"a")
        file1.close()
    
        file2 = open('user_registration.txt', "r")
        x = len(file2.readlines())
    
        if x < 10:
            file4 = open('usernames.txt',"r")
            verify = file4.read().splitlines()
            if username_info in verify:
                username_taken()
                
            else:
                username_file = open('usernames.txt',"a")
                username_file.write(username_info + "\n")
                username_file.close()
                
                file = open('user_registration.txt', "a")
                file.write(username_info + " ")
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
    correct_login = username1 + " " + password1
    username_login_entry.delete(0, END)
    password_login_entry.delete(0, END)

    import os.path
    file_exists = os.path.exists('user_registration.txt')

    if file_exists == False:
        Label(login_screen, text="Please register first, then log in.", fg='red').pack()
    else:
        
    
        file1 = open('user_registration.txt', "r")
        verify = file1.read().splitlines()
        if correct_login in verify:
            login_sucess()
            modes()
        else:
            invalid_login()

############################################################################################

# Designing popup for login success
def login_sucess():
    global login_success_screen
    login_success_screen = Toplevel(login_screen)
    login_success_screen.title("Success")
    login_success_screen.geometry("150x100")
    Label(login_success_screen, text="Login Success").pack()
    Button(login_success_screen, text="OK", command=delete_login_success).pack()
    
# Designing popup for logout success
def logout_success():
    global logout_success_screen
    logout_success_screen = Toplevel(modes_screen)
    logout_success_screen.title("Success")
    logout_success_screen.geometry("150x100")
    Label(logout_success_screen, text="Logout Success").pack()
    Button(logout_success_screen, text="OK", command=delete_logout_success).pack()

# Designing popup for login invalid password
def invalid_login():
    global invalid_login_screen
    invalid_login_screen = Toplevel(login_screen)
    invalid_login_screen.title("Error")
    invalid_login_screen.geometry("350x100")
    Label(invalid_login_screen, text="Invalid Username or Password ").pack()
    Button(invalid_login_screen, text="OK", command=delete_invalid_login_screen).pack()

    
# Designing popup for empty username or password error
def empty_field():
    global empty_field_screen
    empty_field_screen = Toplevel(register_screen)
    empty_field_screen.title("Error")
    empty_field_screen.geometry("350x100")
    Label(empty_field_screen, text="Username or password fields can not be empty").pack()
    Button(empty_field_screen, text="OK", command=delete_empty_field_screen).pack()
    
# Designing popup for max users 
def max_users():
    global max_users_screen
    max_users_screen = Toplevel(register_screen)
    max_users_screen.title("Error")
    max_users_screen.geometry("250x100")
    Label(max_users_screen, text="Max. Number of Users Reached").pack()
    Button(max_users_screen, text="OK", command=delete_max_users_screen).pack()

# Designing popup for username taken
def username_taken():
    global username_taken_screen
    username_taken_screen = Toplevel(register_screen)
    username_taken_screen.title("Error")
    username_taken_screen.geometry("250x100")
    Label(username_taken_screen, text="Username Taken").pack()
    Button(username_taken_screen, text="OK", command=delete_username_taken_screen).pack()

############################################################################################

# Deleting popups
def delete_login_success():
    login_success_screen.destroy()
    login_screen.destroy()
    main_screen.destroy()
    
def delete_logout_success():
    logout_success_screen.destroy()
    modes_screen.destroy()
    main_account_screen()
    

def delete_invalid_login_screen():
    invalid_login_screen.destroy()

def delete_user_not_found_screen():
    user_not_found_screen.destroy()
    
def delete_empty_field_screen():
    empty_field_screen.destroy()

def delete_max_users_screen():
    max_users_screen.destroy()
    
def delete_username_taken_screen():
    username_taken_screen.destroy()

def delete_diff_device_screen():
    diff_device_screen.destroy()

############################################################################################

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


# In[ ]:



