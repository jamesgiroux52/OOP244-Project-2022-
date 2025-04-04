# Script for auto input of ms56

import pyautogui as gui
import time

datafile = 'ms56.txt' # contains inputs for expected output

# pause 3 seconds while you set focus to the terminal/console window:
# print('Click on the terminal/console window where the automated keyboard data needs to be entered...')
# print('NOTE: You have 2 seconds to do this!')
time.sleep(1)

# auto type test data from text file:
#with open('w4p2-inputs.txt', 'r') as tst:
with open(datafile, 'r') as tst:
    time.sleep(1)
    tst = tst.readlines()
    for i in range(0, len(tst), 1):
        print(tst[i])
        gui.typewrite(tst[i])

print('Auto data input completed.')