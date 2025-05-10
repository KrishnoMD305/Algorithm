import pyautogui
import time

time.sleep(1)

message = "Biriyani"
rep = 100

for i in range(rep):
    pyautogui.typewrite(message)
    pyautogui.press("enter")
    time.sleep(0.5)
