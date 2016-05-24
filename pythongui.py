
import threading
import ChaseDriver
from Tkinter import *
import Tkinter
import time

frame = Tk()

def run():
    try:
        t = threading.Thread(target=ChaseDriver.run)
        t.start()
        
    except:
        print "Error: in threading"

def insertCallBack():
    LstBox.insert(END, E1.get())

def deleteCallBack():
    LstBox.delete(END)

Button1 = Tkinter.Button(frame,text="Go", command=run)
Button1.pack()

LstBox = Listbox(frame,width=50,height=20)

LstBox.pack()

frame.mainloop()
